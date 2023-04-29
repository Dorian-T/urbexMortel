#include "Game.h"
#include "entity/Rat.h"
#include "entity/Spider.h"

#include <iostream>
#include <assert.h>

using namespace std;

const int NB_ROOM = 3;

Game::Game() {
	building = NULL;
	player = NULL;
	room = 0;
}

Game::~Game() {
	if (building != NULL)
		delete building;
	if (player != NULL)
		delete player;
	if (rats.size() != 0) {
		for (unsigned int i = 0; i < rats.size(); i++)
			delete rats[i];
		rats.clear();
	}	
	if (spiders.size() != 0) {
		for (unsigned int i = 0; i < spiders.size(); i++)
			delete spiders[i];
		spiders.clear();
	}
}

void Game::setDifficulty(unsigned int difficulty) {
	if(difficulty==3) {
		building = new Building(8);
		player = new Player(Vector2D(12, 16), lilith, 1);
		getBuilding()->setTotalTime(getBuilding()->getTotalTime()*20);
	}
	else if(difficulty==2) {
		building = new Building(5);
		player = new Player(Vector2D(12, 16), lilith, 3);
		getBuilding()->setTotalTime(getBuilding()->getTotalTime()*15);
	}
	else {
		building = new Building(3);
		player = new Player(Vector2D(12, 16), lilith, 5);
		getBuilding()->setTotalTime(getBuilding()->getTotalTime()*10);
	}
	getBuilding()->setTimeLeft(getBuilding()->getTotalTime());
}

Building* Game::getBuilding() const {
    return building;
}

Player * Game::getPlayer() const { // TODO : a modifier pour le multi
    return player;
}

unsigned int Game::getNbRat() const {
	return rats.size();
}

Rat * Game::getRat(unsigned int i) const {
	return rats[i];
}

unsigned int Game::getNbSpider() const {
	return spiders.size();
}

Spider * Game::getSpider(unsigned int i) const {
	return spiders[i];
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

void Game::removeRat() {
	for (unsigned int i = 0; i < rats.size(); i++)
	{
		delete rats[i];
	}
	rats.clear();
}

void Game::collisionRat() {
	for(unsigned int i = 0; i < getNbRat(); i++)
		if(rats[i]->getPosition().getX() == player->getPosition().getX() && rats[i]->getPosition().getY() == player->getPosition().getY())
			player->decreaseHp(1);
}

void Game::addSpider() {
	for(unsigned int i = building->getCurrentRoom()->getNbSpider(); i > 0; i--)
		spiders.push_back(new Spider(*building->getCurrentRoom()->getSpider(i-1), 1, 1));
}

void Game::removeSpider() {
	for (unsigned int i = 0; i < spiders.size(); i++)
	{
		delete spiders[i];
	}
	spiders.clear();
}

void Game::collisionSpider() {
	for(unsigned int i = 0; i < getNbSpider(); i++)
		if((spiders[i]->getPosition().getX() == player->getPosition().getX() && spiders[i]->getPosition().getY() == player->getPosition().getY())
			|| (spiders[i]->getPosition().getX() == player->getPosition().getX() && spiders[i]->getPosition().getY() == player->getPosition().getY()-1))
			player->decreaseHp(1);
}

int Game::update (int time) {

    if(time == 0)
		player->gravity(building);
	else time = time - 1;

	if(player->getTimeInvincible() > 0)
		player->decreaseTimeInvincible();

	getBuilding()->setTimeLeft(getBuilding()->getTimeLeft() - 1);

	if(changeRoom()) {
		removeRat();
		addRat();
		removeSpider();
		addSpider();
	}
	for(unsigned int i = 0; i < getNbRat(); i++) {
		rats[i]->move(building, player);
		rats[i]->gravity(building);
	}
	for(unsigned int i = 0; i < getNbSpider(); i++)
		spiders[i]->move(building);
	collisionRat();
	collisionSpider();

	player->StandingOnGhostBlock(building);

	return time;
}

bool Game::keyboardAction (const char touche) {
	bool b;
	switch(touche) {
		case 'q' :
				player->left(building);
				break;
		case 'd' :
				
				b = player->right(building);
				return b;
		case 'z' :
				player->up(building);
				break;
		case 's' :
				player->down(building);
				break;
	}
	return true;
}

void Game::regressionTest() { // TODO : à refaire et vérifier
	cout << endl << "Test de la classe Game" << endl;

	assert(building == NULL);
	assert(room == 0);
	assert(player == NULL);
	cout << "\tTest du constructeur par defaut : OK" << endl;

	setDifficulty(1);
	assert(building->getNbRoom()==5);
	assert(room == 0);
	assert(player->getHp() == 5); assert(player->getSkin() == lilith) ; 
	assert(player->getPosition().getX() == 12 && player->getPosition().getY() == 16);
	cout << "\tTest de getBuilding : OK" << endl;

	assert(getBuilding() == building);
	cout << "\tTest de getBuilding : OK" << endl;

	assert(getPlayer() == player);
	cout << "\tTest de getPlayer : OK" << endl;

	// TODO : tester getNbRat

	// TODO : tester getRat

	assert(changeRoom() == false);
	if(NB_ROOM > 1) {
		assert(building->finishRoom());
		assert(changeRoom() == true);
		removeRat();
		addRat();
		removeSpider();
		addSpider();
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

	// TODO : tester update

	cout << "Test de la classe Game : OK" << endl;
}