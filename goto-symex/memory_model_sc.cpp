/*******************************************************************\

Module: Memory model for partial order concurrency

Author: Michael Tautschnig, michael.tautschnig@cs.ox.ac.uk

\*******************************************************************/
#include <iostream>
#include <util/std_expr.h>
#include <util/i2string.h>

#include <langapi/languages.h>
#include <langapi/language_util.h>
#include <ansi-c/ansi_c_language.h>

#include "memory_model_sc.h"

/*******************************************************************\

Function: memory_model_sct::operator()

  Inputs: 

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::operator()(
		symex_target_equationt &equation,
		std::vector<std::vector<std::string>> atomic_control)
{
  print(8, "Adding SC constraints");
  std::cout << " " << equation.SSA_steps.size() << std::endl;

  build_event_lists(equation);
  std::cout << "build_event_lists(equation); " << equation.SSA_steps.size() << std::endl;
  
  build_clock_type(equation);
  std::cout << "build_clock_type(equation); " << equation.SSA_steps.size() << std::endl;

  std::map<std::string, std::pair<int, std::string>> var_loop;
  classify_loop(equation, atomic_control, var_loop);

  read_from(equation, atomic_control, var_loop);
  std::cout << "read_from(equation); " << equation.SSA_steps.size() << std::endl;

  write_serialization_external(equation, atomic_control);
  std::cout << "write_serialization_external(equation); " << equation.SSA_steps.size() << std::endl;

  program_order(equation);
  std::cout << "program_order(equation); " << equation.SSA_steps.size() << std::endl;

  from_read(equation);
  std::cout << "from_read(equation); " << equation.SSA_steps.size() << std::endl;

}

/*******************************************************************\

Function: memory_model_sct::before

  Inputs: 

 Outputs:

 Purpose:

\*******************************************************************/

exprt memory_model_sct::before(event_it e1, event_it e2)
{
  return partial_order_concurrencyt::before(
    e1, e2, AX_PROPAGATION);
}

/*******************************************************************\

Function: memory_model_sct::program_order_is_relaxed

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool memory_model_sct::program_order_is_relaxed(
  partial_order_concurrencyt::event_it e1,
  partial_order_concurrencyt::event_it e2) const
{
  assert(is_shared_read(e1) || is_shared_write(e1));
  assert(is_shared_read(e2) || is_shared_write(e2));

  return false;
}

/*******************************************************************\

Function: memory_model_sct::build_per_thread_map

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::build_per_thread_map(
  const symex_target_equationt &equation,
  per_thread_mapt &dest) const
{
  // this orders the events within a thread
  
  for(eventst::const_iterator
      e_it=equation.SSA_steps.begin();
      e_it!=equation.SSA_steps.end();
      e_it++)
  {
    // concurreny-related?
    if(!is_shared_read(e_it) &&
       !is_shared_write(e_it) &&
       !is_spawn(e_it) &&
       !is_memory_barrier(e_it)) continue;

    dest[e_it->source.thread_nr].push_back(e_it);
  }
}

/*******************************************************************\

Function: memory_model_sct::thread_spawn

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::thread_spawn(
  symex_target_equationt &equation,
  const per_thread_mapt &per_thread_map)
{
  // thread spawn: the spawn precedes the first
  // instruction of the new thread in program order
  
  unsigned next_thread_id=0;
  for(eventst::const_iterator
      e_it=equation.SSA_steps.begin();
      e_it!=equation.SSA_steps.end();
      e_it++)
  {
    if(is_spawn(e_it))
    {
      per_thread_mapt::const_iterator next_thread=
        per_thread_map.find(++next_thread_id);
      if(next_thread==per_thread_map.end()) continue;

      // For SC and several weaker memory models a memory barrier
      // at the beginning of a thread can simply be ignored, because
      // we enforce program order in the thread-spawn constraint
      // anyway. Memory models with cumulative memory barriers
      // require explicit handling of these.
      event_listt::const_iterator n_it=next_thread->second.begin();
      for( ;
          n_it!=next_thread->second.end() &&
          (*n_it)->is_memory_barrier();
          ++n_it)
        ;

      if(n_it!=next_thread->second.end())
        add_constraint(
          equation,
          before(e_it, *n_it),
          "thread-spawn",
          e_it->source);
    }
  }
}

/*******************************************************************\

Function: memory_model_sct::program_order

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::program_order(
  symex_target_equationt &equation)
{
	languagest languages(ns, new_ansi_c_language());
  per_thread_mapt per_thread_map;
  build_per_thread_map(equation, per_thread_map);

  thread_spawn(equation, per_thread_map);
  
  // iterate over threads

  for(per_thread_mapt::const_iterator
      t_it=per_thread_map.begin();
      t_it!=per_thread_map.end();
      t_it++)
  {
    const event_listt &events=t_it->second;
    
    // iterate over relevant events in the thread
    
    event_it previous=equation.SSA_steps.end();
    
    for(event_listt::const_iterator
        e_it=events.begin();
        e_it!=events.end();
        e_it++)
    {
      if(is_memory_barrier(*e_it))
         continue;

      if(previous==equation.SSA_steps.end())
      {
        // first one?
        previous=*e_it;
        continue;
      }

      exprt expr = before(previous, *e_it);
      std::string string_value;
      languages.from_expr(expr, string_value);
      std::cout << "void memory_model_sct::program_order: \t" << string_value << std::endl;

      add_constraint(
        equation,
//        before(previous, *e_it),
        expr,
        "po",
        (*e_it)->source);

      previous=*e_it;
    }
  }
}

/*******************************************************************\

Function: memory_model_sct::update_block

  Inputs:

 Outputs:

 Purpose: only the last write can interleave, only the read - before write, can interleave

\*******************************************************************/
void memory_model_sct::update_block(std::vector<std::pair<event_it, int>> &atomic_block)
{
	std::map<std::string, bool> assigned_vars;
	for (int i = atomic_block.size() - 1; i >= 0; --i)
	{
		if (atomic_block.at(i).first->is_shared_write())
		{
			std::string var_name = id2string(id((atomic_block.at(i).first)));
			std::string name = var_name.substr(0, var_name.find('#'));
			if (assigned_vars.find(name) == assigned_vars.end())
			{
				// record the last write
				assigned_vars[name] = true;
				std::cout << "first write: " << var_name << std::endl;
			} else
			{
				// cannot interleave
				atomic_block[i] = std::make_pair(atomic_block[i].first, -1);
				std::cout << "NOTfirst write: " << var_name << std::endl;
			}
		}
	}
	assigned_vars.clear();

	for (int i = 0; i < atomic_block.size(); ++i)
	{
		std::string var_name = id2string(id((atomic_block.at(i).first)));
		std::string name = var_name.substr(0, var_name.find('#'));
		if (atomic_block.at(i).first->is_shared_read())
		{
			// record the write
			if (assigned_vars.find(name) != assigned_vars.end())
				atomic_block[i] = std::make_pair(atomic_block[i].first, -1);
		} else
		{
			// cannot interleave
			assigned_vars[name] = true;
		}
	}
}

