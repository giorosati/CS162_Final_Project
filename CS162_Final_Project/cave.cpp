/*********************************************************************
** Program Filename: cave.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Cave class implementation file CS162_400 Final project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "cave.hpp"

//usings
using std::cout;
using std::endl;

Cave::Cave(string name, string description, string entryMessage, string look1, string look2) //constructor
	: Space(name, description, entryMessage, look1, look2)
{}

Cave::~Cave()
{
	//cout << " deconstructor has run." << endl;
}

/*********************************************************************
** Function: special
** Description:
**
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Cave::special()
{
	return - 1;
}