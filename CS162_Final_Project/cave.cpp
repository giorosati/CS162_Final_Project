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

Cave::Cave(string name, string description, string entryMessage, string look1, string look2) //constructor
	: Space(name, description, entryMessage, look1, look2)
{}

Cave::~Cave()
{
	//cout << " deconstructor has run." << endl;
}

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

		//replaces cin >> move;
		//string stringIn;
		//getline(cin, stringIn);
		//stringstream(stringIn) >> move;
		//cin.clear();
		//cin.ignore(256, '\n');




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
** Description:
**
** Parameters: none
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Cave::special()
{
	cout << "You touch the black orb..." << endl;
	cout << "It electrocuted you...you are now unconciuos" << endl;
	cout << "Press enter to wake up..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "\n\n";
	cout << "You wake up and are very thirsty..." << endl;
	cout << "It appears you have been unconcious for quite some time." << endl;
	cout << "You lost three turns while unconcious and also lost 2 hydration points." << endl;
	cout << endl;
	return 5;
}