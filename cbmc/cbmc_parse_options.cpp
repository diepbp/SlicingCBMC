/*******************************************************************\

Module: CBMC Command Line Option Processing

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <fstream>
#include <cstdlib> // exit()
#include <iostream>
#include <memory>

#include <util/string2int.h>
#include <util/config.h>
#include <util/expr_util.h>
#include <util/language.h>
#include <util/unicode.h>
#include <util/memory_info.h>
#include <util/i2string.h>

#include <ansi-c/c_preprocess.h>

#include <goto-programs/goto_convert_functions.h>
#include <goto-programs/remove_function_pointers.h>
#include <goto-programs/remove_returns.h>
#include <goto-programs/remove_vector.h>
#include <goto-programs/remove_complex.h>
#include <goto-programs/remove_asm.h>
#include <goto-programs/remove_unused_functions.h>
#include <goto-programs/goto_inline.h>
#include <goto-programs/show_properties.h>
#include <goto-programs/set_properties.h>
#include <goto-programs/read_goto_binary.h>
#include <goto-programs/string_abstraction.h>
#include <goto-programs/string_instrumentation.h>
#include <goto-programs/loop_ids.h>
#include <goto-programs/link_to_library.h>

#include <cegis/bmc_verification_oracle.h>
#include <cegis/cegis.h>
#include <cegis/ga_learning_algorithm.h>

#include <pointer-analysis/add_failed_symbols.h>

#include <analyses/goto_check.h>

#include <langapi/mode.h>

#include "cbmc_parse_options.h"
#include "bmc.h"
#include "version.h"
#include "xml_interface.h"

/*******************************************************************\

Function: cbmc_parse_optionst::cbmc_parse_optionst

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

cbmc_parse_optionst::cbmc_parse_optionst(int argc, const char **argv):
  parse_options_baset(CBMC_OPTIONS, argc, argv),
  xml_interfacet(cmdline),
  language_uit("CBMC " CBMC_VERSION, cmdline)
{
}

/*******************************************************************\

Function: cbmc_parse_optionst::cbmc_parse_optionst

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

::cbmc_parse_optionst::cbmc_parse_optionst(
  int argc,
  const char **argv,
  const std::string &extra_options):
  parse_options_baset(CBMC_OPTIONS+extra_options, argc, argv),
  xml_interfacet(cmdline),
  language_uit("CBMC " CBMC_VERSION, cmdline)
{
}

/*******************************************************************\

Function: cbmc_parse_optionst::eval_verbosity

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void cbmc_parse_optionst::eval_verbosity()
{
  // this is our default verbosity
  unsigned int v=messaget::M_STATISTICS;

  if(cmdline.isset("verbosity"))
  {
    v=unsafe_string2unsigned(cmdline.get_value("verbosity"));
    if(v>10) v=10;
  }

  ui_message_handler.set_verbosity(v);
}

/*******************************************************************\

Function: cbmc_parse_optionst::get_command_line_options

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void cbmc_parse_optionst::get_command_line_options(optionst &options)
{
  if(config.set(cmdline))
  {
    usage_error();
    exit(1);
  }

  if(cmdline.isset("program-only"))
    options.set_option("program-only", true);

  if(cmdline.isset("show-vcc"))
    options.set_option("show-vcc", true);

  if(cmdline.isset("cover-assertions"))
    options.set_option("cover-assertions", true);

  if(cmdline.isset("mm"))
    options.set_option("mm", cmdline.get_value("mm"));

  if(cmdline.isset("no-simplify"))
    options.set_option("simplify", false);
  else
    options.set_option("simplify", true);

  if(cmdline.isset("all-claims") || // will go away
     cmdline.isset("all-properties")) // use this one
    options.set_option("all-properties", true);
  else
    options.set_option("all-properties", false);

  if(cmdline.isset("unwind"))
    options.set_option("unwind", cmdline.get_value("unwind"));

  if(cmdline.isset("depth"))
    options.set_option("depth", cmdline.get_value("depth"));

  if(cmdline.isset("debug-level"))
    options.set_option("debug-level", cmdline.get_value("debug-level"));

  if(cmdline.isset("slice-by-trace"))
    options.set_option("slice-by-trace", cmdline.get_value("slice-by-trace"));

  if(cmdline.isset("unwindset"))
    options.set_option("unwindset", cmdline.get_value("unwindset"));

  // constant propagation
  if(cmdline.isset("no-propagation"))
    options.set_option("propagation", false);
  else
    options.set_option("propagation", true);

  // check array bounds
  if(cmdline.isset("bounds-check"))
    options.set_option("bounds-check", true);
  else
    options.set_option("bounds-check", false);

  // check division by zero
  if(cmdline.isset("div-by-zero-check"))
    options.set_option("div-by-zero-check", true);
  else
    options.set_option("div-by-zero-check", false);

  // check overflow/underflow
  if(cmdline.isset("signed-overflow-check"))
    options.set_option("signed-overflow-check", true);
  else
    options.set_option("signed-overflow-check", false);

  // check overflow/underflow
  if(cmdline.isset("unsigned-overflow-check"))
    options.set_option("unsigned-overflow-check", true);
  else
    options.set_option("unsigned-overflow-check", false);

  // check overflow/underflow
  if(cmdline.isset("float-overflow-check"))
    options.set_option("float-overflow-check", true);
  else
    options.set_option("float-overflow-check", false);

  // check for NaN (not a number)
  if(cmdline.isset("nan-check"))
    options.set_option("nan-check", true);
  else
    options.set_option("nan-check", false);

  // check pointers
  if(cmdline.isset("pointer-check"))
    options.set_option("pointer-check", true);
  else
    options.set_option("pointer-check", false);

  // check for memory leaks
  if(cmdline.isset("memory-leak-check"))
    options.set_option("memory-leak-check", true);
  else
    options.set_option("memory-leak-check", false);

  // check assertions
  if(cmdline.isset("no-assertions"))
    options.set_option("assertions", false);
  else
    options.set_option("assertions", true);

  // use assumptions
  if(cmdline.isset("no-assumptions"))
    options.set_option("assumptions", false);
  else
    options.set_option("assumptions", true);

  // magic error label
  if(cmdline.isset("error-label"))
    options.set_option("error-label", cmdline.get_values("error-label"));

  // generate unwinding assertions
  if(cmdline.isset("cover-assertions"))
    options.set_option("unwinding-assertions", false);
  else
    options.set_option("unwinding-assertions",
      !cmdline.isset("no-unwinding-assertions"));

  // generate unwinding assumptions otherwise
  options.set_option("partial-loops",
   cmdline.isset("partial-loops"));

  // remove unused equations
  options.set_option("slice-formula",
       cmdline.isset("slice-formula"));

  // simplify if conditions and branches
  if(cmdline.isset("no-simplify-if"))
    options.set_option("simplify-if", false);
  else
    options.set_option("simplify-if", true);

  if(cmdline.isset("arrays-uf-always"))
    options.set_option("arrays-uf", "always");
  else if(cmdline.isset("arrays-uf-never"))
    options.set_option("arrays-uf", "never");
  else
    options.set_option("arrays-uf", "auto");

  if(cmdline.isset("dimacs"))
    options.set_option("dimacs", true);

  if(cmdline.isset("refine"))
    options.set_option("refine", true);

  if(cmdline.isset("max-node-refinement"))
    options.set_option("max-node-refinement", cmdline.get_value("max-node-refinement"));

  if(cmdline.isset("aig"))
    options.set_option("aig", true);

  // SMT Options
  bool version_set = false;

  if(cmdline.isset("smt1"))
  {
    options.set_option("smt1", true);
    options.set_option("smt2", false);
    version_set = true;
  }

  if(cmdline.isset("smt2"))
  {
    options.set_option("smt1", false);// If both are given, smt2 takes precedence
    options.set_option("smt2", true);
    version_set = true;
  }

  if(cmdline.isset("fpa"))
    options.set_option("fpa", true);


  bool solver_set = false;

  if(cmdline.isset("boolector"))
  {
    options.set_option("boolector", true), solver_set = true;
    if(!version_set)
      options.set_option("smt2", true), version_set = true;
  }

  if(cmdline.isset("mathsat"))
  {
    options.set_option("mathsat", true), solver_set = true;
    if(!version_set)
      options.set_option("smt2", true), version_set = true;
  }

  if(cmdline.isset("cvc3"))
  {
    options.set_option("cvc3", true), solver_set = true;
    if(!version_set)
      options.set_option("smt1", true), version_set = true;
  }

  if(cmdline.isset("cvc4"))
  {
    options.set_option("cvc4", true), solver_set = true;
    if(!version_set)
      options.set_option("smt2", true), version_set = true;
  }

  if(cmdline.isset("yices"))
  {
    options.set_option("yices", true), solver_set = true;
    if(!version_set)
      options.set_option("smt2", true), version_set = true;
  }

  if(cmdline.isset("z3"))
  {
    options.set_option("z3", true), solver_set = true;
    if(!version_set)
      options.set_option("smt2", true), version_set = true;
  }

  if(cmdline.isset("opensmt"))
  {
    options.set_option("opensmt", true), solver_set = true;
    if(!version_set)
      options.set_option("smt1", true), version_set = true;
  }

  if(version_set && !solver_set)
  {
    if(cmdline.isset("outfile"))
    {
      // outfile and no solver should give standard compliant SMT-LIB
      options.set_option("generic", true), solver_set = true;
    }
    else
    {
      if(options.get_bool_option("smt1"))
      {
	options.set_option("boolector", true), solver_set = true;
      }
      else
      {
	assert(options.get_bool_option("smt2"));
	options.set_option("mathsat", true), solver_set = true;
      }
    }
  }
  // Either have solver and standard version set, or neither.
  assert(version_set == solver_set);

  if(cmdline.isset("beautify"))
    options.set_option("beautify", true);

  if(cmdline.isset("no-sat-preprocessor"))
    options.set_option("sat-preprocessor", false);
  else
    options.set_option("sat-preprocessor", true);

  options.set_option("pretty-names",
                     !cmdline.isset("no-pretty-names"));

  if(cmdline.isset("outfile"))
    options.set_option("outfile", cmdline.get_value("outfile"));

  if(cmdline.isset("graphml-cex"))
    options.set_option("graphml-cex", cmdline.get_value("graphml-cex"));
}

/*******************************************************************\

Function: cbmc_parse_optionst::DFS_dependence

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::vector<int> cbmc_parse_optionst::DFS_dependence(
    		std::vector<int> properties,
    		std::vector<std::vector<int>> dependencies,
    		std::vector<int> &alone_vars)
{
	std::vector<int> r;
	bool checked[dependencies.size() + 10];
	memset(checked, false, sizeof checked);


	// sequential programs
//	return properties;


	// concurrent programs
	std::cout << "Start DFS_dependence: " << properties.size() << "\n";
	for (std::vector<int>::iterator i = properties.begin(); i != properties.end(); ++i)
	{
		std::vector<int> partial_result = DFS_dependence_1(*i, dependencies,
		    checked);

		std::cout << "partial_result: " << partial_result.size() << std::endl;
		if (partial_result.size() <= 1 && dependencies[*i].size() < 1)
		{
			// alone variables
			alone_vars.push_back(*i);
		}

		for (std::vector<int>::iterator it = partial_result.begin();
		    it != partial_result.end(); ++it)
		{
			r.push_back(*it);
		}
	}
	return r;
}

/*******************************************************************\

Function: cbmc_parse_optionst::DFS_dependence

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::vector<int> cbmc_parse_optionst::DFS_dependence(
			int property, std::vector<std::vector<int>> dependencies, bool checked[])
{
	std::vector<int> q;
	q.push_back(property);
	checked[property] = true;

	int pos = 0;
	while (pos < q.size())
	{
		int current = q.at(pos++);
		for (int i = 0 ; i < dependencies[current].size(); ++i)
			if (checked[dependencies[current][i]] == false)
			{
				checked[dependencies[current][i]] = true;
				q.push_back(dependencies[current][i]);
			}
	}
	return q;
}

/*******************************************************************\

Function: cbmc_parse_optionst::DFS_dependence

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::vector<int> cbmc_parse_optionst::DFS_dependence_1(
			int property, std::vector<std::vector<int>> dependencies, bool checked[])
{
	std::vector<int> q;
	q.push_back(property);
	checked[property] = true;
	for (int i = 0; i < dependencies[property].size(); ++i)
		if (checked[dependencies[property][i]] == false)
		{
			checked[dependencies[property][i]] = true;
			q.push_back(dependencies[property][i]);
		}
	return q;
}

/*******************************************************************\

Function: has_element

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
bool has_element(std::vector<int> v, int element)
{
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		if (*it == element)
			return true;
	}
	return false;
}

void cbmc_parse_optionst::edit_CFG(std::vector<std::string> lines)
{
	for (int i = 0; i < lines.size(); ++i)
		if (lines[i].find('}') != std::string::npos)
		{
			// create a path from previous line to it
			int pos = i - 1;
			while (lines[pos].size() == 0)
			{
				pos++;
			}
			// if doesnt have connection
			if (!has_element(CFG[pos + 1], i + 1))
			{
//				std::cout << "Update CFG: " << pos + 1 << " " << i + 1 << std::endl;
				CFG.at(pos + 1).push_back(i + 1);
			}

			for (int j = 0; j < CFG.at(pos + 1).size(); ++j)
				if (!has_element(CFG[i + 1], CFG[pos + 1][j]) && CFG[pos + 1][j] != i + 1)
				{
					CFG[i + 1].push_back(CFG[pos + 1][j]);
				}
		}

//	for (int i = 0 ; i < lines.size(); ++i)
//	  {
//	  	std::cout << i << ": ";
//	  	for (int j = 0; j < CFG[i].size(); ++j)
//	  		std::cout << CFG[i][j] << " ";
//	  	std::cout << std::endl;
//	  }
}

/*******************************************************************\

Function: cbmc_parse_optionst::doit()

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
int cbmc_parse_optionst::doit()
{
	std::vector<variable_struct> variables;
  optionst options;
  get_command_line_options(options);
  eval_verbosity();

  register_languages();

  goto_functionst goto_functions;
  bmct bmc(options, symbol_table, ui_message_handler);
  int get_goto_program_ret = get_goto_program(options, bmc, goto_functions);

  std::vector<std::string> lines;
  read_program(cmdline.args[cmdline.args.size() - 1], lines);
	/*
	 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	 */
  namespacet ns(symbol_table);
	variables = get_variables();

	// check if an array is exist
	bool have_array = false;
	for (std::vector<variable_struct>::const_iterator it = variables.begin(); it != variables.end(); ++it)
		if (it->type == 2)
		{
			have_array = true;
			break;
		}

	std::vector<std::pair<std::string, std::string>> tmp_properties = get_properties(ns, goto_functions);
	std::vector<int> properties_1;
	std::vector<variable_struct> properties_2;
	// filer
	for (int i = 0; i < tmp_properties.size(); ++i)
	{
		bool found = false;
		for (int j = 0 ; j < variables.size(); ++j)
		{
			// find local var
			if (tmp_properties[i].first.compare(variables[j].name) == 0
			    && tmp_properties[i].second.compare(variables[j].proc) == 0)
			{
				properties_1.push_back(j);
				found = true;
				break;
			}
		}

		if (found == false)
		{
			for (int j = 0; j < variables.size(); ++j)
			{
				// find global var
				if (tmp_properties[i].first.compare(variables[j].name) == 0
				    && variables[j].proc.size() == 0)
				{
					properties_1.push_back(j);
					found = true;
					break;
				}
			}
		}
	}

	label_properties(goto_functions);

	std::vector<std::vector<int>> dependencies;
	if (!have_array)
		dependencies = goto_functions.get_dependencies(variables, ns, lines);

	// TODO: select variables for slicing
	// --> use properties
	std::vector<int> alone_variables;
	std::vector<int> slice_variables;
	if (!have_array)
		slice_variables = DFS_dependence(properties_1, dependencies, alone_variables);

	for (int i = 0; i < variables.size(); ++i)
		if (variables[i].type == -1)
			// we have a thread
			slice_variables.push_back(i);

	std::cout << "Slice variables: \n";
	for (int i = 0 ; i < slice_variables.size(); ++i)
		if (variables[slice_variables[i]].name.find('$') == std::string::npos ||
				variables[slice_variables[i]].name.find("main") != std::string::npos)
	{
		properties_2.push_back(variables[slice_variables[i]]);
		std::cout << variables[slice_variables[i]].name << std::endl;
	}

	std::cout << "Alone variables: \n";
	std::vector<variable_struct> alone_vars;
	for (int i = 0 ; i < alone_variables.size(); ++i)
	{
		std::cout << variables[alone_variables[i]].name << std::endl;
		alone_vars.push_back(variables[alone_variables[i]]);
	}
	std::vector<int> slicing_lines;
	// doing slicing
	if (have_array == true)
	{
		properties_2 = variables;
		for (int i = 0; i < lines.size(); ++i)
			slicing_lines.push_back(0);
	}
	else
		slicing_lines = goto_functions.slice_variable(ns, properties_2, variables);

	for (int i = 0 ; i < slicing_lines.size(); ++i)
		std::cout << i << ":-> " << slicing_lines[i] << std::endl;
	std::vector<int> lines_map;
	slice_program(slicing_lines,variables, properties_2, lines_map, lines);
	/*
	 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	 */
	cmdline.args.at(cmdline.args.size() - 1) = "//Users//diepbp//Desktop//test//slicing_init.c";

	// edit CFG
	edit_CFG(lines);

	// clear data
	language_files.clear();
	symbol_table.clear();

