/*********************************************************************
** Program Filename: main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: main.cpp file for CS162_400 Final Assignment
** This is a C++ console puzzle game.
*********************************************************************/

//includes
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>

#include "space.hpp"
#include "ravine.hpp"
#include "cave.hpp"
#include "tower.hpp"
#include "treehouse.hpp"
#include "object.hpp"

//usings
using std::cout;
using std::endl;
using std::cin;
using std::srand;
using std::rand;
using std::string;
using std::stringstream;

//function prototypes
void displayMenu();				//displays user options to console
int getInput();					//gets user input

int main()
{
	srand((unsigned)time(NULL));		//initialize random number generator
	bool done = false;					//for game exit
	bool death = false;					//player death flag
	bool happyLeprechaun = false;		//Leprechaun mood flag
	int move = 0;						//move option
	Space* location = NULL;				//current location pointer
	int turnsRemaining = 30;			//counter for number of turns
	int hydration = 10;					//hydration "tank"
	bool flashlightOn = false;			//flashlight state
	int flashDeath = 0;					//counter for death by ghost in tower
	Object* backpack[4];				//pointer to backpack array
	for (int i = 0; i < 4; i++)
	{
		backpack[i] = NULL;				//set backpack object pointers to NULL
	}
	Object* currentObject = NULL;		//object currently being held by player

	//seed the world
	//create the spaces
	Space* ravine = new Ravine("Mossy ravine", "A narrow ravine with steep moss covered sides, a stream, and gently moving dense mist...", "You are in a ravine.", "You see a gently flowing stream, a dark wet cave to your left \nthat the stream comes out of, another cave behind you, \nand in front of you is a bridge to two stone stairways, \nboth leading up into the mist. \nAt the bridge there is a clear orb atop a marble obelisk,  \nand the following items:", "");
	Space* cave1 = new Cave("Wet Cave", "A pitch black, very wet cave with a stream flowing towards the entrance.", "You are in a very wet & dark cave.", "All you can see is dim light in the direction of the cave mouth and \na black orb atop a marble obelisk. \nYou will need a light source to see what else may be here.", "You can see the dim light in the direction of the cave mouth, \na giant menacing spider furter back in the cave, \na black orb atop a marble obelisk, and the following items:");
	Space* cave2 = new Cave("Dry Cave", "A pitch black cave", "You are in a dark cave.", "All you can see is dim light in the direction of the cave mouth and \na black orb atop a marble obelisk. \nYou will need a light source to see what else may be here.", "You can see the dim light in the direction of the cave mouth, \na giant menacing spider further back in the cave, \na black orb atop a marble obelisk, and the following items:");
	Space* tower1 = new Tower("Stone Tower", "A circular room with open windows at the top of a high stone tower.", "You are in a circular room at the top of a stone tower.", "You are in a dim circular room with windows at the top of a stone tower. \nIt is very misty outside. \nYou can see stairs going down, a white orb atop a marble obelisk, \na rope bridge leading into the mist, and the following items:", "");
	Space* treehouse1 = new Treehouse("Tree House", "A rustic, weathered tree house surrounded by mist.", "You are in a rustic, weathered tree house.", "You can see stairs going down, a bright green orb atop a wooden post, \na rope bridge leading into the mist, and the following items:", "");

	//set pointers of the spaces
	ravine->setPointers(cave1, cave2, tower1, treehouse1);
	cave1->setPointers(ravine, NULL, NULL, NULL);
	cave2->setPointers(ravine, NULL, NULL, NULL);
	tower1->setPointers(ravine, treehouse1, NULL, NULL);
	treehouse1->setPointers(ravine, tower1, NULL, NULL);

	//create objects
	Object* water1 = new Object(1, "Sealed water bottle");
	Object* water2 = new Object(1, "Sealed water bottle");
	Object* water3 = new Object(1, "Sealed water bottle");
	Object* water4 = new Object(2, "1/2 empty water bottle");
	Object* water5 = new Object(2, "1/2 empty water bottle");
	Object* orb = new Object(3, "Irish green glass orb.");
	Object* knife = new Object(4, "Hunting knife");
	Object* flashlight = new Object(5, "Flashlight");

	//place objects
	cave1->addObject(water1);	 //good water to wet cave
	cave1->addObject(knife);	 //knife to wet cave
	cave1->addObject(water5);	 //bad water to wet cave
	cave2->addObject(water2);	 //good water to dry cave
	cave2->addObject(orb);		 //green orb to dry cave
	cave2->addObject(water4);	 //bad water to dry cave
	tower1->addObject(flashlight); //flashlight to tower
	treehouse1->addObject(water3);	 //good water to treehouse

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
	//cout << treehouse1->getName() << endl << treehouse1->getDescription() << endl << treehouse1->getEntryMessage() << endl << treehouse1->getLook1() << endl << treehouse1->getLook2() << endl;
	//cout << endl;

	//display instructions
	cout << endl;
	cout << endl;
	cout << "****************************************" << endl;
	cout << "Welcome to \"Make the Leprechaun Happy\" game" << endl;
	cout << endl;
	cout << "You will have 30 moves to find and please the Leprechaun. " << endl;
	cout << "Your current hydration level is 10. You loose one hydration level" << endl;
	cout << "every time you move or cancel a move." << endl;
	cout << "Drinking safe water adds 5 to your hydration level." << endl;
	cout << "This is important because if your hydration level reaches zero you die." << endl;
	cout << "You can only hold and use one item at a time, but you have a" << endl;
	cout << "backpack that holds up to three items." << endl;
	cout << "You can drop items wherever you are and they keep working..." << endl;
	cout << "Orbs exist in many places and you can touch them." << endl;
	cout << endl;
	cout << "Most importantly, if the Leprechaun doesn't laugh the world ends." << endl;
	cout << endl;
	cout << "Dangerous things exist here..." << endl;
	cout << endl;
	cout << "Please save the world!" << endl;
	cout << endl;
	cout << "HINT: " << endl;
	cout << "This puzzle / game can be solved in only 5 moves" << endl;
	cout << "and 5 \"actions\" (pick up, drop, use, touch)." << endl;
	cout << "Good luck..." << endl;
	cout << endl;
	cout << "Press enter to continue..." << endl;
	cin.get();
	cout << "You begin your journey in a cool and damp ravine." << endl;
	cout << "The steep walls are thickly covered in ferns and moss." << endl;
	cout << "A crystal clear stream gently flows by in front of you." << endl;
	cout << "Mist continually moves through the ravine creating a serene" << endl;
	cout << "feel, but visibility is limited... " << endl;
	cout << endl;
	cout << "Let the game begin..." << endl;
	

	while (done != true)
	{
		//death checks
		if (turnsRemaining < 1)
		{
			done = true;
			death = true;
		}
		else if (hydration < 1)
		{
			done = true;
			death = true;
		}
		//status update to user
		else cout << endl << "You have " << turnsRemaining << " turns left and your hydration level is " << hydration << "." << endl;
		cout << endl;
		if (hydration < 3 && hydration > 0) cout << "You are dangerously close to dying from dehydration..." << endl;
		cout << endl;
		if (!death)
		{
			cout << "Press enter to continue..." << endl;
			//cin.clear();
			//cin.ignore(256, '\n');
			cin.clear();
			//cin.get();
			cin.get();
			cout << endl;
			displayMenu();
			int menuChoice = 0;			//for menu/user inputs
			menuChoice = getInput();
			switch (menuChoice) {
			case 0:		//exit option
			{
				done = true;
				break;
			}
			case 1:		//look
			{
				if ((location == cave1 || location == cave2) && flashlightOn)
				{
					cout << endl << location->getLook2() << endl << endl;
					location->displayObjects();
				}
				else if ((location == cave1 || location == cave2) && !flashlightOn)
				{
					cout << endl << location->getLook1() << endl << endl;
				}
				else
				{
					//display location view
					cout << endl << location->getLook1() << endl << endl;
					//display objects present
					location->displayObjects();
				}
				cin.ignore(256, '\n');
				break;
			}
			case 2:		//move
			{
				move = location->move();
				switch (move)
				{
				case 1:
				{
					location = location->getPointer(1);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
				}
				break;
				case 2:
				{
					location = location->getPointer(2);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
				}
				break;
				case 3:
				{
					location = location->getPointer(3);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
				}
				break;
				case 4:
				{
					location = location->getPointer(4);
					cout << endl << location->getEntryMessage() << endl;
					turnsRemaining -= 1;
					hydration -= 1;
				}
				break;
				case 5:
				{
					cout << endl << "You have not moved. You still lose hydration when you don't move." << endl;
					cout << endl << location->getEntryMessage() << endl;
					hydration -= 1;
				}
				break;
				case 9:
				{
					cout << endl << "You have been stung by a giant spider and are being packaged" << endl;
					cout << "for future enjoyment. Game over." << endl;
					cout << "Press enter to continue." << endl;
					death = true;
					done = true;
				}
				cin.ignore(256, '\n');
				break;
				} //end of move switch
			}
			break;
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
							cout << "Press enter to continue..." << endl;
							//cin.clear();
							cin.ignore(256, '\n');
							cin.get();
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
								cout << "Press enter to continue..." << endl;
								//cin.clear();
								//cin.ignore(256, '\n');
								cin.get();
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
							else if (location == ravine)
							{
								cout << "A flashlight doesn't do much here..." << endl;
								cout << "Press enter to continue..." << endl;
								//cin.clear();
								//cin.ignore(256, '\n');
								cin.get();
							}
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
				cin.ignore(256, '\n');
				break;
			}
			case 4:		//pick up item
			{
				//test if object already being held
				if (currentObject == NULL)
				{
					if ((location == cave1 || location == cave2) && !flashlightOn)	//in cave but no light
					{
						cout << "It's too dark to see any items. Some light may help." << endl;
					}
					//test for cave location and flashlight status   OR   any other location
					else if (((location == cave1 || location == cave2) && flashlightOn) || (location != cave1 || location != cave2))
					{
						//test for items
						if (location->objectsPresent())
						{
							int choice = -1;
							int getComplete = false;
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
							}
						}
						else
						{
							cout << "No items to pick up here." << endl;
						}
					}
					/*else if ((location == cave1 || location == cave2) && !flashlightOn)
					{
						cout << endl << location->getLook1() << endl << endl;
					}*/
					//else
						//{
						//	//display location view
						//	cout << endl << location->getLook1() << endl << endl;
						//	//display objects present
						//	location->displayObjects();
						//}
				}
				else
				{
					cout << "You cannot pick up another item because you are already holding something" << endl;
				}
				cin.ignore(256, '\n');
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
				cin.ignore(256, '\n');
				break;
			}
			case 6:		//list backpack & item held
			{
				if (currentObject != NULL) cout << "You are holdling: " << endl << currentObject->getName() << endl;
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
				cin.ignore(256, '\n');
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
				cin.ignore(256, '\n');
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
				cin.ignore(256, '\n');
				break;
			}
			case 9:		//special option
			{
				int specialResult = location->special();
				switch (specialResult)
				{
				case 1:			//cases 1 to 4 are result from transporting after touching ravine orb
					location = location->getPointer(specialResult);
					turnsRemaining -= 1;
					break;
				case 2:
					location = location->getPointer(specialResult);
					turnsRemaining -= 1;
					break;
				case 3:
					location = location->getPointer(specialResult);
					turnsRemaining -= 1;
					break;
				case 4:
					location = location->getPointer(specialResult);
					turnsRemaining -= 1;
					break;
				case 5:		//touching orb in a cave
					turnsRemaining -= 3;
					hydration -= 2;
					cout << location->getEntryMessage() << endl;
					break;
				case 6:		//touching orb in tower
					hydration += 1;
					cout << "The mist has increased your hydration level 1 point." << endl;
					cout << location->getEntryMessage() << endl;
					break;
				case 7:		//touching orb in treehouse
					if (currentObject == orb)
					{
						cout << "The Leprechaun looks at the orb in your hand and begins to laugh hysterically." << endl;
						cout << "He snatches the orb from your hand and jumps out of the window!" << endl;
						happyLeprechaun = true;
						done = true;
					}
					else
					{
						cout << "The Leprechaun looks at your hand, then to the ground. \nHe stands for a moment, then retreats to behind the chair." << endl;
					}
					break;
				}
				//cin.ignore(256, '\n');
				break;  //break out of menu case 9
			}
			default:
				cout << "Not a valid choice" << endl;
				cin.ignore(256, '\n');
				break;
			}	//end of menu loop
		}
	}	//end of game while loop
	if (hydration < 1) cout << "You died from dehydration." << endl;
	if (turnsRemaining < 1) cout << "You have died from exhaustion." << endl;
	if (death) cout << endl << "Sorry you didn't make it. Try again ;-)" << endl;
	if (happyLeprechaun) cout << endl << "You are a hero! \nYou made him happy! \nYou have saved the world! \n******* Well Done! *******" << endl;
	cout << "\n\n";
	return 0;
}

//displays user options to console
void displayMenu()
{
	//cout << endl;
	cout << "Choose option and press enter" << endl;
	cout << "*****************************" << endl;
	cout << "  1) Look around" << endl;
	cout << "  2) Move" << endl;
	cout << "  3) Use the item you are holding" << endl;
	cout << "  4) Pick up an item" << endl;
	cout << "  5) Drop the item you are holding" << endl;
	cout << "  6) List backpack contents & what you are holding" << endl;
	cout << "  7) Place the item you are holding in your backpack" << endl;
	cout << "  8) Get an item from your backpack" << endl;
	cout << "  9) Touch an orb" << endl;
	cout << "  0) Exit" << endl;
	cout << endl;
}

int getInput() {	//to collect user responses to menu
	int choice;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}