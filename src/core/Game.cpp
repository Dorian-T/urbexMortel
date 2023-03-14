#include "Game.h"

Game::Game ()  {
	bui = new Building;
	pla = new Player;
}

Game::~Game() {
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
				pla->left(bui->getcurrentRoom());
				break;
		case 'd' :
				pla->right(bui->getcurrentRoom());
				break;
		case 'z' :
				pla->up(bui->getcurrentRoom());
				break;
		case 's' :
				pla->down(bui->getcurrentRoom());
				break;
	}
}

void Game::actionsAutomatiques () {
    pla->gravity(bui->getcurrentRoom());
}

