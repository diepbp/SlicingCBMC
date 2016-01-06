/*******************************************************************\

Module: Symbolic Execution of ANSI-C

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include <langapi/languages.h>
#include <langapi/language_util.h>

#include <util/simplify_expr.h>
#include <util/time_stopping.h>
#include <util/xml.h>

#include <ansi-c/ansi_c_language.h>

#include <solvers/sat/satcheck.h>
#include <solvers/prop/cover_goals.h>
#include <solvers/prop/literal_expr.h>

#include <goto-symex/build_goto_trace.h>
#include <goto-programs/xml_goto_trace.h>

#include "bmc.h"
#include "bv_cbmc.h"

/*******************************************************************\

   Class: bmc_all_propertiest

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

class bmc_all_propertiest:
  public cover_goalst::observert,
  public messaget
{
public:

  bmc_all_propertiest(
      const goto_functionst &_goto_functions,
      prop_convt &_solver,
      bmct &_bmc):
      goto_functions(_goto_functions), solver(_solver), bmc(_bmc)
	{
	}

  bool operator()();

  virtual void goal_covered(const cover_goalst::goalt &);

  struct updating_assertiont
  {
  	exprt guard;
  	exprt new_guard;

  	updating_assertiont(exprt _cond)
  	{
  		guard = _cond;
  	}

		updating_assertiont(exprt _cond, exprt _guard)
		{
			guard = _cond;
			new_guard = _guard;
		}
  };

  std::vector<updating_assertiont> updating_exprt;
  std::vector<symex_target_equationt::SSA_stept> trace_guards;

  struct goalt
  {
    // a property holds if all instances of it are true
    typedef std::vector<symex_target_equationt::SSA_stepst::iterator> instancest;
    instancest instances;
    std::string description;
    
    // if failed, we compute a goto_trace for the first failing instance
    bool failed;
    goto_tracet goto_trace;
    
    explicit goalt(
      const goto_programt::instructiont &instruction):
      failed(false)
    {
      description=id2string(instruction.source_location.get_comment());
    }
    
    goalt():failed(false)
    {
    }
    
    exprt as_expr() const
    {
      std::vector<exprt> tmp;
      for(instancest::const_iterator
          it=instances.begin();
          it!=instances.end();
          it++)
        tmp.push_back(literal_exprt((*it)->cond_literal));
      return conjunction(tmp);
    }
  };

  typedef std::map<irep_idt, goalt> goal_mapt;
  goal_mapt goal_map;

protected:
  const goto_functionst &goto_functions;
  prop_convt &solver;
  bmct &bmc;
};

/*******************************************************************\

Function: bmc_all_propertiest::goal_covered

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmc_all_propertiest::goal_covered(const cover_goalst::goalt &)
{
	languagest languages(bmc.ns, new_ansi_c_language());
	std::cout << "Goal size: " << goal_map.size() << std::endl;
  for(goal_mapt::iterator
      g_it=goal_map.begin();
      g_it!=goal_map.end();
      g_it++)
  {
    goalt &g=g_it->second;
    std::cout << "Goal size x: " <<  g.instances.size() << "-------------------------------------------------------" << std::endl;
    // check whether failed
    for(goalt::instancest::const_iterator
        c_it=g.instances.begin();
        c_it!=g.instances.end();
        c_it++)
    {
      literalt cond=(*c_it)->cond_literal;
      
      if(solver.l_get(cond).is_false())
      {
        g.failed=true;
        symex_target_equationt::SSA_stepst::iterator next=*c_it;
        next++; // include the assertion

        exprt new_guard, old_guard; trace_guards.clear();
        build_goto_trace_new(bmc.equation, bmc.equation.SSA_steps.end(), solver, bmc.ns, g.goto_trace, new_guard, old_guard);
//        build_goto_trace_new_2(bmc.equation, next, solver, bmc.ns, g.goto_trace, new_guard, old_guard, trace_guards);
        updating_exprt.push_back(updating_assertiont(old_guard, new_guard));

//        bmc.update_conversion(solver, new_guard, old_guard);
//        std::unique_ptr<propt> new_solver;
//        bv_cbmct bv_cbmc(bmc.ns, *new_solver);
//        prop_convt& new_prop =  bv_cbmc;
//        bmc.do_conversion(new_prop);
        break;
      }
    }
  }
}

/*******************************************************************\

Function: bmc_all_propertiest::operator()

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool bmc_all_propertiest::operator()()
{
  status() << "Passing problem to " << solver.decision_procedure_text() << eom;

  solver.set_message_handler(get_message_handler());

  // stop the time
  absolute_timet sat_start=current_time();
  
  bmc.do_conversion(solver);  
  
  // Collect _all_ goals in `goal_map'.
  // This maps property IDs to 'goalt'
  forall_goto_functions(f_it, goto_functions)
    forall_goto_program_instructions(i_it, f_it->second.body)
      if(i_it->is_assert())
        goal_map[i_it->source_location.get_property_id()]=goalt(*i_it);

  // get the conditions for these goals from formula
  // collect all 'instances' of the properties
  for(symex_target_equationt::SSA_stepst::iterator
      it=bmc.equation.SSA_steps.begin();
      it!=bmc.equation.SSA_steps.end();
      it++)
  {
    if(it->is_assert())
    {
      irep_idt property_id;

      if(it->source.pc->is_assert())
        property_id=it->source.pc->source_location.get_property_id();
      else if(it->source.pc->is_goto())
      {
        // this is likely an unwinding assertion
        property_id=id2string(it->source.pc->source_location.get_function())+".unwind."+
                    i2string(it->source.pc->loop_number);
        goal_map[property_id].description=it->comment;
      }
      else
        continue;
      
      goal_map[property_id].instances.push_back(it);
    }
  }
  
  cover_goalst cover_goals(solver);
  
  cover_goals.register_observer(*this);

  languagest languages(bmc.ns, new_ansi_c_language());
  for(goal_mapt::const_iterator
      it=goal_map.begin();
      it!=goal_map.end();
      it++)
  {
  	std::string tmp_string;
  	std::vector<symex_target_equationt::SSA_stepst::iterator> tmp = it->second.instances;
  	for (std::vector<symex_target_equationt::SSA_stepst::iterator>::iterator itx = tmp.begin();
  			itx != tmp.end(); itx++)
  	{
  		languages.from_expr((*itx)->cond_expr, tmp_string);
  		std::cout << "goal: " << tmp_string << " -- ";
  	}

  	std::cout << std::endl;

    // Our goal is to falsify a property, i.e., we will
    // add the negation of the property as goal.
    literalt p=!solver.convert(it->second.as_expr());
    cover_goals.add(p);
  }


  status() << "Running " << solver.decision_procedure_text() << eom;

  cover_goals();

  // output runtime

  {
    absolute_timet sat_stop=current_time();
    status() << "Runtime decision procedure: "
             << (sat_stop-sat_start) << "s" << eom;
  }
  
  // report
  if(bmc.ui!=ui_message_handlert::XML_UI)
  {
    status() << eom;
    status() << "** Results:" << eom;
  }
  
  for(goal_mapt::const_iterator
      it=goal_map.begin();
      it!=goal_map.end();
      it++)
  {
    if(bmc.ui==ui_message_handlert::XML_UI)
    {
      xmlt xml_result("result");
      xml_result.set_attribute("property", id2string(it->first));
      xml_result.set_attribute("status", it->second.failed?"FAILURE":"SUCCESS");

      if(it->second.failed)
        convert(bmc.ns, it->second.goto_trace, xml_result.new_element());

      std::cout << xml_result << "\n";
    }
    else
    {
      status() << "[" << it->first << "] "
               << it->second.description << ": " << (it->second.failed?"FAILED":"OK")
               << eom;
      if(it->second.failed)
      {
				std::string tmp_string;
				std::vector<symex_target_equationt::SSA_stepst::iterator> tmp =
				    it->second.instances;
				for (std::vector<symex_target_equationt::SSA_stepst::iterator>::iterator itx =
				    tmp.begin(); itx != tmp.end(); itx++)
				{
					languages.from_expr((*itx)->cond_expr, tmp_string);
					std::cout << "goal++ " << tmp_string << " -- ";
				}

				std::cout << std::endl;
				show_goto_trace(std::cout, bmc.ns, it->second.goto_trace);
      }
      else
      {
				std::string tmp_string;
				std::vector<symex_target_equationt::SSA_stepst::iterator> tmp =
				    it->second.instances;
				for (std::vector<symex_target_equationt::SSA_stepst::iterator>::iterator itx =
				    tmp.begin(); itx != tmp.end(); itx++)
				{
					languages.from_expr((*itx)->cond_expr, tmp_string);
					std::cout << "goal-- " << tmp_string << " -- ";
				}

				std::cout << std::endl;
				show_goto_trace(std::cout, bmc.ns, it->second.goto_trace);
      }
    }
  }

  status() << eom;
  
  status() << "** " << cover_goals.number_covered()
           << " of " << cover_goals.size() << " failed ("
           << cover_goals.iterations() << " iterations)" << eom;
  
  if (cover_goals.number_covered() == 0)
  	return true;
  else
  	return false;
}

/*******************************************************************\

Function: change_current_instance

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
bool change_current_instance(std::map<std::string, int> &current_instance, const std::string proc_name)
{
	if (proc_name.find("__VERIFIER_atomic_") != std::string::npos)
	{
		current_instance[proc_name] = 1;
		return false;
	}
	else
	{
		current_instance[proc_name] = current_instance[proc_name] + 1;
		return true;
	}
}

/*******************************************************************\

Function: is_index_member_symbol

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool bmct::is_index_member_symbol(const exprt &src)
{
  if(src.id()==ID_index)
    return is_index_member_symbol(src.op0());
  else if(src.id()==ID_member)
    return is_index_member_symbol(src.op0());
  else if(src.id()==ID_symbol)
    return true;
  else
    return false;
}

/*******************************************************************\

Function: simulate_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void construct_atomic_array(std::vector<int> &atomic_sign, std::vector<std::string> lines)
{
	for (int i = lines.size() - 1; i >= 0; --i)
		if (lines[i].find("__VERIFIER_atomic_end();") != std::string::npos)
			atomic_sign.insert(atomic_sign.begin(), i);
		else
		{
			if (lines[i].find("__VERIFIER_atomic_begin();") != std::string::npos)
				atomic_sign.insert(atomic_sign.begin(), -1);
			else if (atomic_sign.size() > 0)
				atomic_sign.insert(atomic_sign.begin(), atomic_sign[0]);
			else
				atomic_sign.insert(atomic_sign.begin(), -1);
		}
}
/*******************************************************************\

Function: simulate_trace for sequential programs

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void bmct::simulate_trace_3(goto_tracet goto_trace,
    std::vector<variable_struct> variables,
    std::vector<int> lines_map,
    std::vector<std::string> lines,
    std::vector<std::vector<int>> CFG,
    const std::vector<int> slicing_lines,

    std::vector<int> atomic_sign)
{

	static int counter = 0;
	bool checked[10000];
	memset(checked, false, sizeof checked);
	for (std::vector<int>::const_iterator it = slicing_lines.begin();
	    it != slicing_lines.end(); ++it)
		if ((*it) > 0)
			checked[*it] = true;

	// possibly a false, check it
	// if the last step is assert -> false
	std::vector<procedure_data> new_file;
	std::map<std::string, int> prev_line;
	int pre_thread = 0;
	std::string pre_thread_name = "";
	int prev_instance = -1;
	std::vector<int> lines_tmp;

	// store the current instance of procedure
	std::map<std::string, int> current_instance;

	// add "main"
	std::vector<command_data> line_proc_main;
	procedure_data m("main", 1);
	m.set_commands(line_proc_main);
	new_file.push_back(m);
	prev_line["main"] = 0;

	// get start from thread 0
	for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin();
	    it != goto_trace.steps.end();)
	{
		if (it->hidden || it->pc->source_location.is_nil())
		{
			it++;
			continue;
		}
		if (it->thread_nr == 0)
			break;
		else
			it = goto_trace.steps.erase(it);
	}



	// handle instructions
	for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin();
	    it != goto_trace.steps.end(); ++it)
	{
		if (it->hidden || it->pc->source_location.is_nil())
			continue;

		unsigned int line1 = std::stoi(as_string((*it).pc->source_location.get_line()), nullptr);

		unsigned int bak_line = line1;
		line1 = lines_map[line1];


		// get procedure name
		std::string proc = as_string((*it).pc->source_location.get_function());

		// do not handle atomic because there are no atomic blocks
		if (proc.size() == 0 ||
				proc.find("__VERIFIER_atomic_begin") != std::string::npos ||
		    proc.find("__VERIFIER_atomic_end") != std::string::npos)
			continue;

		// do not handle procedure of C-thread
		if (proc.compare("__actual_thread_spawn") == 0
		    || proc.compare("pthread_create") == 0)
			continue;

//		std::cout << line1 << " -in- " << proc << std::endl;

		// get the current name of proc
		std::string current_instance_proc;
		if (proc.compare("main") == 0 || proc.find("__VERIFIER_atomic_") != std::string::npos)
			current_instance_proc = proc;
		else
			current_instance_proc = proc + "_call_" + std::to_string(current_instance[proc]);

		// find index proc in new_file
		int index = find_procedure_index(proc, current_instance[proc], new_file);

		// procedure is not defined
		if (index == -1)
		{
			//add procedure definition
			std::vector<command_data> tmp_proc;
			procedure_data m(proc, 1);
			m.set_commands(tmp_proc);
			new_file.push_back(m);
			prev_line[proc] = 0;

			index = new_file.size() - 1;
		}

		std::vector<command_data> proc_lines = new_file[index].commands;

		if (prev_line.find(current_instance_proc) == prev_line.end())
		{
			std::cout << current_instance_proc
			    << " Error in if (prev_line.find(current_instance_proc) == prev_line.end())\n";
		}

		if (prev_line[current_instance_proc] == line1)
			// same line
			continue;


		// print atomic for previous line
		for (std::map<std::string, int>::iterator i = prev_line.begin(); i != prev_line.end(); ++i)
		{
			if (i->second <= 0)
				continue;

			int tmp = atomic_sign.at(i->second - 1);
			if (tmp != -1)
			{
				for (int j = i->second + 1; j < tmp; ++j)
					proc_lines.push_back(command_data(j));
				prev_line[i->first] = tmp;
			}
		}

		// find path
		lines_tmp = find_lines(prev_line[current_instance_proc], line1, CFG, checked);

		if (lines_tmp.size() == 0)
		// reach the end of procedure, start again
		{
			std::cout << prev_line[current_instance_proc] << " vssssss " << line1
			    << " Error in if (lines_tmp.size() == 0)\n";
			continue;
		}

		for (int k = 0; k < lines_tmp.size() - 1; ++k)
		{
			proc_lines.push_back(command_data(lines_tmp[k] - 1));
		}

		// handle loop
		int line2 = -1;
		if (it->is_location())
		{
			std::list<goto_trace_stept>::iterator itx = std::next(it);
//			std::cout << "we here\n";
			while (true)
			{
				if (itx == goto_trace.steps.end())
					break;
				if (itx->hidden || itx->pc->source_location.is_nil())
				{
					itx = std::next(itx);
					continue;
				}

				if (as_string((*itx).pc->source_location.get_function()).compare(proc) == 0 &&
						lines_map[std::stoi(as_string((*itx).pc->source_location.get_line()), nullptr)] != line1)
				{
					line2 = std::stoi(as_string((*itx).pc->source_location.get_line()),
					    nullptr);
					break;
				} else
					itx = std::next(itx);
			}

		}
		if (line2 > 0)
			line2 = lines_map[line2];

		std::string expr_condition;
		if (prev_line[current_instance_proc] > line1)
			expr_condition = get_condition_expr(lines, (line1 - 1), it, line2);
		else
			expr_condition = get_condition_expr(lines, -(line1 - 1), it, line2);

		if (expr_condition.size() > 0)
			std::cout << "expr_condition: " << expr_condition << std::endl;

		// handle assignment
		bool nondet_assign = false;
		if (it->type == goto_trace_stept::ASSIGNMENT)
		{
			std::cout << "assignment\n";
			const irep_idt &identifier = it->lhs_object.get_identifier();
			if (is_index_member_symbol(it->full_lhs))
			{
				expr_condition = from_expr(ns, identifier, it->full_lhs_value);
			} else
			{
				expr_condition = from_expr(ns, identifier, it->lhs_object_value);
			}

			if (slicing_lines[line1] == RightAssign)
			{
				nondet_assign = true;
				std::cout << "nondet_Assign: " << line1 << std::endl;
			}
		}
		if (!nondet_assign)
			proc_lines.push_back(command_data(lines_tmp[lines_tmp.size() - 1] - 1, expr_condition));
		else
			proc_lines.push_back(command_data(lines_tmp[lines_tmp.size() - 1] - 1, expr_condition, true));

		prev_line[current_instance_proc] = line1;

		// handle function call
		if (it->pc->is_function_call())
		{
			// reverse call function
			proc_lines.at(proc_lines.size() - 1) = command_data(
			    -proc_lines.at(proc_lines.size() - 1).line_number,
			    proc_lines.at(proc_lines.size() - 1).condition);

			std::string code = from_expr(ns, (*it).pc->source_location.get_function(),
			    (*it).pc->code);
			std::cout << code << std::endl;

			std::string new_proc_name = get_proc_name(code);

			std::cout << "New proc name: " << new_proc_name << std::endl;

			// create new instance of procedure
			std::map<std::string, int>::iterator it_proc = current_instance.find(new_proc_name);
			std::vector<command_data> line_proc;
			if (it_proc != current_instance.end())
			{
				bool added = change_current_instance(current_instance, new_proc_name);
				if (added)
				{
					int t_proc = current_instance[new_proc_name];
					procedure_data tmp_proc(new_proc_name, t_proc);
					new_file.push_back(tmp_proc);
					prev_line[generate_new_name(new_proc_name, t_proc)] = 0;
				}
			} else
			{
				current_instance[new_proc_name] = 1;
				procedure_data tmp_proc(new_proc_name, 1);
				new_file.push_back(tmp_proc);
				prev_line[generate_new_name(new_proc_name, 1)] = 0;
				std::cout << "Instance: Nope " << 1 << std::endl;
			}
		}

		if (index == -1)
			std::cerr << "if (index == -1) beng beng\n";
		else
		{
			new_file.at(index) = procedure_data(proc, current_instance[proc],
			    proc_lines);
		}
	}

	write_to_file(++counter, new_file, lines);
}

/*******************************************************************\

Function: simulate_trace for concurrent program ---> one procedure

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void bmct::simulate_trace_2(goto_tracet goto_trace,
    std::vector<variable_struct> variables,
    std::vector<int> lines_map,
    std::vector<std::string> lines,
    std::vector<std::vector<int>> CFG,
    const std::vector<int> slicing_lines,

    std::vector<int> atomic_sign)
{

	static int counter = 0;
	bool checked[10000];
	memset(checked, false, sizeof checked);
	for (std::vector<int>::const_iterator it = slicing_lines.begin();
	    it != slicing_lines.end(); ++it)
		if ((*it) > 0)
			checked[*it] = true;

	// possibly a false, check it
	// if the last step is assert -> false
	std::vector<procedure_data> new_file;
	std::map<std::string, int> prev_line;
	int pre_thread = 0;
	std::string pre_thread_name = "";
	int prev_instance = -1;
	std::vector<int> lines_tmp;

	// store the current instance of procedure
	std::map<std::string, int> current_instance;

	// add "main"
	std::vector<command_data> line_proc_main;
	procedure_data m("main", 1);
	m.set_commands(line_proc_main);
	new_file.push_back(m);
	prev_line["main"] = 0;

	// get start from thread 0
	for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin();
	    it != goto_trace.steps.end();)
	{
		if (it->hidden || it->pc->source_location.is_nil())
		{
			it++;
			continue;
		}
		if (it->thread_nr == 0)
			break;
		else
			it = goto_trace.steps.erase(it);
	}

	std::vector<command_data> proc_lines;

	// handle instructions
	for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin();
	    it != goto_trace.steps.end(); ++it)
	{
		if (it->hidden || it->pc->source_location.is_nil())
			continue;

		unsigned int line1 = std::stoi(as_string((*it).pc->source_location.get_line()), nullptr);

		unsigned int bak_line = line1;
		line1 = lines_map[line1];


		// get procedure name
		std::string proc = as_string((*it).pc->source_location.get_function());

		// do not handle atomic because there are no atomic blocks
		if (proc.size() == 0 ||
				proc.find("__VERIFIER_atomic_begin") != std::string::npos ||
		    proc.find("__VERIFIER_atomic_end") != std::string::npos)
			continue;

		// do not handle procedure of C-thread
		if (proc.compare("__actual_thread_spawn") == 0
		    || proc.compare("pthread_create") == 0)
			continue;

//		std::cout << line1 << " -in- " << proc << std::endl;

		// get the current name of proc
		std::string current_instance_proc;
		if (proc.compare("main") == 0 || proc.find("__VERIFIER_atomic_") != std::string::npos)
			current_instance_proc = proc;
		else
			current_instance_proc = proc + "_call_" + std::to_string(current_instance[proc]);

		// find index proc in new_file
		int index = find_procedure_index(proc, current_instance[proc], new_file);

		// procedure is not defined
		if (index == -1)
		{
			//add procedure definition
			std::vector<command_data> tmp_proc;
			procedure_data m(proc, 1);
			m.set_commands(tmp_proc);
			new_file.push_back(m);
			prev_line[proc] = 0;

			index = new_file.size() - 1;
		}

		if (prev_line.find(current_instance_proc) == prev_line.end())
		{
			std::cout << current_instance_proc << " Error in if (prev_line.find(current_instance_proc) == prev_line.end())\n";
		}

		if (prev_line[current_instance_proc] == line1)
			// same line
			continue;


		// print atomic for previous line
		for (std::map<std::string, int>::iterator i = prev_line.begin(); i != prev_line.end(); ++i)
		{
			if (i->second <= 0)
				continue;

			int tmp = atomic_sign.at(i->second - 1);
			if (tmp != -1)
			{
				for (int j = i->second + 1; j < tmp; ++j)
					proc_lines.push_back(command_data(j));
				prev_line[i->first] = tmp;
			}
		}

		// find path
		lines_tmp = find_lines(prev_line[current_instance_proc], line1, CFG, checked);

		if (lines_tmp.size() == 0)
		// reach the end of procedure, start again
		{
			std::cout << prev_line[current_instance_proc] << " vssssss " << line1
			    << " Error in if (lines_tmp.size() == 0)\n";
			continue;
		}

		for (int k = 0; k < lines_tmp.size() - 1; ++k)
		{
			proc_lines.push_back(command_data(lines_tmp[k] - 1));
		}

		// handle loop
		int line2 = -1;
		if (it->is_location())
		{
			std::list<goto_trace_stept>::iterator itx = std::next(it);
			std::cout << "we here\n";
			while (true)
			{
				if (itx == goto_trace.steps.end())
					break;
				if (itx->hidden || itx->pc->source_location.is_nil())
				{
					itx = std::next(itx);
					continue;
				}

				if (as_string((*itx).pc->source_location.get_function()).compare(proc) == 0 &&
						lines_map[std::stoi(as_string((*itx).pc->source_location.get_line()), nullptr)] != line1)
				{
					line2 = std::stoi(as_string((*itx).pc->source_location.get_line()),
					    nullptr);
					break;
				} else
					itx = std::next(itx);
			}

		}
		if (line2 > 0)
			line2 = lines_map[line2];

		std::string expr_condition;
		if (prev_line[current_instance_proc] > line1)
			expr_condition = get_condition_expr(lines, (line1 - 1), it, line2);
		else
			expr_condition = get_condition_expr(lines, -(line1 - 1), it, line2);

		if (expr_condition.size() > 0)
			std::cout << "expr_condition: " << expr_condition << std::endl;

		// handle assignment
		bool nondet_assign = false;
		if (it->type == goto_trace_stept::ASSIGNMENT)
		{
			std::cout << "assignment\n";
			const irep_idt &identifier = it->lhs_object.get_identifier();
			if (is_index_member_symbol(it->full_lhs))
			{
				expr_condition = from_expr(ns, identifier, it->full_lhs_value);
			} else
			{
				expr_condition = from_expr(ns, identifier, it->lhs_object_value);
			}

			if (slicing_lines[line1] == RightAssign)
			{
				nondet_assign = true;
				std::cout << "nondet_Assign: " << line1 << std::endl;
			}
		}
		if (!nondet_assign)
			proc_lines.push_back(command_data(lines_tmp[lines_tmp.size() - 1] - 1, expr_condition));
		else
			proc_lines.push_back(command_data(lines_tmp[lines_tmp.size() - 1] - 1, expr_condition, true));

		prev_line[current_instance_proc] = line1;

		// handle function call
		if (it->pc->is_function_call())
		{
			// reverse call function
			proc_lines.at(proc_lines.size() - 1) = command_data(
			    -proc_lines.at(proc_lines.size() - 1).line_number,
			    proc_lines.at(proc_lines.size() - 1).condition);

			std::string code = from_expr(ns, (*it).pc->source_location.get_function(),
			    (*it).pc->code);
			std::cout << code << std::endl;

			std::string new_proc_name = get_proc_name(code);

			std::cout << "New proc name: " << new_proc_name << std::endl;

			// create new instance of procedure
			std::map<std::string, int>::iterator it_proc = current_instance.find(new_proc_name);
			std::vector<command_data> line_proc;
			if (it_proc != current_instance.end())
			{
				bool added = change_current_instance(current_instance, new_proc_name);
				if (added)
				{
					int t_proc = current_instance[new_proc_name];
					procedure_data tmp_proc(new_proc_name, t_proc + 1);
					new_file.push_back(tmp_proc);
					prev_line[generate_new_name(new_proc_name, t_proc + 1)] = 0;
					std::cout << "Instance: " << t_proc + 1 << std::endl;
				}
				else
				{
					std::cout << "Instance: Nope" << std::endl;
				}
			} else
			{
				current_instance[new_proc_name] = 1;
				procedure_data tmp_proc(new_proc_name, 1);
				new_file.push_back(tmp_proc);
				prev_line[generate_new_name(new_proc_name, 1)] = 0;
				std::cout << "Instance: Nopeeeee" << std::endl;
			}
		}

		if (index == -1)
			std::cerr << "if (index == -1) beng beng\n";
		else
		{
			new_file.at(index) = procedure_data(proc, current_instance[proc],
			    proc_lines);
		}
	}

	write_to_file_2(++counter, proc_lines, lines);
}
/*******************************************************************\

Function: simulate_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void bmct::simulate_trace(goto_tracet goto_trace,
    std::vector<variable_struct> variables,
    std::vector<int> lines_map,
    std::vector<std::string> lines,
    std::vector<std::vector<int>> CFG,
    const std::vector<int> slicing_lines)
{
	static int counter = 0;
	bool checked[10000];
	memset(checked, false, sizeof checked);
	for (std::vector<int>::const_iterator it = slicing_lines.begin(); it != slicing_lines.end(); ++it)
		if ((*it) > 0)
				checked[*it] = true;

	// possibly a false, check it
	// if the last step is assert -> false
	std::vector<procedure_data> new_file;
	std::map<std::string, int> prev_line;
	int pre_thread = 0;
	std::string pre_thread_name = "";
	int prev_instance = -1;
	std::vector<int> lines_tmp;

	// store the current instance of procedure
	std::map<std::string, int> current_instance;

	// add "main"
	std::vector<command_data> line_proc_main;
	procedure_data m("main", 1);
	m.set_commands(line_proc_main);
	new_file.push_back(m);
	prev_line["main"] = 0;

	bool added_begin_atomic = false, added_end_atomic = false;

	int remain_begin_atomic[1000];
	memset(remain_begin_atomic, 0, sizeof remain_begin_atomic);

	// get start from thread 0
	for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin();
	    it != goto_trace.steps.end();)
	{
		if (it->hidden || it->pc->source_location.is_nil())
		{
			it++;
			continue;
		}
		if (it->thread_nr == 0)
			break;
		else
			it = goto_trace.steps.erase(it);
	}

	// handle instructions
	for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin();
	    it != goto_trace.steps.end(); ++it)
	{
		if (it->hidden || it->pc->source_location.is_nil())
			continue;

		unsigned int line1 = std::stoi(
		    as_string((*it).pc->source_location.get_line()), nullptr);
		unsigned int bak_line = line1;

		line1 = lines_map[line1];

		std::string proc = as_string((*it).pc->source_location.get_function());

		std::cout << "line: " << line1 << std::endl;
		if (proc.size() == 0 ||
				(proc.find("__VERIFIER_atomic_begin") != std::string::npos && added_begin_atomic) ||
				(proc.find("__VERIFIER_atomic_end") != std::string::npos && added_end_atomic))
			continue;

		if (proc.compare("__actual_thread_spawn") == 0
		    || proc.compare("pthread_create") == 0)
			continue;

//		std::cout << line1 << " -in- " << proc << std::endl;

		// get the current name of proc
		std::string current_instance_proc;
		if (proc.compare("main") == 0 ||
				proc.find("__VERIFIER_atomic_") != std::string::npos)
		{
			current_instance_proc = proc;
		}
		else
			current_instance_proc = proc + "_call_"
			    + std::to_string(current_instance[proc]);

		// find index proc
		int index = find_procedure_index(proc, current_instance[proc], new_file);

		// procedure is defined
		if (index == -1)
		{
			//add procedure definition
			std::vector<command_data> tmp_proc;
			procedure_data m(proc, 1);
			m.set_commands(tmp_proc);
			new_file.push_back(m);
			prev_line[proc] = 0;

			index = new_file.size() - 1;
		}

		if (prev_line.find(current_instance_proc) == prev_line.end())
		{
			std::cout << current_instance_proc
			    << " Error in if (prev_line.find(current_instance_proc) == prev_line.end())\n";
		}

		if (prev_line[current_instance_proc] == line1)
			// same line
			continue;

		lines_tmp = find_lines(prev_line[current_instance_proc], line1, CFG,
		    checked);

		if (lines_tmp.size() == 0)
		// reach the end of procedure, start again
		{
			std::cout << prev_line[current_instance_proc] << " vssssss " << line1
			    << " Error in if (lines_tmp.size() == 0)\n";
			continue;
		}

		std::cout << "index: " << index << std::endl;
		std::vector<command_data> proc_lines = new_file[index].commands;

		// for concurrent program
		if (pre_thread != it->thread_nr)
		{
			// add atomic begin
			if (proc.find("atomic") == std::string::npos)
			{
				if (proc.compare("main") != 0)
					proc_lines.push_back(command_data(32760));
			} else
				remain_begin_atomic[it->thread_nr] = 1;

			// add atomic end for prev thread
			int prev_index = find_procedure_index(pre_thread_name, prev_instance,
			    new_file);

			if (prev_index != -1 && pre_thread_name.compare("main") != 0)
			{
				std::vector<command_data> prev_lines = new_file.at(prev_index).commands;

				// find position to add "end atomic"
				// --> if not call, add at the end; otherwise add before the call
				std::string last_line = lines.at(abs(prev_lines.at(prev_lines.size() - 1).line_number));
				std::cout << "Last line: " << last_line << std::endl;
				if (!is_procedure_call(last_line))
				{
					std::cout << "Add bracket\n";
					prev_lines.push_back(command_data(-32760));
				} else
				{
					command_data temp = prev_lines.at(prev_lines.size() - 1);
					prev_lines.pop_back();
					prev_lines.push_back(command_data(-32760));
					prev_lines.push_back(temp);
					std::cout << "Change atomic order because of call\n";
				}

				procedure_data tmp_proc(pre_thread_name, prev_instance, prev_lines);
				new_file.at(prev_index) = tmp_proc;
				std::cout << "End atomic: " << pre_thread_name << " " << prev_instance
				    << std::endl;
			}

			pre_thread_name = proc;
			pre_thread = it->thread_nr;
			prev_instance = current_instance[proc];
			std::cout << "Pre thread: " << pre_thread_name << " " << prev_instance
			    << std::endl;
		}

		else if (pre_thread_name.compare(proc) != 0)
		{
			if (remain_begin_atomic[it->thread_nr] == 1
			    && proc.find("atomic") == std::string::npos)
			{
				proc_lines.push_back(command_data(32760));
				remain_begin_atomic[it->thread_nr] = 0;
			}
			pre_thread_name = proc;

		}

		for (int k = 0; k < lines_tmp.size() - 1; ++k)
		{
			proc_lines.push_back(command_data(lines_tmp[k] - 1));
		}

		// handle loop
		int line2 = -1;
		if (it->is_location())
		{
			std::list<goto_trace_stept>::iterator itx = std::next(it);
//			std::cout << "we here\n";
			while (true)
			{
				if (itx == goto_trace.steps.end())
					break;
				if (itx->hidden || itx->pc->source_location.is_nil())
				{
					itx = std::next(itx);
					continue;
				}

				if (as_string((*itx).pc->source_location.get_function()).compare(proc) == 0
				    && lines_map[std::stoi( as_string((*itx).pc->source_location.get_line()), nullptr)] != line1)
				{
					line2 = std::stoi(as_string((*itx).pc->source_location.get_line()), nullptr);
					break;
				} else
					itx = std::next(itx);
			}

		}
		if (line2 > 0)
			line2 = lines_map[line2];

		std::string expr_condition;
		if (prev_line[current_instance_proc] > line1)
			expr_condition = get_condition_expr(lines, (line1 - 1), it, line2);
		else
			expr_condition = get_condition_expr(lines, -(line1 - 1), it, line2);

		// handle assignment
		bool nondet_assign = false;
		if (it->type == goto_trace_stept::ASSIGNMENT)
		{
			const irep_idt &identifier = it->lhs_object.get_identifier();
			if (is_index_member_symbol(it->full_lhs))
			{
				std::cout << "assignment 3: " << from_expr(ns, identifier, it->full_lhs)
				    << "-->" << from_expr(ns, identifier, it->full_lhs_value)
				    << std::endl;
				expr_condition = from_expr(ns, identifier, it->full_lhs_value);
			} else
			{
				std::cout << "assignment 3: "
				    << from_expr(ns, identifier, it->lhs_object) << "-->"
				    << from_expr(ns, identifier, it->lhs_object_value) << std::endl;
				expr_condition = from_expr(ns, identifier, it->lhs_object_value);
			}

			if (slicing_lines[bak_line] == RightAssign)
				nondet_assign = true;
		}
		if (nondet_assign)
			proc_lines.push_back(command_data(lines_tmp[lines_tmp.size() - 1] - 1, expr_condition));
		else
			proc_lines.push_back(command_data(lines_tmp[lines_tmp.size() - 1] - 1, expr_condition, true));

		prev_line[current_instance_proc] = line1;
		if (it->pc->is_function_call())
		{
			// reverse call function
			proc_lines.at(proc_lines.size() - 1) = command_data(
			    -proc_lines.at(proc_lines.size() - 1).line_number,
			    proc_lines.at(proc_lines.size() - 1).condition);

			std::string code = from_expr(ns, (*it).pc->source_location.get_function(),
			    (*it).pc->code);
			std::cout << code << std::endl;

			std::string new_proc_name = get_proc_name(code);

			std::cout << "New proc name: " << new_proc_name << std::endl;

			// create new instance of procedure
			std::map<std::string, int>::iterator it_proc = current_instance.find(
			    new_proc_name);
			std::vector<command_data> line_proc;
			if (it_proc != current_instance.end())
			{
				bool added = change_current_instance(current_instance, new_proc_name);
				if (added)
				{
					int t_proc = current_instance[new_proc_name];
					procedure_data tmp_proc(new_proc_name, t_proc + 1);
					new_file.push_back(tmp_proc);
					prev_line[generate_new_name(new_proc_name, t_proc + 1)] = 0;
				}
				else
				{
					if (new_proc_name.compare("__VERIFIER_atomic_begin") == 0)
						added_begin_atomic = true;
					else if (new_proc_name.compare("__VERIFIER_atomic_end") == 0)
						added_end_atomic = true;
				}
			} else
			{
				current_instance[new_proc_name] = 1;
				procedure_data tmp_proc(new_proc_name, 1);
				new_file.push_back(tmp_proc);
				prev_line[generate_new_name(new_proc_name, 1)] = 0;
			}
		}

		if (index == -1)
			std::cerr << "if (index == -1) beng beng\n";
		else
		{
			new_file.at(index) = procedure_data(proc, current_instance[proc],
			    proc_lines);
		}
	}

	// add the last slicing_unlock
	for (int itt = 0; itt != new_file.size(); itt++)
	{
		int counterx = 0;
		std::vector<command_data> tmp = new_file[itt].commands;
		for (std::vector<command_data>::iterator itx = tmp.begin();
		    itx != tmp.end(); ++itx)
		{
			if ((*itx).line_number == 32760)
				counterx++;
			else if ((*itx).line_number == -32760)
				counterx--;
		}
		if (counterx == 1)
		{
			command_data tmp_command(-32760);
			tmp.push_back(tmp_command);
			procedure_data tmp_proc(new_file[itt].name, new_file[itt].instance, tmp);
			new_file.at(itt) = tmp_proc;
		}
	}

	write_to_file(++counter, new_file, lines);
}

/*******************************************************************\

Function: exec

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void *exec(void *args) {
	char* cmd = *((char* *) args);
	FILE* pipe = popen(cmd, "r");
	char buffer[128];
	std::string result = "";
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
		{
			result += buffer;
		}
	}
	pclose(pipe);

	std::string last_line(buffer);
	int *err = (int *)malloc(sizeof(int));
	if (last_line.find("VERIFICATION FAILED") == std::string::npos)
		*err = 1;
	else
		*err = 0;
	pthread_exit(err);
}

/*******************************************************************\

Function: bmct::all_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
int run_constructed_file(int number) {
	std::string s = std::to_string(number);
	std::string cmd = "cbmc /Users/diepbp/Desktop/test/slicing_" + s + ".c";

	std::cout << cmd << std::endl;

	const char* ss = cmd.c_str();
	pthread_t thread_id;
	void *thread_return;
	pthread_create(&thread_id, NULL, exec, (void *) &ss);
	pthread_join(thread_id, &thread_return);
	int result = *((int *)thread_return);
	return result;
}

/*******************************************************************\

Function: bmct::all_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool bmct::all_properties(
  const goto_functionst &goto_functions,
  prop_convt &solver,
  std::vector<variable_struct> variables,
    std::vector<int> lines_map,
    std::vector<std::string> lines,
    std::vector<std::vector<int>> CFG,
    const std::vector<int> slicing_lines)
{
	std::cout << "in bool bmct::all_properties\n";
	init();
	CParser c_parser("c_token_automata.dat");

	languagest languages(ns, new_ansi_c_language());
	int counter_loop = 0;
	bool result = false;
	std::cout << "we start\n";

	std::vector<int> atomic_sign;
	construct_atomic_array(atomic_sign, lines);

	while (!result && counter_loop < 2)
//	while (!result)
	{
		std::unique_ptr<propt> new_solver;

		// SAT preprocessor won't work with beautification.
		if (options.get_bool_option("sat-preprocessor")
		    && !options.get_bool_option("beautify"))
		{
			new_solver = std::unique_ptr<propt>(new satcheckt);
		} else
			new_solver = std::unique_ptr<propt>(new satcheck_minisat_no_simplifiert);

		new_solver->set_message_handler(get_message_handler());

		bv_cbmct bv_cbmc(ns, *new_solver);

#if 0
		std::vector<exprt> conditions;
		// optimize for pthread-wmm
		// get all procedure name
		for(symex_target_equationt::SSA_stepst::iterator
		      s_it=equation.SSA_steps.begin();
		      s_it!=equation.SSA_steps.end();
		      s_it++)
		{
			std::string string_value;
			languages.from_expr(s_it->cond_expr, string_value);
			if (string_value.find("#return_value!") != std::string::npos)
			{
				std::cout << string_value << std::endl;
				languages.from_expr(s_it->cond_expr.op0(), string_value);
				if (string_value.find("main") == std::string::npos &&
						string_value.find("pthread_create") == std::string::npos &&
						string_value.find("nondet") == std::string::npos)
				{
					languages.from_expr(s_it->cond_expr.op1(), string_value);
					if (string_value.find("NULL") == std::string::npos)
						conditions.push_back(s_it->cond_expr.op0());
				}
			}
		}

		std::cout << "return return\n";
		exprt additional_expr = true_exprt();
		constant_exprt zero = constant_exprt::integer_constant(0);
		exprt nill = nil_exprt();
		for (std::vector<exprt>::iterator it = conditions.begin(); it != conditions.end(); ++it)
		{
			std::string string_value;
			exprt tmp_guard = equal_exprt(*it, zero);
			languages.from_expr(*it, string_value);
			std::cout << "return value: " << string_value << std::endl;
			additional_expr = and_exprt(additional_expr, *it);
		}

		// edit the assertion
		for(symex_target_equationt::SSA_stepst::iterator
				      s_it=equation.SSA_steps.begin();
				      s_it!=equation.SSA_steps.end();
				      s_it++)
		{
			if (s_it->is_assert())
			{
				s_it->cond_expr = and_exprt(s_it->cond_expr, additional_expr);
				s_it->guard = and_exprt(s_it->guard, additional_expr);
			}
		}
#endif

		bmc_all_propertiest bmc_all_properties(goto_functions, bv_cbmc, *this);
		bmc_all_properties.set_message_handler(get_message_handler());
		result = bmc_all_properties();
#if 0
		// reconstruct counterexamples
		for(bmc_all_propertiest::goal_mapt::const_iterator
				      it=bmc_all_properties.goal_map.begin();
				      it!=bmc_all_properties.goal_map.end();
				      it++)
		{
			 if(it->second.failed)
			 {
				 simulate_trace_2(it->second.goto_trace, variables, lines_map, lines, CFG, slicing_lines, atomic_sign);
				 int r = run_constructed_file(counter_loop + 1);
				 if (r == 0)
				 {
					 std::cout << "Number of loop traces: " << counter_loop << std::endl;
					 return false;
				 }
			 }
		}
#endif

#if 1
		std::cout << "After reconstructing counterexamples\n";

		std::map<std::string, exprt> current_instances;
		symex_target_equationt::SSA_stepst::iterator ssa =
				equation.SSA_steps.begin();

		for (int i = 0; i < bmc_all_properties.trace_guards.size(); ++i)
		{
			std::string guard;
			languages.from_expr(bmc_all_properties.trace_guards[i].cond_expr, guard);

			if (guard.find("return_value_nondet") != std::string::npos
			    && guard.find("guard") != std::string::npos)
			{
				std::cout << "trace guard: " << guard << std::endl;
				while (ssa != equation.SSA_steps.end())
				{
					// go to the equation
					if (ssa->cond_expr.is_not_nil())
					{
						// convert
						std::string cond_expr;
						languages.from_expr(ssa->cond_expr, cond_expr);
						if (guard.find(cond_expr) == 0)
						{
							// we got it
							// --> get line
							std::string tmp = as_string(
							    ssa->source.pc->source_location.get_line());
							int line = std::stoi(tmp, nullptr, 10);

							// go back until get if or while
							std::string l;
							while (line >= 0)
							{
								l = lines[lines_map[line] - 1];
								if (l.find("if") != std::string::npos ||
										l.find("while") != std::string::npos)
									break;
								line--;
							}
//							std::cout << "Guard at: " << lines_map[line] - 1 << ": " << lines[lines_map[line] - 1] << std::endl;
//							for (std::map<std::string, exprt>::iterator obj = current_instances.begin(); obj != current_instances.end(); ++obj)
//							{
//								std::string s; languages.from_expr(obj->second, s);
//								std::cout << "\t" << s;
//
//							}
//							std::cout << std::endl;

							// get the expr

							int start_l, finish_l;
							for (start_l = 0; start_l < l.size() &&  l[start_l] != '('; ++start_l);
							for (finish_l = l.size(); finish_l >= 0 &&  l[finish_l] != ')'; --finish_l);
							l = l.substr(start_l, finish_l - start_l + 1);
							std::vector<TokenElement> c_token = c_parser.tokenHandler(l, lines_map[line] - 1);
							exprt new_expr = get_expr(infixToRPN(c_token), current_instances);

//							ssa++;
//							ssa++;
							std::string s; languages.from_expr(ssa->cond_expr, s);
//							if (s.find("return_value_nondet") != std::string::npos
//										    && s.find("guard") != std::string::npos)
							{
								ssa->ssa_rhs = new_expr;
								ssa->cond_expr = equal_exprt(ssa->ssa_full_lhs, ssa->ssa_rhs);

								languages.from_expr(ssa->cond_expr, s);
								std::cout << "new exprt: " << s << std::endl;
							}
//							else
//							{
//								std::cout << "Error:" << s << std::endl;
//								assert(false);
//							}
							break;
						} else
						{
							// update the current state
							std::string original_lhs_object;
							languages.from_expr(ssa->original_lhs_object,
							    original_lhs_object);
							if (original_lhs_object.find("return") == std::string::npos &&
									original_lhs_object.find("guard") == std::string::npos &&
									original_lhs_object.find("__CPROVER") == std::string::npos &&
									original_lhs_object.find("return_value") == std::string::npos)
							current_instances[original_lhs_object] = ssa->ssa_full_lhs;
						}
					}
					ssa++;
				}
			assert(ssa != equation.SSA_steps.end());
			}
			else
			{
//				assert (false);
			}
		}

		std::cout << bmc_all_properties.updating_exprt.size() << std::endl;

#if 1
		//updating solver
		for (int i = 0; i < bmc_all_properties.updating_exprt.size(); ++i)
		{
			exprt new_guard = true_exprt();

			std::string expr_str, old_str;

			new_guard = bmc_all_properties.updating_exprt[i].new_guard;
			simplify(new_guard, ns);

			languages.from_expr(new_guard, expr_str);
			languages.from_expr(bmc_all_properties.updating_exprt[i].guard, old_str);
			std::cout << old_str << " to " << expr_str << " already updated\n";
			for (symex_target_equationt::SSA_stepst::iterator it =
			    equation.SSA_steps.begin(); it != equation.SSA_steps.end(); it++)
			{
				if (it->is_assert())
				{
					if (!it->guard.is_true())
					{
						std::string cond_string;
						languages.from_expr(it->guard, cond_string);
						if (old_str.compare(cond_string) == 0)
						{
							it->guard = and_exprt(it->guard, not_exprt(new_guard));
							it->cond_expr = or_exprt(new_guard, it->cond_expr);
							languages.from_expr(it->cond_expr, expr_str);
							std::cout << expr_str << " already updateddd\n";
							break;
						}
					}
					else
					{
						it->guard = not_exprt(new_guard);
						it->cond_expr = or_exprt(new_guard, it->cond_expr);
						languages.from_expr(it->cond_expr, expr_str);
						std::cout << expr_str << " already updateddd\n";
					}
				}
			}
		}
#endif

#endif
		bmc_all_properties.updating_exprt.clear();
		counter_loop++;
	}

	std::cout << "Number of loop traces: " << counter_loop << std::endl;
	return true;
}

/*******************************************************************\

Function: bmct::all_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
bool bmct::all_properties(
  const goto_functionst &goto_functions,
  prop_convt &solver)
{
	languagest languages(ns, new_ansi_c_language());
	int counter_loop = 0;
	bool result = false;
	std::cout << "in bool bmct::all_properties\n";
//	while (!result && counter_loop < 1)
	while (!result)
	{
		std::unique_ptr<propt> new_solver;

		// SAT preprocessor won't work with beautification.
		if (options.get_bool_option("sat-preprocessor")
		    && !options.get_bool_option("beautify"))
		{
			new_solver = std::unique_ptr<propt>(new satcheckt);
		} else
			new_solver = std::unique_ptr<propt>(new satcheck_minisat_no_simplifiert);

		new_solver->set_message_handler(get_message_handler());

		bv_cbmct bv_cbmc(ns, *new_solver);

#if 0
		std::vector<exprt> conditions;
		// optimize for pthread-wmm
		// get all procedure name
		for(symex_target_equationt::SSA_stepst::iterator
		      s_it=equation.SSA_steps.begin();
		      s_it!=equation.SSA_steps.end();
		      s_it++)
		{
			std::string string_value;
			languages.from_expr(s_it->cond_expr, string_value);
			if (string_value.find("#return_value!") != std::string::npos)
			{
				std::cout << string_value << std::endl;
				languages.from_expr(s_it->cond_expr.op0(), string_value);
				if (string_value.find("main") == std::string::npos &&
						string_value.find("pthread_create") == std::string::npos &&
						string_value.find("nondet") == std::string::npos)
				{
					languages.from_expr(s_it->cond_expr.op1(), string_value);
					if (string_value.find("NULL") == std::string::npos)
						conditions.push_back(s_it->cond_expr.op0());
				}
			}
		}

		std::cout << "return return\n";
		exprt additional_expr = true_exprt();
		constant_exprt zero = constant_exprt::integer_constant(0);
		exprt nill = nil_exprt();
		for (std::vector<exprt>::iterator it = conditions.begin(); it != conditions.end(); ++it)
		{
			std::string string_value;
//			exprt tmp_guard = binary_predicate_exprt(*it, ID_ge, zero);
			exprt tmp_guard = equal_exprt(*it, zero);
			languages.from_expr(*it, string_value);
			std::cout << "return value: " << string_value << std::endl;
			additional_expr = and_exprt(additional_expr, *it);
		}

		// edit the assertion
		for(symex_target_equationt::SSA_stepst::iterator
				      s_it=equation.SSA_steps.begin();
				      s_it!=equation.SSA_steps.end();
				      s_it++)
		{
			if (s_it->is_assert())
			{
				s_it->cond_expr = and_exprt(s_it->cond_expr, additional_expr);
				s_it->guard = and_exprt(s_it->guard, additional_expr);
			}
		}
#endif

		bmc_all_propertiest bmc_all_properties(goto_functions, bv_cbmc, *this);
		bmc_all_properties.set_message_handler(get_message_handler());
		result = bmc_all_properties();

		//updating solver
		for (int i = 0; i < bmc_all_properties.updating_exprt.size(); ++i)
		{
			exprt new_guard = true_exprt();

			std::string expr_str, old_str;

//			new_guard = and_exprt(bmc_all_properties.updating_exprt[i].guard, bmc_all_properties.updating_exprt[i].new_guard);
			new_guard = bmc_all_properties.updating_exprt[i].new_guard;
			simplify(new_guard, ns);

			languages.from_expr(new_guard, expr_str);
			languages.from_expr(bmc_all_properties.updating_exprt[i].guard, old_str);
			std::cout << old_str << " to " << expr_str << " already updated\n";
			for (symex_target_equationt::SSA_stepst::iterator it =
			    equation.SSA_steps.begin(); it != equation.SSA_steps.end(); it++)
			{
				if (it->is_assert())
				{
					if (!it->guard.is_true())
					{
						std::string cond_string;
						languages.from_expr(it->guard, cond_string);
						if (old_str.compare(cond_string) == 0)
						{
							it->guard = and_exprt(it->guard, not_exprt(new_guard));
							it->cond_expr = or_exprt(new_guard, it->cond_expr);
							languages.from_expr(it->cond_expr, expr_str);
							std::cout << expr_str << " already updateddd\n";
							break;
						}
					}
					else
					{
						it->guard = not_exprt(new_guard);
						it->cond_expr = or_exprt(new_guard, it->cond_expr);
						languages.from_expr(it->cond_expr, expr_str);
						std::cout << expr_str << " already updateddd\n";
					}
				}
			}
		}
		bmc_all_properties.updating_exprt.clear();
		counter_loop++;
	}

	std::cout << "Number of loop traces: " << counter_loop << std::endl;
	return true;
}

