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

/*********************************************************************
** Function: move
** Description: Presents a menu to the user. User must enter 1, 2,
** or 3.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns 5, 2, or 1 for additional processing in main()
*********************************************************************/
int Tower::move()
{
	int move = 0;
	while (move == 0)
	{
		cout << "Where would you like to go?" << endl;
		cout << "1) Down the circular stairwell." << endl;
		cout << "2) Accross the rope bridge into the mist." << endl;
		cout << "3) Stay here." << endl;
		cout << endl;
		cout << "Enter 1, 2, or 3 and press enter:" << endl;
		cin >> move;
		cin.ignore(256, '\n');
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
** Description: Create mist in the tower, then a voice gives the 
** player a big hint to solvign the game.
** Parameters: none
** Pre-Conditions:
** Post-Conditions: returns 6 to main() for additional processing
*********************************************************************/
int Tower::special()
{
	cout << "You touch the white orb..." << endl;
	cout << "A heavy mist slowy pours in through the widows..." << endl;
	cout << "Press enter to continue..." << endl;
	cin.ignore(256, '\n');
	cin.get();
	cout << "It is now at your waist..." << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	//cin.ignore(256, '\n');
	cin.get();
	cout << "It has completely filled the room...you can see nothing." << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	//cin.ignore(256, '\n');
	cin.get();
	cout << "A deep voice behind you says \n" << endl;
	cout << "\"Leprechan's like tree houses and green orbs!\"\n\n" << endl;
	cout << "Press enter to continue..." << endl;
	cin.clear();
	//cin.ignore(256, '\n');
	cin.get();
	cout << endl;
	cout << "The mist clears away..." << endl;
	cout << endl;;
	return 6;
}