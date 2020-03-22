#include "Player.h"

Player::Player(const Vec2 & _pos, const int & _id)
{
	initialPos = pos = _pos;
	id = _id;
}

Player::Player(const Player & p)
{
	initialPos = pos = p.pos;
	score = p.score;
	id = p.id;
}

void Player::AddScore(const int & scoreAdded)
{
	score += scoreAdded;
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
