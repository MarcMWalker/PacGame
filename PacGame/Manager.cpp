#include <Windows.h>
#include "Manager.h"
#include "GameMap.h"

Manager::Manager(){}

void ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Manager::gameStart() {
	GameMap map;
	while (map.getPebbles() > 0) {
		std::cout << "GAME STARTED\n";
		ShowConsoleCursor(false);
		printGameMap(map);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}
}

bool Manager::levelEnd() {
	return true;
}

void Manager::printGameMap(GameMap& map){
	map.printMap();
}


void Manager::endGame() {
	if (hasGameEnded() == true) {
		std::cout << "GAME ENDING...\n";
		m_gameEnd = true;
	}
	else {
		std::cout << "STARTING AGAIN...\n";
		m_gameEnd = false;
	}
}

bool Manager::hasGameEnded() {
	
	std::cout << "Try Again? Y/N: ";
	char choice{' '};

	while (choice != 'Y' && choice != 'N') {
		std::cin >> choice;
		choice = toupper(choice);
		
		if (choice != 'Y' && choice != 'N') {
			std::cout << "Incorrect Input\n";
			std::cout << "Try Again? Y/N: ";
		}
		else {
			if (choice == 'Y')
				return false;
			return true;
		}
	}
}

bool Manager::getGameEnd()const{
	return m_gameEnd;
}
