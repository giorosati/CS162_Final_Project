/*********************************************************************
** Program Filename: space.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Space class implementation file CS162_400 Final Project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "space.hpp"
#include "object.hpp"

//usings
using std::cout;
using std::endl;

Space::Space()
{
}

Space::Space(string name, string description, string entryMessage, string look1, string look2)
{
	this->name = name;
	this->description = description;
	this->entryMessage = entryMessage;
	this->look1 = look1;
	this->look2 = look2;
	this->doors = 4;
	for (int i = 0; i < 10; i++)
	{
		this->objects[i] = NULL;
	}
	this->sPointer1 = NULL;
	this->sPointer2 = NULL;
	this->sPointer3 = NULL;
	this->sPointer4 = NULL;

}

Space::~Space()
{
	//cout << "Space deconstructor has run" << endl;
}

string Space::getName()
{
	return name;
}

string Space::getDescription()
{
	return description;
}

string Space::getEntryMessage()
{
	return entryMessage;
}

string Space::getLook1()
{
	return look1;
}

string Space::getLook2()
{
	return look2;
}