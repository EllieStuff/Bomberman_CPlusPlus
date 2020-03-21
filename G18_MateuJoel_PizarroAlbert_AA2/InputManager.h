#pragma once
#include <Windows.h>


enum class Inputs { LEFT, RIGHT, SHOOT, ESC, YES, NO, COUNT };

struct InputManager {
private:
	bool inputs[static_cast<int>(Inputs::COUNT)];

public:

	InputManager() {};

	void Update();


	bool GetKey(const Inputs &key);

	Inputs WaitForAnswer();


};