//	return 1;
  return do_slice(variables, lines_map, lines, CFG, slicing_lines, alone_vars);
}

/*******************************************************************\

Function: cbmc_parse_optionst::doit

  Inputs:

 Outputs:

 Purpose: invoke main modules

\*******************************************************************/

int cbmc_parse_optionst::do_slice(
		std::vector<variable_struct> variables,
		std::vector<int> lines_map,
		std::vector<std::string> lines,
		std::vector<std::vector<int>> original_CFG,
		std::vector<int> slicing_lines,
		std::vector<variable_struct> alone_vars)
{
  if(cmdline.isset("version"))
  {
    std::cout << CBMC_VERSION << std::endl;
    return 0;
  }

  //
  // command line options
  //

  optionst options;
  get_command_line_options(options);
  eval_verbosity();

  //
  // Print a banner
  //
  status() << "CBMC version " CBMC_VERSION " "
           << sizeof(void *)*8 << "-bit "
           << config.this_architecture() << " "
           << config.this_operating_system() << eom;

  //
  // Unwinding of transition systems is done by hw-cbmc.
  //

  if(cmdline.isset("module") ||
     cmdline.isset("gen-interface"))

  {
    error() << "This version of CBMC has no support for "
               " hardware modules. Please use hw-cbmc." << eom;
    return 1;
  }

  register_languages();

  if(cmdline.isset("test-preprocessor"))
    return test_c_preprocessor(ui_message_handler)?8:0;

  if(cmdline.isset("preprocess"))
  {
    preprocessing();
    return 0;
  }

  goto_functionst goto_functions;
  bmct bmc(options, symbol_table, ui_message_handler);
  int get_goto_program_ret=
    get_goto_program(options, bmc, goto_functions);

  if(get_goto_program_ret!=-1)
    return get_goto_program_ret;

  label_properties(goto_functions);

  if(cmdline.isset("show-claims") || // will go away
     cmdline.isset("show-properties")) // use this one
  {
    const namespacet ns(symbol_table);
    show_properties(ns, get_ui(), goto_functions);
    return 0;
  }

  if(cmdline.isset("show-reachable-properties")) // may replace --show-properties
  {
    const namespacet ns(symbol_table);

    // Entry point will have been set before and function pointers removed
    status() << "Removing Unused Functions" << eom;
    remove_unused_functions(goto_functions, ui_message_handler);

    show_properties(ns, get_ui(), goto_functions);
    return 0;
  }

  if(set_properties(goto_functions))
    return 7;

  if(cmdline.isset("cegis"))
  {
    ga_learning_algorithmt learning_algorithm;
    bmc_verification_oraclet verification_oracle(bmc, goto_functions);
    return run_cegis(learning_algorithm, verification_oracle, result());
  }
  namespacet ns(symbol_table);

  // do actual BMC
  return do_bmc(bmc, goto_functions, variables, lines_map, lines, original_CFG, slicing_lines, alone_vars);
}

