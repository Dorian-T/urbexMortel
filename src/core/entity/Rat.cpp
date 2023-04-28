#include "Rat.h"
#include "../building/Building.h"
#include <iostream>
#include <assert.h>
using namespace std;

Rat::Rat() : Entity() {
	direction = 0;
}

Rat::Rat(Vector2D p, unsigned int h, unsigned int w) : Entity(p, h, w) {
	direction = 0;
}

int Rat::getDirection() const {
	return direction;
}

void Rat::move(Building * B, Player * P) {
	if(time == 0) {
		findDirection(B, P);
		if(isMovePossible(B, getPosition() + Vector2D(direction, 0))) {
			setPosition(getPosition() + Vector2D(direction, 0));
			time += 1; // est-ce que ça marche vraiment ?
		}
	}
	else if(time >1) time = 1;
	else time -= 1;
}

void Rat::findDirection(Building * B, Player * P) {
	if(isPlayerArround(B, P)) {
		if(getPosition().getX() < P->getPosition().getX()) direction = 1;
		else if(getPosition().getX() > P->getPosition().getX()) direction = -1;
		else direction = 0;
	}
	else { // directions : 0 = rien, 1 = droite, -1 = gauche
		int x = rand() % 6; // 4/6 de chance de continuer dans la meme direction, 2/6 de chance de changer de direction
		if(x == 0) direction = 0;
		else if(x == 1) direction = 1;
		else if(x == 2) direction = -1;
	}
}

bool Rat::isPlayerArround(Building * B, Player * P) const {
	if(getPosition().distance(P->getPosition()) <= 10) return true;
	else return false;
}

bool Rat::isMovePossible(Building *B, const Vector2D & V) const {
	if(V.getX() < B->getCurrentRoom()->getDimX() && V.getX() >= 0 && V.getY() < B->getCurrentRoom()->getDimY() && V.getY() >= 0)
		if(B->getCurrentRoom()->getObstacle(V) == nothing || B->getCurrentRoom()->getObstacle(V) == fakeBlock )
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
		if(R->getObstacle(position) == nothing || R->getObstacle(position) == fakeBlock)
			return true;
	return false;
}

void Rat::regressionTest() { // a verifier
	cout << endl << "Test de la classe Rat" << endl;

	assert(getPosition().getX() == 0 && getPosition().getY() == 0);
	assert(getHeight() == 0 && getWidth() == 0);
	assert(direction == 0);
	cout << "\tconstructeur par défaut : OK" << endl;

	assert(getDirection() == 0);
	cout << "\tgetDirection : OK" << endl;

	Rat R(Vector2D(6, 8), 1, 1);
	assert(R.getPosition().getX() == 6 && R.getPosition().getY() == 8);
	assert(R.getHeight() == 1 && R.getWidth() == 1);
	assert(R.getDirection() == 0);
	cout << "\tconstructeur par defaut : OK" << endl;

	// TODO

	cout << "Test de la classe Rat : OK" << endl;
}