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
void displayMenu();				//displays user options to console
int getInput();					//gets user input
void grabObject(Object*);		//removes object from space & makes it currentObject
void dropObject(Object*);		//removes object from currentObject, places it in current Space
void removeObject(Object*);		//removes an object from backpack
void addObject(Object*);		//adds an object to backpack
//bool objectsPresent();			//returns true if any objects in backpack, otherwise false

int main()
{
	bool done = false;					//for menu
	bool death = false;
	int move = 0;						//for moves
	Space* location = NULL;				//current location
	int turnsRemaining = 20;			//counter for number of turns
	int hydration = 5;					//track hydration
	bool flashlightOn = false;			//track flashlight state
	int flashDeath = 0;					//counter for potential death in tower1
	Object* backpack[4];				//array for objects in backpack
	for (int i = 0; i < 4; i++)
	{
		backpack[i] = NULL;				//set backpack object pointers to NULL
	}
	Object* currentObject = NULL;		//object currently being used

	//populate the world
	//create the spaces
	Space* ravine = new Ravine("Mossy ravine", "A narrow ravine with steep moss covered sides, a stream, and gently moving dense mist...", "You are in a ravine.", "You see a stream, a dark wet cave to your left that the stream comes out of, another cave behind you, and two stone stairs in front of you, both leading up into the mist.", "You see a stream, a dark wet cave to your left that the stream comes out of, another cave behind you, and two stone stairs in front of you, both leading up into the mist.");
	Space* cave1 = new Cave("Wet Cave", "A pitch black, very wet cave with a stream flowing towards the entrance.", "You are in a very wet & dark cave.", "All you can see is dim light in the direction of the cave mouth. Some light would let you see more.", "You can see the dim light in the direction of the cave mouth, a giant spider further back in the cave, and the following items:");
	Space* cave2 = new Cave("Dry Cave", "A pitch black cave", "You are in a dark cave.", "All you can see is dim light in the direction of the cave mouth. Some light would let you see more.", "You can see the dim light in the direction of the cave mouth, a giant spider further back in the cave, and the following items:");
	Space* tower1 = new Tower("Stone Tower", "A circular room with open windows at the top of a high stone tower.", "You are now at the top of a stone tower.", "You can see stairs going down, a rope bridge leading into the mist, and the following items:", "You can see stairs going down, a rope bridge leading into the mist, and the following items:");
	Space* tower2 = new Tower("Tree House", "A rustic, weathered tree house surrounded by mist.", "You are now in a tree house.", "You can see stairs going down, a rope bridge leading into the mist, and the following items:", "You can see stairs going down, a rope bridge leading into the mist, and the following items:");

	//set pointers of the spaces
	ravine->setPointers(cave1, cave2, tower1, tower2);
	cave1->setPointers(ravine, NULL, NULL, NULL);
	cave2->setPointers(ravine, NULL, NULL, NULL);
	tower1->setPointers(ravine, tower2, NULL, NULL);
	tower2->setPointers(ravine, tower1, NULL, NULL);

	//create objects
	Object* water1 = new Object(1, "Sealed water bottle");
	Object* water2 = new Object(1, "Sealed water bottle");
	Object* water3 = new Object(1, "Sealed water bottle");
	Object* water4 = new Object(2, "1/2 empty water bottle");
	Object* orb = new Object(3, "Dark blue glass orb.");
	Object* knife = new Object(4, "Hunting knife");
	Object* flashlight = new Object(5, "Flashlight");

	//place objects
	cave1->addObject(water1);
	cave1->addObject(knife);
	cave2->addObject(water2);
	cave2->addObject(water4);
	tower1->addObject(water3);
	tower1->addObject(flashlight);
	tower2->addObject(orb);

	//for testing
	//test objects in space arrays
	//cout << "Objects in ravine: " << endl;
	//ravine->displayObjects();
	//cout << "Objects in cave1: " << endl;
	//cave1->displayObjects();
	//cout << "Objects in cave2: " << endl;
	//cave2->displayObjects();
	//cout << "Objects in tower1: " << endl;
	//tower1->displayObjects();
	//cout << "Objects in tower2: " << endl;
	//tower2->displayObjects();

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
	cout << "every turn. Drinking safe water adds 5 to your hydration level." << endl;
	cout << "If your hydration level reaches zero you die." << endl;
	cout << "Dangerous creatures exist in this realm..." << endl;
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
				//display locations views
				cout << endl << location->getLook1() << endl << endl;
				//display objects present
				location->displayObjects();
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
				//test if object being held
				if (currentObject != NULL)
				{
					int id = currentObject->getId();
					switch (id)
					{
					case 1:		//sealed water bottle
					{
						cout << "You are holding a sealed water bottle." << endl;
						cout << "Do you want to drink it? (1 for Yes, 2 for No)" << endl;
						int choice = getInput();
						if (choice == 1)
						{
							hydration += 5;
							cout << "Your hydration level is now " << hydration << endl;
							currentObject->setId(6);
							currentObject->setName("Empty water bottle");
							cout << "FYI, you are holding an empty bottle." << endl;
						}
						else if (choice == 2)
						{
							cout << "OK, you did not drink the water. You are still holdling the bottle." << endl;
						}
						else cout << "Invalid response. Item has not been used." << endl << endl;
					}
					break;
					case 2:		//comprimised water bottle
					{
						cout << "You are holding a 1/2 full water bottle." << endl;
						cout << "Do you want to drink it? (1 for Yes, 2 for No)" << endl;
						int choice = getInput();
						if (choice == 1)
						{
							cout << "Bad choice...you are now dead." << endl;
							currentObject->setId(6);
							currentObject->setName("Empty water bottle");
							death = true;
							done = true;
						}
						else if (choice == 2)
						{
							cout << "OK, you did not drink the water. You are still holdling the bottle." << endl;
						}
						else cout << "Invalid response. Item has not been used." << endl << endl;
					}
					break;
					case 3:		//glass orb
					{
						cout << "You are holding a glass orb." << endl;
						cout << "Do you want to use it? (1 for Yes, 2 for No)" << endl;
						int choice = getInput();
						if (choice == 1)
						{
							if (location == tower1)
							{
								cout << "Congratulations you have completed the game." << endl;
								done = true;
							}
							else cout << "The orb doesn't seem to do anything here..." << endl;
						}
						else if (choice == 2)
						{
							cout << "OK, you are still holdling the orb." << endl;
						}
						else cout << "Invalid response. Orb has not been used." << endl << endl;
					}
					break;
					case 4:		//knife
					{
						cout << "You are holding a very sharp hunting knife." << endl;
						cout << "Do you want to use it? (1 for Yes, 2 for No)" << endl;
						int choice = getInput();
						if (choice == 1)
						{
							if (location == cave1 || location == cave2)
							{
								int choice;
								cout << "Enter 1 to kill yourself. This will save time..." << endl;
								cout << "Enter 2 to throw the kife towards the back of the cave." << endl;
								choice = getInput();
								if (choice == 1)
								{
									cout << "You are dead. Game over..." << endl;
									death = true;
									done = true;
								}
								else if (choice == 2) cout << "Congratulations, you have killed a giant spider." << endl;
								else cout << "Invalid choice nothing has been done, you are still holding the knife." << endl;
							}
							else
							{
								int choice;
								cout << "Enter 1 to kill yourself. This will save time..." << endl;
								cout << "Enter 2 to throw the kife." << endl;
								choice = getInput();
								if (choice == 1)
								{
									cout << "You are dead. Game over..." << endl;
									death = true;
									done = true;
								}
								else if (choice == 2)
								{
									cout << "Such bravado..." << endl;
									location->addObject(currentObject);
									currentObject = NULL;
								}
								else cout << "Invalid choice nothing has been done, you are still holding the knife." << endl;
							}
						}
						else if (choice == 2)
						{
							cout << "OK, you are still holdling the knife." << endl;
						}
						else cout << "Invalid response. Knife has not been used." << endl << endl;
					}
					break;
					case 5:		//flashlight
					{
						cout << "You are holding a flashlight." << endl;
						if (flashlightOn == true) cout << "It is already on...." << endl;
						if (location == tower1 && flashlightOn)
						{
							cout << "The tower ghost doesn't like flashlights." << endl;
							cout << "He turned it off." << endl;
							flashlightOn = false;
							flashDeath += 1;
							if (flashDeath >= 3)
							{
								cout << "You really pissed off the tower ghost. He pushed you out the" << endl;
								cout << "window to your death. Game over." << endl;
								death = true;
								done = true;
							}
						}
						cout << "Do you want the flashlight on or off? (1 for On, 2 for Off)" << endl;
						int choice = getInput();
						if (choice == 1)
						{
							flashlightOn = true;
							cout << "Flashlight on." << endl;
							if (location == cave1 || location == cave2)
							{
								cout << "You may want to have a look around..." << endl;
							}
							else if (location == tower1)
							{
								cout << "The tower ghost doesn't like flashlights." << endl;
								cout << "He turned it off and threw it out the window." << endl;
								flashDeath += 1;
								flashlightOn = false;
								ravine->addObject(currentObject);
								currentObject = NULL;
								if (flashDeath >= 3)
								{
									cout << "You really pissed off the tower ghost. He pushed you out the" << endl;
									cout << "window to your death. Game over." << endl;
									death = true;
									done = true;
								}
							}
							else if (location = ravine) cout << "A flashlight doesn't do much here..." << endl;
							else cout << "You might want to have a look around..." << endl;
						}
						else if (choice == 2)
						{
							cout << "Flashlight is off." << endl;
						}
						else cout << "Invalid response. No change to flashlight." << endl << endl;
					}
					break;
					case 6:
					{
						cout << "You are holding an empty water bottle." << endl;
						cout << "Not much you can do with that..." << endl;
					}
					break;
					default:
						cout << "Not a valid choice" << endl;
						break;
					}
				}
				else
				{
					cout << "You are not holding anything." << endl;
				}
				break;
			}
			case 4:		//pick up item
			{
				//test if object already being held
				if (currentObject == NULL)
				{
					int choice = -1;
					int getComplete = false;
					//test for items
					if (location->objectsPresent())
					{
						while (choice = -1 && getComplete == false)
						{
							location->displayObjects();		//display item list
							cout << endl;
							cout << "Enter the Item # and press enter." << endl;
							choice = getInput();			//user selects item
							if (choice > -1 && choice < 10)	//test for valid choice
							{
								if (location->getObject(choice) != NULL)
								{
									currentObject = (location->getObject(choice)); //add object to currentObject
									location->removeObject(choice);		//remove object from space
									cout << "You are now holding " << currentObject->getName() << endl;
									getComplete = true;
								}
								else
								{
									cout << "Incorrect choice. Try again" << endl;
									choice = -1;
								}
							}
							else
							{
								cout << "Incorrect choice. Try again" << endl;
								choice = -1;
							}
						}
					}
					else
					{
						cout << "No items to pick up here." << endl;
					}
				}
				else
				{
					cout << "You cannot pick up another item because you are already holding something" << endl;
				}
				break;
			}
			case 5:		//drop item
			{
				//test if object already being held
				if (currentObject != NULL)
				{
					//int complete = false;
					//add object to space
					location->addObject(currentObject);
					currentObject = NULL;
					cout << "You have dropped the item." << endl;
					//complete = true;
				}
				else
				{
					cout << "You are not holding anything, nothing to drop" << endl;
				}
				break;
			}
			case 6:		//list backpack
			{
				if (currentObject != NULL) cout << "You are holdling: " << currentObject->getName() << endl;
				else cout << "You are not holding anything" << endl;
				cout << endl;
				bool noObjects = true;
				cout << "Backpack contents: " << endl;
				for (int i = 0; i < 4; i++)
				{
					if (backpack[i] != NULL)
					{
						cout << "Item # " << i << "   " << backpack[i]->getName() << endl;
						noObjects = false;
					}
				}
				if (noObjects) cout << "No items." << endl;
				cout << endl;
				break;
			}
			case 7:		//put item in backpack
			{
				//test if object being held
				if (currentObject != NULL)
				{
					int complete = false;
					for (int i = 0; i < 4; i++)
					{
						if (!complete && backpack[i] == NULL)
						{
							backpack[i] = currentObject;
							complete = true;
						}
					}
					if (complete)
					{
						currentObject = NULL;
						cout << "The item has been placed in your backpack." << endl;
					}
					else cout << "Backpack is full. Item not placed in backpack.";
				}
				else
				{
					cout << "You are not holding anything to put in the backpack." << endl;
				}
				break;
			}
			case 8:		//get item from backpack
			{
				//test if object already being held
				if (currentObject == NULL)
				{
					int choice = -1;
					int complete = false;
					//test for items
					bool isEmpty = true;
					for (int i = 0; i < 4; i++)
					{
						if (isEmpty && backpack[i] != NULL) isEmpty = false;
					}
					if (!isEmpty)
					{
						while (choice == -1 && complete == false)
						{
							//display item list
							for (int i = 0; i < 4; i++)
							{
								if (backpack[i] != NULL)
								{
									cout << "Item # " << i << "   " << backpack[i]->getName() << endl;
								}
							}
							cout << endl;
							cout << "Enter the Item # and press enter." << endl;
							choice = getInput();			//user selects item
							if (choice > -1 && choice < 4)	//test for valid choice
							{
								if (backpack[choice] != NULL)
								{
									currentObject = backpack[choice];
									backpack[choice] = NULL;			//remove object from backpack
									cout << "You are now holding " << currentObject->getName() << endl;
									complete = true;
								}
								else
								{
									cout << "Incorrect choice. Try again" << endl;
									choice = -1;
								}
							}
							else
							{
								cout << "Incorrect choice. Try again" << endl;
								choice = -1;
							}
						}
					}
					else
					{
						cout << "No items in backpack." << endl;
					}
				}
				else
				{
					cout << "You cannot get something from the backpack because you are already holding something" << endl;
				}
				break;
			}
			case 9:		//exit option
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
	cout << "  6) List backpack contents & what you holding" << endl;
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