#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include "../core/Game.h"

void sfmlLoop(Game & g, sf::RenderWindow & window);
void sfmlDraw(sf::RenderWindow & window);

#endif