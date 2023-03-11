#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Game.h"
#include "../core/Vector2D.h"
#include "txtGame.h"

void txtAff(WinTXT & win, const Game & ga) {
	const Building& bui = ga.getBuilding();
	const Player& pla = ga.getPlayer();
	

	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<bui.getcurrentRoom()->getDimX();++x)
		for(int y=0;y<bui.getcurrentRoom()->getDimY();++y)
			win.print( x, y,(char) bui.getcurrentRoom()->getObstacle(Vector2D(x,y)));

    // Affichage de Pacman
	win.print(pla.getPosition().getX(),pla.getPosition().getY(),'P');
	

	win.draw();
}

void txtBoucle (Game & ga) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (ga.getBuilding().getcurrentRoom()->getDimX(),ga.getBuilding().getcurrentRoom()->getDimY());

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
