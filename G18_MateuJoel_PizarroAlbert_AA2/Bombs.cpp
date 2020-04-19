#include "Bombs.h"

Bombs::Bombs(const int &_id)
{
	playerID = _id;
}

void Bombs::IsExploding(Map &map, int &_score)
{
	if (clock() - startTime >= BOMB_TIMER && hasExploded == false)
	{
		hasExploded = true;
		isSet = false;
		///UP CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x][position.y - i] != Cell::WALL)
			{
				if (playerID == 1 && map.map[position.x][position.y - i] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map.map[position.x][position.y - i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map.map[position.x][position.y - i] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map.map[position.x][position.y - i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map.map[position.x][position.y - i] = Cell::EXPLOSION;
			}
#pragma region cosasNasisUtilizables
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
#pragma endregion
		}
		///DOWN CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x][position.y + i] != Cell::WALL)
			{
				if (playerID == 1 && map.map[position.x][position.y + i] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map.map[position.x][position.y + i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map.map[position.x][position.y + i] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map.map[position.x][position.y + i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map.map[position.x][position.y + i] = Cell::EXPLOSION;
			}
		}
		///LEFT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x - i][position.y] != Cell::WALL)
			{
				if (playerID == 1 && map.map[position.x - i][position.y ] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map.map[position.x - i][position.y ] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map.map[position.x - i][position.y] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map.map[position.x - i][position.y] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map.map[position.x - i][position.y] = Cell::EXPLOSION;
			}
		}
		///RIGHT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map.map[position.x + i][position.y] != Cell::WALL)
			{
				if (playerID == 1 && map.map[position.x + i][position.y] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map.map[position.x + i][position.y] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map.map[position.x + i][position.y] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map.map[position.x + i][position.y] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map.map[position.x + i][position.y] = Cell::EXPLOSION;
			}
		}
	}
	else if (hasExploded)
		EndedExplosion(map);
}

void Bombs::SetBombs(Player player)
{
	isSet = true;
	startTime = clock();
	position = player.pos;
}

void Bombs::EndedExplosion(Map &map)
{
	//Funcion sirve para volver a poner las Cells como NONE una vez han explotado
	///UP CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map.map[position.x][position.y - i] == Cell::EXPLOSION)
		{
			map.map[position.x][position.y - i] = Cell::NONE;
		}
	}
	///DOWN CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map.map[position.x][position.y + i] == Cell::EXPLOSION)
		{
			map.map[position.x][position.y + i] = Cell::NONE;
		}
	}
	///LEFT CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map.map[position.x - i][position.y] == Cell::EXPLOSION)
		{
			map.map[position.x - i][position.y] = Cell::NONE;
		}
	}
	///RIGHT CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map.map[position.x + i][position.y] == Cell::EXPLOSION)
		{
			map.map[position.x + i][position.y] = Cell::NONE;
		}
	}
}