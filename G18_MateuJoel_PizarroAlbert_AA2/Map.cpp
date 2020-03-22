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
		map = new Cell *[numRows];
		for (int i = 0; i < numRows; i++)
		{
			map[i] = new Cell[numColumns];
			j = 0;
			while (j < numColumns)
			{
				file >> aux;
				if (aux != '\n')
				{
					map[i][j] = static_cast<Cell>(aux);
					if (aux == static_cast<char>(Cell::PLAYER1))
					{
						//setPos Player1
					}
					else if (aux == static_cast<char>(Cell::PLAYER2))
					{
						//setPos Player2
					}
					j++;
				}
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

void Map::PrintMap() const
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numColumns; j++)
		{
			switch (map[i][j])
			{
				case Cell::BLOCK:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 136);
					std::cout << static_cast<char>(map[i][j]) << static_cast<char>(map[i][j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				case Cell::WALL:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 119);
					std::cout << static_cast<char>(map[i][j]) << static_cast<char>(map[i][j]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				case Cell::PLAYER1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 34);
					std::cout << static_cast<char>(map[i][j]) << ' ';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				case Cell::PLAYER2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 85);
					std::cout << static_cast<char>(map[i][j]) << ' ';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				default:
					std::cout << ' ' << static_cast<char>(map[i][j]);
					break;
			}
		}
		std::cout << std::endl;
	}
}