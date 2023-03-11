#include "Game.h"

Game::Game ()  {

}

const Building& Game::getBuilding() const {
    return bui;
}

const Player& Game::getPlayer() const {
    return pla;
}



void Game::actionClavier (const char touche) {
	switch(touche) {
		case 'q' :
				pla.left(bui.getcurrentRoom());
				break;
		case 'd' :
				pla.right(bui.getcurrentRoom());
				break;
		case 'z' :
				pla.up(bui.getcurrentRoom());
				break;
		case 's' :
				pla.down(bui.getcurrentRoom());
				break;
	}
}

void Game::actionsAutomatiques () {
    pla.gravity(bui.getcurrentRoom());
}

