#include "Bombs.h"

void Bombs::IsExploding(Map &map, Player player1, Player player2)
{
	if (clock() - startTime >= BOMB_TIMER)
	{
		//explosion
		hasExploded = true;
		isSet = false;
		//cambiar CELLS
		///UP CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x][position.y - i] != Cell::WALL)
			{
				map.map[position.x][position.y - i] = Cell::EXPLOSION;
			}
			//Cosas de colisiones del player 
			/////PLAYER COLLISION WITH BOMB
			/////UP
			//if (position.y - i == player1.pos.y && position.x == player1.pos.x)	//player1 hit by bomb	//no se me ocurre como hacer modo no cutre eso
			//{
			//	player1.hit = true;
			//	player1.lives--;
			//}
			//if (position.y - i == player2.pos.y && position.x == player2.pos.x)	//player2 hit by bomb
			//{
			//	player2.hit = true;
			//	player2.lives--;
			//}
			//
			/////DOWN
			//if (position.y + i == player1.pos.y && position.x == player1.pos.x)
			//{
			//	player1.hit = true;
			//	player1.lives--;
			//}
			//if (position.y + i == player2.pos.y && position.x == player2.pos.x)
			//{
			//	player2.hit = true;
			//	player2.lives--;
			//}

			/////LEFT 
			//if (position.x - i == player1.pos.x && position.y == player1.pos.y)
			//{
			//	player1.hit = true;
			//	player1.lives--;
			//}
			//if (position.x - i == player2.pos.x && position.y == player2.pos.y)
			//{
			//	player2.hit = true;
			//	player2.lives--;
			//}

			/////RIGHT 
			//if (position.x + i == player1.pos.x && position.y == player1.pos.y)
			//{
			//	player1.hit = true;
			//	player1.lives--;
			//}
			//if (position.x + i == player2.pos.x && position.y == player2.pos.y)
			//{
			//	player2.hit = true;
			//	player2.lives--;
			//}

			/////BLOCK COLLISION WITH BOMB
			//if ()								//Misma funcion que hitsWalls del pacman???
		}
		///DOWN CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x][position.y + i] != Cell::WALL)
			{
				map.map[position.x][position.y + i] = Cell::EXPLOSION;
			}
		}
		///LEFT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x - i][position.y ] != Cell::WALL)
			{
				map.map[position.x - i][position.y] = Cell::EXPLOSION;
			}
		}
		///RIGHT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x + i][position.y] != Cell::WALL)
			{
				map.map[position.x + i][position.y] = Cell::EXPLOSION;
			}
		}
	}
}

void Bombs::SetBombs(Player player)
{
	isSet = true;
	startTime = clock();
	position = player.pos;
}