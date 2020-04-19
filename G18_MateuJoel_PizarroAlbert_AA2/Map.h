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
	int numRows, numColumns;

public:
	std::vector<std::vector<Cell>> map;
	//Methods
	void ReadConfigTXT(Player &player1, Player &player2);

	void Refresh(Player &player1, Player &player2, InputManager inputManager);

	bool MoveAvailable(Player player, const Inputs &input);

	bool CollisionWithExplosion(Player &player);

	void PrintMap() const;
};