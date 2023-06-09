#include "Spider.h"

#include <assert.h>
#include <iostream>

using namespace std;


// Constructeur :

Spider::Spider(Vector2D p) : Entity(p, 1, 1) {
	direction = 1;
	time = 0;
}


// Accesseur :

int Spider::getDirection() const {
	return direction;
}


// Déplacements :

void Spider::move(const Room & R) {
	if(time == 0) {
		Vector2D V = getPosition();
		V.setY(V.getY() + direction);
		if(isMovePossible(R, V)) {
			setPosition(V);
			time += 2;
		}
		else direction = -direction;
	}
	else if(time >2) time = 2;
	else time -= 1;
}

bool Spider::isMovePossible(const Room & R, const Vector2D & V) const {
	if(V.getX() < R.getDimX() && V.getX() >= 0 && V.getY() < R.getDimY() && V.getY() >= 0)
		if(R.getObstacle(V) == nothing || R.getObstacle(V) == fakeBlock)
			return true;
	return false;
}

void Spider::regressionTest() { 
	cout << endl << "Test de la classe Spider" << endl;

	assert(getPosition().getX() == 2 && getPosition().getY() == 3);
	assert(getHeight() == 1 && getWidth() == 1);
	assert(direction == 1); assert(time == 0);
	cout << "\tconstructeur parametre : OK" << endl;

	assert(getDirection() == direction);
	cout << "\tgetDirection : OK" << endl;

	// Les tests de déplacements sont dans tests.cpp

	cout << "Test de la classe Spider : OK" << endl;
}