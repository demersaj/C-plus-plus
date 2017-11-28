//Menu class definition

#include "Menu.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

Menu *INSTANCE = NULL;
bool teamAWon = true;
Queue TeamA;
Queue TeamB;
Stack losers;


//Default constructor
Menu::Menu()
{
	teamAPoints = 0;
	teamBPoints = 0;
}

//Starts the game - gives the user the opportunity to quit
Menu* Menu::start()
{
	bool valid = false;
	Menu* inst = NULL;
	int choice;
	
	if(INSTANCE == NULL) {
		INSTANCE = new Menu();
	}
	
	srand(time(NULL));
	cout << "Press 1 to start.\n";
	cout << "Press 2 to exit.\n";
	
	cin >> choice;
	do
	{
		if (cin.fail() || choice < 1 || choice > 2)
		{
			cout << "Invalid entry. Please enter either 1 or 2.\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choice;
		}
		else if (choice == 1)
		{
			valid = true;
			inst = INSTANCE;
		}
		else if (choice == 2)
		{
		//Set inst to NULL again
			valid = true;
			exit(0);
		}
	}
	while (valid == false);
	return inst;
}

void Menu::buildTeam(int tNum)
{
	int choice;
	
	cout << "Team " << (tNum == 1 ? ("A") : ("B") )<< " build your team.\n";
	do
	{
		cout << "Would you like to add a character to your Team? \n";
		cout << "1. Yes.\n";
		cout << "2. No.\n";
	
		cin >> choice;
		if (choice == 1)
		{
			createNewChar(tNum);
		}
	}
	while (choice == 1);
}

//Lets the players pick their characters
void Menu::createNewChar(int pNum)
{
	//Player pNum character selection
	cout << "Player " << pNum <<" please select your character.\n";
	cout << "1. Vampire\n";
	cout << "2. Barbarian\n";
	cout << "3. Blue Men\n";
	cout << "4. Medusa\n";
	cout << "5. Harry Potter\n";
	
	//Player pNum switch statement for character choice
	int choice;
	bool valid = true;
	string name;
	
	cin >> choice;
	
	while (valid == true)
	{
		if (cin.fail() || choice < 1 || choice > 5)
		{
			cout << "Invalid entry. Please enter a number between 1 and 5.\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choice;
		}
		else
		{
			valid = false;
			Character* toon = NULL;
			switch (choice)
			{
				case 1:
				{
					toon = new Vampire("Vampire", 1, 18);
					cout << "Player " << pNum << " chose Vampire.\n";
					break;
				}
				case 2:
				{
					toon = new Barbarian("Barbarian", 0, 12);
					cout << "Player " << pNum << " chose Barbarian.\n\n";
					break;
				}
				case 3:
				{
					toon = new BlueMen("Blue Men", 3, 12);
					cout << "Player " << pNum << " chose Blue Men.\n\n";
					break;
				}
				case 4:
				{
					toon = new Medusa("Medusa", 3, 8);
					cout << "Player " << pNum << " chose Medusa.\n\n";
					break;
				}
				case 5:
				{
					toon = new HarryPotter("Harry Potter", 0, 10);
					cout << "Player " << pNum << " chose Harry Potter\n";
					break;
				}
			}
			
			cout << "What would you like to name your " << toon->getType() << "?\n";
			
			
			char name[256];
			memset(name, 0,256);
			cin.get(); //Make the cin wait
			cin.getline(name, 256);
			cin.clear();
			cin.sync();
			toon->setName(name);
			
			if (pNum == 1)
			{
				TeamA.addBack(toon);
			}
			if (pNum == 2)
			{
				TeamB.addBack(toon);
			}
		}
	}
}

//Battle between teams
void Menu::battleTeams()
{
	int round = 1;
	
	do
	{
		//Pop the front character.
		Character *CharA = TeamA.getFront();
		TeamA.removeFront();
		
		Character *CharB = TeamB.getFront();
		TeamB.removeFront();
		
		//Surviving character is pushed into their respective queue
		battle(CharA, CharB);

		//Prints out stats for each round (Type of character, name, and winner).
		cout << "Round " << round << ": Team A's " << CharA->getType() << " named " << CharA->getName() << " vs "
		<< "Team B's " << CharB->getType() << " named " << CharB->getName() << ". ";
		
		if (teamAWon == true)
			cout << "Team A's " << CharA->getType() << " " << CharA->getName() << " won!\n\n";
		else if (teamAWon == false)
			cout << "Team B's " << CharB->getType() << " " << CharB->getName() << " won!\n\n";
		
		//Keeps track of points for each team
		cout << "Team A has " << getTeamAPoints() << " points.\n";
		cout << "Team B has " << getTeamBPoints() << " points.\n\n";
	}
	while (TeamA.isEmpty() == false && TeamB.isEmpty() == false);
}

