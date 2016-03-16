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

//default constructor
Space::Space()
{
}

//constructor
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

//sets Space all pointers
void Space::setPointers(Space* sPointer1, Space* sPointer2, Space* sPointer3, Space* sPointer4)
{
	this->sPointer1 = sPointer1;
	this->sPointer2 = sPointer2;
	this->sPointer3 = sPointer3;
	this->sPointer4 = sPointer4;
}

string Space::getName()	//returns name
{
	return name;
}

string Space::getDescription()	//returns description
{
	return description;
}

string Space::getEntryMessage()	//returns entryMessage
{
	return entryMessage;
}

string Space::getLook1()	//returns look1 string
{
	return look1;
}

string Space::getLook2()	//returns look2 string
{
	return look2;
}

//returns pointer 1,2,3 or 4 depending on the int parameter
Space* Space::getPointer(int sPointer)
{
	if (sPointer == 1) return sPointer1;
	else if (sPointer == 2) return sPointer2;
	else if (sPointer == 3) return sPointer3;
	else if (sPointer == 4) return sPointer4;
	else return NULL;
}

//adds an object pointer to the first available array position, 
//and returns a string message if the array is full
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

//outputs to the console the objects in the array
//or a message if the array is empty
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

//returns true if any objects exist in the array
//returns false if the array is empty
bool Space::objectsPresent()
{
	bool result = false;
	for (int i = 0; i < 10; i++)
	{
		if (!result && objects[i] != NULL) result = true;
	}
	return result;
}

//returns the object pointer at the array 
//position detemined by parameter
Object* Space::getObject(int position)
{
	return objects[position];
}

//sets the object pointer at an array 
//position (detemined by parameter) to NULL
void Space::removeObject(int position)
{
	objects[position] = NULL;
}