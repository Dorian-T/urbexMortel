#include "Player.h"
#include "Room.h"
#include <iostream>
#include <assert.h>
using namespace std;

Player::Player() {
	skin = M;
	hp = 0;
	timeInvincible = 0;
}

Player::Player(const Vector2D & P, unsigned int h, unsigned int w, Skin s, unsigned int health): Entity(P, h, w) {
	skin = s;
	hp = h;
	timeInvincible = 0;
}

bool Player::decreaseHp(unsigned int h) {
	if(timeInvincible == 0) {
		hp -= h;
		if(hp == 0)
			return false;
		else {
			timeInvincible = 5; // a modifier
			return false;
		}
	}
}

void Player::decreaseTimeInvincible() {
	timeInvincible--;
}

void Player::up(Room * R) { // peut-etre qu'il faudra modifier en passant a la version graphique
	Vector2D V;
	V.setX(getPosition().getX());
	if(getPosition().getY() > 1) {
		V.setY(getPosition().getY() - 1);
		if(R->isMovePossible(V)) setPosition(V);
	}
}

void Player::right(Room * R) {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	if(R->isMovePossible(V)) setPosition(V);
}

void Player::down(Room * R) {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	if(R->isMovePossible(V)) setPosition(V);
}

void Player::left (Room * R) {
	Vector2D V;
	V.setX(getPosition().getX());
	if(getPosition().getY() > 1) {
		V.setY(getPosition().getY() - 1);
		if(R->isMovePossible(V)) setPosition(V);
	}
}

void Player::gravity(Room * R) {
	down(R);
}

void Player::regressionTest() {
	cout << endl << "Test de la classe Player" << endl;

	assert(getPosition().getX() == 0 && getPosition().getY() == 0 && getHeight() == 0 && getWidth() == 0);
	assert(skin == M && hp == 0 && timeInvincible == 0);
	cout << "\tconstructeur par defaut : OK" << endl;

	Player P(Vector2D(1, 2), 1, 1, F, 3);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 2 && P.getHeight() == 1 && P.getWidth() == 1);
	assert(P.skin == F && P.hp == 3 && P.timeInvincible == 0);
	cout << "\tconstructeur parametre : OK" << endl;

	assert(P.decreaseHp(1) == true);
	assert(P.hp == 2);
	assert(P.decreaseHp(2) == false);
	assert(P.hp == 0);
	cout << "\tdecreaseHp : OK" << endl;

	assert(P.timeInvincible == 5);
	P.decreaseTimeInvincible();
	assert(P.timeInvincible == 4);
	cout << "\tdecreaseTimeInvincible : OK" << endl;

	// P.up(Room("data/test.txt"));
	// TODO

	cout << "Test de la classe Player : OK" << endl;
}