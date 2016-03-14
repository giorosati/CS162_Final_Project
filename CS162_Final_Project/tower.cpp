/*********************************************************************
** Program Filename: tower.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Tower class implementation file CS162_400 Final project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "tower.hpp"

//usings
using std::cout;
using std::endl;

Tower::Tower(string name, string description, string entryMessage, string look1, string look2) //constructor
	: Space(name, description, entryMessage, look1, look2)
{}

Tower::~Tower()
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
int Tower::special()
{
	return -1;
}