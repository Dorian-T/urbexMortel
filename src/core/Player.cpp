#include "Player.h"
#include "Room.h"

Player::Player(Skin Pskin, unsigned int Php) {
	skin = Pskin;
	hp = Php;
}

void Player::up (const Room & R) {
	// TODO
}

void Player::right (const Room & R) {
	Vector2D RightPosition;
	RightPosition.setX(getPosition().getX());
	RightPosition.setY(getPosition().getY());
	RightPosition.setX(RightPosition.getX()+1);
	bool b;
	b= R&.isMovePossible(RightPosition);
	if(b)
	{
		setPosition(RightPosition);
	}
}

void Player::down (const Room & R) {
	// TODO
}

void Player::left (const Room & R) {
	// TODO
}