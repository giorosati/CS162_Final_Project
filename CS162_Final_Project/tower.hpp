/*********************************************************************
** Program Filename: tower.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: Tower class header file CS162_400 Final Project
*********************************************************************/

#ifndef TOWER_HPP
#define TOWER_HPP

//includes
#include <cstdlib>
#include <string>
#include "space.hpp"

//usings
using std::string;

class Tower : public Space
{
public:
	//Tower();		//default constructor
	Tower(string name, string description, string entryMessage, string look1, string look2); //constructor
	~Tower();		//deconstructor

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