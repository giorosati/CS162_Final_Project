/*********************************************************************
** Program Filename: ravine.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-12
** Description: Ravine class implementation file CS162_400 Final project
*********************************************************************/

//includes
#include <cstdlib>
#include <iostream>
#include "ravine.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;

Ravine::Ravine(string name, string description, string entryMessage, string look1, string look2) //constructor
	: Space(name, description, entryMessage, look1, look2)
{}

Ravine::~Ravine()
{
	//cout << " deconstructor has run." << endl;
}

int Ravine::move()
{
	int move = 0;
	while (move == 0)
	{
		cout << "Where would you like to go?" << endl;
		cout << "1) Into the cave with the stream." << endl;
		cout << "2) Into the dry cave." << endl;
		cout << "3) Up the stairs to the left." << endl;
		cout << "4) Up the stairs to the right." << endl;
		cout << "5) Stay put." << endl;
		cout << endl;
		cout << "Enter 1, 2, 3, 4, or 5 and press enter:" << endl;
		cin >> move;
		if (move != 1 && move != 2 && move != 3 && move != 4 && move !=5)
		{
			cout << "Invalid response. " << endl;
			move = 0;
		}
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
int Ravine::special()
{
	cout << "You touched the clear orb..." << endl;
	cout << "You just blacked out..." << endl;
	cout << "Press enter to wake up..." << endl;
	cin.clear();
	cin.ignore(256, '\n');
	cin.get();
	cout << "\n\n\n";
	cout << "Your eyes open, and you are not where you were..." << endl;
	cout << "You stand up...you are OK. Better have a look around." << endl;
	int specialResult = rand() % 4 + 1;  //generates random int between 1 and 4
	return specialResult;
}