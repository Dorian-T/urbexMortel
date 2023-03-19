#include "Game.h"
#include <iostream>
using namespace std;
Game::Game ()  {
	bui = new Building;
	pla = new Player(Vector2D(12,16),M,3);
}

Game::~Game() {
	cout<<"delete Game"<<endl;
	if (bui!=NULL)
	{
		delete bui;
	}
	if (pla!=NULL)
	{
		delete pla;
	}
	
}

Building * Game::getBuilding() const {
    return bui;
}

Player * Game::getPlayer() const {
    return pla;
}



void Game::actionClavier (const char touche) {
	switch(touche) {
		case 'q' :
				pla->left(bui);
				break;
		case 'd' :
				pla->right(bui);
				break;
		case 'z' :
				pla->up(bui);
				break;
		case 's' :
				pla->down(bui);
				break;
	}
}

int Game::actionsAutomatiques (int time) {
    if(time == 0){
		pla->gravity(bui); time= 3;
		}
	else time=time-1;
	if(pla->getTimeInvincible()>0){
		pla->decreaseTimeInvincible();
	}
	return time;
}

