#pragma once
#include "Player.h"
#include <fstream>
#include <iostream>
#include <Windows.h>

class Map
{
	//Attributes
	//Private att
	//Cell **map;
private:
	int numRows, numColumns;

public:
	std::vector<std::vector<Cell>> map;
	//Methods
	void ReadConfigTXT(Player &player1, Player &player2);

	void Refresh(Player &player1, Player &player2, GameState &gameState, InputManager inputManager);

	bool MoveAvailable(Player player, InputManager inputManager);

	bool CollisionWithExplosion(Player &player, GameState &gameState);

	void PrintMap() const;
};