#include "Player.h"
#include "Room.h"

Player::Player() {
	skin = M;
	hp = 0;
	hurted = false;
	TimeInvincible = 0;
}


Player::Player(Skin Pskin, unsigned int Php) {
	skin = Pskin;
	hp = Php;
	hurted = false;
	TimeInvincible = 0;
}

void Player::setHp(unsigned int H)
{
	hp = H;
}

void Player::up (Room * R) {
	Vector2D UpPosition;
	UpPosition.setX(getPosition().getX());
	UpPosition.setY(getPosition().getY());
	UpPosition.setY(UpPosition.getY()+1);
	bool b;
	b= R->isMovePossible(UpPosition);
	if(b)
	{
		setPosition(UpPosition);
	}
}

void Player::right (Room * R) {
	Vector2D RightPosition;
	RightPosition.setX(getPosition().getX());
	RightPosition.setY(getPosition().getY());
	RightPosition.setX(RightPosition.getX()+1);
	bool b;
	b= R->isMovePossible(RightPosition);
	if(b)
	{
		setPosition(RightPosition);
	}
}

void Player::down (Room * R) {
	Vector2D DownPosition;
	DownPosition.setX(getPosition().getX());
	DownPosition.setY(getPosition().getY());
	DownPosition.setY(DownPosition.getY()-1);
	bool b;
	b= R->isMovePossible(DownPosition);
	if(b)
	{
		setPosition(DownPosition);
	}
}

void Player::left (Room * R) {
	Vector2D LeftPosition;
	LeftPosition.setX(getPosition().getX());
	LeftPosition.setY(getPosition().getY());
	LeftPosition.setX(LeftPosition.getX()-1);
	bool b;
	b= R->isMovePossible(LeftPosition);
	if(b)
	{
		setPosition(LeftPosition);
	}
}

void Player::gravity(Room * R) {
	down(R);
}

void Player::Hurted() {
	hurted = true;
	TimeInvincible = 5;
}

void Player::decreaseTimeInvincible()
{
	TimeInvincible--;
}

bool Player::isDead() {
	if(hp==0){return true;}
	return false;
}