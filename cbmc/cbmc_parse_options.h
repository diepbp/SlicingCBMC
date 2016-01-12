/*******************************************************************\

Module: CBMC Command Line Option Processing

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#ifndef CPROVER_CBMC_PARSEOPTIONS_H
#define CPROVER_CBMC_PARSEOPTIONS_H

#include <util/ui_message.h>
#include <util/parse_options.h>

#include <langapi/language_ui.h>

#include "xml_interface.h"

class bmct;
class goto_functionst;
class optionst;

#define CBMC_OPTIONS \
  "(program-only)(function):(preprocess)(slice-by-trace):" \
  "(no-simplify)(unwind):(unwindset):(slice-formula)" \
  "(debug-level):(no-propagation)(no-simplify-if)" \
  "(document-subgoals)(outfile):(test-preprocessor)" \
  "D:I:" \
  "(depth):(partial-loops)(no-unwinding-assertions)(unwinding-assertions)" \
  "(bounds-check)(pointer-check)(div-by-zero-check)(memory-leak-check)" \
  "(signed-overflow-check)(unsigned-overflow-check)(float-overflow-check)(nan-check)" \
  "(no-assertions)(no-assumptions)" \
  "(xml-ui)(xml-interface)(vcd):" \
  "(smt1)(smt2)(fpa)(cvc3)(cvc4)(boolector)(yices)(z3)(opensmt)(mathsat)" \
  "(no-sat-preprocessor)" \
  "(no-pretty-names)(beautify)" \
  "(floatbv)(fixedbv)" \
  "(dimacs)(refine)(max-node-refinement):(aig)" \
  "(16)(32)(64)(LP64)(ILP64)(LLP64)(ILP32)(LP32)" \
  "(little-endian)(big-endian)" \
  "(show-goto-functions)(show-loops)" \
  "(show-symbol-table)(show-parse-tree)(show-vcc)" \
  "(show-claims)(claim):(show-properties)(show-reachable-properties)(property):" \
  "(all-claims)(all-properties)" \
  "(error-label):(verbosity):(no-library)" \
  "(version)" \
  "(cover-assertions)" \
  "(mm):" \
  "(i386-linux)(i386-macos)(i386-win32)(win32)(winx64)(gcc)" \
  "(ppc-macos)(unsigned-char)" \
  "(arrays-uf-always)(arrays-uf-never)" \
  "(string-abstraction)(no-arch)(arch):" \
  "(round-to-nearest)(round-to-plus-inf)(round-to-minus-inf)(round-to-zero)" \
  "(graphml-cex):" \
  "(decide)" // legacy, and will eventually disappear

class cbmc_parse_optionst:
  public parse_options_baset,
  public xml_interfacet,
  public language_uit
{
public:
	struct pair_string_compare {
	  bool operator() (const variable_struct& lhs, const variable_struct& rhs) const
		{
			int first = lhs.name.compare(rhs.name);


			if (first > 0)
				return true;
			else if (first < 0)
				return false;
			else if (first == 0)
			{
				int second = lhs.proc.compare(rhs.proc);
				if (second > 0)
					return true;
				else
					return false;
			}
			return false;
		}
	};

	virtual int doit();

  int do_slice(
  		std::vector<variable_struct> variables,
  		std::vector<int> lines_map,
  		std::vector<std::string> lines,
  		std::vector<std::vector<int>> original_CFG,
  		std::vector<int> slicing_lines);

  void edit_CFG(std::vector<std::string> lines);
	std::vector<int> DFS_dependence(std::vector<int> properties, std::vector<std::vector<int>> dependencies);
	std::vector<int> DFS_dependence(
			int property, std::vector<std::vector<int>> dependencies, bool checked[]);
	std::vector<int> DFS_dependence_1(
				int property, std::vector<std::vector<int>> dependencies, bool checked[]);

	void slice_program(std::string file_name,
			std::vector<int> slicing_lines,
			std::vector<variable_struct> variables,
			std::vector<variable_struct> selected_variables,
			std::vector<int> &lines_map,
			std::vector<std::string> &lines);

	void optimize_while_if(std::vector<std::string> &lines);

	void optimize_atomic(std::vector<std::string> &lines);

	int handle_block(
			int line,
			std::vector<std::string> &lines);

  virtual void help();

  cbmc_parse_optionst(int argc, const char **argv);
  cbmc_parse_optionst(
    int argc,
    const char **argv,
    const std::string &extra_options);

protected:
  virtual void register_languages();

  virtual void get_command_line_options(optionst &options);
	virtual int do_bmc(bmct &bmc,
			const goto_functionst &goto_functions,
	    std::vector<variable_struct> variables,
	    std::vector<int> lines_map,
	    std::vector<std::string> lines,
	    std::vector<std::vector<int>> original_CFG,
	    std::vector<int> slicing_lines);

  virtual int get_goto_program(
    const optionst &options,
    bmct &bmc,
    goto_functionst &goto_functions);

  virtual bool process_goto_program(
    const optionst &options,
    goto_functionst &goto_functions);
    
  bool set_properties(goto_functionst &goto_functions);
  
  void eval_verbosity();
  
  // get any additional stuff before finalizing
  virtual int get_modules(bmct &bmc)
  {
    return -1; // continue
  }
  
  void preprocessing();

  std::vector<std::vector<int>> CFG;
};

#endif
