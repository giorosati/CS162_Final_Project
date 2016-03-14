/*********************************************************************
** Program Filename: main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: main.cpp file for CS162_400 Assignment 4
*********************************************************************/

//includes
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

#include "space.hpp"
#include "ravine.hpp"
#include "cave.hpp"
#include "tower.hpp"
#include "player.hpp"
#include "object.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;
using std::srand;
using std::rand;
using std::string;

//function prototypes
//displays user options to console
void displayMenu();
//gets user input
int getInput();
//create the world
//void createWorld();

int main()
{
	bool done = false;			//for menu
	//create the spaces
	Space* ravine = new Ravine("Mossy ravine", "A narrow ravine with steep moss covered sides, a stream, and gently moving dense mist...", "You are in a ravine", "You see a stream, a dark wet cave to your left that the stream comes out of, another cave behind you, and two stone stairs in front of you, both leading up into the mist.", "You see a stream, a dark wet cave to your left that the stream comes out of, another cave behind you, and two stone stairs in front of you, both leading up into the mist.");
	Space* cave1 = new Cave("Wet Cave", "A pitch black, very wet cave with a stream flowing towards the entrance.", "You are in a very wet & dark cave.", "All you can see is dim light in the direction of the cave mouth.", "You can see the dim light in the direction of the cave mouth and the following items:");
	Space* cave2 = new Cave("Dry Cave", "A pitch black cave", "You are in a dark cave.", "All you can see is dim light in the direction of the cave mouth.", "You can see the dim light in the direction of the cave mouth and the following items:");
	Space* tower1 = new Tower("Stone Tower", "A circular room with open windows at the top of a high stone tower.", "You are now at the top of a stone tower.", "You can see stairs going down, a rope bridge leading into the mist, and the following items:", "You can see stairs going down, a rope bridge leading into the mist, and the following items:");
	Space* tower2 = new Tower("Tree House", "A rustic, weathered tree house surrounded by mist.", "You are now in a tree house.", "You can see a rope ladder descending into the mist, a rope bridge leading into the mist, and the following items:", "You can see a rope ladder descending into the mist, a rope bridge leading into the mist, and the following items:");
	
	//test spaces
	cout << ravine->getName() << endl << ravine->getDescription() << endl << ravine->getEntryMessage() << endl << ravine->getLook1() << endl << ravine->getLook2() << endl;
	cout << endl;
	cout << cave1->getName() << endl << cave1->getDescription() << endl << cave1->getEntryMessage() << endl << cave1->getLook1() << endl << cave1->getLook2() << endl;
	cout << endl;
	cout << cave2->getName() << endl << cave2->getDescription() << endl << cave2->getEntryMessage() << endl << cave2->getLook1() << endl << cave2->getLook2() << endl;
	cout << endl;
	cout << tower1->getName() << endl << tower1->getDescription() << endl << tower1->getEntryMessage() << endl << tower1->getLook1() << endl << tower1->getLook2() << endl;
	cout << endl;
	cout << tower2->getName() << endl << tower2->getDescription() << endl << tower2->getEntryMessage() << endl << tower2->getLook1() << endl << tower2->getLook2() << endl;
	cout << endl;

	while (done != true)
	{
		displayMenu();
		int menuChoice = 0;			//for menu/user inputs
		menuChoice = getInput();
		switch (menuChoice) {
		case 1:		//look
		{
			break;
		}
		case 2:		//move
		{
			break;
		}
		case 3:		//use item
		{
			break;
		}
		case 4:		//pick up item
		{
			break;
		}
		case 5:		//drop an item
		{
			break;
		}
		case 6:		//list backpack
		{
			break;
		}
		case 7:		//put item in backpack
		{
			break;
		}
		case 8:		//get item from backpack
		{
			break;
		}
		case 9:		//exit
			done = true;
			break;
		default:
			cout << "Not a valid choice" << std::endl;
			break;
		}

		return 0;
	}
}

//displays user options to console
void displayMenu()
{
	cout << endl;
	cout << "Choose option and press enter" << endl;
	cout << "*****************************" << endl;
	cout << "  1) Look around" << endl;
	cout << "  2) Move" << endl;
	cout << "  3) Use the item you are holding" << endl;
	cout << "  4) Pick up an item" << endl;
	cout << "  5) Drop an item" << endl;
	cout << "  6) List backpack contents" << endl;
	cout << "  7) Place an item in your backpack" << endl;
	cout << "  8) Get an item from your backpack" << endl;
	cout << "  9) Exit" << endl;
	cout << endl;
}

int getInput() {	//to collect user responses to menu
	int choice;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}


