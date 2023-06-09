#include "winTxt.h"
#include "gameTxt.h"
#include "../core/Game.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int chooseDifficulty() {
	int diff;
	cout << "Choisissez la difficulté :" << endl;
	cout << "1. Facile" << endl;
	cout << "2. Moyen" << endl;
	cout << "3. Difficile" << endl;
	cin >> diff;
	return diff;
}

int main() {
	srand(time(NULL));
	Game game;
	GameTXT GTXT(game);

	// choix de la difficulté
	int diff;
	cout << "Choisissez la difficulté :" << endl;
	cout << "1. Facile" << endl;
	cout << "2. Moyen" << endl;
	cout << "3. Difficile" << endl;
	cin >> diff;
	game.setDifficulty(diff);

	GTXT.loop(game);
	termClear();

	// message de fin
	if(game.getPlayer()->getHp() == 0 || game.getBuilding()->getTimeLeft() == 0)
		cout << "T'es mort, nul !" << endl;
	else
		cout << "Bravo ! T'es pas nul." << endl;

	return 0;
}
