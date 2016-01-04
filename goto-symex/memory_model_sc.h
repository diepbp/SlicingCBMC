/*******************************************************************\

Module: Memory models for partial order concurrency

Author: Michael Tautschnig, michael.tautschnig@cs.ox.ac.uk

\*******************************************************************/

#ifndef CPROVER_MEMORY_MODEL_SC_H
#define CPROVER_MEMORY_MODEL_SC_H

#include "memory_model.h"

class memory_model_sct:public memory_model_baset
{
public:
  inline explicit memory_model_sct(const namespacet &_ns):
    memory_model_baset(_ns)
  {
  }

  virtual void operator()(
  		symex_target_equationt &equation,
  		std::vector<std::vector<std::string>> atomic_control);
  
protected:
  virtual exprt before(event_it e1, event_it e2);
  virtual bool program_order_is_relaxed(
    partial_order_concurrencyt::event_it e1,
    partial_order_concurrencyt::event_it e2) const;

  void build_per_thread_map(
    const symex_target_equationt &equation,
    per_thread_mapt &dest) const;
  void thread_spawn(
    symex_target_equationt &equation,
    const per_thread_mapt &per_thread_map);
  void program_order(symex_target_equationt &equation);
  void from_read(symex_target_equationt &equation);
  void write_serialization_external(
  		symex_target_equationt &equation,
  		std::vector<std::vector<std::string>> atomic_control);
  void write_serialization_external(
   		symex_target_equationt &equation);

  void classify_loop(
    symex_target_equationt &equation,
    std::vector<std::vector<std::string>> atomic_control,
    std::map<std::string, std::pair<int, std::string>> &var_loop);
  void update_block(std::vector<std::pair<event_it, int>> &atomic_block);
  void add_to_var_loop(
  		int loop_index,
  		std::string atomic_var,
  		std::vector<std::pair<event_it, int>> &atomic_block,
  		std::map<std::string, std::pair<int, std::string>> &var_loop);
};

#endif

