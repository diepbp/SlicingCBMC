/*******************************************************************\

Module: Traces of GOTO Programs

Author: Daniel Kroening

  Date: July 2005

\*******************************************************************/
#include <cassert>
#include <iostream>
#include <algorithm>
#include <util/threeval.h>
#include <util/simplify_expr.h>
#include <util/arith_tools.h>




#include <langapi/mode.h>
#include <langapi/languages.h>
#include <langapi/language_util.h>

#include <ansi-c/ansi_c_language.h>






#include <solvers/prop/prop_conv.h>
#include <solvers/prop/prop.h>

#include "partial_order_concurrency.h"

#include "build_goto_trace.h"

/*******************************************************************\

Function: build_full_lhs_rec

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

exprt build_full_lhs_rec(
  const prop_convt &prop_conv,
  const namespacet &ns,
  const exprt &src_original, // original identifiers
  const exprt &src_ssa)      // renamed identifiers
{
  if(src_ssa.id()!=src_original.id())
    return src_original;
    
  const irep_idt id=src_original.id();

  if(id==ID_index)
  {
    // get index value from src_ssa
    exprt index_value=prop_conv.get(to_index_expr(src_ssa).index());
    
    if(index_value.is_not_nil())
    {
      simplify(index_value, ns);
      index_exprt tmp=to_index_expr(src_original);
      tmp.index()=index_value;
      tmp.array()=
        build_full_lhs_rec(prop_conv, ns, 
          to_index_expr(src_original).array(),
          to_index_expr(src_ssa).array());
      return tmp;
    }

    return src_original;
  }
  else if(id==ID_member)
  {
    member_exprt tmp=to_member_expr(src_original);
    tmp.struct_op()=build_full_lhs_rec(
      prop_conv, ns,
      to_member_expr(src_original).struct_op(),
      to_member_expr(src_ssa).struct_op());
  }
  else if(id==ID_if)
  {
    if_exprt tmp2=to_if_expr(src_original);
    
    tmp2.false_case()=build_full_lhs_rec(prop_conv, ns, 
      tmp2.false_case(), to_if_expr(src_ssa).false_case());

    tmp2.true_case()=build_full_lhs_rec(prop_conv, ns,
      tmp2.true_case(), to_if_expr(src_ssa).true_case());

    exprt tmp=prop_conv.get(to_if_expr(src_ssa).cond());

    if(tmp.is_true())
      return tmp2.true_case();
    else if(tmp.is_false())
      return tmp2.false_case();
    else
      return tmp2;
  }
  else if(id==ID_typecast)
  {
    typecast_exprt tmp=to_typecast_expr(src_original);
    tmp.op()=build_full_lhs_rec(prop_conv, ns,
      to_typecast_expr(src_original).op(), to_typecast_expr(src_ssa).op());
    return tmp;
  }
  else if(id==ID_byte_extract_little_endian ||
          id==ID_byte_extract_big_endian)
  {
    exprt tmp=src_original;
    assert(tmp.operands().size()==2);
    tmp.op0()=build_full_lhs_rec(prop_conv, ns, tmp.op0(), src_ssa.op0());

    // re-write into big case-split
    
  }
  
  return src_original;
}

/*******************************************************************\

Function: adjust_lhs_object

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

exprt adjust_lhs_object(
  const prop_convt &prop_conv,
  const namespacet &ns,
  const exprt &src)
{
  return nil_exprt();
}

/*******************************************************************\

Function: build_goto_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void get_exprt(std::vector<exprt> v, std::vector<exprt> &exprs, const namespacet &ns)
{
	languagest languages(ns, new_ansi_c_language());
	for (std::vector<exprt>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		std::string s;
		languages.from_expr(*it, s);
		if (s.find("__CPROVER") == std::string::npos &&
				s.find("va_arg") == std::string::npos)
		{
			exprs.push_back(*it);
		}
	}
}

void add_element(exprt cond_expr, std::string expr_str, std::vector<std::pair<std::string, exprt>> &choices)
{
	for (std::vector<std::pair<std::string, exprt>>::iterator it = choices.begin(); it != choices.end(); ++it)
	{
		if (it->first.compare(expr_str) == 0)
			return;
	}
	choices.push_back(std::make_pair(expr_str, cond_expr));
}
/*******************************************************************\

Function: build_goto_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void build_goto_trace_new_2(
  symex_target_equationt &target,
  symex_target_equationt::SSA_stepst::const_iterator end_step,
  const prop_convt &prop_conv,
  const namespacet &ns,
  goto_tracet &goto_trace,
  exprt &new_guard,
  exprt &old_guard,
  std::vector<symex_target_equationt::SSA_stept> &trace_guards)
{
  // We need to re-sort the steps according to their clock.
  // Furthermore, read-events need to occur before write
  // events with the same clock.

  typedef std::map<mp_integer, goto_tracet::stepst> time_mapt;
  time_mapt time_map;

  mp_integer current_time=0;
  unsigned icount=1;

  languagest languages(ns, new_ansi_c_language());

  std::map<std::string, int> guard_map;
  std::map<mp_integer, std::vector<exprt>> time_to_expr;
  std::vector<exprt> guard_list;
  std::vector<exprt> another_guard_list;
  exprt last_operand = false_exprt();
  exprt current_time_expr;
  std::vector<std::pair<std::string, exprt>> choices;


  for(symex_target_equationt::SSA_stepst::const_iterator
      it=target.SSA_steps.begin();
      it!=end_step;
      it++)
  {
    const symex_target_equationt::SSA_stept &SSA_step=*it;

    std::string string_value;
		languages.from_expr(it->cond_expr, string_value);
    if(prop_conv.l_get(SSA_step.guard_literal)!=tvt(true))
    {
      continue;
    }

		if (it->is_assert())
		{
			std::cout << "(" << icount << ") ASSERT(" << string_value << ") " << "\n";
			if(!it->guard.is_true())
			{
				old_guard = it->guard;
			}
			else
			{
				old_guard = true_exprt();
			}
		}
		else
		{
			if (it->cond_expr.is_not_nil())
			{
//				std::cout << "{-" << icount << "} " << string_value << "\n";
				if (!it->guard.is_true())
				{
					std::string string_value1;
					languages.from_expr(it->guard, string_value1);
					if (guard_map.find(string_value1) == guard_map.end()
					    && string_value1.find("__CPROVER_threads") == std::string::npos)
					{
						guard_map[string_value1] = 1;
						guard_list.push_back(it->guard);
					}
//					std::cout << "guard: " << string_value1 << "\n";
				}

				// collect all choice_rf
				if (it->cond_expr.operands().size() > 1 &&
						string_value.find("__CPROVER_") == std::string::npos &&
						string_value.find("=") != std::string::npos)
				{
					// get the last one
					exprt last_one = it->cond_expr.operands().at(it->cond_expr.operands().size() - 1);
					std::string last_one_str;
					languages.from_expr(last_one, last_one_str);
//					std::cout << "\t" << last_one_str << " " << last_one.operands().size() << "\n";

					if (last_one_str.find("choice_rf") != std::string::npos)
					{
						if (last_one_str[0] == '!')
						{
							last_one = not_exprt(last_one);
							last_one = simplify_expr(last_one, ns);
							languages.from_expr(last_one, last_one_str);
						}
						add_element(last_one, last_one_str, choices);
					}

//					std::string ss;
//					languages.from_expr(it->ssa_full_lhs, ss);
//					std::cout << "\t ssa_full_lhs " << ss;
//					languages.from_expr(it->original_full_lhs, ss);
//					std::cout << "\t original_full_lhs " << ss;
//					languages.from_expr(it->ssa_lhs, ss);
//					std::cout << "\t ssa_lhs " << ss;
//					languages.from_expr(it->original_lhs_object, ss);
//					std::cout << "\t original_lhs_object " << ss;
//					languages.from_expr(it->ssa_rhs, ss);
//					std::cout << "\t ssa_rhs " << ss << "\n";

				}
			}
		}
		icount++;

    if(it->is_constraint() ||
       it->is_spawn())
      continue;
    else if(it->is_atomic_begin())
    {
      // for atomic sections the timing can only be determined once we see
      // a shared read or write (if there is none, the time will be
      // reverted to the time before entering the atomic section); we thus
      // use a temporary negative time slot to gather all events
      current_time*=-1;
      continue;
    }
    else if(it->is_shared_read() || it->is_shared_write() ||
            it->is_atomic_end())
    {
      mp_integer time_before=current_time;

      if(it->is_shared_read() || it->is_shared_write())
      {
        // these are just used to get the time stamp
        exprt clock_value=prop_conv.get(
          symbol_exprt(partial_order_concurrencyt::rw_clock_id(it)));

        std::string tmp;
        languages.from_expr(clock_value, tmp);

        to_integer(clock_value, current_time);

        // add to map
				current_time_expr = symbol_exprt(partial_order_concurrencyt::rw_clock_id(it), bitvector_typet(ID_unsignedbv, 6));
				time_to_expr[current_time].push_back(current_time_expr);
      }
      else if(it->is_atomic_end() && current_time<0)
        current_time*=-1;

      assert(current_time>=0);
      // move any steps gathered in an atomic section

      if(time_before<0)
      {
        time_mapt::iterator entry=
          time_map.insert(std::make_pair(
              current_time,
              goto_tracet::stepst())).first;
        entry->second.splice(entry->second.end(), time_map[time_before]);
        time_map.erase(time_before);
      }

      continue;
    }

    // drop PHI and GUARD assignments altogether
    if(it->is_assignment() &&
       (SSA_step.assignment_type==symex_target_equationt::PHI ||
        SSA_step.assignment_type==symex_target_equationt::GUARD))
    {
//    	std::string expr_s; languages.from_expr(it->cond_expr, expr_s);
//    	std::cout << "PHI and GUARD: " << it->source.pc->source_location << " " << expr_s << std::endl;
    	if (SSA_step.assignment_type==symex_target_equationt::GUARD)
    		trace_guards.push_back(*it);
      continue;
    }

    goto_tracet::stepst &steps=time_map[current_time];
    steps.push_back(goto_trace_stept());
    goto_trace_stept &goto_trace_step=steps.back();

//    std::string expr_s; languages.from_expr(SSA_step.cond_expr, expr_s);
//    if (expr_s.find("return_value_nondet") != std::string::npos &&
//    		expr_s.find("nondet_symbol") != std::string::npos)
//    	trace_guards.push_back(SSA_step);

    goto_trace_step.time_expr = current_time_expr;
    goto_trace_step.thread_nr=SSA_step.source.thread_nr;
    goto_trace_step.pc=SSA_step.source.pc;
    goto_trace_step.comment=SSA_step.comment;
    goto_trace_step.lhs_object=SSA_step.original_lhs_object;
    goto_trace_step.type=SSA_step.type;
    goto_trace_step.hidden=SSA_step.hidden;
    goto_trace_step.format_string=SSA_step.format_string;
    goto_trace_step.io_id=SSA_step.io_id;
    goto_trace_step.formatted=SSA_step.formatted;
    goto_trace_step.identifier=SSA_step.identifier;

    goto_trace_step.assignment_type=
      (SSA_step.assignment_type==symex_targett::VISIBLE_ACTUAL_PARAMETER ||
       SSA_step.assignment_type==symex_targett::HIDDEN_ACTUAL_PARAMETER)?
      goto_trace_stept::ACTUAL_PARAMETER:
      goto_trace_stept::STATE;

    if(SSA_step.original_full_lhs.is_not_nil())
      goto_trace_step.full_lhs=
        build_full_lhs_rec(
          prop_conv, ns, SSA_step.original_full_lhs, SSA_step.ssa_full_lhs);

    if(SSA_step.ssa_lhs.is_not_nil())
      goto_trace_step.lhs_object_value=prop_conv.get(SSA_step.ssa_lhs);

    if(SSA_step.ssa_full_lhs.is_not_nil())
    {
    	goto_trace_step.ssa_full_lhs = SSA_step.ssa_full_lhs;
      goto_trace_step.full_lhs_value=prop_conv.get(SSA_step.ssa_full_lhs);
      simplify(goto_trace_step.full_lhs_value, ns);
    }

    if(SSA_step.ssa_rhs.is_not_nil())
		{
			goto_trace_step.ssa_rhs = SSA_step.ssa_rhs;
		}

    for(std::list<exprt>::const_iterator
        j=SSA_step.converted_io_args.begin();
        j!=SSA_step.converted_io_args.end();
        j++)
    {
      const exprt &arg=*j;
      if(arg.is_constant() ||
         arg.id()==ID_string_constant)
        goto_trace_step.io_args.push_back(arg);
      else
      {
        exprt tmp=prop_conv.get(arg);
        goto_trace_step.io_args.push_back(tmp);
      }
    }

    if(SSA_step.is_assert() ||
       SSA_step.is_assume())
    {
      goto_trace_step.cond_expr=SSA_step.cond_expr;

      goto_trace_step.cond_value=
        prop_conv.l_get(SSA_step.cond_literal).is_true();
    }
    else if(SSA_step.is_location() &&
            SSA_step.source.pc->is_goto())
    {
      goto_trace_step.cond_expr=SSA_step.source.pc->guard;

      const bool backwards=SSA_step.source.pc->is_backwards_goto();

      symex_target_equationt::SSA_stepst::const_iterator next=it;
      ++next;
      assert(next!=target.SSA_steps.end());

      // goto was taken if backwards and next is enabled or forward
      // and next is not active;
      // there is an ambiguity here if a forward goto is to the next
      // instruction, which we simply ignore for now
      goto_trace_step.goto_taken=
        backwards==
        (prop_conv.l_get(next->guard_literal)==tvt(true));
    }
  }

  std::cout << "counting total switches\n";
  int total_switches = 0;
  // test choices
  for (std::vector<std::pair<std::string, exprt>>::iterator it = choices.begin(); it != choices.end(); ++it)
  {
  	int value = prop_conv.get(it->second).is_true() ? 1 : 0;
  	total_switches += value;
  }

  std::cout << "total switches: " << total_switches << std::endl;

  std::vector<std::pair<exprt, exprt>> interleavings;
  goto_trace_stept prev_step;
  prev_step.thread_nr = -1;

  // Now assemble into a single goto_trace.
  // This expoits sorted-ness of the map.

  for(time_mapt::iterator t_it=time_map.begin();
      t_it!=time_map.end(); t_it++)
  {
  	std::cout << t_it->first << " at \n";

  	int expr_pos = 0;
  	for (goto_tracet::stepst::iterator it = t_it->second.begin(); it != t_it->second.end(); ++it)
  	{
//  		std::cout << "\t" << it->pc->source_location.get_line() << std::endl;
  		if (as_string(it->pc->source_location.get_file()).find("<built") == std::string::npos)
  		{
  			std::string function = as_string(it->pc->source_location.get_function());
  			std::string expr_s; languages.from_expr(it->time_expr, expr_s);
//  			std::cout << "\t\t" << expr_s;

//  			std::string step_l;

//				if (it->full_lhs_value.is_not_nil())
//				{
//					languages.from_expr(it->ssa_full_lhs, step_l);
//					std::cout << "\t ssa_full_lhs " << step_l;
//				}
//				std::cout << std::endl;

  			if (expr_s.find("__CPROVER") == std::string::npos &&
  					expr_s.find("va_arg") == std::string::npos &&
  					function.find("__VERIFIER_atomic") == std::string::npos)
  			{
  				if (prev_step.thread_nr == -1)
  				{
  					// find the first assignment
  					 if (function.size() > 0)
  						 prev_step = *it;
  				}
  				else if (function.compare(as_string(prev_step.pc->source_location.get_function())) == 0)
  				{
  					prev_step = *it;
  				}
  				else if (function.size() > 0)
  				{
  					interleavings.push_back(std::make_pair(prev_step.time_expr, it->time_expr));
  					prev_step = *it;
  				}
  			}
  		}
  	}
    goto_trace.steps.splice(goto_trace.steps.end(), t_it->second);
  }

  for (int i = 0; i < interleavings.size(); i++)
  {
  	std::string s1, s2;
  	languages.from_expr(interleavings[i].first, s1);
  	languages.from_expr(interleavings[i].second, s2);

  	std::cout << "interleaving: " << s1 << " --->" << s2 << std::endl;
  }

  // produce the step numbers
  unsigned step_nr=0;

  for(goto_tracet::stepst::iterator
      s_it=goto_trace.steps.begin();
      s_it!=goto_trace.steps.end();
      s_it++)
    s_it->step_nr=++step_nr;

  new_guard = true_exprt();
  std::string guard;
  for (std::vector<exprt>::const_iterator it = guard_list.begin(); it != guard_list.end(); ++it)
  {
		new_guard = and_exprt(new_guard, *it);

//		languages.from_expr(*it, guard);
//		std::cout << "guard xx : " << guard << "\n";
  }

  for (std::vector<std::pair<std::string, exprt>>::iterator it = choices.begin(); it != choices.end(); ++it)
	{
  	if (prop_conv.get(it->second).is_true())
  		new_guard = and_exprt(new_guard, it->second);
	}

	simplify(new_guard, ns);

	languages.from_expr(new_guard, guard);
	std::cout << "guard final : " << guard << "\n";
}

/*******************************************************************\

Function: build_goto_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void build_goto_trace_new(
  symex_target_equationt &target,
  symex_target_equationt::SSA_stepst::const_iterator end_step,
  const prop_convt &prop_conv,
  const namespacet &ns,
  goto_tracet &goto_trace,
  std::vector<exprt> &new_guards,
  exprt &old_guard)
{
  // We need to re-sort the steps according to their clock.
  // Furthermore, read-events need to occur before write
  // events with the same clock.

  typedef std::map<mp_integer, goto_tracet::stepst> time_mapt;
  time_mapt time_map;

  mp_integer current_time=0;
  unsigned icount=1;

  languagest languages(ns, new_ansi_c_language());

  std::map<std::string, int> guard_map;
  std::map<mp_integer, std::vector<exprt>> time_to_expr;
  std::vector<exprt> guard_list;
  std::vector<exprt> another_guard_list;
  exprt last_operand = false_exprt();
  exprt current_time_expr;
  std::vector<std::pair<std::string, exprt>> choices;

#if 0
  bool has_threads=target.has_threads();

  for(symex_target_equationt::SSA_stepst::iterator
      s_it=target.SSA_steps.begin();
      s_it!=end_step;
      s_it++)
  {
    if(!s_it->is_assert()) continue;

    if(s_it->source.pc->source_location.is_not_nil())
      std::cout << s_it->source.pc->source_location << "\n";

    if(s_it->comment!="")
    	std::cout << s_it->comment << "\n";

    symex_target_equationt::SSA_stepst::const_iterator
      p_it=target.SSA_steps.begin();

    // we show everything in case there are threads
    symex_target_equationt::SSA_stepst::const_iterator
      last_it=has_threads?target.SSA_steps.end():s_it;

    for(unsigned count=1; p_it!=last_it; p_it++)
      if(p_it->is_assume() || p_it->is_assignment() || p_it->is_constraint())
        if(!p_it->ignore)
        {
        	std::string string_value;
					languages.from_expr(p_it->cond_expr, string_value);
        	if(prop_conv.l_get(p_it->guard_literal)!=tvt(true))
        	{
        		std::cout << "{++" << count << "} " << string_value << "\n";
        		count++;
        		continue;
        	}

          std::cout << "{-" << count << "} " << string_value << "\n";

          count++;
        }

    std::cout << "|--------------------------" << "\n";

    std::string string_value;
    languages.from_expr(s_it->cond_expr, string_value);
    std::cout << "{" << 1 << "} " << string_value << "\n";

    std::cout << "\n";
  }
#endif






  for(symex_target_equationt::SSA_stepst::const_iterator
      it=target.SSA_steps.begin();
      it!=end_step;
      it++)
  {
    const symex_target_equationt::SSA_stept &SSA_step=*it;

//    if (SSA_step.hidden)
//    	std::cout << "Why hidden: " << SSA_step.source.pc->source_location  << std::endl;

    std::string string_value;
		languages.from_expr(it->cond_expr, string_value);
    if(prop_conv.l_get(SSA_step.guard_literal)!=tvt(true))
    {
      continue;
    }

		if (it->is_assert())
		{
			std::cout << "(" << icount << ") ASSERT(" << string_value << ") " << "\n";
			 std::string assert_guard;
			 languages.from_expr(it->guard, assert_guard);
			 if (prop_conv.get(it->cond_expr).is_false())
				 std::cout << "Guard: FALSE" << assert_guard << std::endl;
			 else
				 std::cout << "Guard: TRUE" << assert_guard << std::endl;
			if(!it->guard.is_true())
			{
				old_guard = it->guard;
			}
			else
			{
				old_guard = true_exprt();
			}
		}
		else
		{
			if (it->cond_expr.is_not_nil())
			{
//				std::cout << "{-" << icount << "} " << string_value << "\n";
				if (!it->guard.is_true())
				{
					std::string string_value1;
					languages.from_expr(it->guard, string_value1);
					if (guard_map.find(string_value1) == guard_map.end()
					    && string_value1.find("__CPROVER_threads") == std::string::npos)
					{
						guard_map[string_value1] = 1;
						guard_list.push_back(it->guard);
					}
					std::cout << "guard: " << string_value1 << "\n";
				}

				// collect all choice_rf
				if (it->cond_expr.operands().size() > 1 &&
						string_value.find("__CPROVER_") == std::string::npos &&
						string_value.find("=") != std::string::npos)
				{
					// get the last one
					exprt last_one = it->cond_expr.operands().at(it->cond_expr.operands().size() - 1);
					std::string last_one_str;
					languages.from_expr(last_one, last_one_str);
					std::cout << "\t" << last_one_str << " " << last_one.operands().size() << "\n";

					if (last_one_str.find("choice_rf") != std::string::npos)
					{
						if (last_one_str[0] == '!')
						{
							last_one = not_exprt(last_one);
							last_one = simplify_expr(last_one, ns);
							languages.from_expr(last_one, last_one_str);
						}
						add_element(it->cond_expr, last_one_str, choices);
					}

				}
			}
		}
		icount++;

    if(it->is_constraint() ||
       it->is_spawn())
      continue;
    else if(it->is_atomic_begin())
    {
      // for atomic sections the timing can only be determined once we see
      // a shared read or write (if there is none, the time will be
      // reverted to the time before entering the atomic section); we thus
      // use a temporary negative time slot to gather all events
      current_time*=-1;
      continue;
    }
    else if(it->is_shared_read() || it->is_shared_write() ||
            it->is_atomic_end())
    {
      mp_integer time_before=current_time;

      if(it->is_shared_read() || it->is_shared_write())
      {
        // these are just used to get the time stamp
        exprt clock_value=prop_conv.get(
          symbol_exprt(partial_order_concurrencyt::rw_clock_id(it)));

        std::string tmp;
        languages.from_expr(clock_value, tmp);

        to_integer(clock_value, current_time);

        // add to map
				current_time_expr = symbol_exprt(partial_order_concurrencyt::rw_clock_id(it), bitvector_typet(ID_unsignedbv, 6));
				time_to_expr[current_time].push_back(current_time_expr);
      }
      else if(it->is_atomic_end() && current_time<0)
        current_time*=-1;

      assert(current_time>=0);
      // move any steps gathered in an atomic section

      if(time_before<0)
      {
        time_mapt::iterator entry=
          time_map.insert(std::make_pair(
              current_time,
              goto_tracet::stepst())).first;
        entry->second.splice(entry->second.end(), time_map[time_before]);
        time_map.erase(time_before);
      }

      continue;
    }

    // drop PHI and GUARD assignments altogether
    std::string expr_1; languages.from_expr(it->cond_expr, expr_1);
    if(it->is_assignment() &&
       (SSA_step.assignment_type==symex_target_equationt::PHI ||
        SSA_step.assignment_type==symex_target_equationt::GUARD))
    {
      continue;
    }

    goto_tracet::stepst &steps=time_map[current_time];
    steps.push_back(goto_trace_stept());
    goto_trace_stept &goto_trace_step=steps.back();

    goto_trace_step.time_expr = current_time_expr;
    goto_trace_step.thread_nr=SSA_step.source.thread_nr;
    goto_trace_step.pc=SSA_step.source.pc;
    goto_trace_step.comment=SSA_step.comment;
    goto_trace_step.lhs_object=SSA_step.original_lhs_object;
    goto_trace_step.type=SSA_step.type;
    goto_trace_step.hidden=SSA_step.hidden;
    goto_trace_step.format_string=SSA_step.format_string;
    goto_trace_step.io_id=SSA_step.io_id;
    goto_trace_step.formatted=SSA_step.formatted;
    goto_trace_step.identifier=SSA_step.identifier;

    goto_trace_step.assignment_type=
      (SSA_step.assignment_type==symex_targett::VISIBLE_ACTUAL_PARAMETER ||
       SSA_step.assignment_type==symex_targett::HIDDEN_ACTUAL_PARAMETER)?
      goto_trace_stept::ACTUAL_PARAMETER:
      goto_trace_stept::STATE;

    if(SSA_step.original_full_lhs.is_not_nil())
      goto_trace_step.full_lhs=
        build_full_lhs_rec(
          prop_conv, ns, SSA_step.original_full_lhs, SSA_step.ssa_full_lhs);

    if(SSA_step.ssa_lhs.is_not_nil())
      goto_trace_step.lhs_object_value=prop_conv.get(SSA_step.ssa_lhs);

    if(SSA_step.ssa_full_lhs.is_not_nil())
    {
    	goto_trace_step.ssa_full_lhs = SSA_step.ssa_full_lhs;
      goto_trace_step.full_lhs_value=prop_conv.get(SSA_step.ssa_full_lhs);
      simplify(goto_trace_step.full_lhs_value, ns);
    }

    if(SSA_step.ssa_rhs.is_not_nil())
		{
			goto_trace_step.ssa_rhs = SSA_step.ssa_rhs;
		}

    for(std::list<exprt>::const_iterator
        j=SSA_step.converted_io_args.begin();
        j!=SSA_step.converted_io_args.end();
        j++)
    {
      const exprt &arg=*j;
      if(arg.is_constant() ||
         arg.id()==ID_string_constant)
        goto_trace_step.io_args.push_back(arg);
      else
      {
        exprt tmp=prop_conv.get(arg);
        goto_trace_step.io_args.push_back(tmp);
      }
    }

    if(SSA_step.is_assert() ||
       SSA_step.is_assume())
    {
      goto_trace_step.cond_expr=SSA_step.cond_expr;

      goto_trace_step.cond_value=
        prop_conv.l_get(SSA_step.cond_literal).is_true();
    }
    else if(SSA_step.is_location() &&
            SSA_step.source.pc->is_goto())
    {
      goto_trace_step.cond_expr=SSA_step.source.pc->guard;

      const bool backwards=SSA_step.source.pc->is_backwards_goto();

      symex_target_equationt::SSA_stepst::const_iterator next=it;
      ++next;
      assert(next!=target.SSA_steps.end());

      // goto was taken if backwards and next is enabled or forward
      // and next is not active;
      // there is an ambiguity here if a forward goto is to the next
      // instruction, which we simply ignore for now
      goto_trace_step.goto_taken=
        backwards==
        (prop_conv.l_get(next->guard_literal)==tvt(true));
    }
  }

  std::cout << "counting total switches\n";
  int total_switches = 0;
  // test choices
  for (std::vector<std::pair<std::string, exprt>>::iterator it = choices.begin(); it != choices.end(); ++it)
  {
  	int value = prop_conv.get(it->second).is_true() ? 1 : 0;
  	std::cout << it->first << ": " << value << std::endl;
  	total_switches += value;
  }

  std::cout << "total switches: " << total_switches << std::endl;

  std::vector<std::pair<exprt, exprt>> interleavings;
  goto_trace_stept prev_step;
  prev_step.thread_nr = -1;

  // Now assemble into a single goto_trace.
  // This expoits sorted-ness of the map.

  std::map<std::string, exprt> current_instances;
  symex_target_equationt::SSA_stepst::const_iterator ssa=target.SSA_steps.begin();

  for(time_mapt::iterator t_it=time_map.begin();
      t_it!=time_map.end(); t_it++)
  {
  	std::cout << t_it->first << " at \n";

  	int expr_pos = 0;
  	for (goto_tracet::stepst::iterator it = t_it->second.begin(); it != t_it->second.end(); ++it)
  	{
  		std::cout << "\t" << it->pc->source_location << std::endl;
  		if (as_string(it->pc->source_location.get_file()).find("<built") == std::string::npos)
  		{
  			std::string function = as_string(it->pc->source_location.get_function());
  			std::string expr_s; languages.from_expr(it->time_expr, expr_s);
  			std::cout << "\t\t" << expr_s;

  			std::string step_l;
				if (it->full_lhs_value.is_not_nil())
				{
					languages.from_expr(it->ssa_full_lhs, step_l);
					std::cout << "\t ssa_full_lhs " << step_l;
				}
				std::cout << std::endl;
				if (false)
				while (ssa != target.SSA_steps.end())
				{
					// go to the equation
					if (ssa->ssa_full_lhs.is_not_nil())
					{
						// convert
						std::string ssa_l; languages.from_expr(ssa->ssa_full_lhs, ssa_l);
						if (ssa_l.compare(step_l) == 0)
						{
							// we got it

						}
						else
						{
							// update the current state
							std::string original_lhs_object; languages.from_expr(ssa->original_lhs_object, original_lhs_object);
							current_instances[original_lhs_object] = ssa->ssa_full_lhs;
						}
					}
					ssa++;
				}

  			if (expr_s.find("__CPROVER") == std::string::npos &&
  					expr_s.find("va_arg") == std::string::npos &&
  					function.find("__VERIFIER_atomic") == std::string::npos)
  			{
  				if (prev_step.thread_nr == -1)
  				{
  					// find the first assignment
  					 if (function.size() > 0)
  						 prev_step = *it;
  				}
  				else if (function.compare(as_string(prev_step.pc->source_location.get_function())) == 0)
  				{
  					prev_step = *it;
  				}
  				else if (function.size() > 0)
  				{
  					interleavings.push_back(std::make_pair(prev_step.time_expr, it->time_expr));
  					prev_step = *it;
  				}
  			}
  		}
  	}
    goto_trace.steps.splice(goto_trace.steps.end(), t_it->second);
  }

//  for (int i = 0; i < interleavings.size(); i++)
//  {
//  	std::string s1, s2;
//  	languages.from_expr(interleavings[i].first, s1);
//  	languages.from_expr(interleavings[i].second, s2);
//
//  	std::cout << "interleaving: " << s1 << " --->" << s2 << std::endl;
//  }

  // produce the step numbers
  unsigned step_nr=0;

  for(goto_tracet::stepst::iterator
      s_it=goto_trace.steps.begin();
      s_it!=goto_trace.steps.end();
      s_it++)
  {
    s_it->step_nr=++step_nr;
    if(!s_it->pc->source_location.is_nil())
              std::cout << "goto_trace  " << s_it->pc->source_location << "\n";
  }
  for (int i = 0; i < choices.size(); ++i)
  	new_guards.push_back(choices.at(i).second);

//  new_guard = true_exprt();
//  std::string guard;
//  for (std::vector<exprt>::const_iterator it = guard_list.begin(); it != guard_list.end(); ++it)
//  {
//		new_guard = and_exprt(new_guard, *it);
//
//		languages.from_expr(*it, guard);
//		std::cout << "guard xx : " << guard << "\n";
//  }

//  for (std::vector<std::pair<std::string, exprt>>::iterator it = choices.begin(); it != choices.end(); ++it)
//	{
//  	if (prop_conv.get(it->second).is_true())
//  		new_guard = and_exprt(new_guard, it->second);
//	}

//  for (int i = 0; i < interleavings.size(); ++i)
//  {
//  	exprt tmp_guard = binary_predicate_exprt(interleavings[i].first, ID_le, interleavings[i].second);
//		new_guard = and_exprt(new_guard, tmp_guard);
//  }

//	simplify(new_guard, ns);

//	languages.from_expr(new_guard, guard);
//	std::cout << "guard final : " << guard << "\n";
}
/*******************************************************************\

Function: build_goto_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void build_goto_trace(
  symex_target_equationt &target,
  symex_target_equationt::SSA_stepst::const_iterator end_step,
  const prop_convt &prop_conv,
  const namespacet &ns,
  goto_tracet &goto_trace)
{
  // We need to re-sort the steps according to their clock.
  // Furthermore, read-events need to occur before write
  // events with the same clock.
  
  typedef std::map<mp_integer, goto_tracet::stepst> time_mapt;
  time_mapt time_map;
  
  mp_integer current_time=0;
  unsigned icount=1;

  languagest languages(ns, new_ansi_c_language());

  std::map<std::string, int> guard_map;
  std::vector<exprt> guard_list;
  std::string expr_str;
  exprt last_operand;
  exprt assert_guard;

  for(symex_target_equationt::SSA_stepst::const_iterator
      it=target.SSA_steps.begin();
      it!=end_step;
      it++)
  {

    const symex_target_equationt::SSA_stept &SSA_step=*it;
    
    std::string string_value;
		languages.from_expr(it->cond_expr, string_value);
    if(prop_conv.l_get(SSA_step.guard_literal)!=tvt(true))
    {
      continue;
    }

		if (it->is_assert())
		{
			//std::cout << "(" << icount << ") ASSERT(" << string_value << ") " << "\n";
			expr_str = string_value;
			if(!it->guard.is_true())
			{
				std::string string_value1;
				languages.from_expr(it->guard, string_value1);

				assert_guard = it->guard;
				//std::cout << "guard: " << string_value1 << "\n";


				if(it->cond_expr.has_operands()){
				//	std::cout << "operands size: " << it->cond_expr.operands().size() << std::endl;
					for (int ii = 0; ii < it->cond_expr.operands().size(); ++ii)
					{
						languages.from_expr(it->cond_expr.operands()[ii], string_value1);
					//	std::cout << "ssa_full_lhs: " << string_value1 << "\n";
					}
					last_operand = it->cond_expr.operands()[it->cond_expr.operands().size() - 1];
				}
			}
		}
		else
			if(!it->cond_expr.is_nil())
			{
				//std::cout << "============(" << icount << ") " << string_value << "\n";
				if (!it->guard.is_true())
				{
					std::string string_value1;
					languages.from_expr(it->guard, string_value1);
					if (guard_map.find(string_value1) == guard_map.end())
					{
						guard_map[string_value1] = 1;
						guard_list.push_back(it->guard);
					}
				//	std::cout << "guard: " << string_value1 << "\n";
				}
//				if (string_value.find("guard") != std::string::npos){
//					target.SSA_steps.push_back(symex_target_equationt::SSA_stept());
//					symex_target_equationt::SSA_stept &SSA_step=target.SSA_steps.back();
//
//					exprt tmp = it->cond_expr;
//
//					  SSA_step.guard=tmp;
//					  SSA_step.cond_expr=tmp;
//					  SSA_step.type=goto_trace_stept::ASSIGNMENT;
////					target.SSA_steps.push_back();
//				}
			}
		icount++;

    if(it->is_constraint() ||
       it->is_spawn())
      continue;
    else if(it->is_atomic_begin())
    {
      // for atomic sections the timing can only be determined once we see
      // a shared read or write (if there is none, the time will be
      // reverted to the time before entering the atomic section); we thus
      // use a temporary negative time slot to gather all events
      current_time*=-1;
      continue;
    }
    else if(it->is_shared_read() || it->is_shared_write() ||
            it->is_atomic_end())
    {
      mp_integer time_before=current_time;

      if(it->is_shared_read() || it->is_shared_write())
      {
        // these are just used to get the time stamp
        exprt clock_value=prop_conv.get(
          symbol_exprt(partial_order_concurrencyt::rw_clock_id(it)));

        to_integer(clock_value, current_time);
      }
      else if(it->is_atomic_end() && current_time<0)
        current_time*=-1;

      assert(current_time>=0);
      // move any steps gathered in an atomic section

      if(time_before<0)
      {
        time_mapt::iterator entry=
          time_map.insert(std::make_pair(
              current_time,
              goto_tracet::stepst())).first;
        entry->second.splice(entry->second.end(), time_map[time_before]);
        time_map.erase(time_before);
      }

      continue;
    }

    // drop PHI and GUARD assignments altogether
    if(it->is_assignment() &&
       (SSA_step.assignment_type==symex_target_equationt::PHI ||
        SSA_step.assignment_type==symex_target_equationt::GUARD))
      continue;

    goto_tracet::stepst &steps=time_map[current_time];
    steps.push_back(goto_trace_stept());    
    goto_trace_stept &goto_trace_step=steps.back();
    
    goto_trace_step.thread_nr=SSA_step.source.thread_nr;
    goto_trace_step.pc=SSA_step.source.pc;
    goto_trace_step.comment=SSA_step.comment;
    goto_trace_step.lhs_object=SSA_step.original_lhs_object;
    goto_trace_step.type=SSA_step.type;
    goto_trace_step.hidden=SSA_step.hidden;
    goto_trace_step.format_string=SSA_step.format_string;
    goto_trace_step.io_id=SSA_step.io_id;
    goto_trace_step.formatted=SSA_step.formatted;
    goto_trace_step.identifier=SSA_step.identifier;

    goto_trace_step.assignment_type=
      (SSA_step.assignment_type==symex_targett::VISIBLE_ACTUAL_PARAMETER ||
       SSA_step.assignment_type==symex_targett::HIDDEN_ACTUAL_PARAMETER)?
      goto_trace_stept::ACTUAL_PARAMETER:
      goto_trace_stept::STATE;
    
    if(SSA_step.original_full_lhs.is_not_nil())
      goto_trace_step.full_lhs=
        build_full_lhs_rec(
          prop_conv, ns, SSA_step.original_full_lhs, SSA_step.ssa_full_lhs);
    
    if(SSA_step.ssa_lhs.is_not_nil())
      goto_trace_step.lhs_object_value=prop_conv.get(SSA_step.ssa_lhs);
    
    if(SSA_step.ssa_full_lhs.is_not_nil())
    {
      goto_trace_step.full_lhs_value=prop_conv.get(SSA_step.ssa_full_lhs);
      simplify(goto_trace_step.full_lhs_value, ns);
    }
    
    for(std::list<exprt>::const_iterator
        j=SSA_step.converted_io_args.begin();
        j!=SSA_step.converted_io_args.end();
        j++)
    {
      const exprt &arg=*j;
      if(arg.is_constant() ||
         arg.id()==ID_string_constant)
        goto_trace_step.io_args.push_back(arg);
      else
      {
        exprt tmp=prop_conv.get(arg);
        goto_trace_step.io_args.push_back(tmp);
      }
    }

    if(SSA_step.is_assert() ||
       SSA_step.is_assume())
    {
      goto_trace_step.cond_expr=SSA_step.cond_expr;

      goto_trace_step.cond_value=
        prop_conv.l_get(SSA_step.cond_literal).is_true();
    }
    else if(SSA_step.is_location() &&
            SSA_step.source.pc->is_goto())
    {
      goto_trace_step.cond_expr=SSA_step.source.pc->guard;

      const bool backwards=SSA_step.source.pc->is_backwards_goto();

      symex_target_equationt::SSA_stepst::const_iterator next=it;
      ++next;
      assert(next!=target.SSA_steps.end());

      // goto was taken if backwards and next is enabled or forward
      // and next is not active;
      // there is an ambiguity here if a forward goto is to the next
      // instruction, which we simply ignore for now
      goto_trace_step.goto_taken=
        backwards==
        (prop_conv.l_get(next->guard_literal)==tvt(true));
    }
  }
  
  // Now assemble into a single goto_trace.
  // This expoits sorted-ness of the map.
  for(time_mapt::iterator t_it=time_map.begin();
      t_it!=time_map.end(); t_it++)
  {
    goto_trace.steps.splice(goto_trace.steps.end(), t_it->second);
  }

  // produce the step numbers
  unsigned step_nr=0;
  
  for(goto_tracet::stepst::iterator
      s_it=goto_trace.steps.begin();
      s_it!=goto_trace.steps.end();
      s_it++)
    s_it->step_nr=++step_nr;
}

/*******************************************************************\

Function: build_goto_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::string get_error_condition(const namespacet &ns, const goto_tracet &goto_trace)
{
	languagest languages(ns, new_ansi_c_language());
	for (goto_tracet::stepst::const_iterator it = goto_trace.steps.begin();
	    it != goto_trace.steps.end(); it++)
	{
		// hide the hidden ones
		if (it->hidden || it->pc->source_location.is_nil())
			continue;
//		std::cout << "\n";

//		if (it->step_nr == 0)
//			std::cout << "Initial State";
//		else
//			std::cout << "State " << it->step_nr;

//		std::cout << " " << it->pc->source_location << " thread " << (*it).thread_nr << "\n";
		if (it->is_assert())
		{
			std::string string_value;
			languages.from_expr(it->cond_expr, string_value);
			std::cout << "Assert: " << string_value << std::endl;
			return string_value;
		}
	}

	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << "\n";
	return "";
}
/*******************************************************************\

Function: build_goto_trace

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void build_goto_trace(
  symex_target_equationt &target,
  const prop_convt &prop_conv,
  const namespacet &ns,
  goto_tracet &goto_trace)
{
	goto_trace.clear();
  build_goto_trace(
    target, target.SSA_steps.end(), prop_conv, ns, goto_trace);

  // Now delete anything after first failed assertion
  for(goto_tracet::stepst::iterator
      s_it1=goto_trace.steps.begin();
      s_it1!=goto_trace.steps.end();
      s_it1++)
    if(s_it1->is_assert() && !s_it1->cond_value)
    {
      s_it1++;

      for(goto_tracet::stepst::iterator
          s_it2=s_it1;
          s_it2!=goto_trace.steps.end();
          s_it2=goto_trace.steps.erase(s_it2));
        
      break;
    }

  //get_error_condition(ns, goto_trace);
}
