#pragma once
#include "Types.h"
#include "InputManager.h"
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

	void InitPos(const Vec2 &_pos);

	void AddScore(const int &scoreAdded);

	void Move(const Inputs &input);

	void PrintScore();
	void PrintPlayer();

};