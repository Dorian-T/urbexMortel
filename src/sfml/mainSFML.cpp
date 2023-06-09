#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gameSFML.h"

#include <time.h>
#include <stdlib.h>

using namespace sf;

int main() {
	srand(time(NULL));
	Game game;
	GameSFML GSFML(game);

	GSFML.drawStory();
	GSFML.drawDifficultyMenu(game);
	GSFML.drawSkinMenu(game);

	GSFML.loop(game);
	return 0;
}