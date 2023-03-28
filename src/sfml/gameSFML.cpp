#include <SFML/Graphics.hpp>
#include "../core/Game.h"
#include "gameSFML.h"
using namespace sf;

void sfmlLoop(Game & g, RenderWindow & window) {
	while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
			if(event.type == Event::Closed)
				window.close();
			else if(event.type == Event::KeyPressed)
				switch(event.key.code) {

					case Keyboard::Up:
						g.getPlayer()->up(g.getBuilding());
						break;

					case Keyboard::Right:
						g.getPlayer()->right(g.getBuilding());
						break;

					case Keyboard::Down:
						g.getPlayer()->down(g.getBuilding());
						break;

					case Keyboard::Left:
						g.getPlayer()->left(g.getBuilding());
						break;

					default:
						break;
				}
        }
		sfmlDraw(window);
    }
}

void sfmlDraw(RenderWindow & window) {
	window.clear(Color::Black);
	
	window.display();
}