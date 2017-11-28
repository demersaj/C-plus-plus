//Character class declaration - abstract base class

#ifndef Character_hpp
#define Character_hpp

#include <string>
#include <iostream>
#include <cstdlib>

using std::string;

class Character
{
protected:
	//character attributes
	string type;
	string name;
	int armor;
	int strengthPoints;
	int maxSP;
	string currAttkRoll;
	string currDefRoll;

public:
	//character interaction functions
	Character(string type, int armor, int strengthPoints);
	~Character() {};
	string getType();
	bool isAlive();
	void printAttackStats(int damage);
	void printDefenseStats(int damage);
	int getArmor();
	int getStrengthPoints();
	string currentAttackRoll();
	string currentDefenseRoll();
	void setCurrAttackRoll(string roll);
	void setCurrDefenseRoll(string roll);
	string itos(int roll);
	void recovery();
	void setName(string name);
	string getName();
	virtual int attackFunc() = 0;
	virtual int defenseFunc() = 0;
	virtual int useSpecial() = 0;
	virtual int takeDamage(int totalDamage);
};


#endif /* Character_hpp */
