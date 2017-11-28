//Vampire class declaration - inherited from Character class

#ifndef Vampire_hpp
#define Vampire_hpp

#include "Character.hpp"

class Vampire : public Character
{
protected:

public:
	Vampire(string type, int armor, int strengthPoints);
	string getType();
	int getArmor();
	int getStrengthPoints();
	int takeDamage(int totalDamage);
	virtual int useSpecial();
	virtual int attackFunc();
	virtual int defenseFunc();
};

#endif /* Vampire_hpp */
