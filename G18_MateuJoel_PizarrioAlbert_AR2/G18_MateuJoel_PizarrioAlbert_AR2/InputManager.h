#pragma once
#include <Windows.h>


enum class Inputs { UP_1, DOWN_1, RIGHT_1, LEFT_1, BOMB_1, UP_2, DOWN_2, RIGHT_2, LEFT_2, BOMB_2, ESC, PAUSE, SPACE_BAR, COUNT };
enum class InputOrigin { PLAYER_1, PLAYER_2, ALL, NONE };


struct InputManager {
private:
	bool inputs[static_cast<int>(Inputs::COUNT)];

public:

	InputManager() {};

	void Update();

	//bool* GetKeys();

	bool GetKey(const Inputs &key);

	/*bool WaitForInput(const Inputs &key);

	Inputs WaitForAnswer();

	InputOrigin GetInputOrigin(Inputs input);*/

};