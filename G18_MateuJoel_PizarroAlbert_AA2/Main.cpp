//Main.cpp
#include "InputManager.h"
#include "Player.h"
#include "Constants.h"


int main() {
	InputManager inputManager;
	int playerCount = 0;
	Player p1({ 0, 0 }, playerCount);
	playerCount++;
	Player p2({ 1, 1 }, playerCount);
	playerCount++;

	p1.PrintPlayer();
	p2.PrintPlayer();

	bool gameOver = false;
	while (!gameOver) {



	}


	return 0;
}
