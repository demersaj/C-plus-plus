//Vampire class definition

#include "Vampire.hpp"

//constructor
Vampire::Vampire(string type, int armor, int strengthPoints) : Character(type, armor, strengthPoints)
{
	this->type = type;
	this->armor = armor;
	this->strengthPoints = strengthPoints;
}

//Attack function for the vampire - uses 1d12. Randomly picks a number between 1 and 12
int Vampire::attackFunc()
{
	int attackDamage = rand() % 12 + 1;
	this->setCurrAttackRoll(itos(attackDamage));
	return attackDamage;
}

//Defense function for vampire - uses 1d6. Randomly picks a number between 1 and 12.
int Vampire::defenseFunc()
{
	int def = rand() % 6 + 1;
	this->setCurrDefenseRoll(itos(def));
	def += Vampire::armor;
	return def;
}

//charm special ability for the vampire. 50% chance that the opponent does not actually attack
int Vampire::useSpecial()
{
	int charm = rand() % 2; //50/50 chance
	
	if(charm) std::cout << "Vampire used charmed!\n";
	return charm;
}

//Returns remaining strength points. Also implements the charm special ability.
int Vampire::takeDamage(int totalDamage)
{
	if (totalDamage > 0)
	{
		strengthPoints -= (useSpecial()) ? 0 : totalDamage;
	}
	return strengthPoints;
}
