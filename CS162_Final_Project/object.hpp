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
private:
	int id;
	string name;
	string description;

public:
	Object(int id, string name);	//constructor
	~Object();					//deconstructor
	int getId();				//returns id
	void setId(int);			//sets id
	string getName();			//returns name
	void setName(string name);		//sets name
};

#endif
