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
	else if(time >2) time = 2;
	else time -= 1;
}

bool Spider::isMovePossible(Building *B, const Vector2D & V) const {
	if(V.getX() < B->getCurrentRoom()->getDimX() && V.getX() >= 0 && V.getY() < B->getCurrentRoom()->getDimY() && V.getY() >= 0)
		if(B->getCurrentRoom()->getObstacle(V) == nothing || B->getCurrentRoom()->getObstacle(V) == fakeBlock)
			return true;
	return false;
}

void Spider::regressionTest() { 
	cout << endl << "Test de la classe Spider" << endl;

	assert(getPosition().getX() == 0 && getPosition().getY() == 0);
	assert(getHeight() == 0 && getWidth() == 0);
	assert(direction == 1);
	cout << "\tconstructeur par défaut : OK" << endl;

	Spider S(Vector2D(6, 8), 1, 1);
	assert(S.getPosition().getX() == 6 && S.getPosition().getY() == 8);
	assert(S.getHeight() == 1 && S.getWidth() == 1);
	assert(S.getDirection() == 1);
	cout << "\tconstructeur par defaut : OK" << endl;

	cout << "Test de la classe Spider : OK" << endl;
}