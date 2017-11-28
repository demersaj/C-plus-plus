//Harry Potter class declaration

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include "Character.hpp"

class HarryPotter : public Character
{
public:
	HarryPotter(string type, int armor, int strengthPoints);
	string getType();
	int getArmor();
	int getStrengthPoints();
	int takeDamage(int totalDamage);
	virtual int useSpecial();
	virtual int attackFunc();
	virtual int defenseFunc();
};

#endif /* HarryPotter_hpp */
