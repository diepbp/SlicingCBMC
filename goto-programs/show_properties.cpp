/*******************************************************************\

Module: Show Claims

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include <iostream>

#include <util/xml.h>
#include <util/i2string.h>
#include <util/xml_expr.h>

#include <langapi/language_util.h>

#include "show_properties.h"
#include "goto_functions.h"
#include "goto_model.h"

/*******************************************************************\

Function: cbmc_parseoptionst::show_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void show_properties(
  const namespacet &ns,
  const irep_idt &identifier,
  ui_message_handlert::uit ui,
  const goto_programt &goto_program)
{
  for(goto_programt::instructionst::const_iterator
      it=goto_program.instructions.begin();
      it!=goto_program.instructions.end();
      it++)
  {
    if(!it->is_assert())
      continue;
      
    const source_locationt &source_location=it->source_location;
      
    const irep_idt &comment=source_location.get_comment();
    //const irep_idt &function=location.get_function();
    const irep_idt &property_class=source_location.get_property_class();
    const irep_idt description=
      (comment==""?"assertion":comment);
      
    irep_idt property_id=source_location.get_property_id();
    
    switch(ui)
    {
    case ui_message_handlert::XML_UI:
      {
        #if 0
        xmlt xml_claim("claim"); // this will go away, use below
        xml_claim.new_element("number").data=id2string(property_id); // will go away
        xml_claim.new_element("name").data=id2string(property_id); // will go away
        xml_claim.set_attribute("name", id2string(property_id)); // use this one
        
        xmlt &l=xml_claim.new_element();
        l=xml(it->source_location);
        
        xml_claim.new_element("description").data=id2string(description);        
        xml_claim.new_element("property").data=id2string(property_class);
        xml_claim.new_element("expression").data=from_expr(ns, identifier, it->guard);
        xml_claim.new_element("source").data="";

        std::cout << xml_claim << std::endl;
        #endif

        // use me instead
        xmlt xml_property("property");
        xml_property.set_attribute("name", id2string(property_id)); // use this one
        xml_property.set_attribute("class", id2string(property_class)); // use this one
        
        xmlt &property_l=xml_property.new_element();
        property_l=xml(it->source_location);
        
        xml_property.new_element("description").data=id2string(description);        
        xml_property.new_element("expression").data=from_expr(ns, identifier, it->guard);

        std::cout << xml_property << std::endl;
      }
      break;
      
    case ui_message_handlert::PLAIN:
      std::cout << "Property " << property_id << ":" << std::endl;

      std::cout << "  " << it->source_location << std::endl
                << "  " << description << std::endl
                << "  " << from_expr(ns, identifier, it->guard) << std::endl;

      std::cout << std::endl;
      break;

    default:
      assert(false);
    }
  }
}



/*******************************************************************\

Function: show_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void show_properties(
  const namespacet &ns,
  ui_message_handlert::uit ui,
  const goto_functionst &goto_functions)
{
  for(goto_functionst::function_mapt::const_iterator
      it=goto_functions.function_map.begin();
      it!=goto_functions.function_map.end();
      it++)
    if(!it->second.is_inlined())
      show_properties(ns, it->first, ui, it->second.body);
}

/*******************************************************************\

Function: show_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void show_properties(
  const goto_modelt &goto_model,
  ui_message_handlert::uit ui)
{
  const namespacet ns(goto_model.symbol_table);
  show_properties(ns, ui, goto_model.goto_functions);
}

/*******************************************************************\

Function: show_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
//std::vector<std::pair<std::string, std::string>> get_properties(
//		const goto_modelt &goto_model)
//{
//	return get_properties(goto_model.goto_functions);
//}


/*
 *
 */
bool vector_contains(std::vector<std::pair<std::string, std::string>> v, std::pair<std::string, std::string> s)
{
	for (int i = 0; i < v.size(); ++i)
		if (v[i].first.compare(s.first) == 0 &&
				v[i].second.compare(s.second) == 0)
			return true;
	return false;
}

/*******************************************************************\

Function: parse_string

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::vector<std::string> parse_string_properties(std::string s)
{
	std::vector<std::string> result;
	char *str = new char[s.size() + 1];
	str[s.size()] = 0;
	memcpy(str, s.c_str(), s.size());

	//	strcpy(str, s.c_str());
	//	std::cout << str << std::endl;

	char* pch;
	pch = strtok(str, " !+-*/!&|><=()\t");

	while (pch != NULL)
	{
		result.push_back(pch);
		pch = strtok(NULL, " ;=!()&|+-*/<>\t");
	}

	return result;

}

/*******************************************************************\

Function: get_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::vector<std::pair<std::string, std::string>> get_properties(
		const namespacet &ns,
		  const irep_idt &identifier,
		  const goto_programt &goto_program)
{
	std::vector<std::string> line_token;
	int prev_line = -1;
	bool assertion = false;
	std::string location;
	std::vector<std::pair<std::string, std::string>> result;

	for(goto_programt::instructionst::const_iterator
	      it=goto_program.instructions.begin();
	      it!=goto_program.instructions.end();
	      it++)
	  {
			if (it->guard.is_nil() || it->source_location.is_nil())
			 	continue;
	    int line = std::stoi(as_string(it->source_location.get_line()), nullptr);

	    if (line != prev_line)
	    {
	    	std::cout << "Line: " << line << std::endl;
	    	if (assertion == true)
	    	{
	    		std::cout << "Assertion: " << location << " " << prev_line << std::endl;
	    		for (int i = 0; i < line_token.size(); ++i)
						result.push_back(std::make_pair(line_token[i], location));	//std::make_pair(t[i],location));
	    	}
	    	line_token.clear();
	    	prev_line = line;
	    	assertion = false;
	    }


	    if (it->guard.is_true())
	    	continue;
	    std::string expr = from_expr(ns, identifier, it->guard);
	    std::cout << "Property: " << expr << std::endl;

	    std::vector<std::string> t = parse_string_properties(expr);
	    line_token.insert(line_token.begin(), t.begin(), t.end());

	    location =  as_string(it->source_location.get_function());

	    if(it->is_assert() || it->is_assume())
	    	assertion = true;

	  }
	return result;
}


/*******************************************************************\

Function: get_properties

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/
std::vector<std::pair<std::string, std::string>> get_properties(
		const namespacet &ns,
		const goto_functionst &goto_functions)
{
	std::vector<std::pair<std::string, std::string>> result;
	for(goto_functionst::function_mapt::const_iterator
	      it=goto_functions.function_map.begin();
	      it!=goto_functions.function_map.end();
	      it++)
		if (!it->second.is_inlined())
		{
			std::vector<std::pair<std::string, std::string>> partial_result =
						get_properties(ns, it->first, it->second.body);

			for (int i = 0 ; i < partial_result.size(); ++i)
			{
				if (vector_contains(result, partial_result[i]) == false)
				{
					result.push_back(partial_result[i]);
				}
			}
		}
	return result;
}
