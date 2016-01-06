/*******************************************************************\

Module: Program Transformation

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <util/std_expr.h>
#include <util/i2string.h>

#include <langapi/language_util.h>

#include "goto_program.h"

/*******************************************************************\

Function: goto_programt::output_instruction

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::ostream& goto_programt::output_instruction(
  const class namespacet &ns,
  const irep_idt &identifier,
  std::ostream& out,
  instructionst::const_iterator it) const
{
  out << "        //" << it->location_number << " ";

  if(!it->source_location.is_nil())
    out << it->source_location.as_string();
  else
    out << "no location";

  out << "\n";

  if(!it->labels.empty())
  {
    out << "        // Labels:";
    for(instructiont::labelst::const_iterator
        l_it=it->labels.begin();
        l_it!=it->labels.end();
        l_it++)
    {
      out << " " << *l_it;
    }
    
    out << std::endl;
  }

  if(it->is_target())
    out << std::setw(6) << it->target_number << ": ";
  else
    out << "        ";

  switch(it->type)
  {
  case NO_INSTRUCTION_TYPE:
    out << "NO INSTRUCTION TYPE SET" << std::endl;
    break;
  
  case GOTO:
    if(!it->guard.is_true())
    {
      out << "IF "
          << from_expr(ns, identifier, it->guard)
          << " THEN ";
    }

    out << "GOTO ";
    
    for(instructiont::targetst::const_iterator
        gt_it=it->targets.begin();
        gt_it!=it->targets.end();
        gt_it++)
    {
      if(gt_it!=it->targets.begin()) out << ", ";
      out << (*gt_it)->target_number;
    }
      
    out << std::endl;
    break;
    
  case RETURN:
  case OTHER:
  case DECL:
  case DEAD:
  case FUNCTION_CALL:
  case ASSIGN:
    out << from_expr(ns, identifier, it->code) << std::endl;
    break;
    
  case ASSUME:
  case ASSERT:
    if(it->is_assume())
      out << "ASSUME ";
    else
      out << "ASSERT ";
      
    {
      out << from_expr(ns, identifier, it->guard);
    
      const irep_idt &comment=it->source_location.get_comment();
      if(comment!="") out << " // " << comment;
    }
      
    out << std::endl;
    break;

  case SKIP:
    out << "SKIP" << std::endl;
    break;
    
  case END_FUNCTION:
    out << "END_FUNCTION" << std::endl;
    break;
    
  case LOCATION:
    out << "LOCATION" << std::endl;
    break;
    
  case THROW:
    out << "THROW";

    {
      const irept::subt &exception_list=
        it->code.find(ID_exception_list).get_sub();
    
      for(irept::subt::const_iterator
          it=exception_list.begin();
          it!=exception_list.end();
          it++)
        out << " " << it->id();
    }
    
    if(it->code.operands().size()==1)
      out << ": " << from_expr(ns, identifier, it->code.op0());
    
    out << std::endl;
    break;
    
  case CATCH:
    if(!it->targets.empty())
    {
      out << "CATCH-PUSH ";
    
      unsigned i=0;
      const irept::subt &exception_list=
        it->code.find(ID_exception_list).get_sub();
      assert(it->targets.size()==exception_list.size());
      for(instructiont::targetst::const_iterator
          gt_it=it->targets.begin();
          gt_it!=it->targets.end();
          gt_it++,
          i++)
      {
        if(gt_it!=it->targets.begin()) out << ", ";
        out << exception_list[i].id() << "->"
            << (*gt_it)->target_number;
      }
    }
    else
      out << "CATCH-POP";
      
    out << std::endl;
    break;
    
  case ATOMIC_BEGIN:
    out << "ATOMIC_BEGIN" << std::endl;
    break;
    
  case ATOMIC_END:
    out << "ATOMIC_END" << std::endl;
    break;
    
  case START_THREAD:
    out << "START THREAD ";

    if(it->targets.size()==1)
      out << it->targets.front()->target_number;
    
    out << std::endl;
    break;
    
  case END_THREAD:
    out << "END THREAD" << std::endl;
    break;
    
  default:
    throw "unknown statement";
  }

  return out;  
}

std::vector<std::string> parse_string_goto_program(std::string s)
{
	std::vector<std::string> result;
	char *str=new char[s.size()+1];
	str[s.size()]=0;
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

std::vector<std::string> parse_string_assignment(std::string s)
{
	std::vector<std::string> result;
	char *str=new char[s.size()+1];
	str[s.size()]=0;
	memcpy(str, s.c_str(), s.size());
	char* pch;
	pch = strtok(str, " !+-*/!&|><();\t");

	while (pch != NULL)
	{
		result.push_back(pch);
		pch = strtok(NULL, " ;!()&|+-*/<>\t");
	}

	return result;
}

