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

void Player::up(Room * R) { // peut-etre qu'il faudra modifier en passant a la version graphique
	Vector2D V;
	V.setX(getPosition().getX());
	if(getPosition().getY() > 1) {
		V.setY(getPosition().getY() - 1);
		int i = isMovePossibleUp(V, R);
		if(i == -1) setPosition(V);
		else if(i > 0) decreaseHp(i);
	}
}

int Player::isMovePossibleUp(const Vector2D & position, Room * R) const {
	if(position.getX() < R->getDimX() && position.getY() < R->getDimY() && position.getX() > 0 && position.getY() > 0) {
		Vector2D V(position.getX(), position.getY() + 1);
		Obstacle o = R->getObstacle(V);
		if(o == nothing || o == trapdoor || o == ladder) return -1;
		else if(o == barbedWire) return 1;
		else return 0;
	}
}

void Player::right(Room * R) {
	Vector2D V;
	V.setY(getPosition().getY());
	V.setX(getPosition().getX() + 1);
	if(R->isMovePossible(V)) setPosition(V);
}

void Player::left (Room * R) {
	Vector2D V;
	V.setY(getPosition().getY());
	if(getPosition().getX() > 1) {
		V.setX(getPosition().getX() - 1);
		int i = isMovePossibleUp(V, R);
		if(i == -1) setPosition(V);
		else if(i > 0) decreaseHp(i); // !!!
	}
}

void Player::down(Room * R) { // il va y avoir un probleme avec les trappes (en plus gravity utilise down)
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	int i = isMovePossibleUp(V, R);
	if(i == -1) setPosition(V);
	else if(i > 0) decreaseHp(i);
}

int Player::isMovePossibleDown(const Vector2D & position, Room * R) const {
	if(position.getX() < R->getDimX() && position.getY() < R->getDimY() && position.getX() > 0 && position.getY() > 0) {
		Obstacle o = R->getObstacle(position);
		if(o == nothing || o == trapdoor || o == ladder) return -1;
		else if(o == barbedWire) return 1;
		else return 0;
	}
}

void Player::gravity(Room * R) { // a modifier : probleme avec les trappes
	Vector2D V;
	
}

// TODO : ajouter la gestion des autres obstacles
int Player::isMovePossible(const Vector2D & position, Room * R) const {
	if(position.getX() < R->getDimX() || position.getY() < R->getDimY() || position.getX() > 0 || position.getY() > 0) {
		if(R->getObstacle(position) == nothing && R-> getObstacle(position.setY(position.getY() - 1)) == nothing)
	}
}

void Player::regressionTest() {
	cout << endl << "Test de la classe Player" << endl;

	assert(getPosition().getX() == 0 && getPosition().getY() == 0 && getHeight() == 0 && getWidth() == 0);
	assert(skin == M && hp == 0 && timeInvincible == 0);
	cout << "\tconstructeur par defaut : OK" << endl;

	Player P(Vector2D(2, 3), 1, 1, F, 3);
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 3 && P.getHeight() == 1 && P.getWidth() == 1);
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

	Room * R = new Room("data/test.txt");
	P.left(R); // gauche qui fonctionne
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
	P.left(R); // gauche qui ne fonctionne pas
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
	cout << "\tleft : OK" << endl;

	P.up(R); // haut qui fonctionne
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 2);
	P.up(R); // haut qui ne fonctionne pas
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 2);
	cout << "\tup : OK" << endl;

	P.gravity(R); // gravite qui fonctionne
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
	P.gravity(R); // gravite qui ne fonctionne pas
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
	cout << "\tgravity : OK" << endl;

	P.right(R); // droite qui fonctionne
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 3);
	P.right(R); // droite qui ne fonctionne pas
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 3);
	cout << "\tright : OK" << endl;

	// TODO : down

	cout << "Test de la classe Player : OK" << endl;
}