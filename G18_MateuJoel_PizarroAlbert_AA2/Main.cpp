//Main.cpp
#include "Map.h"
#include "Utils.h"



int main() {
	InputManager inputManager;
	Player player1, player2;
	Map map;

	clock_t timeEnd, timeLeft;

	//player1.PrintPlayer();
	//player2.PrintPlayer();

	GameState gameState = GameState::INIT;
	while (gameState != GameState::GAME_OVER) {
		switch (gameState)
		{
		case GameState::INIT:
			map.ReadConfigTXT(player1, player2);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			std::cout << "-*-*-INIT-*-*-\nPress the Spacebar to start the game. ";
			while (gameState == GameState::INIT) {
				inputManager.Update();

				if (inputManager.GetKey(Inputs::SPACE_BAR))
					gameState = GameState::PLAY;
				else if (inputManager.GetKey(Inputs::ESC))
					gameState = GameState::GAME_OVER;
			}

			timeEnd = clock() + PLAY_TIME;
			break;

		case GameState::PLAY:
			//Inputs
			inputManager.Update();

			//Update
			map.Refresh(player1, player2, gameState, inputManager);
			if (inputManager.GetKey(Inputs::PAUSE)) {
				//Fer gestió de les variables necessaries (recordar parar temps a tot)
				gameState = GameState::PAUSE;
			}
			else if (inputManager.GetKey(Inputs::ESC) || timeEnd < clock()) gameState = GameState::GAME_OVER;
			
			timeLeft = timeEnd - clock();

			//Draw
			Utils::PrintUI(player1.lives, player2.lives, timeLeft, false);
			map.PrintMap();
			Utils::PrintScores(player1.score, player2.score);

			break;

		case GameState::PAUSE:
			Utils::PrintUI(player1.lives, player2.lives, timeLeft, true);
			map.PrintMap();
			Utils::PrintScores(player1.score, player2.score);

			while (gameState == GameState::PAUSE) {
				inputManager.Update();

				if (inputManager.GetKey(Inputs::SPACE_BAR))
					gameState = GameState::PLAY;
				else if (inputManager.GetKey(Inputs::ESC))
					gameState = GameState::GAME_OVER;
			}

			timeEnd = clock() + timeLeft;

			break;

		case GameState::GAME_OVER:
			break;

		default:;

		}

		Sleep(500);
		system("cls");


	}


	return 0;
}