/*******************************************************************\

Function: cbmc_parse_optionst::set_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool cbmc_parse_optionst::set_properties(goto_functionst &goto_functions)
{
  try
  {
    if(cmdline.isset("claim")) // will go away
      ::set_properties(goto_functions, cmdline.get_values("claim"));

    if(cmdline.isset("property")) // use this one
      ::set_properties(goto_functions, cmdline.get_values("property"));
  }

  catch(const char *e)
  {
    error() << e << eom;
    return true;
  }

  catch(const std::string e)
  {
    error() << e << eom;
    return true;
  }

  catch(int)
  {
    return true;
  }

  return false;
}

std::vector<std::string> parse_string_parse_options(std::string s)
{
	std::vector<std::string> result;
	char *str = new char[s.size() + 1];
	str[s.size()] = 0;
	memcpy(str, s.c_str(), s.size());

	char* pch;
	pch = strtok(str, " !+-*/!&|><=();,\t");

	while (pch != NULL)
	{
		result.push_back(pch);
		pch = strtok(NULL, " ;=!()&|+-*/<>,\t");
	}

	return result;
}

std::vector<std::string> parse_call_parse_options(std::string s)
{
	std::vector<std::string> result;
	char *str = new char[s.size() + 1];
	str[s.size()] = 0;
	memcpy(str, s.c_str(), s.size());

	char* pch;
	pch = strtok(str, " &!+-/!|><();,\t");

	while (pch != NULL)
	{
		result.push_back(pch);
		pch = strtok(NULL, " &;!()|+-/<>,\t");
	}

	return result;
}

