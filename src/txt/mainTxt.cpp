#include "winTxt.h"
#include "txtGame.h"
#include "../core/Game.h"

#include <time.h>
#include <iostream>

using namespace std;

int main ( int argc, char** argv ) {
	srand(time(NULL));
    termClear();
	Game ga;
	txtLoop(ga);
    termClear();
	if(ga.getPlayer()->getHp()==0) cout << "T'es mort, nul !" << endl ;
	else cout << "Bravo ! T'es pas nul." << endl ;
	return 0;
}
