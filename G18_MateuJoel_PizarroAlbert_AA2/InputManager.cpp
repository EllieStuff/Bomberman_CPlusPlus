#include "InputManager.h"

void InputManager::Update()
{
	inputs[static_cast<int>(Inputs::UP_1)] = GetAsyncKeyState('W');
	inputs[static_cast<int>(Inputs::DOWN_1)] = GetAsyncKeyState('S');
	inputs[static_cast<int>(Inputs::LEFT_1)] = GetAsyncKeyState('A');
	inputs[static_cast<int>(Inputs::RIGHT_1)] = GetAsyncKeyState('D');
	inputs[static_cast<int>(Inputs::UP_2)] = GetAsyncKeyState(VK_UP);
	inputs[static_cast<int>(Inputs::DOWN_2)] = GetAsyncKeyState(VK_DOWN);
	inputs[static_cast<int>(Inputs::LEFT_2)] = GetAsyncKeyState(VK_LEFT);
	inputs[static_cast<int>(Inputs::RIGHT_2)] = GetAsyncKeyState(VK_RIGHT);
	//inputs[static_cast<int>(Inputs::BOMB)] = GetAsyncKeyState(VK_SPACE);
	inputs[static_cast<int>(Inputs::ESC)] = GetAsyncKeyState(VK_ESCAPE);
	inputs[static_cast<int>(Inputs::YES)] = GetAsyncKeyState('Y');
	inputs[static_cast<int>(Inputs::NO)] = GetAsyncKeyState('N');

}

bool InputManager::GetKey(const Inputs & key)
{

	return inputs[static_cast<int>(key)];
}

Inputs InputManager::WaitForAnswer()
{
	while (true) {
		Update();
		for (int i = 0; i < static_cast<int>(Inputs::COUNT); i++) {
			if (inputs[i] == true) return static_cast<Inputs>(i);

		}
	}

}