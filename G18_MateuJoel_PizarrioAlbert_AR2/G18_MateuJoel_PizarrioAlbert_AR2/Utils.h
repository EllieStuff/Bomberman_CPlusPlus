#pragma once
#include <iostream>
#include "Player.h"

namespace Utils {
	void PrintScores(const int &p1Score, const int &p2Score);

	void PrintUI(const int &p1lives, const int &p2lives, const int &timeLeft, const bool &paused);

}