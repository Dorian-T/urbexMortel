#include "winTxt.h"
#include "txtGame.h"
#include "../core/Game.h"

int main ( int argc, char** argv ) {
    termClear();
	Game ga;
	txtBoucle(ga);
    termClear();
	return 0;
}
