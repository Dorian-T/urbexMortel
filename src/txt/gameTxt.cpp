#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Game.h"
#include "../core/entity/Vector2D.h"
#include "../core/entity/Player.h"
#include "../core/building/Building.h"
#include "gameTxt.h"
#include <unistd.h>

void txtDraw(WinTXT & win, const Game & ga) {
	Building* building = ga.getBuilding();
	Player* player = ga.getPlayer();
	
	
	win.clear();
	char c;

	for(unsigned int x=0;x<building->getCurrentRoom()->getDimX();++x)
		for(unsigned int y=0;y<building->getCurrentRoom()->getDimY();++y) {
			c = (char) building->getCurrentRoom()->getObstacle(Vector2D(x,y));
			if( c == '.') win.print(x, y, ' ');
			else win.print(x, y, c);
		}	
	
	win.print(player->getPosition().getX(),player->getPosition().getY(),'X');
	win.print(player->getPosition().getX(),player->getPosition().getY()-1,'O');
	for(unsigned int i = 0; i < ga.getNbRat(); i++) {
		Rat* rat = ga.getRat(i);
		win.print(rat->getPosition().getX(), ga.getRat(i)->getPosition().getY(), 'R');
	}
	for(unsigned int i = 0; i < ga.getNbSpider(); i++) {
		Spider* spider = ga.getSpider(i);
		win.print(spider->getPosition().getX(), ga.getSpider(i)->getPosition().getY(), 'S');
	}

	unsigned int hp = player->getHp();
	unsigned int TimeInv = player->getTimeInvincible();
	win.print(0,18,'H');
	win.print(1,18,':');
	win.print(2,18,std::to_string(hp).c_str());
	win.print(4,18,'I');
	win.print(5,18,':');
	win.print(6,18,std::to_string(TimeInv).c_str());
	win.print(9,18,'R');
	win.print(10,18,':');
	win.print(11,18,std::to_string(building->getIntCurrentRoom()+1).c_str());
	win.print(12,18,'/');
	win.print(13,18,std::to_string(building->getNbRoom()).c_str());
	win.print(15,18,'T');
	win.print(16,18,':');
	win.print(17,18,std::to_string(ga.getBuilding()->getTimeLeft()).c_str());

	win.draw();
}

void txtLoop (Game & ga) {
	WinTXT win (ga.getBuilding()->getCurrentRoom()->getDimX()+1,ga.getBuilding()->getCurrentRoom()->getDimY()+1);
	int time = 3;
	bool ok = true;
	int c;

	ga.addRat();
	ga.addSpider();

	while (ok) {
		txtDraw(win,ga);

		#ifdef _WIN32
		Sleep(100);
		#else
		usleep(100000);
		#endif // WIN32

		time=ga.update(time);

		c = win.getCh();
		switch (c) {
			case 'q':
				ga.keyboardAction('q');
				break;
			case 's':
				ga.keyboardAction('s');
				break;
			case 'z':
			if(ga.getPlayer()->standingOnBlock(ga.getBuilding())) {
				ga.keyboardAction('z');
				time = 4;
			}
				break;
			case 'd':
				ok = ga.keyboardAction('d');
				break;
			case 'p':
				ok = false;
				break;
		}

		if (ga.getPlayer()->getHp() == 0 || ga.getBuilding()->getTimeLeft() == 0)
			ok = false;
	}
}
