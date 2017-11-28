//Harry Potter class definition

#include "HarryPotter.hpp"

using std::cout;

//Constructor
HarryPotter::HarryPotter(string type, int armor, int strenghtPoints) : Character(type, armor, strenghtPoints)
{
	this->type = type;
	this->armor = armor;
	this->strengthPoints = strenghtPoints;
}

//Attack function for Harry Potter - uses 2d6. Randomly picks two numbers between 1 and 6. 
int HarryPotter::attackFunc()
{
	int attack1 = rand() % 6 + 1;
	int attack2 = rand() % 6 + 1;
	
	int attackDamage = attack1 + attack2;
	this->setCurrAttackRoll(itos(attack1) + ", " + itos(attack2));
	return attackDamage;
}

//Defense function for Harry Potter - uses 2d6. Randomly picks two numbers between 1 and 6.
int HarryPotter::defenseFunc()
{
	int def = rand() % 6 + 1;
	this->setCurrDefenseRoll(itos(def));
	def += HarryPotter::armor;
	return def;
}

//Returns remaining srength points after damage is applied
int HarryPotter::takeDamage(int totalDamage)
{
	if (totalDamage > 0)
	{
		strengthPoints -= totalDamage;
	}
		useSpecial();
		return strengthPoints;
}

//Hogwarts special ability. If Harry Potter's strength
int HarryPotter::useSpecial()
{
	int health = 0;
	
	if (strengthPoints <= 0)
	{
		if (health == 0)
		{
			strengthPoints = 20;
			health = 1;
			cout << "Harry Potter used Hogwarts!\n";
		}
	}
	return strengthPoints;
}
