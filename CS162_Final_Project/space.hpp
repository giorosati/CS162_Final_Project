/*********************************************************************
** Program Filename: space.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: Space class header file CS162_400 Final Project
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

//includes
#include <cstdlib>
#include <string>
#include <vector>
#include "object.hpp"

//usings
using std::string;
using std::vector;

class Space
{
protected:
	string name;
	string description;
	string entryMessage;
	string look1;
	string look2;
	int doors;
	Object* objects[10];
	Space* sPointer1;
	Space* sPointer2;
	Space* sPointer3;
	Space* sPointer4;

	//vector<Object*> objects;
	//NodeLL<Object*> objectList;

public:
	Space();					//default constructor
	Space(string name, string description, string entryMessage, string look1, string look2); //constructor
	~Space();					//deconstructor
	string getName();			//returns name
	string getDescription();	//returns description
	string getEntryMessage();	//returns entry message
	string getLook1();				//returns look1
	string getLook2();				//returns look2
	virtual int special() = 0;	//pure virtual function prototype
};

#endif