//Controls battle between two characters
void Menu::battle(Character *CharA, Character *CharB)
{	
	int dmg;
	bool fighting = true;
	
	while(fighting)
	{
		//Checks players' strength points to see if one is dead
		if (!CharA->isAlive() && !CharB->isAlive())
		{
			//Both combatants are dead
			losers.addBack(CharA);
			losers.addBack(CharB);
			fighting = false;
		}
		//Character B is dead
		else if (!CharB->isAlive())
		{
			cout << "Team 2's " << CharB->getType() << " is dead.\n";
			//Character B goes to loser stack
			losers.addBack(CharB);
			//Character A goes to back of queue Team A
			TeamA.addBack(CharA);
			CharA->recovery();
			addTeamBPoints();
			teamAWon = false;
			fighting = false;
		}
		//Character A is dead
		else if (!CharA->isAlive())
		{
			cout << "Team 1's " << CharA->getType() << " is dead.\n";
			//Character A goes to loser stack
			losers.addBack(CharA);
			//Character B goes to back of queue Team B
			TeamB.addBack(CharB);
			CharB->recovery();
			addTeamAPoints();
			teamAWon = true;
			fighting = false;
		}
		else //Both are alive. can attack simultaneously
		{
			//Player 1 attacks player 2
			dmg = CharA->attackFunc();
			CharA->printAttackStats(dmg);
			dmg -= CharB->defenseFunc();
			CharB->takeDamage(dmg);
			CharB->printDefenseStats(dmg);
			
			//player 2 attacks player 1
			dmg = CharB->attackFunc();
			CharB->printAttackStats(dmg);
			dmg -= CharA->defenseFunc();
			CharA->takeDamage(dmg);
			CharA->printDefenseStats(dmg);
		}
	} //ends fighting while loop
}

//Prints the final score for each team, along with the winner of the tournament. Also gives option to print loser stack.
void Menu::printFinalStats()
{
	int input;
	bool valid = false;
	
	if (getTeamAPoints() > getTeamBPoints())
		cout << "Team A won with " << getTeamAPoints() << " points!\n";
	else if (getTeamAPoints() < getTeamBPoints())
		cout << "Team B won with "<< getTeamBPoints() << " points!\n";
	else
		cout << "Tie game.\n";
	
	cout << "\nWould you like to display the loser pile?\n";
	cout << "1. Yes.\n";
	cout << "2. No.\n";
	cin >> input;
	do
	{
		if (cin.fail() || input < 1 || input > 2)
		{
			cout << "Invalid entry. Please enter either 1 or 2.\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;
		}
		else if (input == 1)
		{
			losers.printStack();
			valid = true;
		}
		else if (input == 2)
			break;
	}
	while (valid == false);
}

//Asks user if they would like to run the program again
bool Menu::playAgain()
{
	int choice;
	bool valid = false;
	
	cout << "Would you like to play again?\n";
	cout << "1. Play again.\n";
	cout << "2. Exit the game.\n";
	
	cin >> choice;
	
	//Validates user input
	do
	{
		//If user didn't enter a valid integer
		if (cin.fail() || choice < 1 || choice > 2)
		{
			cout << "Invalid entry. Please enter 1 or 2.\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> choice;
		}
		else if (choice == 1)
		{
			valid = true;
			//Clears out the players vector to start over
			TeamA.clearQueue();
			TeamB.clearQueue();
			losers.clearStack();
		}
		else if (choice == 2)
		{
			valid = true;
			exit(0);
		}
		
	}
	while (valid == false);
	return choice == 1;
}

//Getter and setter functions for points
int Menu::getTeamAPoints()
{
	return teamAPoints;
}

void Menu::addTeamAPoints()
{
	teamAPoints++;
}

int Menu::getTeamBPoints()
{
	return teamBPoints;
}

void Menu::addTeamBPoints()
{
	teamBPoints++;
}

