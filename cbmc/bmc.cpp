/*******************************************************************\

Module: Symbolic Execution of ANSI-C

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <fstream>
#include <iostream>
#include <memory>

#include <util/string2int.h>
#include <util/i2string.h>
#include <util/source_location.h>
#include <util/time_stopping.h>
#include <util/message_stream.h>

#include <langapi/mode.h>
#include <langapi/languages.h>
#include <langapi/language_util.h>

#include <ansi-c/ansi_c_language.h>

#include <goto-programs/xml_goto_trace.h>
#include <goto-programs/graphml_goto_trace.h>

#include <goto-symex/build_goto_trace.h>
#include <goto-symex/slice.h>
#include <goto-symex/slice_by_trace.h>
#include <goto-symex/memory_model_sc.h>
#include <goto-symex/memory_model_tso.h>
#include <goto-symex/memory_model_pso.h>

#include "bmc.h"
#include "bv_cbmc.h"

/*******************************************************************\

Function: bmct::do_unwind_module

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::do_unwind_module(
  decision_proceduret &decision_procedure)
{
  // this is a hook for hw-cbmc
}

/*******************************************************************\

Function: bmct::error_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::error_trace(const prop_convt &prop_conv)
{
  status() << "Building error trace" << eom;

  build_goto_trace(equation, prop_conv, ns, goto_trace);
  
  #if 0
  if(options.get_option("vcd")!="")
  {
    if(options.get_option("vcd")=="-")
      output_vcd(ns, goto_trace, std::cout);
    else
    {
      std::ofstream out(options.get_option("vcd").c_str());
      output_vcd(ns, goto_trace, out);
    }
  }
  #endif
  
  switch(ui)
  {
  case ui_message_handlert::PLAIN:
    std::cout << "\n" << "Counterexample:" << "\n";
    show_goto_trace(std::cout, ns, goto_trace);
    break;
  
  case ui_message_handlert::XML_UI:
    {
      xmlt xml;
      convert(ns, goto_trace, xml);
      std::cout << xml << "\n";
    }
    break;
  
  default:
    assert(false);
  }

  const std::string graphml=options.get_option("graphml-cex");
  if(!graphml.empty())
  {
    graphmlt cex_graph;
    convert(ns, goto_trace, cex_graph);

    if(graphml=="-")
      write_graphml(cex_graph, std::cout);
    else
    {
      std::ofstream out(graphml.c_str());
      write_graphml(cex_graph, out);
    }
  }

  // get program
}

/*******************************************************************\

Function: bmct::get_error_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::collect_error_trace(const prop_convt &prop_conv)
{
	status() << "Building error trace" << eom;

	build_goto_trace(equation, prop_conv, ns, goto_trace);
	std::string condition = get_error_condition(ns, goto_trace);
	if (condition.size() > 0)
		error_conditions.push_back(condition);
	show_goto_trace(std::cout, ns, goto_trace);
}
/*******************************************************************\

Function: bmct::do_conversion

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::do_conversion(prop_convt &prop_conv)
{
  // convert HDL (hook for hw-cbmc)
  do_unwind_module(prop_conv);
  
  status() << "converting SSA" << eom;

  // convert SSA
  equation.convert(prop_conv);

  // the 'extra constraints'
  if(!bmc_constraints.empty())
  {
    status() << "converting constraints" << eom;

    forall_expr_list(it, bmc_constraints)
      prop_conv.set_to_true(*it);
  }
}

/*******************************************************************\

Function: bmct::do_conversion

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::update_conversion(
		prop_convt &prop_conv,
		const exprt new_expr,
    const exprt old_expr)
{

  status() << "updating SSA" << eom;

  // convert SSA
  equation.update_assertions(prop_conv, new_expr, old_expr);
}



/*******************************************************************\

Function: bmct::run_decision_procedure

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

decision_proceduret::resultt
bmct::run_decision_procedure(prop_convt &prop_conv)
{
  status() << "Passing problem to "
           << prop_conv.decision_procedure_text() << eom;

  prop_conv.set_message_handler(get_message_handler());

  // stop the time
  absolute_timet sat_start=current_time();

  do_conversion(prop_conv);

  status() << "Running " << prop_conv.decision_procedure_text() << eom;

  decision_proceduret::resultt dec_result=prop_conv.dec_solve();
  // output runtime

  {
    absolute_timet sat_stop=current_time();
    status() << "Runtime decision procedure: "
             << (sat_stop-sat_start) << "s" << eom;
  }

  return dec_result;
}

/*******************************************************************\

Function: bmct::report_success

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::report_success()
{
  result() << "VERIFICATION SUCCESSFUL" << eom;

  switch(ui)
  {
  case ui_message_handlert::PLAIN:
    break;
    
  case ui_message_handlert::XML_UI:
    {
      xmlt xml("cprover-status");
      xml.data="SUCCESS";
      std::cout << xml;
      std::cout << "\n";
    }
    break;
    
  default:
    assert(false);
  }
}

/*******************************************************************\

Function: bmct::report_failure

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::report_failure()
{
  result() << "VERIFICATION FAILED" << eom;

  switch(ui)
  {
  case ui_message_handlert::PLAIN:
    break;
    
  case ui_message_handlert::XML_UI:
    {
      xmlt xml("cprover-status");
      xml.data="FAILURE";
      std::cout << xml;
      std::cout << "\n";
    }
    break;
    
  default:
    assert(false);
  }
}

/*******************************************************************\

Function: bmct::show_program

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::show_program()
{
  unsigned count=1;

  languagest languages(ns, new_ansi_c_language());

  for(symex_target_equationt::SSA_stepst::iterator
      it=equation.SSA_steps.begin();
      it!=equation.SSA_steps.end();)
  {
    if(it->is_assignment())
    {
      std::string string_value;
      languages.from_expr(it->cond_expr, string_value);
      std::cout << "(" << count << ") " << string_value << "\n";

      if(!it->guard.is_true())
      {
        languages.from_expr(it->guard, string_value);
        std::cout << std::string(i2string(count).size()+3, ' ');
        std::cout << "guard: " << string_value << "\n";
      }
      
      count++;
      it++;
    }
    else if(it->is_assert() && !it->ignore)
    {
      std::string string_value;
      languages.from_expr(it->cond_expr, string_value);

      std::cout << "(" << count << ") ASSERT("
                << string_value <<") " << "\n";

      if(!it->guard.is_true())
      {
        languages.from_expr(it->guard, string_value);
        std::cout << std::string(i2string(count).size()+3, ' ');
        std::cout << "guard: " << string_value << "\n";
      }
      count++;
      it++;
      //equation.SSA_steps.erase(it);
    }  
    else it++;
  }
}

/*******************************************************************\

Function: find_lines

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::vector<int> bmct::find_lines(int x, int y, std::vector<std::vector<int>> CFG, bool bak_checked[10000])
{
	bool checked[10000];
		for (int i = 0; i < 10000; ++i)
			checked[i] = bak_checked[i];

	std::vector<int> queue;
	queue.push_back(x);
	checked[x] = true;

	int pos = 0;
	int track[10000];
	memset(track, -1, sizeof track);
	track[x] = 0;
	bool reached = false;

	while (pos < queue.size())
	{
		int current = queue[pos++];
		for (int i = 0 ; i < CFG[current].size(); ++i)
		{
			if (checked[CFG[current][i]] == false || CFG[current][i] == y)
			{
				checked[CFG[current][i]] = true;
				track[CFG[current][i]] = current;
				queue.push_back(CFG[current][i]);

				if (CFG[current][i] == y)
				{
					reached = true;
					break;
				}
			}
		}
		if (reached == true)
			break;
	}

	//find path
	int last = y;
	std::vector<int> tmp_result;

	if (reached == false)
	{
		std::cout << checked[y] << std::endl;
		for (int i = 0 ; i < CFG[152].size(); ++i)
			std::cout << CFG[152][i] << " ";
		std::cout << std::endl;
		std::cout << "Cannot reach from " << x << " to " << y << std::endl;
		return tmp_result;
	}

	while (track[last] != x)
	{
		tmp_result.push_back(last);
		last = track[last];
	}
	tmp_result.push_back(last);
	//reverse
	std::vector<int> result;
	for (int i = tmp_result.size() - 1; i >=0; --i)
		result.push_back(tmp_result.at(i));

	std::cout << x << ": ";
	for (int i = 0 ; i < result.size(); ++i)
		std::cout << result[i] << " ";
	std::cout << std::endl;

	return result;
}


/*******************************************************************\

Function: parse_string_bmc

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::vector<std::string> bmct::parse_string_bmc(std::string s)
{
	std::vector<std::string> result;
	char *str=new char[s.size()+1];
	str[s.size()]=0;
	memcpy(str, s.c_str(), s.size());

//	strcpy(str, s.c_str());
//	std::cout << str << std::endl;

	char* pch;
	pch = strtok(str, " ,!+-*/!&|><();\t");

	while (pch != NULL)
	{
		result.push_back(pch);
		pch = strtok(NULL, " ,!+-*/!&|><();\t");
	}

	return result;
}