bool is_variable_goto_program(std::string s, std::vector<variable_struct> variables)
{
	for (std::vector<variable_struct>::iterator it = variables.begin(); it != variables.end(); ++it)
	{
		if ((*it).name.compare(s) == 0)
			return true;
	}
	return false;
}

bool is_selected_variable_goto_program(std::string s, std::string proc_name, std::vector<variable_struct> variables)
{
	for (std::vector<variable_struct>::iterator it = variables.begin(); it != variables.end(); ++it)
	{
		if ((*it).name.compare(s) == 0 &&
				(		(*it).proc.size() == 0 ||
						(*it).proc.compare(proc_name) == 0
				)
			 )
		{
			return true;
		}
	}
	return false;
}

bool has_token_goto_program(std::string s, std::vector<std::string> list)
{
	for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
		if ((*it).compare(s) == 0)
			return true;
	return false;
}

void add_line(int line, Slice_Type type, std::vector<std::pair<int, Slice_Type>> &result, std::vector<std::pair<int, Slice_Type>> &atomic_block)
{
	result.push_back(std::make_pair(line, type));
}

std::vector<std::pair<int, Slice_Type>> goto_programt::slice_variable_instruction(
		const class namespacet &ns,
		const irep_idt &identifier,
	  std::vector<variable_struct> selected_variables,
	  std::vector<variable_struct> variables) const
{

	std::vector<std::pair<int, Slice_Type>> result;
	std::vector<std::pair<int, Slice_Type>> atomic_block;
	int begin_atomic;
	int end_atomic;
	forall_goto_program_instructions(it, (*this))
	{
		if(it->source_location.is_nil())
			continue;

		int line = std::stoi(as_string(it->source_location.get_line()), nullptr);
		bool added = false;

		std::vector<std::string> token;
		bool left = true;
		switch(it->type)
		{
			case GOTO:
				if(!it->guard.is_true())
				{
					std::vector<std::string> token = parse_string_goto_program(from_expr(ns, identifier, it->guard));
//					std::cout << "GOTO: " << from_expr(ns, identifier, it->guard) << std::endl;
					// only keep variables
					for (std::vector<std::string>::iterator itt = token.begin(); itt != token.end();)
					{
						if (is_variable_goto_program((*itt), variables))
						++itt;
						else
						token.erase(itt);
					}

					// check if all variables in selected_variables
					for (std::vector<std::string>::iterator itt = token.begin(); itt != token.end(); ++itt)
					{
						if (!is_selected_variable_goto_program((*itt), as_string(identifier), selected_variables))
						{
							add_line(line, Guard, result, atomic_block);
							added = true;
							break;
						}
					}
				}
				else
				{
					// do not do anything
					added = true;
				}
				break;

			case RETURN:
				token = parse_string_goto_program(from_expr(ns, identifier, it->code));

				// only keep variables
				for (std::vector<std::string>::iterator itt = token.begin();
						itt != token.end();)
				{
					if (is_variable_goto_program((*itt), variables))
					++itt;
					else
					token.erase(itt);
				}

				// check if all variables in selected_variables
				for (std::vector<std::string>::iterator itt = token.begin();
						itt != token.end(); ++itt)
				{
					if (!is_selected_variable_goto_program((*itt), as_string(identifier), selected_variables))
					{
						add_line(line, Return, result, atomic_block);
						added = true;
						break;
					}
				}
				break;

			case DECL:
			token = parse_string_goto_program(from_expr(ns, identifier, it->code));

			// not remove declare of thread
			if (has_token_goto_program("_opaque_pthread_t", token))
				continue;

			// only keep variables
			for (std::vector<std::string>::iterator itt = token.begin();
					itt != token.end();)
			{
				if (is_variable_goto_program((*itt), variables))
				++itt;
				else
				token.erase(itt);
			}

			// check if all variables in selected_variables
			for (std::vector<std::string>::iterator itt = token.begin();
					itt != token.end(); ++itt)
			{
				if (!is_selected_variable_goto_program((*itt), as_string(identifier), selected_variables))
				{
					add_line(line, Decl, result, atomic_block);
					added = true;
					break;
				}
			}
			break;

			case FUNCTION_CALL:

			token = parse_string_goto_program(from_expr(ns, identifier, it->code));

			// handle an atomic block
//			if (has_token_goto_program("__VERIFIER_atomic_begin", token))
//			{
//				atomic_block.push_back(std::make_pair(line, Call));
//				break;
//			}
//			else if (has_token_goto_program("__VERIFIER_atomic_end", token))
//			{
//				atomic_block.push_back(std::make_pair(line, Call));
//				if (atomic_block.size() > 2)
//				{
//					result.insert(result.end(), atomic_block.begin(), atomic_block.end());
//					atomic_block.clear();
//				}
//				else
//				{
//					result.push_back(std::make_pair(line, Remove_Atomic));
//					result.push_back(std::make_pair(line, Remove_Atomic));
//				}
//				break;
//			}

			if (has_token_goto_program("__VERIFIER_atomic_begin", token) ||
					has_token_goto_program("__VERIFIER_atomic_end", token))
			{
				add_line(line, Call, result, atomic_block);
				added = true;
				break;
			}

			// otherwise
			// only keep variables
			for (std::vector<std::string>::iterator itt = token.begin();
					itt != token.end();)
			{
				if (is_variable_goto_program((*itt), variables))
				++itt;
				else
				token.erase(itt);
			}

			// check if all variables in selected_variables
			for (std::vector<std::string>::iterator itt = token.begin();
					itt != token.end(); ++itt)
			{
				if (!is_selected_variable_goto_program((*itt), as_string(identifier), selected_variables))
				{
					std::cout << "Call statement: " << line << " " << from_expr(ns, identifier, it->code) << std::endl;
					add_line(line, Call, result, atomic_block);
					added = true;
					break;
				}
			}
			break;

			case ASSIGN:
			token = parse_string_assignment(from_expr(ns, identifier, it->code));

			// only keep variables
			for (std::vector<std::string>::iterator itt = token.begin();
					itt != token.end();)
			{
				if (is_variable_goto_program((*itt), variables) ||
						(*itt).compare("=") == 0)
				++itt;
				else
				token.erase(itt);
			}

			if (token.size() <= 1)
			{
				add_line(line, None, result, atomic_block);
				added = true;
				break;
			}

			// check if all variables in selected_variables
			for (int itt = 0; itt < token.size(); ++itt)
			{
				if (token[itt].compare("=") == 0)
				{
					left = false;
					continue;
				}

				if (!is_selected_variable_goto_program(token[itt], as_string(identifier), selected_variables))
				{
					if (left == true)
					{
						// TODO wrong because of exit(0)
						add_line(line, LeftAssign, result, atomic_block);
						added = true;
						break;
					}
					else
					{
						add_line(line, RightAssign, result, atomic_block);
						added = true;
						break;
					}
				}
			}
			break;

			case ASSUME:
			token = parse_string_goto_program(from_expr(ns, identifier, it->guard));

			// only keep variables
			for (std::vector<std::string>::iterator itt = token.begin();
					itt != token.end();)
			{
				if (is_variable_goto_program((*itt), variables))
				++itt;
				else
				token.erase(itt);
			}

			// check if all variables in selected_variables
			for (std::vector<std::string>::iterator itt = token.begin();
					itt != token.end(); ++itt)
			{
				if (!is_selected_variable_goto_program((*itt), as_string(identifier), selected_variables))
				{
					add_line(line, Guard, result, atomic_block);
					added = true;
					break;
				}
			}
			break;

			case OTHER:
			case DEAD:
			break;

			case ASSERT:
			break;

			case SKIP:
			case END_FUNCTION:
			case LOCATION:
			break;

			case THROW:
			case CATCH:
			break;

			case ATOMIC_BEGIN:
			case ATOMIC_END:
			case START_THREAD:
			case END_THREAD:
			break;

			default:
			throw "unknown statement";
		}
		if (added == false)
		{
			add_line(line, None, result, atomic_block);
		}
	}
	return result;
}


