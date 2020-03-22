#pragma once
#include "Types.h"
#include <iostream>

struct Player {
private:
	Vec2 initialPos;
	int score = 0;

public:
	Vec2 pos;
	int id = 0;
	//int bombs = 0;

	Player() {};
	Player(const Vec2 &_pos, const int &_id);
	Player(const Player &p);


	void AddScore(const int &scoreAdded);

	void PrintScore();
	void PrintPlayer();

};