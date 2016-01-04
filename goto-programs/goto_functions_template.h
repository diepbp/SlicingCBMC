/*******************************************************************\

Module: Goto Programs with Functions

Author: Daniel Kroening

Date: June 2003

\*******************************************************************/

#ifndef CPROVER_GOTO_FUNCTIONS_TEMPLATE_H
#define CPROVER_GOTO_FUNCTIONS_TEMPLATE_H

#include <iostream>
#include <ostream>
#include <cassert>

#include <util/std_types.h>
#include <util/symbol.h>


template <class bodyT>
class goto_function_templatet
{
public:
  bodyT body;
  code_typet type;
  
  typedef std::vector<irep_idt> parameter_identifierst;
  parameter_identifierst parameter_identifiers;

  bool body_available;

  inline bool is_inlined() const
  {
    return type.get_bool(ID_C_inlined);
  }
  
  inline bool is_hidden() const
  {
    return type.get_bool(ID_C_hide);
  }
  
  inline void make_hidden()
  {
    type.set(ID_C_hide, true);
  }
  
  goto_function_templatet():body_available(false)
  {
  }
  
  void clear()
  {
    body.clear();
    type.clear();
    parameter_identifiers.clear();
    body_available=false;
  }

  void swap(goto_function_templatet &other)
  {
    body.swap(other.body);
    type.swap(other.type);
    parameter_identifiers.swap(other.parameter_identifiers);
    std::swap(body_available, other.body_available);
  }

  void copy_from(const goto_function_templatet<bodyT> &other)
  {
    body.copy_from(other.body);
    type=other.type;
    parameter_identifiers=other.parameter_identifiers;
    body_available=other.body_available;
  }

  goto_function_templatet(const goto_function_templatet<bodyT> &src):
    type(src.type),
    parameter_identifiers(src.parameter_identifiers),
    body_available(src.body_available)
  {
    body.copy_from(src.body);
  }
};

template <class bodyT>
class goto_functions_templatet
{
public:
  typedef goto_function_templatet<bodyT> goto_functiont;
  typedef std::map<irep_idt, goto_functiont> function_mapt;
  function_mapt function_map;
  
  inline goto_functions_templatet()
  {
  }

  // copy constructor, don't use me!
  goto_functions_templatet(const goto_functions_templatet<bodyT> &src)
  {
    assert(src.function_map.empty());
  }
  
  inline void clear()
  {
    function_map.clear();
  }
  
  void output(
    const namespacet &ns,
    std::ostream &out) const;

	std::vector<int> slice_variable(
	    const namespacet &ns,
	    std::vector<variable_struct> selected_variables,
	    std::vector<variable_struct> variables);

	int get_total_line(const namespacet &ns);

	std::vector<std::vector<int>> get_CFG(const namespacet &ns);

  std::vector<std::vector<int>> get_dependencies(
  		std::vector<variable_struct> vars,
  		const namespacet &ns,
  		const std::vector<std::string> lines) const;
    
  void compute_location_numbers();
  void compute_loop_numbers();
  void compute_target_numbers();
  void compute_incoming_edges();

  void update()
  {
    compute_incoming_edges();
    compute_target_numbers();
    compute_location_numbers();
  }

  static inline irep_idt entry_point()
  {
    // do not confuse with C's "int main()"
    return ID__start;
  }
  
  inline void swap(goto_functions_templatet &other)
  {
    function_map.swap(other.function_map);
  }
  
  void copy_from(const goto_functions_templatet &other)
  {
    for(typename function_mapt::const_iterator
        f_it=other.function_map.begin();
        f_it!=other.function_map.end();
        f_it++)
      function_map[f_it->first].copy_from(f_it->second);
  }

};

