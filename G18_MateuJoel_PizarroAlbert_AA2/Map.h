#pragma once
#include "Types.h"

struct Map
{
	//Attributes
	//Private att
	Cell **map;
	int numRows, numColumns;

	//Methods
	void ReadConfigTXT(Player1 &player1, Player2 &player2);

	void PrintMap() const;
};