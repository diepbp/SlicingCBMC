/*******************************************************************\

Module: Traces of GOTO Programs

Author: Daniel Kroening

Date: July 2005

\*******************************************************************/

#ifndef CPROVER_GOTO_SYMEX_BUILD_GOTO_TRACE_H
#define CPROVER_GOTO_SYMEX_BUILD_GOTO_TRACE_H

#include "symex_target_equation.h"
#include "goto_symex_state.h"

// builds a trace that stops at first failing assertion
void build_goto_trace(
  symex_target_equationt &target,
  const prop_convt &prop_conv,
  const namespacet &ns,
  goto_tracet &goto_trace);

// builds a trace that stops after given step
void build_goto_trace(
  symex_target_equationt &target,
  symex_target_equationt::SSA_stepst::const_iterator stop,
  const prop_convt &prop_conv,
  const namespacet &ns,
  goto_tracet &goto_trace);

void build_goto_trace_new(
  symex_target_equationt &target,
  symex_target_equationt::SSA_stepst::const_iterator end_step,
  const prop_convt &prop_conv,
  const namespacet &ns,
  goto_tracet &goto_trace,
  exprt &old_guard,
  exprt &new_guard);

void printTrace(
  const namespacet &ns,
  const goto_tracet &goto_trace);

std::string get_error_condition(const namespacet &ns, const goto_tracet &goto_trace);

#endif
