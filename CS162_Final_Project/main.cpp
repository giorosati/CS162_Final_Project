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
//#include "player.hpp"
#include "object.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;
using std::srand;
using std::rand;
using std::string;

//function prototypes
void displayMenu();			//displays user options to console
int getInput();				//gets user input
void grabObject();			//removes object from space & makes it currentObject
void dropObject();			//removes object from currentObject, places it in current Space
void removeObject();		//removes an object from backpack
void addObject();			//adds an object to backpack

int main()
{
	bool done = false;			//for menu
	bool death = false;
	int move = 0;				//for moves
	Space* location = NULL;		//current location
	int turnsRemaining = 20;	//counter for number of turns
	int hydration = 5;			//track hydration
	Object* backpack[3];		//array for objects in backpack
	Object* currentObject;		//object currently being used

	//create the spaces
	Space* ravine = new Ravine("Mossy ravine", "A narrow ravine with steep moss covered sides, a stream, and gently moving dense mist...", "You are in a ravine.", "You see a stream, a dark wet cave to your left that the stream comes out of, another cave behind you, and two stone stairs in front of you, both leading up into the mist.", "You see a stream, a dark wet cave to your left that the stream comes out of, another cave behind you, and two stone stairs in front of you, both leading up into the mist.");
	Space* cave1 = new Cave("Wet Cave", "A pitch black, very wet cave with a stream flowing towards the entrance.", "You are in a very wet & dark cave.", "All you can see is dim light in the direction of the cave mouth.", "You can see the dim light in the direction of the cave mouth and the following items:");
	Space* cave2 = new Cave("Dry Cave", "A pitch black cave", "You are in a dark cave.", "All you can see is dim light in the direction of the cave mouth.", "You can see the dim light in the direction of the cave mouth and the following items:");
	Space* tower1 = new Tower("Stone Tower", "A circular room with open windows at the top of a high stone tower.", "You are now at the top of a stone tower.", "You can see stairs going down, a rope bridge leading into the mist, and the following items:", "You can see stairs going down, a rope bridge leading into the mist, and the following items:");
	Space* tower2 = new Tower("Tree House", "A rustic, weathered tree house surrounded by mist.", "You are now in a tree house.", "You can see stairs going down, a rope bridge leading into the mist, and the following items:", "You can see stairs going down, a rope bridge leading into the mist, and the following items:");

	//set pointers of the spaces
	ravine->setPointers(cave1, cave2, tower1, tower2);
	cave1->setPointers(ravine, NULL, NULL, NULL);
	cave2->setPointers(ravine, NULL, NULL, NULL);
	tower1->setPointers(ravine, tower2, NULL, NULL);
	tower2->setPointers(ravine, tower1, NULL, NULL);

	//set start location
	location = ravine;

	//test spaces
	//cout << ravine->getName() << endl << ravine->getDescription() << endl << ravine->getEntryMessage() << endl << ravine->getLook1() << endl << ravine->getLook2() << endl;
	//cout << endl;
	//cout << cave1->getName() << endl << cave1->getDescription() << endl << cave1->getEntryMessage() << endl << cave1->getLook1() << endl << cave1->getLook2() << endl;
	//cout << endl;
	//cout << cave2->getName() << endl << cave2->getDescription() << endl << cave2->getEntryMessage() << endl << cave2->getLook1() << endl << cave2->getLook2() << endl;
	//cout << endl;
	//cout << tower1->getName() << endl << tower1->getDescription() << endl << tower1->getEntryMessage() << endl << tower1->getLook1() << endl << tower1->getLook2() << endl;
	//cout << endl;
	//cout << tower2->getName() << endl << tower2->getDescription() << endl << tower2->getEntryMessage() << endl << tower2->getLook1() << endl << tower2->getLook2() << endl;
	//cout << endl;

	//display instructions
	cout << "You will have 20 moves to complete this game. " << endl;
	cout << "You current hydration level is 5. You loose one hydration level" << endl;
	cout << "every turn. If your hydration level reaches zero you perish and the game ends." << endl;
	cout << "Good luck..." << endl;

	while (done != true)
	{
		if (turnsRemaining < 1)
		{
			cout << "You have died from exhaustion." << endl;
			done = true;
			death = true;
		}
		else if (hydration < 1)
		{
			cout << "You have died from dehydration." << endl;
			done = true;
			death = true;
		}
		else cout << endl << "You have " << turnsRemaining << " turns left and your hydration level is " << hydration << "." << endl;
		if (!death)
		{
			displayMenu();
			int menuChoice = 0;			//for menu/user inputs
			menuChoice = getInput();
			switch (menuChoice) {
			case 1:		//look
			{
				cout << endl << location->getLook1() << endl << endl;

				break;
			}
			case 2:		//move
			{
				move = location->move();
				switch (move) {
				case 1:
				{
					location = location->getPointer(1);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
					break;
				}
				case 2:
				{
					location = location->getPointer(2);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
					break;
				}
				case 3:
				{
					location = location->getPointer(3);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
					break;
				}
				case 4:
				{
					location = location->getPointer(4);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
					break;
				}
				case 5:
				{
					cout << endl << "You have not moved. You still lose hydration when you don't move." << endl;
					cout << endl << location->getEntryMessage() << endl;
					hydration -= 1;
					break;
				}
				case 9:
				{
					cout << endl << "You have been stung by a giant spider and are being packaged for future enjoyment." << endl;
					death = true;
					done = true;
					break;
				}
				} //end of move switch
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
			{
				done = true;
				break;
			}
			default:
				cout << "Not a valid choice" << endl;
				break;
			}	//end of menu loop
		}
	}	//end of game while loop
	if (death) cout << endl << "Sorry you didn't make it. Try again ;-)" << endl;
	system("pause");
	return 0;
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