#include "Bombs.h"

Bombs::Bombs(const int &_id)
{
	playerID = _id;
}

void Bombs::IsExploding(std::vector<std::vector<Cell>> &map, int &_score)
{
	if (clock() - startTime >= BOMB_TIMER && hasExploded == false)
	{
		hasExploded = true;
		isSet = false;
		///UP CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map[position.x][position.y - i] != Cell::WALL)
			{
				if (playerID == 1 && map[position.x][position.y - i] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map[position.x][position.y - i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map[position.x][position.y - i] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map[position.x][position.y - i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.x][position.y - i] = Cell::EXPLOSION;
			}

		}
		///DOWN CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map[position.x][position.y + i] != Cell::WALL)
			{
				if (playerID == 1 && map[position.x][position.y + i] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map[position.x][position.y + i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map[position.x][position.y + i] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map[position.x][position.y + i] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.x][position.y + i] = Cell::EXPLOSION;
			}
		}
		///LEFT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map[position.x - i][position.y] != Cell::WALL)
			{
				if (playerID == 1 && map[position.x - i][position.y ] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map[position.x - i][position.y ] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map[position.x - i][position.y] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map[position.x - i][position.y] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.x - i][position.y] = Cell::EXPLOSION;
			}
		}
		///RIGHT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			if (map[position.x + i][position.y] != Cell::WALL)
			{
				if (playerID == 1 && map[position.x + i][position.y] == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 1 && map[position.x + i][position.y] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				else if (playerID == 2 && map[position.x + i][position.y] == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && map[position.x + i][position.y] == Cell::BLOCK)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.x + i][position.y] = Cell::EXPLOSION;
			}
		}
	}
	else if (hasExploded)
		EndedExplosion(map);
}

void Bombs::SetBombs(const Vec2 &playerPos)
{
	isSet = true;
	startTime = clock();
	position = playerPos;
}

void Bombs::EndedExplosion(std::vector<std::vector<Cell>> &map)
{
	//Funcion sirve para volver a poner las Cells como NONE una vez han explotado
	///UP CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.x][position.y - i] == Cell::EXPLOSION)
		{
			map[position.x][position.y - i] = Cell::NONE;
		}
	}
	///DOWN CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.x][position.y + i] == Cell::EXPLOSION)
		{
			map[position.x][position.y + i] = Cell::NONE;
		}
	}
	///LEFT CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.x - i][position.y] == Cell::EXPLOSION)
		{
			map[position.x - i][position.y] = Cell::NONE;
		}
	}
	///RIGHT CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.x + i][position.y] == Cell::EXPLOSION)
		{
			map[position.x + i][position.y] = Cell::NONE;
		}
	}
}