/*******************************************************************\

Function: goto_programt::get_decl_identifiers

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::vector<std::vector<int>> goto_programt::get_program_dependencies(
		const class namespacet &ns,
		const irep_idt &identifier,
		std::vector<variable_struct> vars
		) const
{
	std::vector<std::map<int, int>> result;

	// init result
	for (int i = 0 ; i < vars.size(); ++i){
		std::map<int, int> r;
		result.push_back(r);
	}

	goto_programt::instructionst::const_iterator prev_it;
	std::cout << "goto_programt::get_program_dependencies(std::vector<variable_struct> vars) const" << as_string(identifier) << "\n";

	forall_goto_program_instructions(it, (*this))
	{
		if(it->source_location.is_nil())
			continue;

		std::string code;
		switch(it->type)
		{

			case GOTO:
				if(!it->guard.is_true())
				{
					code = from_expr(ns, identifier, it->guard);
				}

				break;

			case ASSIGN:
				code = from_expr(ns, identifier, it->code);

			break;

			case DECL:
				break;

			case ASSUME:
			case ASSERT:
			{
				code = from_expr(ns, identifier, it->guard);
			}

			break;

			case FUNCTION_CALL:
			prev_it = it;
			break;

			default:
			break;
		}

		if (code.size() > 1)
		{
			// handle function call
			if (it->type == ASSIGN)
			{
				std::size_t found = code.find("#return_value");
				if (found != std::string::npos)
				{
					std::size_t found2 = code.find('=');
					if (found > found2)
					{
						code = code.substr(0, found2 + 1) + from_expr(prev_it->code);
						std::cout << "change code: " << code << std::endl;
					}
				}
			}

			std::vector<std::string> v = parse_string_goto_program(code);
			if (v.size() > 1)
			{
				std::vector<int> tmp_variables;

				for (int k = 0; k < v.size(); ++k)
				{
					for(int i = 0 ; i < vars.size(); ++i)
						if (v[k].compare(vars[i].name) == 0 &&
									(	vars[i].proc.size() == 0 ||
										vars[i].proc.compare(as_string(identifier)) == 0)
							 )
						{
							tmp_variables.push_back(i);
							break;
						}
				}

				if (it->type == ASSIGN)
				{
					std::cout << code << ": " << tmp_variables.size() << std::endl;
					for (int i = 1; i < tmp_variables.size(); ++i)
						if (tmp_variables[i] != tmp_variables[0])
						result[tmp_variables[0]][tmp_variables[i]] = 1;
				}

				else
				{
					std::cout << it->type << ": " << code << std::endl;
				for (int i = 0; i < tmp_variables.size(); ++i)
					for (int j = i + 1; j < tmp_variables.size(); ++j)
						if (tmp_variables[i] != tmp_variables[j])
						{
							result[tmp_variables[i]][tmp_variables[j]] = 1;
							result[tmp_variables[j]][tmp_variables[i]] = 1;
						}
				}
			}
		}
	}


	/*
	 * Print test dependency
	 */
	std::cout << "Test dependency in " << as_string(identifier) << "\n";
	std::vector<std::vector<int>> r(vars.size());
	for (int i = 0; i < vars.size(); ++i)
	{
		std::cout << vars[i].name << ": " << vars[i].proc << ": ";
		for (std::map<int, int>::iterator it = result[i].begin(); it != result[i].end(); ++it)
		{
			r[i].push_back(it->first);
			std::cout << vars[it->first].name << " ";
		}
		std::cout << std::endl;
	}


	std::cout << "DONE goto_program\n";
	return r;
}