std::vector<std::string> parse_other_call_parse_options(std::string s)
{
	std::vector<std::string> result;
	char *str = new char[s.size() + 1];
	str[s.size()] = 0;
	memcpy(str, s.c_str(), s.size());

	char* pch;
	pch = strtok(str, " !+-/!|><();,\t");

	while (pch != NULL)
	{
		result.push_back(pch);
		pch = strtok(NULL, " ;!()|+-/<>,\t");
	}

	return result;
}

std::vector<std::string> parse_assignment_parse_options(std::string s)
{
	std::vector<std::string> result;
	char *str = new char[s.size() + 1];
	str[s.size()] = 0;
	memcpy(str, s.c_str(), s.size());

	char* pch;
	pch = strtok(str, " !+-*/!&|><();\t,");

	while (pch != NULL)
	{
		result.push_back(pch);
		pch = strtok(NULL, " ;!()&|+-*/<>\t,");
	}

	return result;
}


variable_struct get_variable(std::string s, std::vector<variable_struct> list)
{
	// TODO we do not handle local variables now, they may have the same name
	for (std::vector<variable_struct>::iterator it = list.begin(); it != list.end(); ++it)
		if ((*it).name.compare(s) == 0)
			return *it;
	return variable_struct();
}

bool has_token_parse_options(std::string s, std::vector<std::string> list)
{
	for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
		if ((*it).compare(s) == 0)
			return true;
	return false;
}


bool is_variable_cbmc_parse_options(std::string s, std::vector<variable_struct> variables)
{
	for (std::vector<variable_struct>::iterator it = variables.begin(); it != variables.end(); ++it)
	{
		if ((*it).name.compare(s) == 0)
			return true;
	}
	return false;
}

bool is_selected_variable_cbmc_parse_options(variable_struct t, std::vector<variable_struct> selected_variables)
{
	for (std::vector<variable_struct>::iterator it = selected_variables.begin(); it != selected_variables.end(); ++it)
	{
		if ((*it).name.compare(t.name) == 0 &&
				(it->proc.size() == 0 ||
				 it->proc.compare(t.proc) == 0))
			return true;
	}
	return false;
}

bool contain_parse_options(std::string s, std::vector<variable_struct> selected_variables)
{
	for (std::vector<variable_struct>::iterator it = selected_variables.begin(); it != selected_variables.end(); ++it)
	{
		if ((*it).name.compare(s) == 0)
			return true;
	}
	return false;
}

std::vector<std::string> line_to_proc(std::vector<std::string> lines)
{
	int bracket_counter = 0;
	std::string procedure_name;
	std::vector<std::string> result;
	for (int j = 0; j < lines.size(); ++j)
	{
		for (int i = 0; i < lines[j].size(); ++i)
		{
			if (lines[j][i] == '{')
			{
				if (bracket_counter == 0)
				{
					// procedure definition
					// --> get procedure name
					std::string line;
					if (lines[j].find('(') != std::string::npos)
						line = lines[j];
					else
					{
						// go back
						int k = j;
						for (k = j - 1; k >= 0; --k)
							if (lines[k].find('(') != std::string::npos &&
									lines[k].find(')') != std::string::npos)
							{
								line = lines[k];
								break;
							}
					}
					std::vector<std::string> token = parse_string_parse_options(line);

					// find the token before "("
					for (int bracket = 0; bracket < token.size(); ++bracket)
					{
						std::size_t token_pos = line.find(token[bracket]);
						if (line[token_pos + token[bracket].size()] == '(')
						{
							procedure_name = token[bracket];
							break;
						}
					}
				}
				bracket_counter++;
			}
			else if (lines[j][i] == '}')
			{
				bracket_counter--;
				if (bracket_counter == 0)
					procedure_name = "";
			}
		}
		result.push_back(procedure_name);
	}
	return result;
}

