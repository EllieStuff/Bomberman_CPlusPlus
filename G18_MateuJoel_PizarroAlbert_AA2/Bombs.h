#pragma once
#include "Types.h"
#include "Constants.h"
#include "Map.h"
#include <time.h>

class Bombs
{
private:
	bool hasExploded;
	bool isSet;

public:
	Vec2 position;
	clock_t startTime;

	//Methods
	void IsExploding(Map &map, Player player1, Player player2);

	void SetBombs(Player player);
};