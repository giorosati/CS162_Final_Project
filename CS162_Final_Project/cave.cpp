/*********************************************************************
** Program Filename: cave.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Cave class implementation file CS162_400 Final project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "cave.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;
using std::stringstream;

//constructor
Cave::Cave(string name, string description, string entryMessage, string look1, string look2) 
	: Space(name, description, entryMessage, look1, look2)
{}

Cave::~Cave()
{
	//cout << " deconstructor has run." << endl;
}

/*********************************************************************
** Function: move
** Description: Presents a menu to the user. User must enter 1, 2, 
** or 3. 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns 5, 9, or 1 for additional processing in main()
*********************************************************************/
int Cave::move()
{
	int move = 0;
	while (move == 0)
	{
		cout << "Where would you like to go?" << endl;
		cout << "1) Out of the cave." << endl;
		cout << "2) Further into the cave." << endl;
		cout << "3) Stay put." << endl;
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
		else if (move == 2) return 9; //move towards cliff
		else if (move == 1) return 1; //move to ravine
	}
	return move;
}

/*********************************************************************
** Function: special
** Description: Electrocutes the player. Player's turn count is 
** reduced by three and hydration is reduced by 2
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns 5 for additional processing in main()
*********************************************************************/
int Cave::special()
{
	cout << "You touch the black orb..." << endl;
	cout << "It electrocuted you...you are now unconscious" << endl;
	cout << "Press enter to wake up..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "\n\n";
	cout << "You wake up very groggy..." << endl;
	cout << "It appears you have been unconscious for quite some time." << endl;
	cout << "You lost 3 turns and 2 hydration points." << endl;
	cout << endl;
	return 5;
}