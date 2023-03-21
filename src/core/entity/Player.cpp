#include "Player.h"
#include "../building/Room.h"
#include <assert.h>
#include <iostream>
using namespace std;

Player::Player() {
	skin = M;
	hp = 0;
	timeInvincible = 0;
}

Player::Player(const Vector2D & P, Skin s, unsigned int health): Entity(P, 2, 1) {
	skin = s;
	hp = health;
	timeInvincible = 0;
}

bool Player::decreaseHp(unsigned int h) {
	if(timeInvincible == 0) {
		if (hp<h) hp -= hp;
		hp -= h;
		if(hp == 0)
			return false;
		else
			timeInvincible = 5; // a modifier
	}
	return true;
}

void Player::decreaseTimeInvincible() {
	timeInvincible--;
}

void Player::up(Building * B) { // peut-etre qu'il faudra modifier en passant a la version graphique
	if(standingOnBlock(B))
	{Vector2D V;
		V.setX(getPosition().getX());
		if(getPosition().getY() > 1) {
			V.setY(getPosition().getY() - 1);
			int i = isMovePossibleUp(V, B->getCurrentRoom());
			if(i == -1) setPosition(V);
			else if(i > 0) decreaseHp(i);
			else if(i == -3) {
				V.setY(V.getY()-2);
				setPosition(V);
			}
		}
	}
}

int Player::isMovePossibleUp(const Vector2D & position, Room * R) const {
	Vector2D tete(position.getX(), position.getY() - 1);
	if(tete.getY() > 0) {
		Obstacle o = R->getObstacle(tete);
		if(o == nothing || o == ladder) return -1;
		else if(o == barbedWire) return 1;
		else if(o == trapdoor) return -3;
	}
	return 0;
}

bool Player::right(Building * B) {
	Vector2D V;
	bool b=true;
	V.setY(getPosition().getY());
	V.setX(getPosition().getX() + 1);
	int i = isMovePossibleSide(V, B->getCurrentRoom());
	if(i == -1) setPosition(V);
	else if(i > 0) decreaseHp(i);
	else if(i == -2) {
		b = B->finishRoom();
		if(b)setPosition(Vector2D(1,B->getCurrentRoom()->getDimY()-2));
	}
	return b;
}

void Player::left (Building * B) {
	Vector2D V;
	V.setY(getPosition().getY());
	if(getPosition().getX() > 1) {
		V.setX(getPosition().getX() - 1);
		int i = isMovePossibleSide(V, B->getCurrentRoom());
		if(i == -1) setPosition(V);
		else if(i > 0) decreaseHp(i);
	}
}

int Player::isMovePossibleSide(const Vector2D & position, Room * R) const {
	if(position.getX() < R->getDimX() && position.getX() > 0) {
		Vector2D tete(position.getX(), position.getY() - 1);
		Obstacle o1 = R->getObstacle(position);
		Obstacle o2 = R->getObstacle(tete);
		if((o1 == nothing || o1 == ladder) && (o2 == nothing || o2 == ladder)) return -1;
		else if(o1 == barbedWire || o2 == barbedWire) return 1;
		else if(o1 == door && o2 == door) return -2;
	}
	return 0;
}

void Player::down(Building * B) {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	int i = isMovePossibleDown(V, B->getCurrentRoom());
	if(i == -1) setPosition(V);
	else if(i > 0) decreaseHp(i);
}

int Player::isMovePossibleDown(const Vector2D & position, Room * R) const {
	if(position.getY() < R->getDimY()) {
		Obstacle o = R->getObstacle(position);
		if(o == nothing || o == trapdoor || o == ladder) return -1;
		else if(o == barbedWire) return 1;
	}
	return 0;
}

bool Player::standingOnBlock(Building * B) {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	Obstacle o = B->getCurrentRoom()->getObstacle(V);
	if(o == trapdoor || o == ladder || o == barbedWire || o == block) return true;
	return false ;
}

void Player::gravity(Building * B) { // a modifier : probleme avec les trappes
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	int i = isMovePossibleGravity(V, B->getCurrentRoom());
	if(i == -1) setPosition(V);
	else if(i > 0) decreaseHp(i);
}

int Player::isMovePossibleGravity(const Vector2D & position, Room * R) const {
	if(position.getY() < R->getDimY()) {
		Obstacle o = R->getObstacle(position);
		if(o == nothing) return -1;
		else if(o == barbedWire) return 1;
	}
	return 0;
}

unsigned int Player::getHp() {
	return hp;
}

unsigned int Player::getTimeInvincible() {
	return timeInvincible;
}

void Player::regressionTest() {
	cout << endl << "Test de la classe Player" << endl;

	assert(getPosition().getX() == 0 && getPosition().getY() == 0 && getHeight() == 0 && getWidth() == 0);
	assert(skin == M && hp == 0 && timeInvincible == 0);
	cout << "\tconstructeur par defaut : OK" << endl;

	Player P(Vector2D(2, 3), F, 3);
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 3 && P.getHeight() == 2 && P.getWidth() == 1);
	assert(P.skin == F), assert(P.hp == 3); assert(P.timeInvincible == 0);
	cout << "\tconstructeur parametre : OK" << endl;

	assert(P.decreaseHp(1) == true);
	assert(P.hp == 2);
	assert(P.timeInvincible == 5);
	P.decreaseTimeInvincible();
	assert(P.timeInvincible == 4);
	cout << "\tdecreaseTimeInvincible : OK" << endl;
	for(unsigned int i = 0; i < 4; i++)
		P.decreaseTimeInvincible();
	assert(P.decreaseHp(2) == false);
	assert(P.hp == 0);
	cout << "\tdecreaseHp : OK" << endl;

	cout << "Test de la classe Player : OK" << endl;
 }