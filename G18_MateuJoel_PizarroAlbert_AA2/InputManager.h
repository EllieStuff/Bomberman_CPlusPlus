#pragma once
#include <Windows.h>


enum class Inputs { UP_1, DOWN_1, RIGHT_1, LEFT_1, UP_2, DOWN_2, RIGHT_2, LEFT_2, BOMB, ESC, YES, NO, COUNT };

struct InputManager {
private:
	bool inputs[static_cast<int>(Inputs::COUNT)];

public:

	InputManager() {};

	void Update();


	bool GetKey(const Inputs &key);

	Inputs WaitForAnswer();


};