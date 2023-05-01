#include "entity/Vector2D.h"
#include "entity/Entity.h"
#include "entity/Player.h"
#include "entity/Rat.h"
#include "building/Room.h"
#include "building/Building.h"
#include "Game.h"

#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void movementPlayerRegressionTest() {
	cout << "Test des mouvements de Player" << endl;
	Building B(PATH_ROOMS + "test.txt");
	Player P(Vector2D(1, 7), lilith, 5);

	P.down(B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers le bas bloque : OK" << endl;

	P.left(B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers la gauche bloque : OK" << endl;

	P.right(B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 7);
	assert(P.getHp() == 4);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest du mouvement vers la droite degat : OK" << endl;

	P.up(B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers le haut bon : OK" << endl;

	P.right(B);
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers la droite bon : OK" << endl;

	P.up(B);
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers le haut bloque : OK" << endl;

	P.gravity(*B.getCurrentRoom());
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 6);
	assert(P.getHp() == 3);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest de la gravite degat : OK" << endl;

	P.right(B);
	P.gravity(*B.getCurrentRoom());
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	cout << "\tTest de la gravite bon : OK" << endl;

	P.gravity(*B.getCurrentRoom());
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	cout << "\tTest de la gravite bloque : OK" << endl;

	assert(B.getCurrentRoom()->getObstacle(Vector2D (3,8)) == ghostBlock);
	P.StandingOnGhostBlock(*B.getCurrentRoom());
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	assert(B.getCurrentRoom()->getObstacle(Vector2D (3,8)) == nothing);
	cout << "\tTest du ghost block : OK" << endl;

	P.left(B);
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	assert(P.getHp() == 2);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest du mouvement vers la gauche degat : OK" << endl;

	P.right(B);
	P.right(B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers la droite bloque : OK" << endl;

	P.left(B);
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers la gauche bon : OK" << endl;

	P.right(B);
	P.up(B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers le haut sur echelle plus fake block : OK" << endl;

	P.gravity(*B.getCurrentRoom());
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 6);
	cout << "\tTest de la gravite bloque par echelle : OK" << endl;

	P.down(B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers le bas sur echelle : OK" << endl;

	P.up(B);
	P.up(B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 3);
	cout << "\tTest du mouvement vers le haut par une trappe : OK" << endl;

	P.up(B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 3);
	assert(P.getHp() == 1);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest du mouvement vers le haut degat : OK" << endl;

	P.down(B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 4);
	cout << "\tTest du mouvement vers le bas par une trappe plus fake block : OK" << endl;

	assert(!P.right(B));
	cout << "\tTest du changement de salle : OK" << endl;

	cout << "Test des mouvements de Player : OK" << endl;
}

void movementRatRegressionTest() {
	cout << "Test des mouvements de Rat" << endl;
	Building B(PATH_ROOMS + "test.txt");
	Rat R(Vector2D(1, 1));

	Player P1(Vector2D(100, 100), lilith, 4);
	R.move(*B.getCurrentRoom(), P1);
	assert((R.getPosition().getX() == 1 || R.getPosition().getX() == 2) && R.getPosition().getY() == 1);
	cout << "\tTest du mouvement automatique : OK" << endl;

	R.gravity(*B.getCurrentRoom());
	assert(R.getPosition().getY() == 2);
	cout << "\tTest de la gravite : OK" << endl;

	unsigned int x = R.getPosition().getX();
	Player P2(Vector2D(4, 2), lilith, 4);
	R.move(*B.getCurrentRoom(), P2);
	R.move(*B.getCurrentRoom(), P2);
	R.move(*B.getCurrentRoom(), P2);
	assert(R.getPosition().getX() > x && R.getPosition().getY() == 2);
	cout << "\tTest du mouvement vers le joueur : OK" << endl;

	cout << "Test des mouvements de Rat : OK" << endl;
}

void movementSpiderRegressionTest() {
	cout << "Test des mouvements de Spider" << endl;
	Building B(PATH_ROOMS + "test.txt");
	Spider S(Vector2D(2, 0));

	S.move(*B.getCurrentRoom());
	assert(S.getPosition().getX() == 2 && S.getPosition().getY() == 1);
	cout << "\tTest du mouvement vers le bas : OK" << endl;

	S.move(*B.getCurrentRoom());
	assert(S.getPosition().getX() == 2 && S.getPosition().getY() == 1);
	cout << "\tTest du mouvement vers le bas retarde : OK" << endl;

	for(unsigned int i = 0;i< 8;i++)
		S.move(*B.getCurrentRoom());
	assert(S.getPosition().getX() == 2 && S.getPosition().getY() == 3);
	assert(S.getDirection() == -1);
	cout << "\tTest du changement de direction : OK" << endl;

	S.move(*B.getCurrentRoom());
	assert(S.getPosition().getX() == 2 && S.getPosition().getY() == 2);
	cout << "\tTest du non movement vers le haut : OK" << endl;

	cout << "Test des mouvements de Spider : OK" << endl;
}

int main () {
	srand(time(NULL));

	Vector2D V;
	V.regressionTest();

	Entity E;
	E.regressionTest();

	Player P(Vector2D(2, 3), dora, 3);
	P.regressionTest();
	movementPlayerRegressionTest();

	Rat Ra(Vector2D(2, 3));
	Ra.regressionTest();
	movementRatRegressionTest();

	Spider Sp(Vector2D(2, 3));
	Sp.regressionTest();
	movementSpiderRegressionTest();

	Room Ro(PATH_ROOMS + "test.txt");
	Ro.regressionTest();

	Building B(1);
	B.regressionTest();

	Game G;
	G.regressionTest();

	cout << endl << "Tous les tests de non-regression ont reussi" << endl;

	return 0;
}