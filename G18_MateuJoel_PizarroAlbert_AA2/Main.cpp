//Main.cpp
#include "InputManager.h"
#include "Player.h"
#include "Map.h"
#include "Constants.h"
#include "Utils.h"
#include <Windows.h>


int main() {
	InputManager inputManager;
	Player player1, player2;
	Map map;

	//player1.PrintPlayer();
	//player2.PrintPlayer();

	GameState gameState = GameState::INIT;
	while (gameState != GameState::GAME_OVER) {
		switch (gameState)
		{
		case GameState::INIT:
			map.ReadConfigTXT(player1, player2);

			gameState = GameState::PLAY;
			break;

		case GameState::PLAY:
			//Inputs
			inputManager.Update();

			//Update
			map.Refresh(player1, player2, inputManager);
			if (inputManager.GetKey(Inputs::PAUSE)) {
				//Fer gestió de les variables necessaries (recordar parar temps a tot)
				gameState = GameState::PAUSE;
			}
			if (inputManager.GetKey(Inputs::ESC)) gameState = GameState::GAME_OVER;

			//Draw
			map.PrintMap();
			Utils::PrintScores(player1.score, player2.score);

			break;

		case GameState::PAUSE:
			//Inputs
			inputManager.Update();

			//Update
			if (inputManager.GetKey(Inputs::BOMB_1))
				gameState = GameState::PLAY;
			else if (inputManager.GetKey(Inputs::ESC))
				gameState = GameState::GAME_OVER;

			map.PrintMap();

			break;

		case GameState::GAME_OVER:
			break;

		default:;

		}

		Sleep(1000);
		system("cls");


	}


	return 0;
}
