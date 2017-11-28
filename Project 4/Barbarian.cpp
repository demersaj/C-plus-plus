//Barbarian class definition

#include "Barbarian.hpp"

//Constructor
Barbarian::Barbarian(string type, int armor, int strengthPoints) : Character(type, armor, strengthPoints)
{
	this->type = type;
	this->armor = armor;
	this->strengthPoints = strengthPoints;
}

//Attack function for the Barbarian - uses 2d6. Randomly picks two numbers between 1 and 6.
int Barbarian::attackFunc()
{
	int attack1 = rand() % 6 + 1;
	int attack2 = rand() % 6 + 1;
	int attackDamage = attack1 + attack2;
	this->setCurrAttackRoll(itos(attack1) + ", " + itos(attack2));
	return attackDamage;
}

//defense function for barbarian - uses 2d6
int Barbarian::defenseFunc()
{
	int def1 = rand() % 6 + 1;
	int def2 = rand() % 6 + 1;
	int def = def1 + def2;
	this->setCurrDefenseRoll(itos(def1) + ", " + itos(def2));
	return def;
}

//returns remaining srength points after damage is applied
int Barbarian::takeDamage(int totalDamage)
{
	if (totalDamage > 0)
	{
		strengthPoints -= totalDamage;
	}
	return strengthPoints;
}

//this function does nothing
int Barbarian::useSpecial()
{
	return -1;
}

