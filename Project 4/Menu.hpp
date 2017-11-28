//Menu class declaration

#ifndef Menu_hpp
#define Menu_hpp

#include "Character.hpp"
#include <vector>

class Menu
{
private:
	Menu();
	int teamAPoints;
	int teamBPoints;

public:
	static Menu* start();
	void createNewChar(int pNum);
	void buildTeam(int tNum);
	void battle(Character *CharA, Character *CharB);
	void battleTeams();
	bool playAgain();
	void printFinalStats();
	int getTeamAPoints();
	void addTeamAPoints();
	int getTeamBPoints();
	void addTeamBPoints();
};

#endif /* Menu_hpp */
