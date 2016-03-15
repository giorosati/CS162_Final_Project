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

void Space::setPointers(Space* sPointer1, Space* sPointer2, Space* sPointer3, Space* sPointer4)
{
	this->sPointer1 = sPointer1;
	this->sPointer2 = sPointer2;
	this->sPointer3 = sPointer3;
	this->sPointer4 = sPointer4;
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

Space* Space::getPointer(int sPointer)
{
	if (sPointer == 1) return sPointer1;
	else if (sPointer == 2) return sPointer2;
	else if (sPointer == 3) return sPointer3;
	else if (sPointer == 4) return sPointer4;
	else return NULL;
}
void Space::addObject(Object* objectIn)
{
	bool done = false;
	for (int i = 0; i < 10; i++)
	{
		if (!done && objects[i] == NULL)
		{
			objects[i] = objectIn;
			done = true;
		}
	}
	if (!done) cout << "The array is full, object not added";
}

void Space::displayObjects()
{
	bool noObjects = true;
	for (int i = 0; i < 10; i++)
	{
		if (objects[i] != NULL)
		{
			cout << "Item # " << i << "   " << objects[i]->getName() << endl;
			noObjects = false;
		}
	}
	if (noObjects) cout << "No items visible." << endl;
	cout << endl;
}
bool Space::objectsPresent()
{
	bool result = false;
	for (int i = 0; i < 10; i++)
	{
		if (!result && objects[i] != NULL) result = true;
	}
	return result;
}

Object* Space::getObject(int position)
{
	return objects[position];
}

void Space::removeObject(int position)
{
	objects[position] = NULL;
}


