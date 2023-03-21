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

void txtDraw(WinTXT & win, const Game & ga) {
	Building* bui = ga.getBuilding();
	Player* pla = ga.getPlayer();
	
	sleep(1);
	win.clear();
	char c;

	for(unsigned int x=0;x<bui->getCurrentRoom()->getDimX();++x)
		for(unsigned int y=0;y<bui->getCurrentRoom()->getDimY();++y) {
			c = (char) bui->getCurrentRoom()->getObstacle(Vector2D(x,y));
			if( c == '.') win.print(x, y, ' ');
			else win.print(x, y, c);
		}	
	
	win.print(pla->getPosition().getX(),pla->getPosition().getY(),'X');
	win.print(pla->getPosition().getX(),pla->getPosition().getY()-1,'O');
	
	unsigned int hp = pla->getHp();
	unsigned int TimeInv = pla->getTimeInvincible();
	win.print(0,18,'H');
	win.print(1,18,':');
	win.print(2,18,std::to_string(hp).c_str());
	win.print(4,18,'I');
	win.print(5,18,':');
	win.print(6,18,std::to_string(TimeInv).c_str());
	win.print(8,18,'R');
	win.print(9,18,':');
	win.print(10,18,std::to_string(bui->getIntCurrentRoom()+1).c_str());
	win.print(11,18,'/');
	win.print(12,18,std::to_string(bui->getNbRoom()).c_str());

	
	

	win.draw();
}

void txtLoop (Game & ga) {
    WinTXT win (ga.getBuilding()->getCurrentRoom()->getDimX()+1,ga.getBuilding()->getCurrentRoom()->getDimY()+1);
	int time = 3;
	bool ok = true;
	int c;

	do {
	    txtDraw(win,ga);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(500);
        #endif // WIN32

		
		time=ga.automaticAction(time);

		c = win.getCh();
		switch (c) {
			case 'q':
				ga.keyboardAction('q');
				break;
			case 's':
				ga.keyboardAction('s');
				break;
			case 'z':
				ga.keyboardAction('z');
				time = 2;
				break;
			case 'd':
				ok = ga.keyboardAction('d');
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
