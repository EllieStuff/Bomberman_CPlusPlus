#include "InputManager.h"

void InputManager::Update()
{
	inputs[static_cast<int>(Inputs::UP_1)] = GetAsyncKeyState('W');
	inputs[static_cast<int>(Inputs::DOWN_1)] = GetAsyncKeyState('S');
	inputs[static_cast<int>(Inputs::LEFT_1)] = GetAsyncKeyState('A');
	inputs[static_cast<int>(Inputs::RIGHT_1)] = GetAsyncKeyState('D');
	inputs[static_cast<int>(Inputs::BOMB_1)] = inputs[static_cast<int>(Inputs::SPACE_BAR)] = GetAsyncKeyState(VK_SPACE);	//Esta fet aixi prq el codi sigui mes clar
	inputs[static_cast<int>(Inputs::UP_2)] = GetAsyncKeyState(VK_UP);
	inputs[static_cast<int>(Inputs::DOWN_2)] = GetAsyncKeyState(VK_DOWN);
	inputs[static_cast<int>(Inputs::LEFT_2)] = GetAsyncKeyState(VK_LEFT);
	inputs[static_cast<int>(Inputs::RIGHT_2)] = GetAsyncKeyState(VK_RIGHT);
	inputs[static_cast<int>(Inputs::BOMB_2)] = GetAsyncKeyState(VK_CONTROL);
	inputs[static_cast<int>(Inputs::ESC)] = GetAsyncKeyState(VK_ESCAPE);
	inputs[static_cast<int>(Inputs::PAUSE)] = GetAsyncKeyState('P');

}

//bool * InputManager::GetKeys()
//{
//
//	return inputs;
//}

bool InputManager::GetKey(const Inputs & key)
{

	return inputs[static_cast<int>(key)];
}

//bool InputManager::WaitForInput(const Inputs & key)
//{
//	while (true) {
//		Update();
//
//		if (GetKey(key)) return true;
//	}
//}
//
//Inputs InputManager::WaitForAnswer()
//{
//	while (true) {
//		Update();
//		for (int i = 0; i < static_cast<int>(Inputs::COUNT); i++) {
//			if (inputs[i] == true) return static_cast<Inputs>(i);
//
//		}
//	}
//
//}
//
//InputOrigin InputManager::GetInputOrigin(Inputs input)
//{
//	//enum class Inputs { UP_1, DOWN_1, RIGHT_1, LEFT_1, BOMB_1, UP_2, DOWN_2, RIGHT_2, LEFT_2, BOMB_2, ESC, YES, NO, COUNT };
//	switch (input) {
//	case Inputs::UP_1: case Inputs::DOWN_1: case Inputs::RIGHT_1: case Inputs::LEFT_1: case Inputs::BOMB_1:
//		return InputOrigin::PLAYER_1;
//
//	case Inputs::UP_2: case Inputs::DOWN_2: case Inputs::RIGHT_2: case Inputs::LEFT_2: case Inputs::BOMB_2:
//		return InputOrigin::PLAYER_2;
//
//	case Inputs::ESC: case Inputs::PAUSE: case Inputs::SPACE_BAR:
//		return InputOrigin::ALL;
//
//	default:
//		return InputOrigin::NONE;
//
//	}
//}
