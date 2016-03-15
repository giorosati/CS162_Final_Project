/*********************************************************************
** Program Filename: treehouse.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Treehouse class implementation file CS162_400 Final project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "treehouse.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;

Treehouse::Treehouse(string name, string description, string entryMessage, string look1, string look2) //constructor
	: Space(name, description, entryMessage, look1, look2)
{}

Treehouse::~Treehouse()
{
	//cout << " deconstructor has run." << endl;
}

int Treehouse::move()
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
		else if (move == 2) return 2; //move to tower
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
int Treehouse::special()
{
	cout << "You touch the green orb..." << endl;
	cout << "A leprechan jumps out from behind a chair and startles you." << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "\n\n";
	return 7;
}