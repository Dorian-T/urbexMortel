#include "entity/Vector2D.h"
#include "entity/Entity.h"
#include "entity/Player.h"
#include "building/Room.h"
#include "building/Building.h"
#include <iostream>
#include <assert.h>
using namespace std;

// void movementRegressionTest() {
	
// 	Building D("data/test.txt");
// 	Player P(Vector2D(1, 3), M, 1);
// 	P.left(D); // gauche qui fonctionne
// 	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
// 	P.left(D); // gauche qui ne fonctionne pas
// 	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
// 	cout << "\tleft : OK" << endl;

// 	P.up(R); // haut qui fonctionne
// 	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 2);
// 	P.up(R); // haut qui ne fonctionne pas
// 	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 2);
// 	cout << "\tup : OK" << endl;

// 	P.gravity(R); // gravite qui fonctionne
// 	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
// 	P.gravity(R); // gravite qui ne fonctionne pas
// 	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 3);
// 	cout << "\tgravity : OK" << endl;

// 	P.right(R); // droite qui fonctionne
// 	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 3);
// 	P.right(R); // droite qui ne fonctionne pas
// 	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 3);
// 	cout << "\tright : OK" << endl;

// 	// TODO : down

// }

int main () {

	Vector2D V;
	V.regressionTest();

	Entity E;
	E.regressionTest();

	Player P;
	P.regressionTest();

	Room R;
	R.regressionTest();

	Building B(10);
	B.regressionTest();



	return 0;
}