/*******************************************************************\

Function: cbmc_parse_optionst::is_procedure_call

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
bool cbmc_parse_optionst::is_procedure_call(std::string line)
{
	bool is_call = false;
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

Function: cbmc_parse_optionst::optimize_code

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
bool check_remove_block(int line, int i, int &counter, bool &assignment, std::vector<std::string> &lines)
{
	if (lines.at(i)[0] == '}' &&
			counter == 1)
		counter--;
	std::cout << i << ": " << lines[i] << std::endl;
	if (counter == 0 && assignment == false)
	{
		for (int k = line; k <= i; ++k)
		{
			lines[k] = "";
		}
		return true;
	}
	return false;
}
/*******************************************************************\

Function: cbmc_parse_optionst::optimize_code

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
int cbmc_parse_optionst::handle_block(
		int line,
		std::vector<std::string> &lines)
{
	int counter = 0;
	bool assignment = false;
	int i = line;
	while (i < lines.size())
	{
		std::vector<std::string> tokens = parse_string_parse_options(lines[i]);
		if ((has_token_parse_options("if", tokens) ||
				has_token_parse_options("while", tokens) ||
				has_token_parse_options("else", tokens)) &&
				i != line)
		{
			int last_line = handle_block(i, lines);

			// check block because of: } else... -> }
			std::cout << "new block: " << i << " " << last_line << std::endl;
			bool removed = check_remove_block(line, i, counter, assignment, lines);
					if (removed)
						return i;

			assignment = assignment || last_line < 0;
			if (abs(last_line) == i)
				i++;
			else
				i = abs(last_line);

				continue;
		}

		if (lines[i].size() > 0)
		{
			if (has_token_parse_options("assert", tokens) ||
					has_token_parse_options("assume", tokens) ||
					has_token_parse_options("return", tokens) ||
					has_token_parse_options("break", tokens) ||
					has_token_parse_options("continue", tokens) ||
					has_token_parse_options("exit", tokens) ||
					has_token_parse_options("pthread_create", tokens)
					)
			{
				std::cout << "not remove: " << lines[i] << std::endl;
				assignment = true;
			}
			else
			for (int j = 0 ; j < lines[i].size() - 1; ++j)
			{
				if (lines[i][j + 1] == '=' &&
						lines[i][j] != '=' &&
						lines[i][j + 2] != '=' &&
						lines[i][j] != '<' &&
						lines[i][j] != '!') // still missing "for" loop
				{
					assignment = true;
				}
				else if (lines[i][j + 1] == ';' && counter == 0)
				{
					return -i;
				}
				else if (lines[i][j + 1] == '{')
				{
					counter++;
				}
				else if (lines[i][j + 1] == '}' && counter > 0)
				{
					counter--;
					// end block
					if (counter == 0)
					{
						// empty block
						if (assignment == false)
						{
							// remove all line
							std::cout << line << " to " << i << std::endl;
							// handle "} else"
							bool keep_bracket = false;
							std::size_t else_pos = lines[line].find("else");
							if (else_pos != std::string::npos)
							{
								std::size_t bracket_pos = lines[line].find("}");
								if (bracket_pos != std::string::npos)
									if (bracket_pos < else_pos)
										keep_bracket = true;
							}
							if (keep_bracket)
								lines[line] = "}";
							else
								lines[line] = "";

							// handle remaining
							for (int k = line + 1; k <= i; ++k)
							{
								std::cout << lines[k] << std::endl;
								lines[k] = "";
							}
							std::cout << "out block [remove]: " << i << ":" << lines[i] << std::endl;

							return i;
						}
						std::cout << "out block [not remove]: " << i << ":" << lines[i] << std::endl;
						return -i;
					}
				}
			}
		}
		i++;
	}
	std::cout << "out block [error]: " << i << ":" << lines[i] << std::endl;
	return assignment;
}

/*******************************************************************\

Function: cbmc_parse_optionst::optimize_code

  Inputs:

 Outputs:

 Purpose: remove all empty "while" and "if"

\*******************************************************************/
void cbmc_parse_optionst::optimize_while_if(
		std::vector<std::string> &lines)
{
	int counter = 1, i;
	bool assignment = false;
	for (i = 1; i < lines.size(); ++i)
		if (lines[i].find('{') != std::string::npos)
			break;

	i++;
	while (i < lines.size())
	{
		std::vector<std::string> tokens = parse_string_parse_options(lines[i]);
		if (has_token_parse_options("if", tokens)
		    || has_token_parse_options("while", tokens)
		    || has_token_parse_options("else", tokens))
		{
			std::cout << "here111: " << i << " " << lines[i] << std::endl;
			int last_line = handle_block(i, lines);
			assignment = assignment || last_line < 0;
			i = abs(last_line) + 1;
			continue;
		}
		else if (lines[i].find('}') != std::string::npos)
		{
			counter--;
			if (counter == 0)
			// end of procedure
			// --> go to new procedure
			for (int j = i; j < lines.size(); ++j)
				if (lines[j].find('{') != std::string::npos)
				{
					i = j;
					counter = 1;
					break;
				}
		}
		i++;
	}
}

/*******************************************************************\

Function: cbmc_parse_optionst::optimize_code

  Inputs:

 Outputs:

 Purpose: remove all empty "while" and "if"

\*******************************************************************/
void cbmc_parse_optionst::optimize_atomic(
		std::vector<std::string> &lines)
{
	int counter = 0, i;
	bool assignment = false;
	for (i = 1; i < lines.size(); ++i)
		if (lines[i].find('{') != std::string::npos)
			break;

	i++;
	int first_line = -1, last_line = -1;
	while (i < lines.size())
	{
//		std::cout << "at line " << i << ":" << lines[i] << std::endl;
		std::vector<std::string> tokens = parse_string_parse_options(lines[i]);
		if (has_token_parse_options("__VERIFIER_atomic_begin", tokens) &&
				!has_token_parse_options("void", tokens))
		{
			first_line = i;
		}
		else if (has_token_parse_options("__VERIFIER_atomic_end", tokens) &&
				!has_token_parse_options("void", tokens))
		{
			last_line = i;

			if (counter <= 1)
			{
				lines.at(first_line) = "";
				lines.at(last_line) = "";
			}
			counter = 0;
			first_line = -1;
		}
		else
			if (tokens.size() > 1 && first_line != -1)
				counter++;
		i++;
	}
}

