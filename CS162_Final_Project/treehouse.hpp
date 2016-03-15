/*********************************************************************
** Program Filename: treehouse.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: Treehouse class header file CS162_400 Final Project
*********************************************************************/

#ifndef TREEHOUSE_HPP
#define TREEHOUSE_HPP

//includes
#include <cstdlib>
#include <string>
#include "space.hpp"

//usings
using std::string;

class Treehouse : public Space
{
public:
	Treehouse(string name, string description, string entryMessage, string look1, string look2); //constructor
	~Treehouse();		//deconstructor

	int move();

	/*********************************************************************
	** Function: special
	** Description:
	**
	** Parameters: none
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	int special();
};

#endif
