#pragma once
#include "Types.h"
#include "InputManager.h"
#include <iostream>

struct Player {
private:
	Vec2 initialPos;

public:
	Vec2 pos;
	int id = 0;
	int score = 0;
	int lives = 3;
	//int bombs = 0;

	Player() {};
	Player(const Vec2 &_pos, const int &_id);
	Player(const Player &p);

	void InitPos(const Vec2 &_pos);

	void AddScore(const int &scoreAdded);

	void Move(const Inputs &input);

	//void PrintPlayer();

};