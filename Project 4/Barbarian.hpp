//Barbarian class declaration - inherits from Character class

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include "Character.hpp"

class Barbarian : public Character
{
protected:
	
public:
	Barbarian(string type, int armor, int strengthPoints);
	string getType();
	int getStrengthPoints();
	virtual int useSpecial();
	virtual int attackFunc();
	virtual int defenseFunc();
	virtual int takeDamage(int totalDamage);
};


#endif /* Barbarian_hpp */

