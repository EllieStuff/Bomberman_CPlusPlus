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

	void PrintMap() const;
};