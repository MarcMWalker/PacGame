#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "GameMap.h"

class Manager{
private:
	bool m_gameEnd{false};
public:
	Manager();
	void gameStart();
	void endGame();
	bool hasGameEnded();
	bool getGameEnd()const;
	bool levelEnd();
	void printGameMap(GameMap& map);
};
#endif

