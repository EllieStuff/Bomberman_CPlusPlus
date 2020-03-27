#include "Map.h"
#include <fstream>
#include <iostream>
#include <Windows.h>


void Map::ReadConfigTXT(Player &player1, Player &player2)
{
	char aux;
	int j;
	std::ifstream file("config.txt");
	if (file.is_open())
	{
		file >> numRows;
		file >> aux;
		file >> numColumns;
		file >> aux;
		file >> std::noskipws;
		map = new Cell *[numColumns];
		int playerCount = 0;
		for (int i = 0; i < numColumns; i++)
		{
			map[i] = new Cell[numRows];
			file >> aux;
			j = 0;
			while (aux != '\n') {
				map[i][j] = static_cast<Cell>(aux);
				if (aux == static_cast<char>(Cell::PLAYER1))
				{
					//setPos Player1
					player1 = Player({ i, j }, playerCount);
					playerCount++;
				}
				else if (aux == static_cast<char>(Cell::PLAYER2))
				{
					//setPos Player2
					player2 = Player({ i, j }, playerCount);
					playerCount++;
				}

				file >> aux;
				j++;
			} 
		}
		file.close();
	}
	else
	{
		std::cout << "The file doesn't exist." << std::endl << std::endl;
		system("pause");
	}
}

void Map::Refresh(Player & player1, Player & player2, InputManager inputManager)
{
	bool *inputs = inputManager.GetKeys();
	bool hasReadP1, hasReadP2 = hasReadP1 = false;
	for (int i = 0; i < static_cast<int>(Inputs::COUNT); i++) {
		if (inputs[i]) {
			Inputs input = static_cast<Inputs>(i);
			switch (inputManager.GetInputOrigin(input)) {
			case InputOrigin::PLAYER_1:
				if (!hasReadP1) {
					if (MoveAvailable(player1, input)) {
						map[player1.pos.x][player1.pos.y] = Cell::NONE;
						player1.Move(input);
						map[player1.pos.x][player1.pos.y] = Cell::PLAYER1;
					}
					hasReadP1 = true;
				}
				break;

			case InputOrigin::PLAYER_2:
				if (!hasReadP2) {
					if (MoveAvailable(player2, input)) {
						map[player2.pos.x][player2.pos.y] = Cell::NONE;
						player2.Move(input);
						map[player2.pos.x][player2.pos.y] = Cell::PLAYER2;
					}
					hasReadP2 = true;
				}
				break;

			case InputOrigin::ALL:

				break;

			default:;

			}

		}
	}
}


bool Map::MoveAvailable(Player player, const Inputs &input)
{
	switch (input)
	{
	case Inputs::UP_1: case Inputs::UP_2:
		player.pos.y--;
		return map[player.pos.x][player.pos.y] == Cell::NONE && player.pos.x >= 0;

	case Inputs::DOWN_1: case Inputs::DOWN_2:
		player.pos.y++;
		return map[player.pos.x][player.pos.y] == Cell::NONE && player.pos.x < numRows;

	case Inputs::LEFT_1: case Inputs::LEFT_2:
		player.pos.x--;
		return map[player.pos.x][player.pos.y] == Cell::NONE && player.pos.x >= 0;

	case Inputs::RIGHT_1: case Inputs::RIGHT_2:
		player.pos.x++;
		return map[player.pos.x][player.pos.y] == Cell::NONE && player.pos.x < numColumns;

	default:
		return false;

	}

}

void Map::PrintMap() const
{
	for (int i = 0; i < numColumns; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			switch (map[j][i])
			{
				case Cell::BLOCK:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);
					std::cout << static_cast<char>(map[j][i]) << static_cast<char>(map[j][i]);
					break;
				case Cell::WALL:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);
					std::cout << static_cast<char>(map[j][i]) << static_cast<char>(map[j][i]);
					break;
				case Cell::PLAYER1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 34);
					std::cout << static_cast<char>(map[j][i]) << ' ';
					break;
				case Cell::PLAYER2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 85);
					std::cout << static_cast<char>(map[j][i]) << ' ';
					break;
				default:
					std::cout << ' ' << static_cast<char>(map[j][i]);
					break;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		std::cout << std::endl;
	}
}