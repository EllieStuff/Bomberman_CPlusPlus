#pragma once
#include <vector>
#include "Constants.h"
#include "Player.h"

class Map
{
	//Attributes
	//Private att
	//Cell **map;
private:
	std::vector<std::vector<Cell>> map;
	int numRows, numColumns;

public:
	//Methods
	void ReadConfigTXT(Player &player1, Player &player2);

	void Refresh(Player &player1, Player &player2, InputManager inputManager);

	bool MoveAvailable(Player player, const Inputs &input);

	void PrintMap() const;
};