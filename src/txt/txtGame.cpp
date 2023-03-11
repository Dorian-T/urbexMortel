#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "Game.h"
#include "txtGame.h"

void txtAff(WinTXT & win, const Game & ga) {
	const Terrain& ter = ga.getConstTerrain();
	const Pacman& pac = ga.getConstPacman();
	const Fantome& fan = ga.getConstFantome();

	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print( x, y, ter.getXYasChar(x,y));

    // Affichage de Pacman
	win.print(pac.getX(),pac.getY(),'P');
	// Affichage du Fantome
	win.print(fan.getX(),fan.getY(),'F');

	win.draw();
}

void txtBoucle (Game & ga) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (ga.getConstTerrain().getDimX(),ga.getConstTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		game.actionsAutomatiques();

		c = win.getCh();
		switch (c) {
			case 'k':
				ga.actionClavier('g');
				break;
			case 'm':
				ga.actionClavier('d');
				break;
			case 'l':
				ga.actionClavier('h');
				break;
			case 'o':
				ga.actionClavier('b');
				break;
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}
