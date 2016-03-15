/*********************************************************************
** Program Filename: object.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Object class implementation file CS162_400 Final Project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "object.hpp"

//usings
using std::cout;
using std::endl;

Object::Object(string name, string description)
{
	this->name = name;
	this->description = description;
	this->powerState = false;
	this->empty = false;
}

Object::~Object()
{}

string Object::getName()
{
	return name;
}

string Object::getDescription()
{
	return description;
}

bool Object::getPowerState()
{
	return powerState;
}

void Object::setPowerState(bool powerStateIn)
{
	this->powerState = powerStateIn;
}

bool Object::getEmpty()
{
	return empty;
}

void Object::setEmpty(bool emptyIn)
{
	this->empty = emptyIn;
}