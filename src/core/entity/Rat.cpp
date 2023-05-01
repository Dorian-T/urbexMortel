#include "Rat.h"

#include <assert.h>
#include <iostream>

using namespace std;


// Constructeur :

Rat::Rat(Vector2D p) : Entity(p, 1, 1) {
	direction = 0;
	time = 0; 
}


// Accesseur :

int Rat::getDirection() const {
	return direction;
}


// Déplacements :

void Rat::move(const Room & R, const Player & P) {
	if(time == 0) {
		findDirection(P);
		if(isMovePossible(R, getPosition() + Vector2D(direction, 0))) {
			setPosition(getPosition() + Vector2D(direction, 0));
			time += 2;
		}
	}
	else if(time >1) time = 1;
	else time -= 1;
}

void Rat::findDirection(const Player & P) {
	if(isPlayerArround(P)) {
		if(getPosition().getX() < P.getPosition().getX()) direction = 1;
		else if(getPosition().getX() > P.getPosition().getX()) direction = -1;
		else direction = 0;
	}
	else {								// directions : 0 = rien, 1 = droite, -1 = gauche
		int x = rand() % 6;				// probas : 4/6 -> continuer dans la meme direction, 2/6 -> changer de direction
		if(x == 0) direction = 0;
		else if(x == 1) direction = 1;
		else if(x == 2) direction = -1;
	}
}

bool Rat::isPlayerArround(const Player & P) const {
	if(getPosition().distance(P.getPosition()) <= 15)
		return true;
	else
		return false;
}

bool Rat::isMovePossible(const Room & R, const Vector2D & V) const {
	if(V.getX() < R.getDimX() && V.getX() >= 0 && V.getY() < R.getDimY() && V.getY() >= 0)
		if(R.getObstacle(V) == nothing || R.getObstacle(V) == fakeBlock)
			return true;
	return false;
}

void Rat::gravity(const Room & R) {
	Vector2D V;
	V.setX(getPosition().getX());
	V.setY(getPosition().getY() + 1);
	if(isMovePossibleGravity(R, V)) setPosition(V);
}

bool Rat::isMovePossibleGravity(const Room & R, const Vector2D & position) const {
	if(position.getY() < R.getDimY())
		if(R.getObstacle(position) == nothing || R.getObstacle(position) == fakeBlock)
			return true;
	return false;
}

void Rat::regressionTest() {
	cout << endl << "Test de la classe Rat" << endl;

	assert(getPosition().getX() == 2 && getPosition().getY() == 3);
	assert(getHeight() == 1 && getWidth() == 1);
	assert(direction == 0); assert(time == 0);
	cout << "\tconstructeur parametre : OK" << endl;

	assert(getDirection() == direction);
	cout << "\tgetDirection : OK" << endl;

	// Les tests de déplacements sont dans tests.cpp

	cout << "Test de la classe Rat : OK" << endl;
}