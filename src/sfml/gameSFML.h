#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include "../core/Game.h"

void sfmlLoop(Game & game, sf::RenderWindow & window);
void sfmlDraw(Game & game, sf::RenderWindow & window);

#endif