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

	for(unsigned int x=0;x<bui->getcurrentRoom()->getDimX();++x)
		for(unsigned int y=0;y<bui->getcurrentRoom()->getDimY();++y)
			win.print( x, y,(char) bui->getcurrentRoom()->getObstacle(Vector2D(x,y)));
	
	
	win.print(pla->getPosition().getX(),pla->getPosition().getY(),'M');
	win.print(pla->getPosition().getX(),pla->getPosition().getY()-1,'M');
	
	

	win.draw();
}

void txtBoucle (Game & ga) {
    WinTXT win (ga.getBuilding()->getcurrentRoom()->getDimX(),ga.getBuilding()->getcurrentRoom()->getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,ga);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		ga.actionsAutomatiques();

		c = win.getCh();
		switch (c) {
			case 'q':
				ga.actionClavier('q');
				break;
			case 's':
				ga.actionClavier('s');
				break;
			case 'z':
				ga.actionClavier('z');
				break;
			case 'd':
				ga.actionClavier('d');
				break;
			case 'p':
				ok = false;
				break;
		}

	} while (ok);

}
