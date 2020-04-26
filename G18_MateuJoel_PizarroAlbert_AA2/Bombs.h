#pragma once
#include <vector>
#include <time.h>
#include "Constants.h"
#include "Types.h"

class Bombs
{
private:
	bool hasExploded = false;
	clock_t startTime;
	int playerID;

public:
	bool isSet = false;
	Vec2 position;
	//Constructor
	Bombs() {};
	Bombs(const int &_id);
	//Methods
	void IsExploding(std::vector<std::vector<Cell>> &map, int &_score);

	void EndedExplosion(std::vector<std::vector<Cell>> &map);

	void SetBombs(const Vec2 &playerPos);
};