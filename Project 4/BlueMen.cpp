//BlueMen class definition

#include "BlueMen.hpp"

//Constructor
BlueMen::BlueMen(string type, int armor, int strengthPoints) : Character(type, armor, strengthPoints)
{
	this->type = type;
	this->armor = armor;
	this->strengthPoints= strengthPoints;
}

//Attack function for the BlueMen - uses 2d10. Randomly picks a number between 1 and 10 twice.
int BlueMen::attackFunc()
{
	int attack1 = rand() % 10 + 1;
	int attack2 = rand() % 10 + 1;
	int attackDamage = attack1 + attack2;
	this->setCurrAttackRoll(itos(attack1) + ", " + itos(attack2));
	return attackDamage;
}

//Defense function for the BlueMen - uses 2d10. Randomly picks three numbers between 1 and 6.
int BlueMen::defenseFunc()
{
	int def1 = rand() % 6 + 1;
	int def2 = rand() % 6 + 1;
	int def3 = rand() % 6 + 1;
	this->setCurrDefenseRoll(itos(def1) + ", " + itos(def2) + ", " + itos(def3));
	
	//Mob special ability. For every 4 points of damage the Blue Men take, they lose one defense die.
	if (BlueMen::strengthPoints >= 12)
	{
		int def = def1 + def2 + def3 + BlueMen::armor;
		return def;
	}
	else if (BlueMen::strengthPoints >= 8 && BlueMen::strengthPoints < 12)
	{
		int def = def1 + def2 + BlueMen::armor;
		return def;
	}
	else
	{
		return def1 + BlueMen::armor;
	}
}

//Returns remaining srength points after damage is applied
int BlueMen::takeDamage(int totalDamage)
{
	if (totalDamage > 0)
	{
		strengthPoints -= totalDamage;
	}
	return strengthPoints;
}

//This function does nothing
int BlueMen::useSpecial()
{
	return -1;
}
