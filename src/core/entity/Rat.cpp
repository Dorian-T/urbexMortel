#include "Rat.h"
#include "../building/Building.h"
#include <iostream>
#include <assert.h>
using namespace std;

Rat::Rat() : Entity() {
	direction = Vector2D(0, 0);
}

Rat::Rat(Vector2D p, unsigned int h, unsigned int w) : Entity(p, h, w) {
	direction = Vector2D(0, 0);
}

Vector2D Rat::getDirection() const {
	return direction;
}

void Rat::move(Building * B, Player * P) {
	findDirection(B, P);
	if(isMovePossible(B, getPosition() + direction))
	setPosition(getPosition() + direction);
}

void Rat::findDirection(Building * B, Player * P) {
	if(isPlayerArround(B, P)) {
		if(getPosition().getX() < P->getPosition().getX()) direction.setX(1);
		else if(getPosition().getX() > P->getPosition().getX()) direction.setX(-1);
		else direction.setX(0);
	}
	else { // directions : 0 = rien, 1 = droite, -1 = gauche
		int x = rand() % 6; // 4/6 de chance de continuer dans la meme direction, 2/6 de chance de changer de direction
		if(x == 0) direction.setX(0);
		else if(x == 1) direction.setX(1);
		else if(x == 2) direction.setX(-1);
	}
}

bool Rat::isPlayerArround(Building * B, Player * P) const { // peut-etre que quand les deplacements seront modifies, il faudra changer
	if(getPosition().distance(P->getPosition()) <= 10) return true;
	else return false;
}

bool Rat::isMovePossible(Building *B, const Vector2D & V) const {
	if(V.getX() < B->getCurrentRoom()->getDimX() && V.getX() >= 0 && V.getY() < B->getCurrentRoom()->getDimY() && V.getY() >= 0)
		if(B->getCurrentRoom()->getObstacle(V) == nothing)
			return true;
	return false;
}

void Rat::gravity(Building * B) {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	if(isMovePossibleGravity(V, B->getCurrentRoom())) setPosition(V);
}

bool Rat::isMovePossibleGravity(const Vector2D & position, Room * R) const {
	if(position.getY() < R->getDimY())
		if(R->getObstacle(position) == nothing)
			return true;
	return false;
}

void Rat::regressionTest() { // a verifier
	cout << endl << "Test de la classe Rat" << endl;

	assert(getPosition().getX() == 0 && getPosition().getY() == 0);
	assert(getHeight() == 0 && getWidth() == 0);
	assert(direction.getX() == 0 && direction.getY() == 0);
	cout << "\tconstructeur par défaut : OK" << endl;

	assert(getDirection().getX() == 0 && getDirection().getY() == 0);
	cout << "\tgetDirection : OK" << endl;

	Rat R(Vector2D(6, 8), 1, 1);
	assert(R.getPosition().getX() == 6 && R.getPosition().getY() == 8);
	assert(R.getHeight() == 1 && R.getWidth() == 1);
	assert(R.getDirection().getX() == 0 && R.getDirection().getY() == 0);
	cout << "\tconstructeur par defaut : OK" << endl;

	// TODO

	cout << "Test de la classe Rat : OK" << endl;
}