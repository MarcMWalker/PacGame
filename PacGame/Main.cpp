#include <iostream>
#include <Windows.h>
#include "Manager.h"


int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 500, 800, TRUE);

	Manager gameManager{};
	while (gameManager.getGameEnd() == false) {
		gameManager.gameStart();
	}
	return 0;
}