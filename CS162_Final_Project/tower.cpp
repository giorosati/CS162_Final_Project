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
using std::cin;

Tower::Tower(string name, string description, string entryMessage, string look1, string look2) //constructor
	: Space(name, description, entryMessage, look1, look2)
{}

Tower::~Tower()
{
	//cout << " deconstructor has run." << endl;
}

int Tower::move()
{
	int move = 0;
	while (move == 0)
	{
		cout << "Where would you like to go?" << endl;
		cout << "1) Down the stairs." << endl;
		cout << "2) Accross the rope bridge." << endl;
		cout << "3) Stay put." << endl;
		cout << endl;
		cout << "Enter 1, 2, or 3 and press enter:" << endl;
		cin >> move;
		if (move != 1 && move != 2 && move != 3)
		{
			cout << "Invalid response. " << endl;
			move = 0;
		}
		else if (move == 3) return 5; //stay put option
		else if (move == 2) return 2; //move to treehouse
		else if (move == 1) return 1; //move to ravine
	}
	return move;
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
	cout << "You touch the white orb..." << endl;
	cout << "A heavy mist slowy pours in through the widows..." << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "It is now at your waist..." << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "It has completely filled the room...you can see nothing." << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "A deep voice behind you says \n" << endl;
	cout << "\"Leprechan's like tree houses and green orbs!\"\n\n" << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "\n\n";
	cout << "The mist clears away..." << endl;
	cout << "\n\n";
	return 6;
}