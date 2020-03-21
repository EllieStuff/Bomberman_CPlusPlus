#include "InputManager.h"

void InputManager::Update()
{
	inputs[static_cast<int>(Inputs::LEFT)] = GetAsyncKeyState('A');
	inputs[static_cast<int>(Inputs::RIGHT)] = GetAsyncKeyState('D');
	inputs[static_cast<int>(Inputs::SHOOT)] = GetAsyncKeyState(VK_SPACE);
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
