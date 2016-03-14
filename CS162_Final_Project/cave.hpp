/*********************************************************************
** Program Filename: cave.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: Cave class header file CS162_400 Final Project
*********************************************************************/

#ifndef CAVE_HPP
#define CAVE_HPP

//includes
#include <cstdlib>
#include <string>
#include "space.hpp"


//usings
using std::string;

class Cave : public Space
{
public:
	//Cave();			//default constructor
	Cave(string name, string description, string entryMessage, string look1, string look2); //constructor
	~Cave();		//deconstructor

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
