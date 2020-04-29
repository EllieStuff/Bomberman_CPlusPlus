#include "Bombs.h"


void Bombs::IsExploding(std::vector<std::vector<Cell>> &map, int &_score)
{
	if (clock() - startTime >= BOMB_TIMER && hasExploded == false)
	{
		hasExploded = true;
		///UP CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			Cell currentCell = map[position.y - i][position.x];
			if (currentCell != Cell::BLOCK)
			{
				if (playerID == 1 && currentCell == Cell::PLAYER2)	//no cuentan suicidios
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && currentCell == Cell::PLAYER1)		
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (currentCell == Cell::WALL)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.y - i][position.x] = Cell::EXPLOSION;
			}
			else {
				break;
			}
		}
		///DOWN CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			Cell currentCell = map[position.y + i][position.x];
			if (currentCell != Cell::BLOCK)
			{
				if (playerID == 1 && currentCell == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && currentCell == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (currentCell == Cell::WALL)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.y + i][position.x] = Cell::EXPLOSION;
			}
			else {
				break;
			}
		}
		///LEFT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			Cell currentCell = map[position.y][position.x - i];
			if (currentCell != Cell::BLOCK)
			{
				if (playerID == 1 && currentCell == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && currentCell == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (currentCell == Cell::WALL)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.y][position.x - i] = Cell::EXPLOSION;
			}
			else {
				break;
			}
		}
		///RIGHT CELLS
		for (int i = 1; i <= BOMB_RANGE; i++)
		{
			Cell currentCell = map[position.y][position.x + i];
			if (currentCell != Cell::BLOCK)
			{
				if (playerID == 1 && currentCell == Cell::PLAYER2)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (playerID == 2 && currentCell == Cell::PLAYER1)
				{
					_score += KILL_PLAYER_SCORE;
				}
				else if (currentCell == Cell::WALL)
				{
					_score += DESTROY_BLOCK_SCORE;
				}
				map[position.y][position.x + i] = Cell::EXPLOSION;
			}
			else {
				break;
			}
		}
		///CENTER CELLS
		Cell currentCell = map[position.y][position.x];
		if (currentCell != Cell::BLOCK)
		{
			if (playerID == 1 && currentCell == Cell::PLAYER2)
			{
				_score += KILL_PLAYER_SCORE;
			}
			else if (playerID == 2 && currentCell == Cell::PLAYER1)
			{
				_score += KILL_PLAYER_SCORE;
			}
			//No se puede poner bomba en el muro por lo tanto no se mira para puntuar por muro
			map[position.y][position.x] = Cell::EXPLOSION;
		}
	}
	else if (hasExploded) {
		EndedExplosion(map);
	}
}

void Bombs::SetBombs(const Vec2 &playerPos)
{
	isSet = true;
	startTime = clock();
	position = playerPos;
}

void Bombs::SetId(const int & _id)
{
	playerID = _id;
}

void Bombs::EndedExplosion(std::vector<std::vector<Cell>> &map)
{
	//Funcion sirve para volver a poner las Cells como NONE una vez han explotado
	hasExploded = isSet = false;

	///UP CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.y - i][position.x] == Cell::EXPLOSION)
		{
			map[position.y - i][position.x] = Cell::NONE;
		}
		else if (map[position.y - i][position.x] == Cell::BLOCK) {
			break;
		}
	}
	///DOWN CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.y + i][position.x] == Cell::EXPLOSION)
		{
			map[position.y + i][position.x] = Cell::NONE;
		}
		else if (map[position.y + i][position.x] == Cell::BLOCK) {
			break;
		}
	}
	///LEFT CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.y][position.x - i] == Cell::EXPLOSION)
		{
			map[position.y][position.x - i] = Cell::NONE;
		}
		else if (map[position.y][position.x - i] == Cell::BLOCK) {
			break;
		}
	}
	///RIGHT CELLS
	for (int i = 1; i <= BOMB_RANGE; i++)
	{
		if (map[position.y][position.x + i] == Cell::EXPLOSION)
		{
			map[position.y][position.x + i] = Cell::NONE;
		}
		else if (map[position.y][position.x + i] == Cell::BLOCK) {
			break;
		}
	}
	///CENTER CELL
	if (map[position.y][position.x] == Cell::EXPLOSION ||
		map[position.y][position.x] == Cell::BOMB)
		map[position.y][position.x] = Cell::NONE;
}