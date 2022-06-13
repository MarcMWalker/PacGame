#include "GameMap.h"

void GameMap::printMap()const {
	for (int i{ 0 }; i < 30; i++) {
		for (int j{ 0 }; j < 21; j++) {
			std::cout << m_zone[i][j];
		}
		std::cout << '\n';
	}
}

int GameMap::getPebbles()const {
	return m_pebbles;
}