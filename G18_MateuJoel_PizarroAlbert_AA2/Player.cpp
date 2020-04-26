#include "Player.h"

Player::Player(const Vec2 & _pos, const int & _id)
{
	InitPos(_pos);
	id = _id;
	bomb.SetId(_id);
	lives = 3;
	hit = false;
}

Player::Player(const Player & p)
{
	InitPos(p.pos);
	score = p.score;
	id = p.id;
	bomb.SetId(p.id);
	lives = p.lives;
	hit = p.hit;
}

void Player::InitPos(const Vec2 & _pos)
{
	initialPos = pos = _pos;
}

void Player::AddScore(const int & scoreAdded)
{
	score += scoreAdded;
}

void Player::Move(InputManager inputManager)
{
	if (id == 1) {
		if (inputManager.GetKey(Inputs::UP_1)) {
			pos.y--;
		}
		else if (inputManager.GetKey(Inputs::DOWN_1)) {
			pos.y++;
		}
		else if (inputManager.GetKey(Inputs::LEFT_1)) {
			pos.x--;
		}
		else if (inputManager.GetKey(Inputs::RIGHT_1)) {
			pos.x++;
		}
		else if (inputManager.GetKey(Inputs::BOMB_1)) {
			PutBomb();
		}
	}
	else if (id == 2) {
		if (inputManager.GetKey(Inputs::UP_2)) {
			pos.y--;
		}
		else if (inputManager.GetKey(Inputs::DOWN_2)) {
			pos.y++;
		}
		else if (inputManager.GetKey(Inputs::LEFT_2)) {
			pos.x--;
		}
		else if (inputManager.GetKey(Inputs::RIGHT_2)) {
			pos.x++;
		}
		else if (inputManager.GetKey(Inputs::BOMB_2)) {
			PutBomb();
		}
	}

}

void Player::PutBomb()
{
	if (!bomb.isSet)
	{
		if(id == 2){
			id = 2;
		}
		bomb.SetBombs(pos);
	}
}

//void Player::PrintPlayer()
//{
//	std::cout << "Player " << id + 1
//		<< ":\nPosition: (" << pos.x << ", " << pos.y
//		<< ")\nScore: " << score << std::endl;
//}