/*******************************************************************\

Function: memory_model_sct::add_to_var_loop

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void memory_model_sct::add_to_var_loop(
		int loop_index,
		std::string atomic_var,
		std::vector<std::pair<event_it, int>> &atomic_block,
		std::map<std::string, std::pair<int, std::string>> &var_loop)
{
	for (int i = 0; i < atomic_block.size(); ++i)
	{
		var_loop[id2string(id((atomic_block.at(i).first)))] = std::pair<int, std::string>(atomic_block[i].second * loop_index, atomic_var);
	}
	atomic_block.clear();
}
/*******************************************************************\

Function: memory_model_sct::program_order

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::classify_loop(
  symex_target_equationt &equation,
  std::vector<std::vector<std::string>> atomic_control,
  std::map<std::string, std::pair<int, std::string>> &var_loop)
{
	languagest languages(ns, new_ansi_c_language());
  per_thread_mapt per_thread_map;
  build_per_thread_map(equation, per_thread_map);

  thread_spawn(equation, per_thread_map);

  // iterate over threads

  std::string func_name;
  int loop_index = 1;
  std::vector<std::pair<event_it, int>> atomic_block;

  for(per_thread_mapt::const_iterator
      t_it=per_thread_map.begin();
      t_it!=per_thread_map.end();
      t_it++)
  {
    const event_listt &events=t_it->second;

    // iterate over relevant events in the thread

    for(event_listt::const_iterator
        e_it=events.begin();
        e_it!=events.end();
        e_it++)
    {
    	event_it ev = *e_it;
      if(is_memory_barrier(*e_it))
         continue;

      if ((*e_it)->is_shared_read() || (*e_it)->is_shared_write())
			{
				std::string current_s = id2string(id((*e_it)));
				if (current_s.find("__CPROVER") == std::string::npos)
				{

					// get line
					int current_line = std::stoi(
					    as_string((*e_it)->source.pc->source_location.get_line()));
					if (atomic_control.at(current_line).size() > 0)
					{
						atomic_block.push_back(std::pair<event_it, int>(*e_it, 1));
						func_name = as_string((*e_it)->source.pc->source_location.get_function());
					}
					else { // not in atomic
						// TODO handle call procedure

						if (as_string((*e_it)->source.pc->source_location.get_function()).compare(func_name) != 0)
						{
							if (as_string((*e_it)->source.pc->source_location.get_function()).compare("__VERIFIER_atomic_acquire") == 0 ||
									(as_string((*e_it)->source.pc->source_location.get_function()).compare("__VERIFIER_atomic_release") == 0 && (*e_it)->is_shared_read()) ||
									as_string((*e_it)->source.pc->source_location.get_function()).compare("__VERIFIER_atomic_begin") == 0 ||
									(as_string((*e_it)->source.pc->source_location.get_function()).compare("__VERIFIER_atomic_end") == 0 && (*e_it)->is_shared_read()))
							{
								atomic_block.push_back(std::pair<event_it, int>(*e_it, 1));
							}
							else if (as_string((*e_it)->source.pc->source_location.get_function()).compare("__VERIFIER_atomic_release") == 0 ||
									as_string((*e_it)->source.pc->source_location.get_function()).compare("__VERIFIER_atomic_end") == 0)
							{
								if ((*e_it)->is_shared_write())
								{
									atomic_block.push_back(std::pair<event_it, int>(*e_it, 1));
									update_block(atomic_block);
									std::string atomic_var = current_s.substr(0, current_s.find('#'));
//									std::cout << "Atomic control size: " << atomic_var << " " << current_line << " " << atomic_control.at(current_line).size() << std::endl;
									add_to_var_loop(loop_index, atomic_var, atomic_block, var_loop);
									loop_index++;
								}
							}
							else
							{
								atomic_block.push_back(std::pair<event_it, int>(*e_it, 1));
							}
						}
						else
						{
							// check whether variables has changed in the atomic
							var_loop[current_s] = std::pair<int, std::string>(0, "");
							loop_index++;
						}
					}
				}
			}
    }
  }

  std::cout << "Test var loop: \n";
  for (std::map<std::string, std::pair<int, std::string>>::iterator it = var_loop.begin(); it != var_loop.end(); ++it)
  	std::cout << it->first << " " << it->second.first << " " << it->second.second << std::endl;
}

/*******************************************************************\

Function: memory_model_sct::write_serialization_external

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::write_serialization_external(
  symex_target_equationt &equation,
  std::vector<std::vector<std::string>> atomic_control)
{
  for(address_mapt::const_iterator
      a_it=address_map.begin();
      a_it!=address_map.end();
      a_it++)
  {
    const a_rect &a_rec=a_it->second;

    // This is quadratic in the number of writes
    // per address. Perhaps some better encoding
    // based on 'places'?    
    for(event_listt::const_iterator
        w_it1=a_rec.writes.begin();
        w_it1!=a_rec.writes.end();
        ++w_it1)
    {
      event_listt::const_iterator next=w_it1;
      ++next;

      for(event_listt::const_iterator w_it2=next;
          w_it2!=a_rec.writes.end();
          ++w_it2)
      {
        // external?
        if((*w_it1)->source.thread_nr==
           (*w_it2)->source.thread_nr)
          continue;

        int rr = std::stoi(as_string((*w_it1)->source.pc->source_location.get_line()));
               int ww = std::stoi(as_string((*w_it2)->source.pc->source_location.get_line()));
               std::string rs = as_string((*w_it1)->source.pc->source_location.get_function());
               std::string ws = as_string((*w_it2)->source.pc->source_location.get_function());

               if (rs.compare("pthread_create") != 0)
               {
               	if (atomic_control.at(rr).size() > 0)
               	{
               		if (atomic_control.at(ww).size() > 0
       //        				|| ws.size() == 0
               				)
                     std::cout << "w_it1: " << (*w_it1)->source.pc->source_location.get_line() << " at proc " << (*w_it1)->source.pc->source_location.get_function()
                     					<< "(*w_it2)" << (*w_it2)->source.pc->source_location.get_line() << " at proc " << (*w_it2)->source.pc->source_location.get_function()
                     					<< std::endl;
       //        			continue;
               	}
               }
               std::cout << "--w_it1: " << (*w_it1)->source.pc->source_location.get_line() << " at proc " << (*w_it1)->source.pc->source_location.get_function()
                                    					<< " --(*w_it2)" << (*w_it2)->source.pc->source_location.get_line() << " at proc " << (*w_it2)->source.pc->source_location.get_function()
                                    					<< std::endl;
        // ws is a total order, no two elements have the same rank
        // s -> w_evt1 before w_evt2; !s -> w_evt2 before w_evt1

        symbol_exprt s=nondet_bool_symbol("ws-ext");

        // write-to-write edge
        add_constraint(
          equation,
          implies_exprt(s, before(*w_it1, *w_it2)),
          "ws-ext",
          (*w_it1)->source);

        add_constraint(
          equation,
          implies_exprt(not_exprt(s), before(*w_it2, *w_it1)),
          "ws-ext",
          (*w_it1)->source);
      }
    }
  }
}

/*******************************************************************\

Function: memory_model_sct::write_serialization_external

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::write_serialization_external(
  symex_target_equationt &equation)
{
  for(address_mapt::const_iterator
      a_it=address_map.begin();
      a_it!=address_map.end();
      a_it++)
  {
    const a_rect &a_rec=a_it->second;

    // This is quadratic in the number of writes
    // per address. Perhaps some better encoding
    // based on 'places'?
    for(event_listt::const_iterator
        w_it1=a_rec.writes.begin();
        w_it1!=a_rec.writes.end();
        ++w_it1)
    {
      event_listt::const_iterator next=w_it1;
      ++next;

      for(event_listt::const_iterator w_it2=next;
          w_it2!=a_rec.writes.end();
          ++w_it2)
      {
        // external?
        if((*w_it1)->source.thread_nr==
           (*w_it2)->source.thread_nr)
          continue;

        // ws is a total order, no two elements have the same rank
        // s -> w_evt1 before w_evt2; !s -> w_evt2 before w_evt1

        symbol_exprt s=nondet_bool_symbol("ws-ext");

        // write-to-write edge
        add_constraint(
          equation,
          implies_exprt(s, before(*w_it1, *w_it2)),
          "ws-ext",
          (*w_it1)->source);

        add_constraint(
          equation,
          implies_exprt(not_exprt(s), before(*w_it2, *w_it1)),
          "ws-ext",
          (*w_it1)->source);
      }
    }
  }
}

/*******************************************************************\

Function: memory_model_sct::from_read

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_sct::from_read(symex_target_equationt &equation)
{
	languagest languages(ns, new_ansi_c_language());
  // from-read: (w', w) in ws and (w', r) in rf -> (r, w) in fr
  
  for(address_mapt::const_iterator
      a_it=address_map.begin();
      a_it!=address_map.end();
      a_it++)
  {
    const a_rect &a_rec=a_it->second;

    // This is quadratic in the number of writes per address.
    for(event_listt::const_iterator
        w_prime=a_rec.writes.begin();
        w_prime!=a_rec.writes.end();
        ++w_prime)
    {
      event_listt::const_iterator next=w_prime;
      ++next;
      std::string w_prime_value;
			languages.from_expr((*w_prime)->guard, w_prime_value);
			std::cout << "w_prime_value \t" << w_prime_value << std::endl;

      for(event_listt::const_iterator w=next;
          w!=a_rec.writes.end();
          ++w)
      {
        exprt ws1, ws2;
        
        if(po(*w_prime, *w) &&
           !program_order_is_relaxed(*w_prime, *w))
        {
          ws1=true_exprt();
          ws2=false_exprt();
        }
        else if(po(*w, *w_prime) &&
                !program_order_is_relaxed(*w, *w_prime))
        {
          ws1=false_exprt();
          ws2=true_exprt();
        }
        else
        {
          ws1=before(*w_prime, *w);
          ws2=before(*w, *w_prime);
        }

        // smells like cubic
        for(choice_symbolst::const_iterator
            c_it=choice_symbols.begin();
            c_it!=choice_symbols.end();
            c_it++)
        {
          event_it r=c_it->first.first;
          exprt rf=c_it->second;
          exprt cond;
          cond.make_nil();
        
          if(c_it->first.second==*w_prime && !ws1.is_false())
          {
            exprt fr=before(r, *w);

            // the guard of w_prime follows from rf; with rfi
            // optimisation such as the previous write_symbol_primed
            // it would even be wrong to add this guard
            cond=
              implies_exprt(
                and_exprt(r->guard, (*w)->guard, ws1, rf),
                fr);
          }
          else if(c_it->first.second==*w && !ws2.is_false())
          {
            exprt fr=before(r, *w_prime);
            // the guard of w follows from rf; with rfi
            // optimisation such as the previous write_symbol_primed
            // it would even be wrong to add this guard
            cond=
              implies_exprt(
                and_exprt(r->guard, (*w_prime)->guard, ws2, rf),
                fr);
          }

          if(cond.is_not_nil())
          {
            add_constraint(equation,
              cond, "fr", r->source);
          }
        }
        
      }
    }
  }
}

