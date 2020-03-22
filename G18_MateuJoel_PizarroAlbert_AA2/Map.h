#pragma once
#include "Constants.h"
#include "Player.h"

struct Map
{
	//Attributes
	//Private att
	Cell **map;
	int numRows, numColumns;

	//Methods
	void ReadConfigTXT(Player &player1, Player &player2);

	void Refresh(Player &player1, Player &player2, InputManager inputManager);

	bool MoveAvailable(Player player, const Inputs &input);

	void PrintMap() const;
};