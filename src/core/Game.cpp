#include "Game.h"
#include "entity/Rat.h"

#include <iostream>
#include <assert.h>

using namespace std;

const unsigned int NB_ROOM = 3; // nombre de salles intermediaires

Game::Game ()  {
	building = new Building(NB_ROOM);
	room = 0;
	player1 = new Player(Vector2D(12, 16), M, 3);
	multiplayer = false;
	player2 = NULL;
}

Game::~Game() {
	if (building!=NULL)
		delete building;
	if (player1!=NULL)
		delete player1;
}

Building * Game::getBuilding() const {
    return building;
}

Player * Game::getPlayer() const { // TODO : a modifier pour le multi
    return player1;
}

unsigned int Game::getNbRat() const {
	return rats.size();
}

Rat * Game::getRat(unsigned int i) const {
	return rats[i];
}

bool Game::changeRoom() {
	unsigned int n = building->getIntCurrentRoom();
	if(room != n){
		room = n;
		return true;
	}
	return false;
}

void Game::addRat() {
	for(unsigned int i = building->getCurrentRoom()->getNbRat(); i > 0; i--)
		rats.push_back(new Rat(*building->getCurrentRoom()->getRat(i-1), 1, 1));
}

int Game::automaticAction (int time) {

    if(time == 0)
		player1->gravity(building);
	else time = time - 1;

	if(player1->getTimeInvincible() > 0)
		player1->decreaseTimeInvincible();

	building->setTimetot(building->getTimetot() - 1);

	if(changeRoom())
		addRat();

	return time;
}

bool Game::keyboardAction (const char touche) {
	bool b;
	switch(touche) {
		case 'q' :
				player1->left(building);
				break;
		case 'd' :
				
				b = player1->right(building);
				return b;
		case 'z' :
				player1->up(building);
				break;
		case 's' :
				player1->down(building);
				break;
	}
	return true;
}

void Game::regressionTest() {
	cout << endl << "Test de la classe Game" << endl;

	assert(building->getNbRoom() == NB_ROOM);
	assert(room == 0);
	assert(player1->getPosition().getX() == 12 && player1->getPosition().getY() == 16); assert(player1->getHp() == 3); assert(player1->getSkin() == M);
	assert(multiplayer == false);
	assert(player2 == NULL);
	cout << "\tTest du constructeur par defaut : OK" << endl;

	assert(getBuilding() == building);
	cout << "\tTest de getBuilding : OK" << endl;

	assert(getPlayer() == player1);
	cout << "\tTest de getPlayer : OK" << endl;

	// TODO : tester getNbRat

	// TODO : tester getRat

	assert(changeRoom() == false);
	if(NB_ROOM > 1) {
		assert(building->finishRoom());
		assert(changeRoom() == true);
		unsigned int n = building->getCurrentRoom()->getNbRat();
		if(n > 0) {
			assert(rats.size() == n);
			for(unsigned int i = 0; i < n; i++) {
				assert(rats[i]->getPosition().getX() == building->getCurrentRoom()->getRat(i)->getX());
				assert(rats[i]->getPosition().getY() == building->getCurrentRoom()->getRat(i)->getY());
			}
		}
	}
	cout << "\tTest de changeRoom : OK" << endl;

	// TODO : tester keyboardAction

	// TODO : tester automaticAction

	cout << "Test de la classe Game : OK" << endl;
}