/*******************************************************************\

Function: has_token_bmc

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool bmct::has_token_bmc(std::string s, std::vector<std::string> list)
{
	for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
		if ((*it).compare(s) == 0)
			return true;
	return false;
}

/*******************************************************************\

Function: write_to_file

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void bmct::find_brackets(int line, std::vector<std::string> lines, int &start, int &finish)
{
	int counter = 0;
	start = -1;
	finish = -1;
	// go to the line
	if (lines[line].find('{') != std::string::npos)
	{
		start = line;
	}
	else
	{
		// find open bracket
		while (lines[++line].size() < 1);

		for (int i = 0; i < lines[line].size(); ++i)
			if (!(lines[line][i] == '\t' ||
					lines[line][i] == ' ' ||
					lines[line][i] == '{' ||
					lines[line][i] == '/')
				 )
			{
				return;
			}
			else if (lines[line][i] == '{')
			{
				start = line;
				break;
			}
	}

	// find close bracket
	for (int i = start; i < lines.size(); ++i)
	{
		// TODO bracket in string
		for (int j = 0 ; j < lines[i].size(); ++j)
		{
			if (lines[i][j] == '{')
				counter ++;
			else if (lines[i][j] == '}')
			{
				counter --;
				if (counter == 0)
				{
					start++;
					finish = i + 1;
					return;
				}
			}

		}
	}
	start++;
	finish++;
}

/*******************************************************************\

Function: generate_new_name

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::string bmct::generate_new_name(std::string name, int number)
{
	return name + "_call_" + std::to_string(number);
}

/*******************************************************************\

Function: write_to_file

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void bmct::write_to_file(int counter, std::vector<std::vector<std::string>> text_file, std::vector<std::string> lines)
{
	std::string s = std::to_string(counter) + ".c";
	std::ofstream writer;
	writer.open("//Users//diepbp//Desktop//test//slicing_" + s);

	// write header
	// including variables definitions, procedure nondet
	int pos = 0;
	for (int i = 0; i < lines.size(); ++i)
		if (lines[i].find("{") != std::string::npos)
		{
			for (int j = i; j >= 0; j--)
				if (parse_string_bmc(lines[j]).size() > 1)
				{
					pos = j;
					break;
				}
			break;
		}
	// write header
	for (int i = 0; i < pos; ++i)
		writer << lines[i] << std::endl;

	// for concurrent program
	writer << "pthread_mutex_t slicing_locker;" << std::endl;

	for (std::vector<std::vector<std::string>>::iterator it = text_file.begin(); it != text_file.end(); ++it)
	{
		for (std::vector<std::string>::iterator i = (*it).begin(); i != (*it).end();
		    ++i)
			writer << (*i) << std::endl;
	}
	writer.close();
}

/*******************************************************************\

Function: insert_brackets

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void bmct::insert_brackets(int line_number, std::vector<std::pair<int, int>> &brackets, std::vector<std::string> &procedure)
{
	// insert bracket
	if (abs(line_number) == 32760)
		return;

	int insert_counter = 0;
	while (brackets.size() > 0)
	{
		if (brackets[brackets.size() - 1].second < line_number + 1 ||
				brackets[brackets.size() - 1].first >= line_number + 1)
		{
			insert_counter++;
			brackets.pop_back();
		} else
			break;
	}

	std::cout << "bracket size: " << line_number << " " << brackets.size() << std::endl;

	// do insert
	if (insert_counter > 0)
	{
		// find position to insert, it is before the atomic
		std::vector<std::string> tmp;
		int insert_pos = procedure.size() - 1;
		while (insert_pos >= 0
		    && (procedure[insert_pos].compare(
		        "pthread_mutex_lock(&slicing_locker);") == 0
		        || procedure[insert_pos].compare(
		            "pthread_mutex_unlock(&slicing_locker);") == 0))
		{
			tmp.insert(tmp.begin(), procedure[insert_pos]);
			insert_pos--;
			procedure.pop_back();
		}

		for (int close_bracket = 0; close_bracket < insert_counter; ++close_bracket)
			tmp.insert(tmp.begin(), "}");

		// add back to procedure
		procedure.insert(procedure.end(), tmp.begin(), tmp.end());
	}
}

/*******************************************************************\

Function: is_procedure_call

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
bool bmct::is_procedure_call(std::string line)
{
	bool is_call = false;
	if (line.find("while") != std::string::npos)
		return false;
	if (line.find("if") != std::string::npos)
			return false;
	if (line.find("for") != std::string::npos)
			return false;
	for (int c = 0; c < line.size(); ++c)
		if (line[c] == '(')
		{
			// find backward to get char
			int pos_c = c - 1;
			while (pos_c >= 0)
			{
			if (line[pos_c] >= 'a' && line[pos_c] <= 'z')
				return true;
			else if (line[pos_c] >= 'A' && line[pos_c] <= 'Z')
				return true;
			else if (line[pos_c] >= '0' && line[pos_c] <= '9')
							return true;
			else if (line[pos_c] == ' ')
				--pos_c;
			else
				break;
		}
	}
	return false;
}

/*******************************************************************\

Function: reorder_atomic

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void bmct::reorder_atomic(std::vector<std::string> &procedure)
{

	// find position to insert, it is before the atomic
	std::vector<std::string> tmp;
	int insert_pos = procedure.size() - 1;
	while (insert_pos >= 0
	    && (procedure[insert_pos].compare("__VERIFIER_atomic_begin();")
	        == 0
	        || procedure[insert_pos].compare(
	            "__VERIFIER_atomic_end();") == 0))
	{
		tmp.insert(tmp.begin(), procedure[insert_pos]);
		insert_pos--;
		procedure.pop_back();
	}

	if (procedure.at(procedure.size() - 1).compare("}") == 0)
	{
		if (procedure.at(procedure.size() - 2).find("return") != std::string::npos)
		{
			if (is_procedure_call(procedure.at(procedure.size() - 3)))
			{
				tmp.push_back(procedure.at(procedure.size() - 3));
				tmp.push_back(procedure.at(procedure.size() - 2));
				tmp.push_back(procedure.at(procedure.size() - 1));
				procedure.pop_back();
				procedure.pop_back();
				procedure.pop_back();
			} else
			{
				tmp.push_back(procedure.at(procedure.size() - 2));
				tmp.push_back(procedure.at(procedure.size() - 1));
				procedure.pop_back();
				procedure.pop_back();
			}
		}
		else if (is_procedure_call(procedure.at(procedure.size() - 2)))
			{
				tmp.push_back(procedure.at(procedure.size() - 2));
				tmp.push_back(procedure.at(procedure.size() - 1));
				procedure.pop_back();
				procedure.pop_back();
			}
		else {
			tmp.push_back(procedure.at(procedure.size() - 1));
			procedure.pop_back();
		}
	} else
		std::cout
		    << "ERROR at void reorder_atomic(std::vector<std::string> &procedure)"
		    << std::endl;

	// add back to procedure
	procedure.insert(procedure.end(), tmp.begin(), tmp.end());

}

/*******************************************************************\

Function: insert_remaining_lines

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void insert_remaining_lines(int start,
		int finish,
		std::vector<std::string> lines,
		std::vector<std::string> &procedure,
		bool in_atomic)
{
	std::cout << "remaining line " << start << " " << finish << std::endl;
	if (start + 1 >= finish)
		return;

	for (int i = start + 1; i < finish; ++i)
	{
		procedure.push_back(lines[i]);
	}
}

int get_first_line(const std::vector<command_data> commands)
{
	for (std::vector<command_data>::const_iterator it = commands.begin(); it != commands.end(); ++it)
		if (it->line_number != 32760 &&
				it->line_number != -32760)
		{
			std::cout << "first line: " <<  it->line_number << std::endl;
			return abs(it->line_number);
		}
	return -1;
}

/*******************************************************************\

Function: write_to_file

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::write_to_file(int counter, std::vector<procedure_data> new_file, std::vector<std::string> lines)
{
	std::map<std::string, int> current_instance;
	std::vector<std::vector<std::string>> text_file;
	for (std::vector<procedure_data>::iterator it =
	    new_file.begin(); it != new_file.end(); ++it)
	{
		std::vector<std::string> procedure;
		std::vector<std::pair<int, int>> brackets;
		bool in_atomic = false;

		// create procedure definition
		std::cout << "Procedure 1: " << (*it).name << " " << (*it).instance << " " << (*it).commands.size() << std::endl;

		// TODO empty procedure and main
		if ((*it).commands.size() == 0)
		{
			procedure.push_back("void *" + generate_new_name(it->name, it->instance) + "() {" );
			procedure.push_back("}");
			text_file.insert(text_file.begin(), procedure);
			continue;
		}

		int first_line = get_first_line(it->commands);
		int start, finish;
		std::cout << first_line << std::endl;

		for (int i = first_line - 1; i >= 0; --i)
		{
			std::vector<std::string> tokens = parse_string_bmc(lines[i]);
			if(has_token_bmc(it->name, tokens))
			{
				std::string new_proc_definition;
				// only keep "main", change everything else
				if (it->name.compare("main") != 0 &&
						it->name.find("__VERIFIER_atomic_") == std::string::npos)
				{
					new_proc_definition = generate_new_name(it->name, it->instance);

					std::size_t pos = lines[i].find(it->name);
					std::string new_line = lines[i];
					new_line.replace(pos, it->name.size(), new_proc_definition);
					procedure.push_back(new_line);
					std::cout << "Procedure 2: " << (*it).name << std::endl;
				}
				else
				{
					procedure.push_back(lines[i]);
				}

				find_brackets(i, lines, start, finish);
				std::cout << "procedure: " << start << " " << finish << std::endl;
				if (start != -1)
				{
					if (start - 1 != i)
						procedure.push_back("{");

					if (it->name.compare("main") == 0 )
					{
						// insert init for mutex
						procedure.push_back("pthread_mutex_init(&slicing_locker, 0);");
					}
					brackets.push_back(std::make_pair(start, finish));
				}

			}

		}

		int line_number, last_line_in_proc = start;

		std::cout << "Procedure body: " << (*it).name << std::endl;
		// create procedure body
		for (std::vector<command_data>::iterator i = (*it).commands.begin(); i != (*it).commands.end(); ++i)
		{
			line_number = i->line_number;
			//for concurrent program
			if (abs(line_number) == 32760)
			{
				if (line_number == 32760 && !in_atomic)
				{
					procedure.push_back("__VERIFIER_atomic_begin();");
					in_atomic = true;
				}
				else if (line_number == -32760 && in_atomic)
				{
					procedure.push_back("__VERIFIER_atomic_end();");
					in_atomic = false;
				}
				continue;
			}
			else
			{
				last_line_in_proc = line_number;
				std::cout << line_number << std::endl;
				bool call_procedure = false;
				std::string this_line = lines[abs(line_number)];
				if (line_number < 0)
				{
					call_procedure = true;
					line_number = -line_number;

					// change the line
					std::cout << "old procedure call: " << this_line << std::endl;
					std::vector<std::string> call_tokens = parse_string_bmc(this_line);

					if (has_token_bmc("pthread_create", call_tokens))
					{
						if (current_instance.find(call_tokens[3]) == current_instance.end())
														current_instance[call_tokens[3]] = 1;

						for (int kk = 0 ; kk < call_tokens.size(); ++kk)
							std::cout << kk << ": " << call_tokens[kk] << std::endl;
						// create a new thread here
						std::size_t token_pos = this_line.find(call_tokens[3]); // ex: pthread_create(&t1, NULL, thr1, 1);
						this_line.replace(token_pos, call_tokens[3].size(), generate_new_name(call_tokens[3], current_instance[call_tokens[3]]));
						current_instance[call_tokens[3]] = current_instance[call_tokens[3]] + 1; // ex: pthread_create(&t1, NULL, thr1, 1);

						std::cout << "New procedure call: " << current_instance[call_tokens[3]] << ": " << this_line << std::endl;
					}
					else
					{
						if (!has_token_bmc("__VERIFIER_atomic_begin", call_tokens) &&
								!has_token_bmc("__VERIFIER_atomic_end", call_tokens))
						// find the token before "("
						for (int bracket = 0; bracket < call_tokens.size(); ++bracket)
						{
							std::size_t token_pos = this_line.find(call_tokens[bracket]);
							if (this_line[token_pos + call_tokens[bracket].size()] == '(')
							{
								if (current_instance.find(call_tokens[bracket]) == current_instance.end())
									current_instance[call_tokens[bracket]] = 1;
								this_line.replace(token_pos, call_tokens[bracket].size(), generate_new_name(call_tokens[bracket], current_instance[call_tokens[bracket]]));
								current_instance[call_tokens[bracket]] = current_instance[call_tokens[bracket]] + 1;
								break;
							}
						}
					}
				}

				// parse line
				std::vector<std::string> tokens = parse_string_bmc(this_line);

				if (tokens.size() == 1 && tokens[0][0] == '}')
					std::cout << "Special line: " << line_number << std::endl;

				if (has_token_bmc("}", tokens) &&
						brackets.size() > 0)
				{
					brackets.pop_back();
				}

				insert_brackets(line_number, brackets, procedure);

				// if bracket
				if (has_token_bmc("if", tokens))
				{
					if (i->condition.size() > 0)
						procedure.push_back("__CPROVER_assume(" + i->condition + ");");
					procedure.push_back(this_line);

					int start, finish;
					find_brackets(line_number, lines, start, finish);
					std::cout << "If start vs finish" << line_number << ": " << start << " " << finish << std::endl;
					if (start != -1)
					{
						if (start - 1 != line_number)
							procedure.push_back("{");
						brackets.push_back(std::make_pair(start, finish));
					}
				}

				else if (has_token_bmc("while", tokens))
				{
					if (i->condition.size() > 0)
						procedure.push_back("__CPROVER_assume(" + i->condition + ");");

					// TODO replace while by if
					std::size_t while_pos = this_line.find("while");
					std::string new_while = this_line;
					new_while.replace(while_pos, 5, "if");
					procedure.push_back(new_while);

					int start, finish;
					find_brackets(line_number, lines, start, finish);
					std::cout << "While start vs finish" << line_number << " " << start << " " << finish << std::endl;
					if (start != -1)
					{
						if (start  - 1!= line_number)
							procedure.push_back("{");
						brackets.push_back(std::make_pair(start, finish));
					}
				}

				else {
					// do not add break;
					if (!has_token_bmc("break", tokens))
					{
						if (this_line.find("__VERIFIER_atomic_begin") != std::string::npos)
						{
							if (!in_atomic)
								procedure.push_back(this_line);
							in_atomic = true;
						}
						else if (this_line.find("__VERIFIER_atomic_end") != std::string::npos)
						{
							if (in_atomic)
								procedure.push_back(this_line);
							in_atomic = false;
						}
						else
						{
							if (i->nondet_assign == true)
							{
								// right assignment
								procedure.push_back(this_line);
								std::size_t found = this_line.find('=');
								std::string tmp_line = this_line.substr(0, found);
								tmp_line = "__CPROVER_assume(" + tmp_line + " == " + i->condition + ");";
								procedure.push_back(tmp_line);
							}
							else
							{
								if (i->condition.size() > 0 && has_token_bmc("=", tokens))
								{
									std::size_t found = this_line.find('=');
									this_line = this_line.substr(0, found + 1);
									this_line = this_line + i->condition + ';';
									std::cout << "new line: " << this_line << std::endl;
								}
								procedure.push_back(this_line);
							}
						}
					}
				}
			}
		}

		if (in_atomic)
		{
			std::cout << "Insert end atomic: " << last_line_in_proc << " " << line_number << " " << lines[line_number] << std::endl;
			if (32760 != abs(line_number))
				if (lines[line_number].find("__VERIFIER_atomic") == std::string::npos)
				{
					std::cout << "Insert end atomic: " << last_line_in_proc << " " << line_number << std::endl;
					procedure.push_back("__VERIFIER_atomic_end();");
					in_atomic = false;
				}
		}
		if (abs(line_number) != 32760)
			insert_remaining_lines(abs(line_number), finish, lines, procedure, in_atomic);
		else
			insert_remaining_lines(abs(last_line_in_proc), finish, lines, procedure, in_atomic);

//		insert_brackets(32767, brackets, procedure);

		//reorder the last atomic command
		reorder_atomic(procedure);

		text_file.insert(text_file.begin(), procedure);
	}

	for (std::vector<std::vector<std::string>>::iterator it = text_file.begin(); it != text_file.end(); ++it)
	{
		for (std::vector<std::string>::iterator i = (*it).begin(); i != (*it).end(); ++i)
			std::cout << *i << std::endl;
	}

	write_to_file(counter, text_file, lines);
}

/*******************************************************************\

Function: write_to_file_2

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::write_to_file_2(int counter, std::vector<command_data> proc_lines, std::vector<std::string> lines)
{
	std::map<std::string, int> current_instance;
	std::vector<std::vector<std::string>> text_file;
	std::vector<std::string> procedure;
	bool in_atomic = false;

	// create procedure definition
	std::cout << proc_lines.size() << " is size\n";
	int first_line = get_first_line(proc_lines);
	int start, finish;

	for (int i = first_line - 1; i >= 0; --i)
	{
		std::vector<std::string> tokens = parse_string_bmc(lines[i]);
		if (has_token_bmc("main", tokens))
		{
			procedure.push_back(lines[i]);

			find_brackets(i, lines, start, finish);
			std::cout << "procedure: " << start << " " << finish << std::endl;
			if (start != -1)
			{
				if (start - 1 != i)
					procedure.push_back("{");
			}
		}
	}

	int line_number;

	// create procedure body
	for (std::vector<command_data>::iterator i = proc_lines.begin();
	    i != proc_lines.end(); ++i)
	{
		line_number = i->line_number;
		//for concurrent program

		std::cout << line_number << std::endl;
		bool call_procedure = false;
		std::string this_line = lines[abs(line_number)];

		// parse line
		std::vector<std::string> tokens = parse_string_bmc(this_line);

		if (tokens.size() == 1 && tokens[0][0] == '}')
			std::cout << "Special line: " << line_number << std::endl;

		// if bracket
		if (has_token_bmc("if", tokens))
		{
			if (i->condition.size() > 0)
				procedure.push_back("__CPROVER_assume(" + i->condition + ");");
			else
			{
				// write everything
				int start = -1, finish = -1;
				find_brackets(abs(line_number), lines, start, finish);
				for (int t = abs(line_number); t <= finish; ++t)
					procedure.push_back(lines[t]);
			}
		}

		else if (has_token_bmc("while", tokens))
		{
			if (i->condition.size() > 0)
				procedure.push_back("__CPROVER_assume(" + i->condition + ");");
			else
			{
				// write everything
				int start = -1, finish = -1;
				find_brackets(abs(line_number), lines, start, finish);
				for (int t = abs(line_number); t <= finish; ++t)
					procedure.push_back(lines[t]);
			}
		}

		else if (has_token_bmc("return", tokens) ||
				has_token_bmc("pthread_create", tokens) ||
				has_token_bmc("pthread_join", tokens))
		{
			continue;
		}

		else
		{
			// do not add break;
			if (!has_token_bmc("break", tokens) && !has_token_bmc("}", tokens))
			{
				if (this_line.find("__VERIFIER_atomic_begin") != std::string::npos
				    || this_line.find("__VERIFIER_atomic_end") != std::string::npos)
					continue;
				else
				{
					procedure.push_back(this_line);
//					if (i->nondet_assign == true)
//					{
//						// right assignment
//						procedure.push_back(this_line);
//						std::size_t found = this_line.find('=');
//						std::string tmp_line = this_line.substr(0, found);
//						tmp_line = "__CPROVER_assume(" + tmp_line + " == " + i->condition + ");";
//						procedure.push_back(tmp_line);
//						std::cout << "assume line: " << tmp_line << " " << i->line_number << std::endl;
//					} else
//					{
//						if (i->condition.size() > 0 && has_token_bmc("=", tokens))
//						{
//							std::size_t found = this_line.find('=');
//							this_line = this_line.substr(0, found + 1);
//							this_line = this_line + i->condition + ';';
//							std::cout << "new line: " << this_line << std::endl;
//						}
//						procedure.push_back(this_line);
//					}
				}
			}
		}
	}
	procedure.push_back("}");

	text_file.insert(text_file.begin(), procedure);

	for (std::vector<std::vector<std::string>>::iterator it = text_file.begin(); it != text_file.end(); ++it)
	{
		for (std::vector<std::string>::iterator i = (*it).begin(); i != (*it).end(); ++i)
			std::cout << *i << std::endl;
	}

	write_to_file(counter, text_file, lines);
}


/*******************************************************************\

Function: find_procedure_index

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

int bmct::find_procedure_index(std::string name, int instance, const std::vector<procedure_data> new_file)
{
	for (int k = 0; k < new_file.size(); ++k)
		if (new_file[k].name.compare(name) == 0)
		{
			if (name.compare("main") == 0 ||
					name.find("__VERIFIER_atomic_") != std::string::npos ||
					new_file[k].instance == instance)
			{
				return k;
			}
		}
	return -1;
}

/*******************************************************************\

Function: get_proc_name

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::string bmct::get_proc_name(std::string code)
{
	std::string new_proc_name;
	std::vector<std::string> call_tokens = parse_string_bmc(code);
	if (!has_token_bmc("pthread_create", call_tokens))
	{
		// find the token before "("
		for (int bracket = 0; bracket < call_tokens.size(); ++bracket)
		{
			std::size_t token_pos = code.find(call_tokens[bracket]);
			if (code[token_pos + call_tokens[bracket].size()] == '(')
			{
				new_proc_name = call_tokens[bracket];
				break;
			}
		}
	} else
	{
		// ex: pthread_create(&t2, (const struct _opaque_pthread_attr_t *)(void *)0, (void * (*)(void *))thr2, (void *)2);
		// ex: pthread_create(&t1, ((const struct _opaque_pthread_attr_t *)NULL), (void * (*)(void *))thr1, NULL);
		for (int thread_pos = code.size() - 1; thread_pos >= 0; thread_pos--)
		{
			new_proc_name = "";
			if (code[thread_pos] == ',')
			{
				thread_pos--;
				while (code[thread_pos] != ')' &&
							 code[thread_pos] != ' ' &&
							 code[thread_pos] != ',')
					new_proc_name = code[thread_pos--] + new_proc_name;
				break;
			}
		}
		std::cout << "new thread " << new_proc_name << std::endl;
	}
	return new_proc_name;
}

/*******************************************************************\

Function: bmct::get_condition_expr

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::string bmct::get_condition_expr(const std::vector<std::string> lines,
		int line,
		const std::list<goto_trace_stept>::iterator it,
		const int line2)
{
	std::string expr_condition;
	std::string expr_value;
	std::string expr_final = "";

	if (it->is_location())
	{

		std::string line_string = lines.at(abs(line));
		std::vector<std::string> tokens = parse_string_bmc(line_string);

		if ((has_token_bmc("if", tokens)) &&
						line_string.find("nondet") == std::string::npos)
		{
			line = abs(line);
			std::cout << "Next line: " << line << " " << line2 << std::endl;
			for (int i = 0; i < line_string.size(); ++i)
			{
				if (line_string[i] == '(')
				{
					for (int j = i + 1; j < line_string.size() && line_string[j] != ')';
					    ++j)
						expr_condition = expr_condition + line_string[j];
				}
			}

			int start_bracket = -1, finish_bracket = -1;
			find_brackets(line, lines, start_bracket, finish_bracket);

			std::cout << "start vs finish: " << start_bracket - 1 << " "
			    << finish_bracket - 1 << std::endl;
			if (start_bracket == -1
			    || (start_bracket < line2 && finish_bracket > line2)
			    || (start_bracket > line2 && line2 > 0))
				expr_final = "(" + expr_condition + ") == " + "1";
			else
				expr_final = "(" + expr_condition + ") == " + "0";
			std::cout << "Expr final: " << expr_final << std::endl;
			return expr_final;
		}

		else if ((
				has_token_bmc("while", tokens)) &&
				line_string.find("nondet") == std::string::npos)
		{
			for (int i = 0; i < line_string.size(); ++i)
			{
				if (line_string[i] == '(')
				{
					for (int j = i + 1; j < line_string.size() && line_string[j] != ')'; ++j)
						expr_condition = expr_condition + line_string[j];
				}
			}

			if (line < 0)
			{
				//come from top
				std::cout << "Next line: " << line << " " << line2 << std::endl;

				expr_final = "(" + expr_condition + ") == " + "1";
				return expr_final;
			}

			line = abs(line);
			std::cout << "Next line: " << line << " " << line2 << std::endl;

			int start_bracket = -1, finish_bracket = -1;
			find_brackets(line, lines, start_bracket, finish_bracket);

			std::cout << "start vs finish: " << start_bracket - 1 << " "
			    << finish_bracket - 1 << std::endl;
			if (start_bracket == -1
			    || (start_bracket < line2 && finish_bracket > line2)
			    || (start_bracket > line2 && line2 > 0))
				expr_final = "(" + expr_condition + ") == " + "1";
			else
				expr_final = "(" + expr_condition + ") == " + "0";
			std::cout << "Expr final: " << expr_final << std::endl;
			return expr_final;
		}

	}
	return expr_final;
}
/*******************************************************************\

Function: bmct::run

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool bmct::run(const goto_functionst &goto_functions,
		std::vector<variable_struct> variables,
		std::vector<int> lines_map,
		std::vector<std::string> lines,
		std::vector<std::vector<int>> CFG,
		const std::vector<int> slicing_lines)
{
	int counter = 0;
	// convert slicing line to array
	bool checked[10000];
	memset (checked, false, sizeof checked);
	for (std::vector<int>::const_iterator it = slicing_lines.begin(); it != slicing_lines.end(); ++it)
		if ((*it) > 0)
			checked[*it] = true;

  const std::string mm=options.get_option("mm");
  std::unique_ptr<memory_model_baset> memory_model;
  
  if(mm.empty() || mm=="sc")
    memory_model=std::unique_ptr<memory_model_baset>(new memory_model_sct(ns));
  else if(mm=="tso")
    memory_model=std::unique_ptr<memory_model_baset>(new memory_model_tsot(ns));
  else if(mm=="pso")
    memory_model=std::unique_ptr<memory_model_baset>(new memory_model_psot(ns));
  else
  {
    error() << "Invalid memory model " << mm
            << " -- use one of sc, tso, pso" << eom;
    return true;
  }

  symex.set_message_handler(get_message_handler());
  symex.options=options;

  status() << "Starting Bounded Model Checking" << eom;

  symex.last_source_location.make_nil();

  try
  {
    // get unwinding info
    setup_unwind();


    // perform symbolic execution
    symex(goto_functions);

    // add a partial ordering, if required    
    if(equation.has_threads())
    {
      memory_model->set_message_handler(get_message_handler());
      (*memory_model)(equation);
    }
  }

  catch(const std::string &error_str)
  {
    message_streamt message_stream(get_message_handler());
    message_stream.err_location(symex.last_source_location);
    message_stream.error(error_str);
    return true;
  }

  catch(const char *error_str)
  {
    message_streamt message_stream(get_message_handler());
    message_stream.err_location(symex.last_source_location);
    message_stream.error(error_str);
    return true;
  }

  catch(std::bad_alloc)
  {
    error() << "Out of memory" << eom;
    return true;
  }

  statistics() << "size of program expression: "
               << equation.SSA_steps.size()
               << " steps" << eom;

  try
  {
    if(options.get_option("slice-by-trace")!="")
    {
      symex_slice_by_tracet symex_slice_by_trace(ns);

      symex_slice_by_trace.slice_by_trace
	(options.get_option("slice-by-trace"), equation);
    }

    if(equation.has_threads())
    {
      // we should build a thread-aware SSA slicer
      statistics() << "no slicing due to threads" << eom;
    }
    else
    {
      if(options.get_bool_option("slice-formula"))
      {
        slice(equation);
        statistics() << "slicing removed "
                     << equation.count_ignored_SSA_steps()
                     << " assignments" << eom;
      }
      else
      {
        simple_slice(equation);
        statistics() << "simple slicing removed "
                     << equation.count_ignored_SSA_steps()
                     << " assignments" << eom;
      }
    }

    {
      statistics() << "Generated " << symex.total_vccs
                   << " VCC(s), " << symex.remaining_vccs
                   << " remaining after simplification" << eom;
    }

    //show_program();

    if(options.get_bool_option("show-vcc"))
    {
      show_vcc();
      return false;
    }
    
    if(options.get_bool_option("cover-assertions"))
    {
      satcheckt satcheck;
      satcheck.set_message_handler(get_message_handler());
      bv_cbmct bv_cbmc(ns, satcheck);
      bv_cbmc.set_message_handler(get_message_handler());

      if(options.get_option("arrays-uf")=="never")
        bv_cbmc.unbounded_array=bv_cbmct::U_NONE;
      else if(options.get_option("arrays-uf")=="always")
        bv_cbmc.unbounded_array=bv_cbmct::U_ALL;
    
      cover_assertions(goto_functions, bv_cbmc);
      return false;
    }

    std::cout << "what is here " << symex.total_vccs << " " << symex.remaining_vccs << std::endl;

    // any properties to check at all?
    if(!options.get_bool_option("program-only") &&
       symex.remaining_vccs==0)
    {
    	std::cout << "what is here\n";
      report_success();
      return false;
    }

    if(options.get_bool_option("smt1"))
      return decide_smt1(goto_functions);
    else if(options.get_bool_option("smt2"))
      return decide_smt2(goto_functions);
    else if(options.get_bool_option("dimacs"))
      return write_dimacs();
    else if(options.get_bool_option("refine"))
      return decide_bv_refinement(goto_functions);
    else if(options.get_bool_option("aig"))
      return decide_aig(goto_functions);
    else
    {
      if(options.get_bool_option("program-only"))
      {
        show_program();
        return false;
      }

      // get the location of procedure


      while (true)
      {
				unsigned count = 1;

				languagest languages(ns, new_ansi_c_language());

				for (symex_target_equationt::SSA_stepst::iterator it =
						equation.SSA_steps.begin(); it != equation.SSA_steps.end();)
				{
					bool removed = false;
					if (it->is_assert())
					{

						std::string string_value;
						languages.from_expr(it->cond_expr, string_value);
//						it = equation.SSA_steps.erase(it);
//						continue;
						for (int expr = 0; expr < error_conditions.size(); ++expr)
							if (string_value.compare(error_conditions[expr]) == 0 ||
								false)
							{
								// remove to refine
								//it->ignore = true;
								std::cout << "We already have removed " << string_value << std::endl;
								it = equation.SSA_steps.erase(it);
								removed = true;
								break;
							}
					}
					if (removed == false)
						it++;

				}

				std::cout << "before testing\n";
      	int size_error = error_conditions.size();
				bool run_result = decide_default(goto_functions, variables, lines_map, lines, CFG, slicing_lines);
				return run_result;


				if (run_result == true)
				{
					if (size_error == error_conditions.size())
					{
						std::cout << "after testing\n";
						return false;
					}
					else
					{
						std::cout << "Size is: " << error_conditions.size() << std::endl;
						for (int error = 0; error < error_conditions.size(); ++ error)
							std::cout << "Error is: " << error_conditions[error] << std::endl;
					}
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

					int remain_begin_atomic[1000]; memset(remain_begin_atomic, 0, sizeof remain_begin_atomic);

					// get start from thread 0
					for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin(); it != goto_trace.steps.end();)
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
					for (std::list<goto_trace_stept>::iterator it = goto_trace.steps.begin(); it != goto_trace.steps.end(); ++it)
					{
						if (it->hidden || it->pc->source_location.is_nil())
							continue;

						unsigned int line1 = std::stoi(as_string((*it).pc->source_location.get_line()), nullptr);
						line1 = lines_map[line1];
						std::string proc = as_string((*it).pc->source_location.get_function());

						if (proc.size() == 0)
							continue;

						if (proc.compare("__actual_thread_spawn") == 0 ||
								proc.compare("pthread_create") == 0)
							continue;

						std::cout << line1 << " -in- " << proc << std::endl;

						// get the current name of proc
						std::string current_instance_proc;
						if (proc.compare("main") == 0)
							current_instance_proc = proc;
						else
							current_instance_proc = proc + "_call_" + std::to_string(current_instance[proc]);

						if (prev_line.find(current_instance_proc) == prev_line.end())
						{
							std::cout << current_instance_proc << " Error in if (prev_line.find(current_instance_proc) == prev_line.end())\n";
						}

						if (prev_line[current_instance_proc] == line1)
							// same line
							continue;

						lines_tmp = find_lines(prev_line[current_instance_proc], line1, CFG, checked);

						if (lines_tmp.size() == 0)
						// reach the end of procedure, start again
						{
							std::cout << prev_line[current_instance_proc] << " vssssss " << line1 << " Error in if (lines_tmp.size() == 0)\n";
							continue;
						}

						// find index proc
						int index = find_procedure_index(proc, current_instance[proc], new_file);

						std::vector<command_data> proc_lines;

						// procedure is defined
						assert(index != -1);

						proc_lines = new_file[index].commands;

						// for concurrent program
						if (pre_thread != it->thread_nr)
						{
							// add atomic begin
							if (proc.find("atomic") == std::string::npos)
							{
								if (proc.compare("main") != 0)
									proc_lines.push_back(command_data(32760));
							}
							else
								remain_begin_atomic[it->thread_nr] = 1;

							// add atomic end for prev thread
							int prev_index = find_procedure_index(pre_thread_name, prev_instance, new_file);

							if (prev_index != -1 && pre_thread_name.compare("main") != 0)
							{
								std::vector<command_data> prev_lines = new_file.at(prev_index).commands;

								// find position to add "end atomic"
								// --> if not call, add at the end; otherwise add before the call
								std::string last_line = lines.at(abs(prev_lines.at(prev_lines.size() - 1).line_number));
								std::cout << "Last line: " << last_line  << std::endl;
								if (!is_procedure_call(last_line))
								{
									prev_lines.push_back(command_data(-32760));
								}
								else
								{
									command_data temp = prev_lines.at(prev_lines.size() - 1);
									prev_lines.pop_back();
									prev_lines.push_back(command_data(-32760));
									prev_lines.push_back(temp);
									std::cout << "Change atomic order because of call\n";
								}


								procedure_data tmp_proc(pre_thread_name, prev_instance, prev_lines);
								new_file.at(prev_index) = tmp_proc;
								std::cout << "End atomic: " << pre_thread_name << " " << prev_instance << std::endl;
							}

							pre_thread_name = proc;
							pre_thread = it->thread_nr;
							prev_instance = current_instance[proc];
							std::cout << "Pre thread: " << pre_thread_name << " " << prev_instance << std::endl;
						}

						else if (pre_thread_name.compare(proc) != 0)
						{
							if (remain_begin_atomic[it->thread_nr] == 1 &&
									proc.find("atomic") == std::string::npos)
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

								std::cout << std::stoi(as_string((*itx).pc->source_location.get_line()), nullptr) << std::endl;
								if (as_string((*itx).pc->source_location.get_function()).compare(proc) == 0 &&
										lines_map[std::stoi(as_string((*itx).pc->source_location.get_line()), nullptr)] != line1)
								{
									line2 = std::stoi(as_string((*itx).pc->source_location.get_line()), nullptr);
									break;
								}
								else
									itx = std::next(itx);
							}

						}
						if (line2 > 0 )
							line2 = lines_map[line2];

						std::string expr_condition;
						if (prev_line[current_instance_proc] > line1)
							expr_condition = get_condition_expr(lines, (line1 - 1), it, line2);
						else
							expr_condition = get_condition_expr(lines, -(line1 - 1), it, line2);
						proc_lines.push_back(command_data(lines_tmp[lines_tmp.size() - 1] - 1, expr_condition));

						prev_line[current_instance_proc] = line1;
						if (it->pc->is_function_call())
						{
							// reverse call function
							proc_lines.at(proc_lines.size() - 1) = command_data(-proc_lines.at(proc_lines.size() - 1).line_number, proc_lines.at(proc_lines.size() - 1).condition);

							std::string code = from_expr(ns, (*it).pc->source_location.get_function(), (*it).pc->code);
							std::cout << code << std::endl;

							std::string new_proc_name = get_proc_name(code);

							std::cout << "New proc name: " << new_proc_name << std::endl;

							// create new instance of procedure
							std::map<std::string,int>::iterator it_proc = current_instance.find(new_proc_name);
							std::vector<command_data> line_proc;
							if (it_proc != current_instance.end())
							{
								int t_proc = current_instance[new_proc_name];
								current_instance[new_proc_name] = t_proc + 1;
								procedure_data tmp_proc(new_proc_name, t_proc + 1);
								new_file.push_back(tmp_proc);
								prev_line[generate_new_name(new_proc_name, t_proc + 1)] = 0;
							}
							else
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
							new_file.at(index) = procedure_data(proc, current_instance[proc], proc_lines);
						}
					}

					// add the last slicing_unlock
					for (int itt = 0; itt != new_file.size(); itt++)
					{
						int counterx = 0;
						std::vector<command_data> tmp = new_file[itt].commands;
						for (std::vector<command_data>::iterator itx = tmp.begin(); itx != tmp.end(); ++itx)
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
					return run_result;
				}
				else
					break;
				//return run_result;
      }

      return decide_default(goto_functions, variables, lines_map, lines, CFG, slicing_lines);
    }
  }

  catch(std::string &error_str)
  {
    error() << error_str << eom;
    return true;
  }

  catch(const char *error_str)
  {
    error() << error_str << eom;
    return true;
  }

  catch(std::bad_alloc)
  {
    error() << "Out of memory" << eom;
    return true;
  }
}

/*******************************************************************\

Function: bmct::decide

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool bmct::decide(
  const goto_functionst &goto_functions,
  prop_convt &prop_conv,
  		std::vector<variable_struct> variables,
  		std::vector<int> lines_map,
  		std::vector<std::string> lines,
  		std::vector<std::vector<int>> CFG,
  		const std::vector<int> slicing_lines)
{
  prop_conv.set_message_handler(get_message_handler());
  
  if(options.get_bool_option("all-properties"))
    return all_properties(goto_functions, prop_conv, variables, lines_map, lines, CFG, slicing_lines);

  bool result=true;

  switch(run_decision_procedure(prop_conv))
  {
  case decision_proceduret::D_UNSATISFIABLE:
    result=false;
    report_success();
    break;

  case decision_proceduret::D_SATISFIABLE:
    error_trace(prop_conv);
    report_failure();
    break;

  default:
    error() << "decision procedure failed" << eom;
  }

  return result;
}

bool bmct::decide(
  const goto_functionst &goto_functions,
  prop_convt &prop_conv)
{
  prop_conv.set_message_handler(get_message_handler());

  if(options.get_bool_option("all-properties"))
    return all_properties(goto_functions, prop_conv);

  bool result=true;

  switch(run_decision_procedure(prop_conv))
  {
  case decision_proceduret::D_UNSATISFIABLE:
    result=false;
    report_success();
    break;

  case decision_proceduret::D_SATISFIABLE:
    error_trace(prop_conv);
    report_failure();
    break;

  default:
    error() << "decision procedure failed" << eom;
  }

  return result;
}

/*******************************************************************\

Function: bmct::setup_unwind

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void bmct::setup_unwind()
{
  const std::string &set=options.get_option("unwindset");
  std::string::size_type length=set.length();

  for(std::string::size_type idx=0; idx<length; idx++)
  {
    std::string::size_type next=set.find(",", idx);
    std::string val=set.substr(idx, next-idx);
    unsigned thread_nr;
    bool thread_nr_set=false;

    if(!val.empty() &&
       isdigit(val[0]) &&
       val.find(":")!=std::string::npos)
    {
      std::string nr=val.substr(0, val.find(":"));
      thread_nr=unsafe_string2unsigned(nr);
      thread_nr_set=true;
      val.erase(0, nr.size()+1);
    }

    if(val.rfind(":")!=std::string::npos)
    {
      std::string id=val.substr(0, val.rfind(":"));
      long uw=unsafe_string2int(val.substr(val.rfind(":")+1));

      if(thread_nr_set)
        symex.set_unwind_thread_loop_limit(thread_nr, id, uw);
      else
        symex.set_unwind_loop_limit(id, uw);
    }
    
    if(next==std::string::npos) break;
    idx=next;
  }

  if(options.get_option("unwind")!="")
    symex.set_unwind_limit(options.get_unsigned_int_option("unwind"));

}
