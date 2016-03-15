/*********************************************************************
** Program Filename: ravine.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: Ravine class header file CS162_400 Final Project
*********************************************************************/

#ifndef RAVINE_HPP
#define RAVINE_HPP

//includes
#include <cstdlib>
#include <string>
#include "space.hpp"


//usings
using std::string;

class Ravine : public Space
{
public:
	//Ravine();		//default constructor
	Ravine(string name, string description, string entryMessage, string look1, string look2); //constructor
	~Ravine();		//deconstructor


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
