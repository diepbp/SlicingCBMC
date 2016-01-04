/*******************************************************************\

Module: Memory model for partial order concurrency

Author: Michael Tautschnig, michael.tautschnig@cs.ox.ac.uk

\*******************************************************************/

#include <util/std_expr.h>
#include <util/i2string.h>

#include "memory_model.h"

/*******************************************************************\

Function: memory_model_baset::memory_model_baset

  Inputs: 

 Outputs:

 Purpose:

\*******************************************************************/

memory_model_baset::memory_model_baset(const namespacet &_ns):
  partial_order_concurrencyt(_ns),
  var_cnt(0)
{
}

/*******************************************************************\

Function: memory_model_baset::~memory_model_baset

  Inputs: 

 Outputs:

 Purpose:

\*******************************************************************/

memory_model_baset::~memory_model_baset()
{
}

/*******************************************************************\

Function: memory_model_baset::nondet_bool_symbol

  Inputs: 

 Outputs:

 Purpose:

\*******************************************************************/

symbol_exprt memory_model_baset::nondet_bool_symbol(
  const std::string &prefix)
{
  return symbol_exprt(
    "memory_model::choice_"+prefix+i2string(var_cnt++),
    bool_typet());
}

/*******************************************************************\

Function: memory_model_baset::po

  Inputs: 

 Outputs:

 Purpose:

\*******************************************************************/

bool memory_model_baset::po(event_it e1, event_it e2)
{
  // within same thread
  if(e1->source.thread_nr==e2->source.thread_nr)
    return numbering[e1]<numbering[e2];
  else
  {
    // in general un-ordered, with exception of thread-spawning
    return false;
  }
}

