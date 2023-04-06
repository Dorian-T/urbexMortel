#include "Game.h"

#include <iostream>

using namespace std;

Game::Game ()  {
	building = new Building(5);
	player1 = new Player(Vector2D(12,16),M,3);
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

Player * Game::getPlayer() const {
    return player1;
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

int Game::automaticAction (int time) {
    if(time == 0){
		player1->gravity(building);
		}
	else time=time-1;
	if(player1->getTimeInvincible()>0){
		player1->decreaseTimeInvincible();
	}
	building->setTimetot(building->getTimetot()-1);
	return time;
}



