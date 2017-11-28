//Character class defintion

#include "Character.hpp"
#include "BattleLog.hpp"
#include <iostream>
#include <sstream>


using std::cout;

//constructor
Character::Character(string type, int armor, int strengthPoints)
{
	this->type = type;
	this->armor = armor;
	this->strengthPoints = strengthPoints;
	this->maxSP = strengthPoints;
}

//returns type of character - used for each character
string Character::getType()
{
	return type;
}

bool Character::isAlive()
{
	return (this->strengthPoints > 0); //automatically evaluates to true or false
}

//returns remaining strength points
int Character::takeDamage(int totalDamage)
{
	strengthPoints -= totalDamage;
	return strengthPoints;
}

//Returns armor
int Character::getArmor()
{
	return armor;
}

//Returns strength points
int Character::getStrengthPoints()
{
	return strengthPoints;
}

void Character::printAttackStats(int damage)
{
	std::stringstream ss;
	 {
		ss << "Attacker type: " << getType() << ".\n";
		ss << "The total damage inflicted was " << damage << " (rolled a " << currentAttackRoll() << ").\n\n";
	}
	//battleLog(BATTLE, ss.str());
}

void Character::printDefenseStats(int damage)
{
	std::stringstream ss;
		ss << "Defender type: " << getType() << ".\n";
		ss << "Defender armor: " << getArmor() << ".\n";
		ss << "The total damage taken was " <<
			(damage < 0 ? 0 : damage)
			<< " (rolled a " << currentDefenseRoll() << ").\n";
		ss << "Defender maximum strenth points: " << maxSP << ".\n";
		ss << "The defender's currently has " <<
			(getStrengthPoints() < 0 ? 0 : getStrengthPoints())
			 << " strength points.\n\n";
	
	//battleLog(BATTLE, ss.str());
}

string Character::currentAttackRoll()
{
	return currAttkRoll;
}

string Character::currentDefenseRoll()
{
	return currDefRoll;
}

void Character::setCurrAttackRoll(string roll)
{
	this->currAttkRoll = roll;
}

void Character::setCurrDefenseRoll(string roll)
{
	this->currDefRoll = roll;
}

string Character::itos(int roll)
{
	std::ostringstream oss;
	oss << roll;
	
	return oss.str();
}

//Restores a random percentage of strength points to the chacacter (up to half of their maximum SP). Can be 0.
void Character::recovery()
{
	int SP =  (0.5 * maxSP);
	int rec = rand() % SP;
	
	if ((rec + strengthPoints) > maxSP)
			strengthPoints = maxSP;
	else
			strengthPoints += rec;
	cout << "Character " << getName() << " recovered " << rec << " strength points.\n";
}

void Character::setName(string name)
{
	this->name = name;
}

string Character::getName()
{
	return name;
}
