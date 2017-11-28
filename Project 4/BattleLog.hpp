/*//BattleLog class definition - used for debugging

#ifndef BattleLog_hpp
#define BattleLog_hpp

#include <string>
#include <iostream>


enum loglevel {
	CRITICAL,
	ERROR,
	WARNING,
	INFO,
	BATTLE,
	ALL
};

void battleLog(loglevel level, std::string msg);

loglevel battle_log_level = ALL;

#endif /* BattleLog_hpp */