/*******************************************************************\

Function: cbmc_parse_optionst::read_program

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
void cbmc_parse_optionst::read_program(std::string file_name, std::vector<std::string> &lines)
{
	std::ifstream t(file_name);
	int length;

	std::string str;
	while (std::getline(t, str))
	{
		lines.push_back(str);
	}
	t.close();
}
/*******************************************************************\

Function: cbmc_parse_optionst::parse_program

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void cbmc_parse_optionst::slice_program(
		std::vector<int> slicing_lines,
		std::vector<variable_struct> variables,
		std::vector<variable_struct> selected_variables,
		std::vector<int> &lines_map,
		std::vector<std::string> &lines)
{
	std::vector<std::string> bak_lines = lines;

	std::vector<std::string> lines_to_proc = line_to_proc(lines);

	bool insert_nondet_int = false;
	bool insert_nondet_bool = false;
	bool empty_atomic = false;

	int begin_atomic = -1;

	// TODO change the program
	for (int i = 0; i < lines.size(); ++i)
	{
		if (slicing_lines[i + 1] > 0)
		{
			std::vector<std::string> token;
			std::vector<variable_struct> tmp_variables;
			std::string this_line;
			std::size_t pos;
			int counter_bracket = 0;
			std::string condition = "";

			// we need to edit it
			switch (slicing_lines[i + 1]) {
				case Guard:
					std::cout << i + 1 << ": " << slicing_lines[i + 1] << " " << lines[i] << std::endl;
					token = parse_string_parse_options(lines[i]);
					// find
					if (has_token_parse_options("while", token))
						pos = lines[i].find("while");
					else if (has_token_parse_options("if", token))
						pos = lines[i].find("if");
					else if (has_token_parse_options("assume", token))
						pos = lines[i].find("assume");
					else if (has_token_parse_options("__VERIFIER_assume", token))
						pos = lines[i].find("__VERIFIER_assume");
					else if (has_token_parse_options("__CPROVER_assume", token))
						pos = lines[i].find("__CPROVER_assume");

					for (int j = pos; j < lines[i].size(); ++j)
						if (lines[i][j] == '(')
						{
							pos = j;
							break;
						}

					for (int j = pos; j < lines[i].size(); ++j)
					{
						condition = condition + lines[i][j];
						if (lines[i][j] == '(')
							counter_bracket++;
						else if (lines[i][j] == ')')
						{
							counter_bracket--;
							if (counter_bracket == 0)
								break;
						}
					}

					// replace
					lines[i].replace(pos, condition.size(), "(nondet_bool())");
					insert_nondet_bool = true;
					break;

				case Call:
				case CallnLeftAssign:
					//only keep procedure call
					token = parse_assignment_parse_options(lines[i]);
					this_line = lines[i];
					std::cout << "Call: " << this_line << std::endl;

					if (this_line.find("__VERIFIER_atomic_begin") != std::string::npos)
					{
						begin_atomic = i;
						break;
					}
					else if (this_line.find("__VERIFIER_atomic_end") != std::string::npos)
					{
						bool empty_block = true;
						for (int atm = begin_atomic + 1; atm < i; ++atm)
						{
							if (lines[atm].size() > 0)
							{
								empty_block = false;
								break;
							}
						}

						if (empty_block == true)
						{
							lines.at(begin_atomic) = "";
							lines.at(i) = "";
							std::cout << "Removing from " << begin_atomic << " to " << i << std::endl;
						}

						begin_atomic = -1;
						break;
					}

					// only keep variables
					for (std::vector<std::string>::iterator it = token.begin(); it != token.end(); it++)
					{
						for (int k = 0; k < variables.size(); ++k)
							if ((*it).compare(variables[k].name) == 0
									&& (variables[k].proc.size() == 0
											|| variables[k].proc.compare(lines_to_proc[i]) == 0))
							{
								tmp_variables.push_back(variables[k]);
								break;
							}
					}
					for (std::vector<variable_struct>::iterator it = tmp_variables.begin();
							it != tmp_variables.end();)
					{
						if (!is_selected_variable_cbmc_parse_options(*it, selected_variables))
							++it;
						else
							it = tmp_variables.erase(it);
					}

					// find the token before "("
					for (int bracket = 0; bracket < token.size(); ++bracket)
					{
						std::size_t token_pos = this_line.find(token[bracket]);
						if (this_line[token_pos + token[bracket].size()] == '(')
						{
							std::size_t open = this_line.find('(');
							std::size_t close = this_line.find(')');
							std::string arguments = this_line.substr(open, close - open + 1);
							this_line = token[bracket];
							std::cout << "cut string: " << arguments << " " << tmp_variables.size() << std::endl;

							this_line = this_line + "(";

							std::vector<std::string> arguments_token = parse_call_parse_options(arguments);
							std::vector<std::string> other_arguments_token = parse_other_call_parse_options(arguments);

							if (arguments_token.size() != other_arguments_token.size())
							{
								std::cout << "ERROR in arguments_token.size() != other_arguments_token.size()" << std::endl;
							}
							for (int element = 0; element < arguments_token.size(); ++element){
								if (contain_parse_options(arguments_token[element], tmp_variables))
								{
									if (element == 0)
										this_line = this_line + "__VERIFIER_nondet_int()";
									else
										this_line = this_line + ", __VERIFIER_nondet_int()";
								}
								else
								{
									if (element == 0)
										this_line = this_line + other_arguments_token[element];
									else
										this_line = this_line + ", " +  other_arguments_token[element];
								}
							}

							this_line = this_line + ");";
							lines.at(i) = this_line;
							std::cout << "after edit call command: " << this_line << std::endl;
							break;
						}
					}
					break;

				case Decl:
					break;

				case LeftAssign:
					lines.at(i) = "";
					break;

				case RightAssign:
					token = parse_assignment_parse_options(lines[i]);
					for (int k = 0; k < token.size(); ++k)
					{
						if (token[k].compare("=") == 0)
						{
							if (i > 0)
							{
								std::string variable = token[k - 1];

								variable_struct v = get_variable(variable, variables);
								std::size_t equal_symbol = lines[i].find('=');
								std::string s = lines[i].substr(0, equal_symbol);
								if (v.type == 1)
								{
									s = s + "= nondet_int();";
									insert_nondet_int = true;
								}
								else
								{
									s = s + "= nondet_bool();";
									insert_nondet_bool = true;
								}
								lines.at(i) = s;
								break;
							}
						}
					}
					break;

				case Return:
					//TODO
					lines.at(i) = "return nondet_bool();";
					break;

				case Remove_Atomic:
					lines.at(i) = "";
					break;


				default:
					break;
			}
		}
	}

	optimize_while_if(lines);
	optimize_atomic(lines);

	int added_lines = 0;
	if (insert_nondet_bool == true)
	{
		// check existence
		bool found = false;
		for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it)
			if ((*it).compare("_Bool nondet_bool();") == 0)
			{
				found = true;
				break;
			}
		if (found == false)
		{
			added_lines++;
			lines.insert(lines.begin(), "_Bool nondet_bool();");
		}
	}

	if (insert_nondet_int == true)
	{
		// check existence
		bool found = false;
		for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it)
			if ((*it).compare("int nondet_int();") == 0)
			{
				found = true;
				break;
			}
		if (found == false)
		{
			added_lines++;
			lines.insert(lines.begin(), "int nondet_int();");
		}
	}

	for (int i = 0; i < lines.size(); ++i)
	{
//		std::cout << lines[i] << std::endl;
		lines_map.push_back(i-added_lines);
	}

	// write to file
	std::ofstream writer;
	writer.open("//Users//diepbp//Desktop//test//slicing_init.c");
	for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); ++it)
	{
		writer << (*it) << std::endl;
	}
	writer.close();

	lines = bak_lines;
}

/*******************************************************************\

Function: cbmc_parse_optionst::get_goto_program

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
int cbmc_parse_optionst::get_goto_program(
  const optionst &options,
  bmct &bmc, // for get_modules
  goto_functionst &goto_functions)
{
  if(cmdline.args.empty())
  {
    error() << "Please provide a program to verify" << eom;
    return 6;
  }

  try
  {
    if(cmdline.args.size()==1 &&
       is_goto_binary(cmdline.args[0]))
    {
      status() << "Reading GOTO program from file" << eom;

      if(read_goto_binary(cmdline.args[0],
           symbol_table, goto_functions, get_message_handler()))
        return 6;

      config.ansi_c.set_from_symbol_table(symbol_table);

      if(cmdline.isset("show-symbol-table"))
      {
        show_symbol_table();
        return 0;
      }

      irep_idt entry_point=goto_functions.entry_point();

      if(symbol_table.symbols.find(entry_point)==symbol_table.symbols.end())
      {
        error() << "The goto binary has no entry point; please complete linking" << eom;
        return 6;
      }
    }
    else if(cmdline.isset("show-parse-tree"))
    {
      if(cmdline.args.size()!=1)
      {
        error() << "Please give one source file only" << eom;
        return 6;
      }

      std::string filename=cmdline.args[0];

      #ifdef _MSC_VER
      std::ifstream infile(widen(filename).c_str());
      #else
      std::ifstream infile(filename.c_str());
      #endif

      if(!infile)
      {
        error() << "failed to open input file `" << filename << "'" << eom;
        return 6;
      }

      languaget *language=get_language_from_filename(filename);

      if(language==NULL)
      {
        error() << "failed to figure out type of file `" <<  filename << "'" << eom;
        return 6;
      }

      language->set_message_handler(get_message_handler());

      status("Parsing", filename);

      if(language->parse(infile, filename))
      {
        error() << "PARSING ERROR" << eom;
        return 6;
      }

      language->show_parse(std::cout);
      return 0;
    }
    else
    {
      if(parse()) return 6;
      if(typecheck()) return 6;
      int get_modules_ret=get_modules(bmc);
      if(get_modules_ret!=-1) return get_modules_ret;
      if(final()) return 6;

      // we no longer need any parse trees or language files
      clear_parse();

      if(cmdline.isset("show-symbol-table"))
      {
        show_symbol_table();
        return 0;
      }

      irep_idt entry_point=goto_functions.entry_point();

      if(symbol_table.symbols.find(entry_point)==symbol_table.symbols.end())
      {
        error() << "No entry point; please provide a main function" << eom;
        return 6;
      }

      status() << "Generating GOTO Program" << eom;

      goto_convert(symbol_table, goto_functions, ui_message_handler);
    }


    if(process_goto_program(options, goto_functions))
      return 6;
  }

  catch(const char *e)
  {
    error() << e << eom;
    return 6;
  }

  catch(const std::string e)
  {
    error() << e << eom;
    return 6;
  }

  catch(int)
  {
    return 6;
  }

  catch(std::bad_alloc)
  {
    error() << "Out of memory" << eom;
    return 6;
  }

  return -1; // no error, continue
}

/*******************************************************************\

Function: cbmc_parse_optionst::preprocessing

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void cbmc_parse_optionst::preprocessing()
{
  try
  {
    if(cmdline.args.size()!=1)
    {
      error() << "Please provide one program to preprocess" << eom;
      return;
    }

    std::string filename=cmdline.args[0];

    std::ifstream infile(filename.c_str());

    if(!infile)
    {
      error() << "failed to open input file" << eom;
      return;
    }

    languaget *ptr=get_language_from_filename(filename);

    if(ptr==NULL)
    {
      error() << "failed to figure out type of file" << eom;
      return;
    }

    ptr->set_message_handler(get_message_handler());

    std::unique_ptr<languaget> language(ptr);

    if(language->preprocess(infile, filename, std::cout))
      error() << "PREPROCESSING ERROR" << eom;
  }

  catch(const char *e)
  {
    error() << e << eom;
  }

  catch(const std::string e)
  {
    error() << e << eom;
  }

  catch(int)
  {
  }

  catch(std::bad_alloc)
  {
    error() << "Out of memory" << eom;
  }
}

/*******************************************************************\

Function: cbmc_parse_optionst::process_goto_program

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

bool cbmc_parse_optionst::process_goto_program(
  const optionst &options,
  goto_functionst &goto_functions)
{
	std::cout << "keng keng keng\n";
  try
  {
    namespacet ns(symbol_table);

    // Remove inline assembler; this needs to happen before
    // adding the library.
    remove_asm(symbol_table, goto_functions);

    // add the library
    status() << "Adding CPROVER library" << eom;
    link_to_library(symbol_table, goto_functions, ui_message_handler);

    if(cmdline.isset("string-abstraction"))
      string_instrumentation(
        symbol_table, get_message_handler(), goto_functions);

    // remove function pointers
    status() << "Function Pointer Removal" << eom;
    remove_function_pointers(symbol_table, goto_functions,
      cmdline.isset("pointer-check"));

    // do partial inlining
    status() << "Partial Inlining" << eom;
    goto_partial_inline(goto_functions, ns, ui_message_handler);

    // remove returns, gcc vectors, complex
    remove_returns(symbol_table, goto_functions);
    remove_vector(symbol_table, goto_functions);
    remove_complex(symbol_table, goto_functions);

    // add generic checks
    status() << "Generic Property Instrumentation" << eom;
    goto_check(ns, options, goto_functions);

    if(cmdline.isset("string-abstraction"))
    {
      status() << "String Abstraction" << eom;
      string_abstraction(symbol_table,
        get_message_handler(), goto_functions);
    }

    // add failed symbols
    // needs to be done before pointer analysis
    add_failed_symbols(symbol_table);

    // recalculate numbers, etc.
    goto_functions.update();

    // add loop ids
    goto_functions.compute_loop_numbers();

    // if we aim to cover, replace
    // all assertions by false to prevent simplification
    if(cmdline.isset("cover-assertions"))
      make_assertions_false(goto_functions);
    // show it?
    if(cmdline.isset("show-loops"))
    {
      show_loop_ids(get_ui(), goto_functions);
      return true;
    }

		/*
		 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		 */

		std::cout << "we going to get_CFG()";
		CFG = goto_functions.get_CFG(ns);

		/*
		 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		 * my code -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		 */

    // show it?
    if(cmdline.isset("show-goto-functions"))
    {
      goto_functions.output(ns, std::cout);
      return true;
    }



  }

  catch(const char *e)
  {
    error() << e << eom;
    return true;
  }

  catch(const std::string e)
  {
    error() << e << eom;
    return true;
  }

  catch(int)
  {
    return true;
  }

  catch(std::bad_alloc)
  {
    error() << "Out of memory" << eom;
    return true;
  }

  return false;
}

