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
	string name;
	string description;
	bool powerState;
	bool empty;

public:
	Object(string name, string description);	//constructor
	~Object();					//deconstructor
	string getName();			//returns name
	string getDescription();	//returns description
	bool getPowerState();		//returns powerState
	void setPowerState(bool);		//sets powerState
	bool getEmpty();				//returns empty
	void setEmpty(bool);			//sets empty

};

#endif
