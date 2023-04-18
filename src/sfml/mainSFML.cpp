#include <SFML/Graphics.hpp>
#include "gameSFML.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace sf;
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
    unsigned int d = chooseDifficulty();
    Game game(d);
    if (d==2) {
		game.setTimeLeft(game.getBuilding()->getTimetot()*15);
		game.getBuilding()->setTimetot(game.getBuilding()->getTimetot()*15);
	}
	else if (d==3) {
		game.setTimeLeft(game.getBuilding()->getTimetot()*10);
		game.getBuilding()->setTimetot(game.getBuilding()->getTimetot()*10);
	}
	else { 
		game.setTimeLeft(game.getBuilding()->getTimetot()*20);
		game.getBuilding()->setTimetot(game.getBuilding()->getTimetot()*20);
	}
    GameSFML GSFML(game);
    GSFML.Loop(game);
}