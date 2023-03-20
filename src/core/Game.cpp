#include "Game.h"
#include <iostream>
using namespace std;
Game::Game ()  {
	bui = new Building(5);
	pla = new Player(Vector2D(10,16),M,3);
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



bool Game::actionClavier (const char touche) {
	bool b;
	switch(touche) {
		case 'q' :
				pla->left(bui);
				return true;
		case 'd' :
				
				b = pla->right(bui);
				return b;
		case 'z' :
				pla->up(bui);
				return true;
		case 's' :
				pla->down(bui);
				return true;
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

