#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Game.h"
#include "../core/entity/Vector2D.h"
#include "txtGame.h"
#include <unistd.h>

void txtAff(WinTXT & win, const Game & ga) {
	Building* bui = ga.getBuilding();
	Player* pla = ga.getPlayer();
	
	sleep(1);
	win.clear();

	for(unsigned int x=0;x<bui->getCurrentRoom()->getDimX();++x)
		for(unsigned int y=0;y<bui->getCurrentRoom()->getDimY();++y)
			win.print( x, y,(char) bui->getCurrentRoom()->getObstacle(Vector2D(x,y)));
	
	
	win.print(pla->getPosition().getX(),pla->getPosition().getY(),'M');
	win.print(pla->getPosition().getX(),pla->getPosition().getY()-1,'M');
	
	unsigned int hp = pla->getHp();
	unsigned int TimeInv = pla->getTimeInvincible();
	win.print(0,18,'H');
	win.print(2,18,std::to_string(hp).c_str());
	win.print(4,18,'I');
	win.print(6,18,std::to_string(TimeInv).c_str());
	win.print(8,18,'R');
	win.print(10,18,std::to_string(bui->getIntCurrentRoom()).c_str());

	
	

	win.draw();
}

void txtBoucle (Game & ga) {
    WinTXT win (ga.getBuilding()->getCurrentRoom()->getDimX()+1,ga.getBuilding()->getCurrentRoom()->getDimY()+1);
	int time = 3;
	bool ok = true;
	int c;

	do {
	    txtAff(win,ga);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(10000);
        #endif // WIN32

		
		time=ga.actionsAutomatiques(time);

		c = win.getCh();
		switch (c) {
			case 'q':
				ok = ga.actionClavier('q');
				break;
			case 's':
				ok = ga.actionClavier('s');
				break;
			case 'z':
				ok = ga.actionClavier('z');
				break;
			case 'd':
				ok = ga.actionClavier('d');
				break;
			case 'p':
				ok = false;
				break;
		}
		if (ga.getPlayer()->getHp()==0)	{
		ok = false;
		}

	} while (ok);

}
