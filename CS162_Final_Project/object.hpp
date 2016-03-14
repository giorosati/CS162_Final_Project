/*********************************************************************
** Program Filename: object.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: Object class header file CS162_400 Final Project
*********************************************************************/

#ifndef OBJECT_HPP
#define OBJECT_HPP

//includes
#include <cstdlib>
#include <string>

//usings
using std::string;

class Object
{
protected:
	string oName;
	string oDescription;
	int powerState;
	int empty;

public:
	Object();					//default constructor
	~Object();					//deconstructor
	string getName();			//returns name
	string getDescription();	//returns description
	int getPowerState();		//returns powerState
	void setPowerState(int);	//sets powerState
	int getEmpty();				//returns empty
	void setEmpty(int);			//sets empty

};

#endif
