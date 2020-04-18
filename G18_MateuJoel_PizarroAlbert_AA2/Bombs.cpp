#include "Bombs.h"

void Bombs::IsExploding(Map &map)
{
	//cuando pasan los 2 segundos mira los lugares donde esta la explosion y
	//si no hay BLOCK pone una E (explosion)
	
	if (clock() - startTime >= BOMB_TIMER)
	{
		//explosion
		hasExploded = true;
		isSet = false;
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (position)
		}
	}
}

void Bombs::SetBombs(Player player)
{
	isSet = true;
	startTime = clock();
	position = player.pos;
}