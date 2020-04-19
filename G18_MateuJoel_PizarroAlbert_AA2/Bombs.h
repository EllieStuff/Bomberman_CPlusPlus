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
	clock_t startTime;
	int playerID;

public:
	Vec2 position;
	//Constructor
	Bombs(const int &_id);
	//Methods
	void IsExploding(Map &map, int &_score);

	void EndedExplosion(Map &map);

	void SetBombs(Player player);
};