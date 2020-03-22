#include "Player.h"

Player::Player(const Vec2 & _pos, const int & _id)
{
	InitPos(_pos);
	id = _id;
}

Player::Player(const Player & p)
{
	InitPos(p.pos);
	score = p.score;
	id = p.id;
}

void Player::InitPos(const Vec2 & _pos)
{
	initialPos = pos = _pos;
}

void Player::AddScore(const int & scoreAdded)
{
	score += scoreAdded;
}

void Player::Move(const Inputs & input)
{
	switch (input)
	{
	case Inputs::UP_1: case Inputs::UP_2:
		pos.y--;
		break;

	case Inputs::DOWN_1: case Inputs::DOWN_2:
		pos.y++;
		break;

	case Inputs::LEFT_1: case Inputs::LEFT_2:
		pos.x--;
		break;

	case Inputs::RIGHT_1: case Inputs::RIGHT_2:
		pos.x++;
		break;

	default:;

	}
}

void Player::PrintScore()
{
	std::cout << "Player " << id + 1 << " score: " << score << std::endl;
}

void Player::PrintPlayer()
{
	std::cout << "Player " << id + 1
		<< ":\nPosition: (" << pos.x << ", " << pos.y
		<< ")\nScore: " << score << std::endl;
}
