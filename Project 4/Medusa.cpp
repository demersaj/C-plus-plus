//Medusa class definition

#include "Medusa.hpp"

//Constructor
Medusa::Medusa(string type, int armor, int strengthPoints) : Character(type, armor, strengthPoints)
{
	this->type = type;
	this->armor = armor;
	this->strengthPoints = strengthPoints;
}

//Attack function for Medusa - uses 2d6. Randomly picks two numbers between 1 and 6.
//Also implements the glare special ability - if Medusa rolls a 12, it automatically wins.
int Medusa::attackFunc()
{
	int attack1 = rand() % 6 + 1;
	int attack2 = rand() % 6 + 1;
	this->setCurrAttackRoll(itos(attack1) + ", " + itos(attack2));
	
	return (attack1 + attack2 == 12) ? 20 : attack1 + attack2;
}

//Defense function for Medusa - uses 1d6. Randomly picks a number between 1 and 6.
int Medusa::defenseFunc()
{
	int def = rand() % 6 + 1;
	this->setCurrDefenseRoll(itos(def));
	return (def + Medusa::armor);
}

//Returns remaining strength points after damage is applied.
int Medusa::takeDamage(int totalDamage)
{
	if (totalDamage > 0)
	{
		strengthPoints -= totalDamage;
	}
	return strengthPoints;
}

//This function does nothing
int Medusa::useSpecial()
{
	return -1;
}
