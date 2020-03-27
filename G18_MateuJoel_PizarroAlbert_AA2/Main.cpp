//Main.cpp
#include "InputManager.h"
#include "Player.h"
#include "Map.h"
#include "Constants.h"
#include <Windows.h>


int main() {
	InputManager inputManager;
	Player player1, player2;
	Map map;
	map.ReadConfigTXT(player1, player2);

	//player1.PrintPlayer();
	//player2.PrintPlayer();

	bool gameOver = false;
	while (!gameOver) {
		//Inputs
		inputManager.Update();

		//Update
		map.Refresh(player1, player2, inputManager);
		if (inputManager.GetKey(Inputs::ESC)) gameOver = true;

		//Draw
		map.PrintMap();
		Sleep(1000);
		system("cls");


	}


	return 0;
}
