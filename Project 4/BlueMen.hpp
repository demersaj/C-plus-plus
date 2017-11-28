//BlueMen class declaration - inherits from Character class

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include "Character.hpp"

class BlueMen : public Character
{
protected:
	
public:
	BlueMen(string type, int armor, int strengthPoints);
	string getType();
	int getArmor();
	int getStrengthPoints();
	int takeDamage(int totalDamage);
	virtual int useSpecial();
	virtual int attackFunc();
	virtual int defenseFunc();
};

#endif /* BlueMen_hpp */
