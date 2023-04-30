#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gameSFML.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
using namespace sf;

int main() {
	srand(time(NULL));
	Game game;
	GameSFML GSFML(game);

	GSFML.drawStory();
	GSFML.drawDifficultyMenu(game);
	GSFML.drawSkinMenu(game);

	GSFML.Loop(game);
	return 0;
}