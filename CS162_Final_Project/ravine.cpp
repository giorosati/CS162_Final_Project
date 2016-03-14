/*********************************************************************
** Program Filename: ravine.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Ravine class implementation file CS162_400 Final project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "ravine.hpp"

//usings
using std::cout;
using std::endl;

Ravine::Ravine(string name, string description, string entryMessage, string look1, string look2) //constructor
	: Space(name, description, entryMessage, look1, look2)
{}

Ravine::~Ravine()
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
int Ravine::special()
{
	return -1;
}