/*******************************************************************\

Function: goto_programt::get_decl_identifiers

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void goto_programt::get_decl_identifiers(
  decl_identifierst &decl_identifiers) const
{
  forall_goto_program_instructions(it, (*this))
  {
    if(it->is_decl())
    {
      assert(it->code.get_statement()==ID_decl);
      assert(it->code.operands().size()==1);
      const symbol_exprt &symbol_expr=to_symbol_expr(it->code.op0());
      decl_identifiers.insert(symbol_expr.get_identifier());
    }
  }
} 

/*******************************************************************\

Function: parse_lhs_read

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void parse_lhs_read(const exprt &src, std::list<exprt> &dest)
{
  if(src.id()==ID_dereference)
  {
    assert(src.operands().size()==1);
    dest.push_back(src.op0());
  }
  else if(src.id()==ID_index)
  {
    assert(src.operands().size()==2);
    dest.push_back(src.op1());
    parse_lhs_read(src.op0(), dest);
  }
  else if(src.id()==ID_member)
  {
    assert(src.operands().size()==1);
    parse_lhs_read(src.op0(), dest);
  }
  else if(src.id()==ID_if)
  {
    assert(src.operands().size()==3);
    dest.push_back(src.op0());
    parse_lhs_read(src.op1(), dest);
    parse_lhs_read(src.op2(), dest);
  }
}

/*******************************************************************\

Function: expressions_read

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::list<exprt> expressions_read(
  const goto_programt::instructiont &instruction)
{
  std::list<exprt> dest;

  switch(instruction.type)
  {
  case ASSUME:
  case ASSERT:
  case GOTO:
    dest.push_back(instruction.guard);
    break;
  
  case RETURN:
    if(to_code_return(instruction.code).return_value().is_not_nil())
      dest.push_back(to_code_return(instruction.code).return_value());
    break;
  
  case FUNCTION_CALL:
    {
      const code_function_callt &function_call=
        to_code_function_call(instruction.code);
      forall_expr(it, function_call.arguments())
        dest.push_back(*it);
      if(function_call.lhs().is_not_nil())
        parse_lhs_read(function_call.lhs(), dest);
    }
    break;
  
  case ASSIGN:
    {
      const code_assignt &assignment=to_code_assign(instruction.code);
      dest.push_back(assignment.rhs());
      parse_lhs_read(assignment.lhs(), dest);
    }
    break;
  
  default:;
  }
  
  return dest;
}

/*******************************************************************\

Function: expressions_written

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::list<exprt> expressions_written(
  const goto_programt::instructiont &instruction)
{
  std::list<exprt> dest;

  switch(instruction.type)
  {
  case FUNCTION_CALL:
    {
      const code_function_callt &function_call=
        to_code_function_call(instruction.code);
      if(function_call.lhs().is_not_nil())
        dest.push_back(function_call.lhs());
    }
    break;
  
  case ASSIGN:
    dest.push_back(to_code_assign(instruction.code).lhs());
    break;
  
  default:;
  }
  
  return dest;
}

/*******************************************************************\

Function: get_objects_read

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void objects_read(
  const exprt &src,
  std::list<exprt> &dest) 
{
  if(src.id()==ID_symbol)
    dest.push_back(src);
  else if(src.id()==ID_address_of)
  {
    // don't traverse!
  }
  else if(src.id()==ID_dereference)
  {
    // this reads what is pointed to plus the pointer
    assert(src.operands().size()==1);
    dest.push_back(src);
    objects_read(src.op0(), dest);
  }
  else
  {
    forall_operands(it, src)
      objects_read(*it, dest);
  }
}

/*******************************************************************\

Function: objects_read

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::list<exprt> objects_read(
  const goto_programt::instructiont &instruction)
{
  std::list<exprt> expressions=expressions_read(instruction);

  std::list<exprt> dest;
  
  forall_expr_list(it, expressions)
    objects_read(*it, dest);
  
  return dest;
}

/*******************************************************************\

Function: objects_written

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void objects_written(
  const exprt &src,
  std::list<exprt> &dest)
{
  if(src.id()==ID_if)
  {
    assert(src.operands().size()==3);
    objects_written(src.op1(), dest);
    objects_written(src.op2(), dest);
  }
  else
    dest.push_back(src);
}

/*******************************************************************\

Function: objects_written

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::list<exprt> objects_written(
  const goto_programt::instructiont &instruction)
{
  std::list<exprt> expressions=expressions_written(instruction);

  std::list<exprt> dest;
  
  forall_expr_list(it, expressions)
    objects_written(*it, dest);
  
  return dest;
}

/*******************************************************************\

Function: as_string

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

std::string as_string(
  const class namespacet &ns,
  const goto_programt::instructiont &i)
{
  std::string result;

  switch(i.type)
  {
  case NO_INSTRUCTION_TYPE:
    return "(NO INSTRUCTION TYPE)";
    
  case GOTO:
    if(!i.guard.is_true())
    {
      result+="IF "
            +from_expr(ns, i.function, i.guard)
            +" THEN ";
    }

    result+="GOTO ";
    
    for(goto_programt::instructiont::targetst::const_iterator
        gt_it=i.targets.begin();
        gt_it!=i.targets.end();
        gt_it++)
    {
      if(gt_it!=i.targets.begin()) result+=", ";
      result+=i2string((*gt_it)->target_number);
    }
    return result;
    
  case RETURN:
  case OTHER:
  case DECL:
  case DEAD:
  case FUNCTION_CALL:
  case ASSIGN:
    return from_expr(ns, i.function, i.code);
    
  case ASSUME:
  case ASSERT:
    if(i.is_assume())
      result+="ASSUME ";
    else
      result+="ASSERT ";
      
    result+=from_expr(ns, i.function, i.guard);

    {
      const irep_idt &comment=i.source_location.get_comment();
      if(comment!="") result+=" /* "+id2string(comment)+" */";
    }
    return result;

  case SKIP:
    return "SKIP";
    
  case END_FUNCTION:
    return "END_FUNCTION";
    
  case LOCATION:
    return "LOCATION";
    
  case THROW:
    return "THROW";
    
  case CATCH:
    return "CATCH";
    
  case ATOMIC_BEGIN:
    return "ATOMIC_BEGIN";
    
  case ATOMIC_END:
    return "ATOMIC_END";
    
  case START_THREAD:
    result+="START THREAD ";

    if(i.targets.size()==1)
      result+=i2string(i.targets.front()->target_number);
    return result;
    
  case END_THREAD:
    return "END THREAD";
    
  default:
    throw "unknown statement";
  }

  return "";
}

