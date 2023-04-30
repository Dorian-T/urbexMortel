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
	cout << endl << "Test des mouvements de Player" << endl;
	Building B(PATH_ROOMS + "test.txt");
	Player P(Vector2D(1, 7), lilith, 5);

	P.down(&B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers le bas bloque : OK" << endl;

	P.left(&B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers la gauche bloque : OK" << endl;

	P.right(&B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 7);
	assert(P.getHp() == 4);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest du mouvement vers la droite degat : OK" << endl;

	P.up(&B);
	assert(P.getPosition().getX() == 1 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers le haut bon : OK" << endl;

	P.right(&B);
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers la droite bon : OK" << endl;

	P.up(&B);
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers le haut bloque : OK" << endl;

	P.gravity(&B);
	assert(P.getPosition().getX() == 2 && P.getPosition().getY() == 6);
	assert(P.getHp() == 3);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest de la gravite degat : OK" << endl;

	P.right(&B);
	P.gravity(&B);
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	cout << "\tTest de la gravite bon : OK" << endl;

	P.gravity(&B);
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	cout << "\tTest de la gravite bloque : OK" << endl;

	P.left(&B);
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	assert(P.getHp() == 2);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest du mouvement vers la gauche degat : OK" << endl;

	P.right(&B);
	P.right(&B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers la droite bloque : OK" << endl;

	P.left(&B);
	assert(P.getPosition().getX() == 3 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers la gauche bon : OK" << endl;

	P.right(&B);
	P.up(&B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 6);
	cout << "\tTest du mouvement vers le haut sur echelle : OK" << endl;

	P.gravity(&B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 6);
	cout << "\tTest de la gravite bloque par echelle : OK" << endl;

	P.down(&B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 7);
	cout << "\tTest du mouvement vers le bas sur echelle : OK" << endl;

	P.up(&B);
	P.up(&B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 3);
	cout << "\tTest du mouvement vers le haut par une trappe : OK" << endl;

	P.up(&B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 3);
	assert(P.getHp() == 1);
	for(int i = 0; i < 20; i++) P.decreaseTimeInvincible();
	cout << "\tTest du mouvement vers le haut degat : OK" << endl;

	P.down(&B);
	assert(P.getPosition().getX() == 4 && P.getPosition().getY() == 4);
	cout << "\tTest du mouvement vers le bas par une trappe : OK" << endl;

	assert(!P.right(&B));
	cout << "\tTest du changement de salle : OK" << endl;

	cout << "Test des mouvements de Player : OK" << endl;
}

void movementRatRegressionTest() {
	cout << endl << "Test des mouvements de Rat" << endl;
	Building B(PATH_ROOMS + "test.txt");
	Rat R(Vector2D(1, 7), 1, 1);

	// TODO
}

void movementSpiderRegressionTest() {
	cout << endl << "Test des mouvements de Spider" << endl;
	Building B(PATH_ROOMS + "test.txt");
	Spider S(Vector2D(2, 0), 1, 1);

	S.move(&B);
	assert(S.getPosition().getX() == 2 && S.getPosition().getY() == 1);
	cout << "\tTest du movement vers le bas : OK" << endl;

	S.move(&B);
	assert(S.getPosition().getX() == 2 && S.getPosition().getY() == 1);
	cout << "\tTest du non movement vers le bas : OK" << endl;

	for(unsigned int i = 0;i< 8;i++) { 
		S.move(&B); 
		}
	assert(S.getPosition().getX() == 2 && S.getPosition().getY() == 3);
	assert(S.getDirection() == -1);
	cout << "\tTest du changement de direction : OK" << endl;

	S.move(&B);
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

	// Player P;
	// P.regressionTest(); // probleme

	Rat Ra;
	Ra.regressionTest();

	Spider Sp;
	Sp.regressionTest();

	Room Ro(PATH_ROOMS + "test.txt");
	Ro.regressionTest();

	Building B(1);
	B.regressionTest();

	Game G;
	G.regressionTest(); // problème

	movementPlayerRegressionTest();

	movementSpiderRegressionTest();

	return 0;
}