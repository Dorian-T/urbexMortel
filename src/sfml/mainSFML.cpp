#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gameSFML.h"

#include <time.h>
#include <stdlib.h>

using namespace sf;

int main() {
	srand(time(NULL));
	Game game;
	Music music;
	GameSFML GSFML(game);

	if (!music.openFromFile("data/music/theme.ogg")) { return -1; }
	music.play();
	music.setLoop(true);
	GSFML.drawStory();
	GSFML.drawDifficultyMenu(game);
	GSFML.drawSkinMenu(game);

	GSFML.Loop(game);
}