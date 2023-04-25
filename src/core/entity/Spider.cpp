#include "Spider.h"
#include "../building/Building.h"
#include <iostream>
#include <assert.h>
using namespace std;

Spider::Spider() : Entity() {
	direction = 1;
	time = 0;
}

Spider::Spider(Vector2D p, unsigned int h, unsigned int w) : Entity(p, h, w) {
	direction = 1;
	time = 0;
}

int Spider::getDirection() const {
	return direction;
}

void Spider::move(Building * B) {
	if(time==0) {
		Vector2D V;
		V=getPosition();
		V.setY(V.getY()+direction);
		if(isMovePossible(B, V)) {
			setPosition(V);
			time += 2;
		}
		else direction= direction * -1;
	}
	else time -=1;
}

bool Spider::isMovePossible(Building *B, const Vector2D & V) const {
	if(V.getX() < B->getCurrentRoom()->getDimX() && V.getX() >= 0 && V.getY() < B->getCurrentRoom()->getDimY() && V.getY() >= 0)
		if(B->getCurrentRoom()->getObstacle(V) == nothing)
			return true;
	return false;
}



/*void Spider::regressionTest() { // a verifier
	cout << endl << "Test de la classe Spider" << endl;

	assert(getPosition().getX() == 0 && getPosition().getY() == 0);
	assert(getHeight() == 0 && getWidth() == 0);
	assert(direction.getX() == 0 && direction.getY() == 0);
	cout << "\tconstructeur par défaut : OK" << endl;

	assert(getDirection().getX() == 0 && getDirection().getY() == 0);
	cout << "\tgetDirection : OK" << endl;

	Spider R(Vector2D(6, 8), 1, 1);
	assert(R.getPosition().getX() == 6 && R.getPosition().getY() == 8);
	assert(R.getHeight() == 1 && R.getWidth() == 1);
	assert(R.getDirection().getX() == 0 && R.getDirection().getY() == 0);
	cout << "\tconstructeur par defaut : OK" << endl;

	// TODO

	cout << "Test de la classe Spider : OK" << endl;
}*/