#include "Game.h"

#include <iostream>

using namespace std;

Game::Game ()  {
	bui = new Building(5);
	pla = new Player(Vector2D(12,16),M,3);
	multyplayer = false;
	pla2 = NULL;
}

Game::~Game() {
	if (bui!=NULL)
		delete bui;
	if (pla!=NULL)
		delete pla;
}

Building * Game::getBuilding() const {
    return bui;
}

Player * Game::getPlayer() const {
    return pla;
}



bool Game::keyboardAction (const char touche) {
	bool b;
	switch(touche) {
		case 'q' :
				pla->left(bui);
				break;
		case 'd' :
				
				b = pla->right(bui);
				return b;
		case 'z' :
				pla->up(bui);
				break;
		case 's' :
				pla->down(bui);
				break;
	}
	return true;
}

int Game::automaticAction (int time) {
    if(time == 0){
		pla->gravity(bui);
		}
	else time=time-1;
	if(pla->getTimeInvincible()>0){
		pla->decreaseTimeInvincible();
	}
	bui->setTimetot(bui->getTimetot()-1);
	return time;
}