/*******************************************************************\

Function: memory_model_baset::read_from

  Inputs: 

 Outputs:

 Purpose:

\*******************************************************************/
symbol_exprt memory_model_baset::select_choice(
		const event_it r,
		const event_it w,
		std::map<std::pair<event_it, event_it>, symbol_exprt> &choice_map,
		std::map<std::string, std::pair<int, std::string>> var_loop)
{
//	for (std::map<std::pair<event_it, event_it>, symbol_exprt>::iterator it = choice_map.begin();
//			it != choice_map.end(); ++it)
//	{
//		const event_it rr= it->first.first;
//		const event_it ww= it->first.second;
//		// same r
//		if (rr->source.thread_nr == r->source.thread_nr &&
//				ww->source.thread_nr == w->source.thread_nr)
//		{
//			if(var_loop[id2string(id(r))].first == var_loop[id2string(id(rr))].first &&
//			var_loop[id2string(id(w))].first == var_loop[id2string(id(ww))].first &&
//			var_loop[id2string(id(r))].first != 0 && var_loop[id2string(id(w))].first != 0)
//			{
//				std::cout << id2string(id(r)) << " match " << id2string(id(w)) << " by " << id2string(id(rr)) << " and " << id2string(id(ww)) << std::endl;
//				return it->second;
//			}
//		}
//	}

	symbol_exprt s=nondet_bool_symbol("rf");
	if (var_loop[id2string(id(r))].second.compare(var_loop[id2string(id(w))].second) == 0)
		choice_map[std::make_pair(r, w)] = s;
	return s;
}
/*******************************************************************\

Function: memory_model_baset::read_from

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_baset::read_from(
		symex_target_equationt &equation,
		std::vector<std::vector<std::string>> atomic_control,
		std::map<std::string, std::pair<int, std::string>> var_loop)
{
  // We iterate over all the reads, and
  // make them match at least one
  // (internal or external) write.
	std::map<std::pair<event_it, event_it>, symbol_exprt> choice_map;
  for(address_mapt::const_iterator
      a_it=address_map.begin();
      a_it!=address_map.end();
      a_it++)
  {
    const a_rect &a_rec=a_it->second;
  
    for(event_listt::const_iterator
        r_it=a_rec.reads.begin();
        r_it!=a_rec.reads.end();
        r_it++)
    {
      const event_it r=*r_it;
      
      exprt::operandst rf_some_operands;
      rf_some_operands.reserve(a_rec.writes.size());

      // this is quadratic in #events per address
      for(event_listt::const_iterator
          w_it=a_rec.writes.begin();
          w_it!=a_rec.writes.end();
          ++w_it)
      {
        const event_it w=*w_it;
        
        // rf cannot contradict program order
        if(po(r, w))
        {
          continue; // contradicts po
        }
        bool is_rfi=
          w->source.thread_nr==r->source.thread_nr;

        if (((var_loop[id2string(id(r))].first < 0 &&
        		abs(var_loop[id2string(id(r))].first) !=  abs(var_loop[id2string(id(w))].first)) ||

        		(var_loop[id2string(id(w))].first < 0 &&
        		 abs(var_loop[id2string(id(r))].first) != abs(var_loop[id2string(id(w))].first))) &&

        		var_loop[id2string(id(r))].second.compare(var_loop[id2string(id(w))].second) == 0)
        {
        	std::cout << "we remove: " << id2string(id(r)) << " " << id2string(id(w)) << std::endl;
        	continue;
        }

        symbol_exprt s = select_choice(r, w, choice_map, var_loop);
        
        int rr = std::stoi(as_string(r->source.pc->source_location.get_line()));
        int ww = std::stoi(as_string(w->source.pc->source_location.get_line()));

//        std::cout << "+++RR: " << r->source.pc->source_location.get_line() << " at proc " << r->source.pc->source_location.get_function()
//                      					<< "+++WW: " << w->source.pc->source_location.get_line() << " at proc " << w->source.pc->source_location.get_function()
//                      					<< std::endl;
//
//        // record the symbol
//        std::cout << "ID: " << id2string(id(r)) << "\t" << id2string(id(w)) << "\t" << s << std::endl;
        choice_symbols[
          std::make_pair(r, w)]=s;

        // We rely on the fact that there is at least
        // one write event that has guard 'true'.
        implies_exprt read_from(s,
            and_exprt(w->guard,
              equal_exprt(r->ssa_lhs, w->ssa_lhs)));

        // Uses only the write's guard as precondition, read's guard
        // follows from rf_some
        add_constraint(equation,
          read_from, is_rfi?"rfi":"rf", r->source);

        if(!is_rfi)
        {
          // if r reads from w, then w must have happened before r
          exprt cond=implies_exprt(s, before(w, r));
          add_constraint(equation,
            cond, "rf-order", r->source);
        }

        rf_some_operands.push_back(s);
      }
      
      // value equals the one of some write
      exprt rf_some;

      // uninitialised global symbol like symex_dynamic::dynamic_object*
      // or *$object
      if(rf_some_operands.empty())
        continue;
      else if(rf_some_operands.size()==1)
        rf_some=rf_some_operands.front();
      else
      {
        rf_some=or_exprt();
        rf_some.operands().swap(rf_some_operands);
      }

      // Add the read's guard, each of the writes' guards is implied
      // by each entry in rf_some
      add_constraint(equation,
        implies_exprt(r->guard, rf_some), "rf-some", r->source);
    }
  }
}


/*******************************************************************\

Function: memory_model_baset::read_from

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void memory_model_baset::read_from(
		symex_target_equationt &equation)
{
  // We iterate over all the reads, and
  // make them match at least one
  // (internal or external) write.

  for(address_mapt::const_iterator
      a_it=address_map.begin();
      a_it!=address_map.end();
      a_it++)
  {
    const a_rect &a_rec=a_it->second;

    for(event_listt::const_iterator
        r_it=a_rec.reads.begin();
        r_it!=a_rec.reads.end();
        r_it++)
    {
      const event_it r=*r_it;

      exprt::operandst rf_some_operands;
      rf_some_operands.reserve(a_rec.writes.size());

      // this is quadratic in #events per address
      for(event_listt::const_iterator
          w_it=a_rec.writes.begin();
          w_it!=a_rec.writes.end();
          ++w_it)
      {
        const event_it w=*w_it;

        // rf cannot contradict program order
        if(po(r, w))
          continue; // contradicts po

        bool is_rfi=
          w->source.thread_nr==r->source.thread_nr;

        symbol_exprt s=nondet_bool_symbol("rf");

        std::cout << "RR: " << r->source.pc->source_location.get_line()
        					<< "WW: " << w->source.pc->source_location.get_line()
        					<< std::endl;

        // record the symbol
        choice_symbols[
          std::make_pair(r, w)]=s;

        // We rely on the fact that there is at least
        // one write event that has guard 'true'.
        implies_exprt read_from(s,
            and_exprt(w->guard,
              equal_exprt(r->ssa_lhs, w->ssa_lhs)));

        // Uses only the write's guard as precondition, read's guard
        // follows from rf_some
        add_constraint(equation,
          read_from, is_rfi?"rfi":"rf", r->source);

        if(!is_rfi)
        {
          // if r reads from w, then w must have happened before r
          exprt cond=implies_exprt(s, before(w, r));
          add_constraint(equation,
            cond, "rf-order", r->source);
        }

        rf_some_operands.push_back(s);
      }

      // value equals the one of some write
      exprt rf_some;

      // uninitialised global symbol like symex_dynamic::dynamic_object*
      // or *$object
      if(rf_some_operands.empty())
        continue;
      else if(rf_some_operands.size()==1)
        rf_some=rf_some_operands.front();
      else
      {
        rf_some=or_exprt();
        rf_some.operands().swap(rf_some_operands);
      }

      // Add the read's guard, each of the writes' guards is implied
      // by each entry in rf_some
      add_constraint(equation,
        implies_exprt(r->guard, rf_some), "rf-some", r->source);
    }
  }
}