/*******************************************************************\

Function: cbmc_parse_optionst::do_bmc

  Inputs:

 Outputs:

 Purpose: invoke main modules

\*******************************************************************/

int cbmc_parse_optionst::do_bmc(
  bmct &bmc,
  const goto_functionst &goto_functions,
  std::vector<variable_struct> variables,
  std::vector<int> lines_map,
  std::vector<std::string> lines,
  std::vector<std::vector<int>> original_CFG,
  std::vector<int> slicing_lines,
  std::vector<variable_struct> alone_vars)
{
  bmc.set_ui(get_ui());

  // do actual BMC
  bool result=bmc.run(goto_functions, variables, lines_map, lines, original_CFG, slicing_lines, alone_vars);

  // let's log some more statistics
  debug() << "Memory consumption:" << messaget::endl;
  memory_info(debug());
  debug() << eom;

  // We return '0' if the property holds,
  // and '10' if it is violated.
  return result?10:0;
}

/*******************************************************************\

Function: cbmc_parse_optionst::help

  Inputs:

 Outputs:

 Purpose: display command line help

\*******************************************************************/

void cbmc_parse_optionst::help()
{
  std::cout <<
    "\n"
    "* *   CBMC " CBMC_VERSION " - Copyright (C) 2001-2014 ";

  std::cout << "(" << (sizeof(void *)*8) << "-bit version)";

  std::cout << "   * *\n";

  std::cout <<
    "* *              Daniel Kroening, Edmund Clarke             * *\n"
    "* * Carnegie Mellon University, Computer Science Department * *\n"
    "* *                 kroening@kroening.com                   * *\n"
    "* *        Protected in part by U.S. patent 7,225,417       * *\n"
    "\n"
    "Usage:                       Purpose:\n"
    "\n"
    " cbmc [-?] [-h] [--help]      show help\n"
    " cbmc file.c ...              source file names\n"
    "\n"
    "Frontend options:\n"
    " -I path                      set include path (C/C++)\n"
    " -D macro                     define preprocessor macro (C/C++)\n"
    " --preprocess                 stop after preprocessing\n"
    " --16, --32, --64             set width of int\n"
    " --LP64, --ILP64, --LLP64,\n"
    "   --ILP32, --LP32            set width of int, long and pointers\n"
    " --little-endian              allow little-endian word-byte conversions\n"
    " --big-endian                 allow big-endian word-byte conversions\n"
    " --unsigned-char              make \"char\" unsigned by default\n"
    " --show-parse-tree            show parse tree\n"
    " --show-symbol-table          show symbol table\n"
    " --show-goto-functions        show goto program\n"
    " --mm model                   set memory model (default: sc)\n"
    " --arch                       set architecture (default: "
                                   << configt::this_architecture() << ")\n"
    " --os                         set operating system (default: "
                                   << configt::this_operating_system() << ")\n"
    #ifdef _WIN32
    " --gcc                        use GCC as preprocessor\n"
    #endif
    " --no-arch                    don't set up an architecture\n"
    " --no-library                 disable built-in abstract C library\n"
    " --round-to-nearest           IEEE floating point rounding mode (default)\n"
    " --round-to-plus-inf          IEEE floating point rounding mode\n"
    " --round-to-minus-inf         IEEE floating point rounding mode\n"
    " --round-to-zero              IEEE floating point rounding mode\n"
    "\n"
    "Program instrumentation options:\n"
    " --bounds-check               enable array bounds checks\n"
    " --div-by-zero-check          enable division by zero checks\n"
    " --pointer-check              enable pointer checks\n"
    " --memory-leak-check          enable memory leak checks\n"
    " --signed-overflow-check      enable arithmetic over- and underflow checks\n"
    " --unsigned-overflow-check    enable arithmetic over- and underflow checks\n"
    " --float-overflow-check       check floating-point for +/-Inf\n"
    " --nan-check                  check floating-point for NaN\n"
    " --all-properties             report status of all properties\n"
    " --show-properties            show the properties\n"
    " --show-loops                 show the loops in the program\n"
    " --no-assertions              ignore user assertions\n"
    " --no-assumptions             ignore user assumptions\n"
    " --error-label label          check that label is unreachable\n"
    " --cover-assertions           check which assertions are reachable\n"
    " --mm MM                      memory consistency model for concurrent programs\n"
    "\n"
    "BMC options:\n"
    " --function name              set main function name\n"
    " --property id                only check one specific property\n"
    " --program-only               only show program expression\n"
    " --depth nr                   limit search depth\n"
    " --unwind nr                  unwind nr times\n"
    " --unwindset L:B,...          unwind loop L with a bound of B\n"
    "                              (use --show-loops to get the loop IDs)\n"
    " --show-vcc                   show the verification conditions\n"
    " --slice-formula              remove assignments unrelated to property\n"
    " --no-unwinding-assertions    do not generate unwinding assertions\n"
    " --partial-loops              permit paths with partial loops\n"
    " --no-pretty-names            do not simplify identifiers\n"
    " --graphml-cex filename       write the counterexample in GraphML format to filename\n"
    "\n"
    "Backend options:\n"
    " --dimacs                     generate CNF in DIMACS format\n"
    " --beautify                   beautify the counterexample (greedy heuristic)\n"
    " --smt1                       output subgoals in SMT1 syntax (experimental)\n"
    " --smt2                       output subgoals in SMT2 syntax (experimental)\n"
    " --boolector                  use Boolector (experimental)\n"
    " --mathsat                    use MathSAT (experimental)\n"
    " --cvc3                       use CVC3 (experimental)\n"
    " --cvc4                       use CVC4 (experimental)\n"
    " --yices                      use Yices (experimental)\n"
    " --z3                         use Z3 (experimental)\n"
    " --opensmt                    use OpenSMT (experimental)\n"
    " --refine                     use refinement procedure (experimental)\n"
    " --outfile filename           output formula to given file\n"
    " --arrays-uf-never            never turn arrays into uninterpreted functions\n"
    " --arrays-uf-always           always turn arrays into uninterpreted functions\n"
    "\n"
    "Other options:\n"
    " --version                    show version and exit\n"
    " --xml-ui                     use XML-formatted output\n"
    " --xml-interface              bi-directional XML interface\n"
    "\n";
}
