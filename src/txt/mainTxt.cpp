#include "winTxt.h"
#include "txtGame.h"
#include "../core/Game.h"
#include <time.h>

int main ( int argc, char** argv ) {
	srand(time(NULL));
    termClear();
	Game ga;
	txtBoucle(ga);
    termClear();
	return 0;
}
