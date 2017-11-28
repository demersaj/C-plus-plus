//Andrew Demers
//11/19/17
//Project 4 - Fantasy Combat Game part 2

#include <iostream>
#include "Menu.hpp"

int main()
{
	Menu *m = Menu::start();
	do {
		m->buildTeam(1);
		m->buildTeam(2);
		m->battleTeams();
		m->printFinalStats();
	}
	while (m->playAgain());
	
	return 0;
}
