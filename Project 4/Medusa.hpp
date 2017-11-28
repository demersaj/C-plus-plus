//Medusa class declaration

#ifndef Medusa_hpp
#define Medusa_hpp

#include "Character.hpp"

class Medusa : public Character
{
public:
	Medusa(string type, int armor, int strengthPoints);
	string getType();
	int getArmor();
	int getStrengthPoints();
	int takeDamage(int totalDamage);
	virtual int useSpecial();
	virtual int attackFunc();
	virtual int defenseFunc();
};

#endif /* Medusa_hpp */
