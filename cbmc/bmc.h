/*******************************************************************\

Module: Bounded Model Checking for ANSI-C + HDL

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#ifndef CPROVER_CBMC_BMC_H
#define CPROVER_CBMC_BMC_H

#include <list>
#include <map>
#include <stack>

#include <util/hash_cont.h>
#include <util/options.h>

#include <solvers/prop/prop.h>
#include <solvers/prop/prop_conv.h>
#include <solvers/sat/cnf.h>
#include <solvers/sat/satcheck.h>
#include <solvers/smt1/smt1_dec.h>
#include <solvers/smt2/smt2_dec.h>
#include <langapi/language_ui.h>
#include <goto-symex/symex_target_equation.h>

#include "symex_bmc.h"
#define NMAX 100

struct TokenElement{
    TokenElement(int _lineNo, std::string _content, std::string _type) : lineNo(_lineNo), content(_content), type(_type){}

    int lineNo;
    std::string content;
    std::string type;
};


class CParser{
public:
    std::vector<TokenElement> tokenList;
    std::string automataFile;

    CParser(std::string _automataFile) :
        automataFile(_automataFile){

            init();
            readAutomata(automataFile);
        };

    CParser(){
        readAutomata(automataFile);
    };

    void readCFile(std::string fileName);
    bool readAutomata(std::string fileName);

    void findKeyword();
    std::vector<TokenElement> tokenHandler(std::string s, int lineNo);
private:

    std::map<std::string, std::string> keywords;
    std::map<int, int> rowLabels;
    std::map<std::string, int> colLabels;
    std::string tokenMap[NMAX];
    int transitionTable[NMAX][NMAX];
    bool finalStates[NMAX], putbackStates[NMAX];
    std::string temp = "";
    int state = 0;

    void init();
    int processError(int start, std::string error, std::string line);
    std::string findType(char ch);
    std::vector<char*> stringTokens(char* line);
};

struct command_data{
	int line_number;
	std::string condition;
	bool nondet_assign = false;

	command_data(int _line_number, std::string _condition, bool _nondet_assign)
	{
		line_number = _line_number;
		condition = _condition;
		nondet_assign = _nondet_assign;
	}

	command_data(int _line_number, std::string _condition)
	{
		line_number = _line_number;
		condition = _condition;
		nondet_assign = false;
	}

	command_data(int _line_number)
	{
		line_number = _line_number;
		condition = "";
		nondet_assign = false;
	}
};
struct procedure_data{
	std::string name;
	int instance;
	std::vector<command_data> commands;

	procedure_data(std::string _name, int _instance)
	{
		name = _name;
		instance = _instance;
	}

	procedure_data(std::string _name, int _instance, std::vector<command_data> _commands)
	{
		name = _name;
		instance = _instance;
		commands.clear();
		commands.insert(commands.begin(), _commands.begin(), _commands.end());
	}

	void set_commands(std::vector<command_data> _commands)
	{
		commands.clear();
		commands.insert(commands.begin(), _commands.begin(), _commands.end());
	}
};

class bmct:public messaget
{
public:
  bmct(
    const optionst &_options,
    const symbol_tablet &_symbol_table,
    message_handlert &_message_handler):
    messaget(_message_handler),
    options(_options),
    ns(_symbol_table, new_symbol_table),
    equation(ns),
    symex(ns, new_symbol_table, equation),
    ui(ui_message_handlert::PLAIN)
  {
    symex.constant_propagation=options.get_bool_option("propagation");
  }
 
  virtual bool run(
  		const goto_functionst &goto_functions,
  		std::vector<variable_struct> variables,
  		std::vector<int> lines_map,
  		std::vector<std::string> lines,
  		std::vector<std::vector<int>> CFG,
  		const std::vector<int> slicing_lines);

  virtual std::string get_condition_expr(const std::vector<std::string> lines,
  		int line1,
  		const std::list<goto_trace_stept>::iterator it,
  		const int line2);

  virtual ~bmct() { }

  // additional stuff   
  expr_listt bmc_constraints;  
  
  friend class cbmc_satt;
  friend class hw_cbmc_satt;
  friend class counterexample_beautification_greedyt;
  
  void set_ui(language_uit::uit _ui) { ui=_ui; }
  
protected:
  const optionst &options;  
  symbol_tablet new_symbol_table;
  namespacet ns;
  symex_target_equationt equation;
  symex_bmct symex;
  goto_tracet goto_trace;
  std::vector<std::string> error_conditions;
 
  // use gui format
  language_uit::uit ui;
  
  virtual decision_proceduret::resultt
    run_decision_procedure(prop_convt &prop_conv);

  virtual bool decide(
     const goto_functionst &,
     prop_convt &);

  virtual bool decide(
    const goto_functionst &,
    prop_convt &,
	    std::vector<variable_struct> variables,
	    std::vector<int> lines_map,
	    std::vector<std::string> lines,
	    std::vector<std::vector<int>> CFG,
	    const std::vector<int> slicing_lines);
    
  // the solvers we have
  virtual bool decide_default(const goto_functionst &,
  		std::vector<variable_struct> variables,
  			    std::vector<int> lines_map,
  			    std::vector<std::string> lines,
  			    std::vector<std::vector<int>> CFG,
  			    const std::vector<int> slicing_lines);
  virtual bool decide_bv_refinement(const goto_functionst &);
  virtual bool decide_aig(const goto_functionst &);
  virtual bool decide_smt1(const goto_functionst &);
  virtual bool decide_smt2(const goto_functionst &);
  smt1_dect::solvert get_smt1_solver_type() const;
  smt2_dect::solvert get_smt2_solver_type() const;
  virtual void smt1_convert(smt1_dect::solvert solver, std::ostream &out);
  virtual void smt2_convert(smt2_dect::solvert solver, std::ostream &out);
  virtual bool write_dimacs();
  virtual bool write_dimacs(std::ostream &out);
  
  // unwinding
  virtual void setup_unwind();

  virtual void do_unwind_module(
    decision_proceduret &decision_procedure);
  void do_conversion(prop_convt &solver);
  void update_conversion(
		prop_convt &prop_conv,
				const exprt new_expr,
				const exprt old_expr
		);
  prop_convt *solver_factory();

  virtual void show_vcc();
  virtual bool all_properties(
    const goto_functionst &goto_functions,
    prop_convt &solver,
    		std::vector<variable_struct> variables,
    		std::vector<int> lines_map,
    		std::vector<std::string> lines,
    		std::vector<std::vector<int>> CFG,
    		const std::vector<int> slicing_lines);

  virtual bool all_properties(
      const goto_functionst &goto_functions,
      prop_convt &solver);

  virtual void show_vcc(std::ostream &out);
  virtual void show_program();
  virtual void report_success();
  virtual void report_failure();

  virtual void error_trace(
    const prop_convt &prop_conv);
  
  void collect_error_trace(const prop_convt &prop_conv);

  // vacuity checks
  void cover_assertions(
    const goto_functionst &goto_functions,
    prop_convt &solver);

  friend class bmc_all_propertiest;

	void simulate_trace(goto_tracet goto_trace,
	    std::vector<variable_struct> variables,
	    std::vector<int> lines_map,
	    std::vector<std::string> lines,
	    std::vector<std::vector<int>> CFG,
	    const std::vector<int> slicing_lines);

	void simulate_trace_2(goto_tracet goto_trace,
	    std::vector<variable_struct> variables,
	    std::vector<int> lines_map,
	    std::vector<std::string> lines,
	    std::vector<std::vector<int>> CFG,
	    const std::vector<int> slicing_lines,

	    std::vector<int> atomic_sign);

	void simulate_trace_3(goto_tracet goto_trace,
	    std::vector<variable_struct> variables,
	    std::vector<int> lines_map,
	    std::vector<std::string> lines,
	    std::vector<std::vector<int>> CFG,
	    const std::vector<int> slicing_lines,

	    std::vector<int> atomic_sign);

	bool is_index_member_symbol(const exprt &src);

	std::vector<int> find_lines(int x, int y, std::vector<std::vector<int>> CFG, bool bak_checked[10000]);
	std::vector<std::string> parse_string_bmc(std::string s);
	bool has_token_bmc(std::string s, std::vector<std::string> list);
	void find_brackets(int line, std::vector<std::string> lines, int &start, int &finish);
	std::string generate_new_name(std::string name, int number);
	void insert_brackets(int line_number, std::vector<std::pair<int, int>> &brackets, std::vector<std::string> &procedure);
	bool is_procedure_call(std::string line);
	void reorder_atomic(std::vector<std::string> &procedure);
	void write_to_file(int counter, std::vector<std::vector<std::string>> text_file, std::vector<std::string> lines);
	void write_to_file(int counter, std::vector<procedure_data> new_file, std::vector<std::string> lines);
	void write_to_file_2(int counter, std::vector<command_data> new_file, std::vector<std::string> lines);
	std::string get_proc_name(std::string code);
	int find_procedure_index(std::string name, int instance, const std::vector<procedure_data> new_file);


	// to handle expr
	int LEFT_ASSOC = 0;
	int RIGHT_ASSOC = 1;

	struct assoc{
		int value;
		int type;

		assoc(int _value, int _type)
		{
			value = _value;
			type = _type;
		}

		assoc (): value(0), type (0)
		{

		}
	};
	std::map<std::string, assoc> OPERATORS;

	bool isOperator(std::string token)
	{
		return OPERATORS.find(token) != OPERATORS.end();
	}

	bool isAssociative(std::string token, int type)
	{
		if (OPERATORS[token].type == type)
		{
			return true;
		}
		return false;
	}

	int cmpPrecedence(std::string token1, std::string token2)
	{
		return OPERATORS[token1].value - OPERATORS[token2].value;
	}

	std::vector<TokenElement> infixToRPN(std::vector<TokenElement> inputTokens)
	{
		std::vector<TokenElement> out;
		std::stack<TokenElement> stack;
		// For all the input tokens [S1] read the next token [S2]
		for (int i = 0; i < inputTokens.size(); ++i)
		{
			if (isOperator(inputTokens.at(i).content))
			{
				// If token is an operator (x) [S3]
				while (!stack.empty() && isOperator(stack.top().content))
				{
					// [S4]
					if ((isAssociative(inputTokens.at(i).content, LEFT_ASSOC)
					    && cmpPrecedence(inputTokens.at(i).content, stack.top().content) <= 0)
					    || (isAssociative(inputTokens.at(i).content, RIGHT_ASSOC)
					        && cmpPrecedence(inputTokens.at(i).content, stack.top().content) < 0))
					{
						out.push_back(stack.top()); 	// [S5] [S6]
						stack.pop();
						continue;
					}
					break;
				}
				// Push the new operator on the stack [S7]
				stack.push(inputTokens.at(i));
			} else if (inputTokens.at(i).content.compare("(") == 0)
			{
				stack.push(inputTokens.at(i)); 	// [S8]
			} else if (inputTokens.at(i).content.compare(")") == 0)
			{
				// [S9]
				while (!stack.empty() && stack.top().content.compare("(") != 0)
				{
					out.push_back(stack.top()); // [S10]
					stack.pop();
				}
				stack.pop(); // [S11]
			} else
			{
				out.push_back(inputTokens.at(i)); // [S12]
			}
		}
		while (!stack.empty())
		{
			out.push_back(stack.top()); // [S13]
			stack.pop();
		}

		for (int i = 0 ; i < out.size(); ++i)
			std::cout << out.at(i).content << " ";
		std::cout << std::endl;
		return out;
	}

	void init()
	{
		OPERATORS["+"] = assoc(10, LEFT_ASSOC);
		OPERATORS["-"] = assoc(10, LEFT_ASSOC);
		OPERATORS["*"] = assoc(15, LEFT_ASSOC);
		OPERATORS["/"] = assoc(15, LEFT_ASSOC);
		OPERATORS["%"] = assoc(15, LEFT_ASSOC);
		OPERATORS["^"] = assoc(20, RIGHT_ASSOC);

		OPERATORS["=="] = assoc(0, RIGHT_ASSOC);
		OPERATORS[">="] = assoc(0, RIGHT_ASSOC);
		OPERATORS["<="] = assoc(0, RIGHT_ASSOC);
		OPERATORS[">"] = assoc(0, RIGHT_ASSOC);
		OPERATORS["<"] = assoc(0, RIGHT_ASSOC);
		OPERATORS["||"] = assoc(1, RIGHT_ASSOC);
		OPERATORS["&&"] = assoc(2, RIGHT_ASSOC);
		OPERATORS["!"] = assoc(3, RIGHT_ASSOC);
	}

	exprt get_expr(std::string s, const std::map<std::string, exprt> current_instances)
	{
		assert(current_instances.find(s) != current_instances.end());
		return current_instances.at(s);
	}

	exprt get_expr(std::vector<TokenElement> tokens, const std::map<std::string, exprt> current_instances)
	{
		std::stack<exprt> st;
		for (int i = 0; i < tokens.size(); ++i)
			if (isOperator(tokens.at(i).content))
			{
				if (tokens.at(i).content.compare("!") == 0)
				{
					exprt expr = st.top();
					st.pop();
					st.push(not_exprt(expr));
				}
				else
				{
					exprt expr1 = st.top();
					st.pop();
					exprt expr2 = st.top();
					st.pop();

					if (tokens.at(i).content.compare("==") == 0)
//						expr1 = binary_exprt(expr1, ID_equal, expr2, bitvector_typet(ID_c_bool, 8));
						expr1 = equal_exprt(expr2, expr1);
					else if (tokens.at(i).content.compare("&&") == 0)
//						expr1 = binary_exprt(expr1, ID_and, expr2, bitvector_typet(ID_c_bool, 8));
						expr1 = and_exprt(expr1, expr2);
					else if (tokens.at(i).content.compare("||") == 0)
//						expr1 = binary_exprt(expr1, ID_or, expr2, bitvector_typet(ID_c_bool, 8));
						expr1 = or_exprt(expr1, expr2);
					else if (tokens.at(i).content.compare("+") == 0)
						expr1 = binary_exprt(expr1, ID_assign_plus, expr2);
					else if (tokens.at(i).content.compare("*") == 0)
						expr1 = binary_exprt(expr1, ID_assign_mult, expr2);
					else if (tokens.at(i).content.compare("-") == 0)
						expr1 = binary_exprt(expr1, ID_assign_minus, expr2);
					else if (tokens.at(i).content.compare("/") == 0)
						expr1 = binary_exprt(expr1, ID_assign_div, expr2);
					else if (tokens.at(i).content.compare("%") == 0)
						expr1 = binary_exprt(expr1, ID_assign_mod, expr2);
					else if (tokens.at(i).content.compare(">=") == 0)
						expr1 = binary_exprt(expr1, ID_ge, expr2);
					else if (tokens.at(i).content.compare(">") == 0)
						expr1 = binary_exprt(expr1, ID_gt, expr2);
					else if (tokens.at(i).content.compare("<=") == 0)
						expr1 = binary_exprt(expr1, ID_le, expr2);
					else if (tokens.at(i).content.compare("<") == 0)
						expr1 = binary_exprt(expr1, ID_lt, expr2);
//					else if (tokens.at(i).content.compare("!=") == 0)
//						expr1 = binary_exprt(expr1, ID_neq, expr2);

					st.push(expr1);
				}
			}
			else if (tokens.at(i).type.compare("identifier") == 0)
				st.push(get_expr(tokens.at(i).content, current_instances));
			else if (tokens.at(i).type.compare("int_literal") == 0)
			{
				mp_integer number(stoi(tokens.at(i).content));
				unsigned width = 32;

				bitvector_typet type(ID_signedbv, width);
				constant_exprt r(type);
				irep_idt ir = integer2binary(number, width);
				r.set_value(integer2binary(number, width));
				st.push(r);

			}
			else
			{
				std::cout << "what?: " << tokens.at(i).content << std::endl;
				assert(false);
			}
		return st.top();
	}

};

#endif
