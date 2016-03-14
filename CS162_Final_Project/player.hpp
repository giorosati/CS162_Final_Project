/*********************************************************************
** Program Filename: player.hpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: Player class header file CS162_400 Final Project
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

//includes
#include <cstdlib>
#include <string>
#include <vector>
#include "space.hpp"
#include "object.hpp"

//usings
using std::string;
using std::vector;

class Player
{
protected:
	string name;
	int turnCount;
	int hydration;
	Object backpack[3];
	Object currentObject;
	Space* location;

public:
	Player();					//default constructor
	~Player();					//deconstructor
	string getName();			//returns name
	void addTurnCount();		//increments turn count by one		
	int getTurnCount();			//returns turn count
	void subtractHydration(int);//decreases hydration
	void addHydration(int);		//increases hydration
	void grabObject();			//removes object from space & makes it currentObject
	void dropObject();			//removes object from currentObject, places it in current Space
	void removeObject();		//removes an object from backpack
	void addObject();			//adds an object to backpack
	void move(int);				//moves player to a different space
	void look();				//returns the description of the current space
};

#endif