/*******************************************************************\

Function: goto_functions_templatet::output

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
void goto_functions_templatet<bodyT>::output(
  const namespacet &ns,
  std::ostream& out) const
{
  for(typename function_mapt::const_iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
  {
    if(it->second.body_available)
    {
      out << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
      out << std::endl;
      
      const symbolt &symbol=ns.lookup(it->first);
      out << symbol.display_name() << " /* " << symbol.name << " */" << std::endl;
      it->second.body.output(ns, symbol.name, out);
    }
  }
}

/*******************************************************************\

Function: goto_functions_templatet::output

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
template <class bodyT>
std::vector<int> goto_functions_templatet<bodyT>::slice_variable(
  const namespacet &ns,
  std::vector<variable_struct> selected_variables,
  std::vector<variable_struct> variables)
{
	int total_line = get_total_line(ns) + 10;
	std::vector<std::pair<int, Slice_Type>> resultt;
  for(typename function_mapt::const_iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
  {
    if(it->second.body_available)
    {
      const symbolt &symbol=ns.lookup(it->first);
      std::string name = as_string(symbol.name);
//			if ((as_string(symbol.name)[0] == '_' && as_string(symbol.name).find("__VERIFIER_") != std::string::npos)
  		if ((name.compare("__VERIFIER_atomic_end") == 0)
  				|| name.compare("__VERIFIER_atomic_begin") == 0
					|| name.find("pthread_") != std::string::npos
					|| name.compare("__actual_thread_spawn") == 0
					|| name.compare("_start") == 0
					|| name.compare("__CPROVER_initialize") == 0)
			{
				std::cout << "Do not slice " << name << std::endl;
				//default procedure of CPROVER
				continue;
			}
			std::cout << "Slicing procedure: " << name << std::endl;
			std::vector<std::pair<int, Slice_Type>> partial_result =
					it->second.body.slice_variable_instruction(ns, symbol.name, selected_variables, variables);
			resultt.insert(resultt.begin(), partial_result.begin(), partial_result.end());
    }
  }

  // update
  std::vector<int> result (total_line, -1);
  for (std::vector<std::pair<int, Slice_Type>>::iterator it = resultt.begin(); it != resultt.end(); ++it)
  {
  	if (result[(*it).first] == -1)
  		result[(*it).first] = (*it).second;
  	else
  	{
  		if (result[(*it).first] != (*it).second)
  		{
  			std::cout << "Line: " << (*it).first << " Problem might be in std::vector<std::pair<int, Slice_Type>> goto_functions_templatet<bodyT>::slice_variable\n";
  			std::cout << it->second << " ---- " << result[(*it).first]  << std::endl;
  		}
  		if (result[(*it).first] == Call && (*it).second && LeftAssign)
  			result[(*it).first] = CallnLeftAssign;
  		else
  			result[(*it).first] = (*it).second;
  	}
  }
  return result;
}
/*******************************************************************\

Function: goto_functions_templatet::get_total_line

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
int goto_functions_templatet<bodyT>::get_total_line(const namespacet &ns)
{
	int result = -1;
  for(typename function_mapt::const_iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
  {
    if(it->second.body_available)
    {
			const symbolt &symbol = ns.lookup(it->first);
			if ((as_string(symbol.name)[0] == '_' && as_string(symbol.name).find("__VERIFIER_") == std::string::npos)
					|| as_string(symbol.name).find("pthread_") != std::string::npos)
				//default procedure of CPROVER
				continue;

    	result = std::max(it->second.body.get_total_line(ns, symbol.name), result);
    	std::cout << "Total line: "  << result << std::endl;
    }
  }

  std::cout << "Total line: "  << result << std::endl;
  return result;
}


/*******************************************************************\

Function: goto_functions_templatet::get_CFG

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
std::vector<std::vector<int>> goto_functions_templatet<bodyT>::get_CFG(const namespacet &ns)
{
	int total_line = get_total_line(ns) + 10;
	std::vector<std::vector<int>> CFG(total_line);

	std::cout << "std::vector<std::vector<int>> goto_functions_templatet<bodyT>::get_CFG()\n";
  for(typename function_mapt::const_iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
  {
  	std::vector<std::vector<int>> partial_CFG;
    if(it->second.body_available)
    {
    	const symbolt &symbol=ns.lookup(it->first);
			if ((as_string(symbol.name)[0] == '_' && as_string(symbol.name).find("__VERIFIER_") == std::string::npos)
			    || as_string(symbol.name).find("pthread_") != std::string::npos)
				//default procedure of CPROVER
				continue;

    	partial_CFG = it->second.body.get_CFG(ns, symbol.name, total_line);
    	for (int i = 0; i < partial_CFG.size(); ++i)
    	{
    		CFG[i].insert(CFG[i].begin(), partial_CFG[i].begin(), partial_CFG[i].end());
    	}
    }
  }

  // print test
  for (int i = 0 ; i < total_line; ++i)
  {
  	std::cout << i << ": ";
  	for (int j = 0; j < CFG[i].size(); ++j)
  		std::cout << CFG[i][j] << " ";
  	std::cout << std::endl;
  }
  return CFG;
}


/*******************************************************************\

Function: goto_functions_templatet::get_dependency

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
std::vector<std::vector<int>> goto_functions_templatet<bodyT>::get_dependencies(
		std::vector<variable_struct> vars,
		const namespacet &ns,
		const std::vector<std::string> lines) const
{
	// TODO
	std::vector<std::map<int, int>> r(vars.size() + 10);

  for(typename function_mapt::const_iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
  {
    if(it->second.body_available)
    {
			const symbolt &symbol = ns.lookup(it->first);

			if ((as_string(symbol.name)[0] == '_' && as_string(symbol.name).find("__VERIFIER_") == std::string::npos)
					|| as_string(symbol.name).find("pthread_") != std::string::npos)
				//default procedure of CPROVER
				continue;

			std::cout << "std::vector<std::vector<int>> goto_functions_templatet<bodyT>::get_dependencies: " << as_string(symbol.name) << std::endl;

    	std::vector<std::vector<int>> partialResult;
    	partialResult = it->second.body.get_program_dependencies(ns, symbol.name, vars, lines);

    	// add to result
    	for (int i = 0; i < partialResult.size(); ++i)
    		for (int j = 0; j < partialResult[i].size(); ++j)
    			r[i][partialResult[i][j]] = 1;
    }
  }

	/*
	 * Print test dependency
	 */
  std::cout << "Test dependency in general\n";
	std::vector<std::vector<int>> result(vars.size() + 10);
	for (int i = 0; i < vars.size(); ++i)
	{
		std::cout << vars[i].name << ": " << vars[i].proc << ": ";
		for (std::map<int, int>::iterator it = r[i].begin();
		    it != r[i].end(); ++it)
		{
			result[i].push_back(it->first);
			std::cout << vars[it->first].name << " ";
		}
		std::cout << std::endl;
	}
  return result;
}

/*******************************************************************\

Function: goto_functions_templatet::compute_location_numbers

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
void goto_functions_templatet<bodyT>::compute_location_numbers()
{
  unsigned nr=0;

  for(typename function_mapt::iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
    it->second.body.compute_location_numbers(nr);
}

/*******************************************************************\

Function: goto_functions_templatet::compute_incoming_edges

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
void goto_functions_templatet<bodyT>::compute_incoming_edges()
{
  for(typename function_mapt::iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
    it->second.body.compute_incoming_edges();
}

/*******************************************************************\

Function: goto_functions_templatet::compute_target_numbers

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
void goto_functions_templatet<bodyT>::compute_target_numbers()
{
  for(typename function_mapt::iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
    it->second.body.compute_target_numbers();
}

/*******************************************************************\

Function: goto_functions_templatet::compute_loop_numbers

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

template <class bodyT>
void goto_functions_templatet<bodyT>::compute_loop_numbers()
{
  for(typename function_mapt::iterator
      it=function_map.begin();
      it!=function_map.end();
      it++)
    it->second.body.compute_loop_numbers();
}
  
#endif
