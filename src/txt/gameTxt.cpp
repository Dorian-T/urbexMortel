#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "gameTxt.h"
#include "../core/entity/Vector2D.h"
#include "../core/entity/Player.h"
#include "../core/building/Building.h"

#include <iostream>


GameTXT::GameTXT(const Game & G) {
	window = new WinTXT(33, 19);
	termClear();
}

void GameTXT::draw(const Game & G) {
	window->clear();

	// affichage de la salle :
	Room * room = G.getBuilding()->getCurrentRoom();
	char c;
	for(unsigned int x=0; x<room->getDimX(); ++x)
		for(unsigned int y=0; y<room->getDimY(); ++y) {
			c = (char) room->getObstacle(Vector2D(x,y));
			if(c == '.')		window->print(x, y, ' ');
			else if( c == 'O')	window->print(x, y, '#');
			else if( c == '%')	window->print(x, y, '#');
			else				window->print(x, y, c);
		}

	// affichage du joueur :
	Player * player = G.getPlayer();
	window->print(player->getPosition().getX(), player->getPosition().getY(), 'X');
	window->print(player->getPosition().getX(), player->getPosition().getY()-1, 'O');

	// affichage des rats :
	for(unsigned int i = 0; i < G.getNbRat(); i++) {
		Rat * rat = G.getRat(i);
		window->print(rat->getPosition().getX(), rat->getPosition().getY(), 'R');
	}

	// affichage des araignées :
	for(unsigned int i = 0; i < G.getNbSpider(); i++) {
		Spider * spider = G.getSpider(i);
		window->print(spider->getPosition().getX(), spider->getPosition().getY(), 'S');
		int j = 1;
		// affichage de la toile :
		while(room->getObstacle(Vector2D(spider->getPosition().getX(), spider->getPosition().getY()-j)) == nothing) {
			window->print(spider->getPosition().getX(), spider->getPosition().getY()-j, '|');
			j++;
		}
	}

	// affichage des informations :

	// affichage de la vie du joueur :
	unsigned int hp = player->getHp();
	window->print(0,18,'H');
	window->print(1,18,':');
	window->print(2,18,std::to_string(hp).c_str());

	// affichage du temps d'invincibilité du joueur :
	unsigned int timeInv = player->getTimeInvincible();
	window->print(4,18,'I');
	window->print(5,18,':');
	window->print(6,18,std::to_string(timeInv).c_str());

	// affichage de la salle actuelle :
	Building * building = G.getBuilding();
	window->print(9,18,'R');
	window->print(10,18,':');
	window->print(11,18,std::to_string(building->getIntCurrentRoom()+1).c_str());
	window->print(12,18,'/');
	window->print(13,18,std::to_string(building->getNbRoom()).c_str());

	// affichage du temps restant :
	window->print(15,18,'T');
	window->print(16,18,':');
	window->print(17,18,std::to_string(G.getBuilding()->getTimeLeft()).c_str());

	window->draw();
}

void GameTXT::loop(Game & G) {
	int time = 3;
	bool close = false;
	int c;

	G.addRat();
	G.addSpider();

	while (!close) {
		draw(G);

		#ifdef _WIN32
		Sleep(100);
		#else
		usleep(100000);
		#endif // WIN32

		time = G.update(time);

		c = window->getCh();
		switch (c) {

			case 'z':
				if(G.getPlayer()->standingOnBlock(*G.getBuilding()->getCurrentRoom())) {
					G.getPlayer()->up(*G.getBuilding());
					time = 4;
				}
				break;

			case 'q':
				G.getPlayer()->left(*G.getBuilding());
				break;

			case 's':
				G.getPlayer()->down(*G.getBuilding());
				break;

			case 'd':
				close = !G.getPlayer()->right(*G.getBuilding());
				break;

			case 'p':
				close = true;
				break;
		}

		if (G.getPlayer()->getHp() == 0 || G.getBuilding()->getTimeLeft() == 0)
			close = true;
	}
}