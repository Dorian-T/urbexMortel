#include <SFML/Graphics.hpp>
#include "../core/entity/Vector2D.h"
#include "../core/Game.h"
#include "gameSFML.h"
using namespace sf;

void sfmlLoop(Game & game, RenderWindow & window) {
	Clock cl;
	int time = 2;
	while(window.isOpen()) {
		float elapsed = cl.getElapsedTime().asSeconds();
		if(elapsed > 0.1) {
		Clock clo;
		time = game.automaticAction(time);
		};
		Event event;
		while(window.pollEvent(event)) {
			if(event.type == Event::Closed)
			window.close();
			else if(event.type == Event::KeyPressed) 
				switch(event.key.code) {
					case Keyboard::Z:
						game.getPlayer()->up(game.getBuilding());
						time = 2;
						break;

					case Keyboard::D:
						game.getPlayer()->right(game.getBuilding());
						break;

					case Keyboard::S:
						game.getPlayer()->down(game.getBuilding());
						break;

					case Keyboard::Q:
						game.getPlayer()->left(game.getBuilding());
						break;

					default:
						break;
				}
        }
		sfmlDraw(game, window);
		if(game.getPlayer()->getHp()==0) window.close();
		
    }
}

void sfmlDraw(Game & game, RenderWindow & window) {
	window.clear(Color::Black);
	unsigned int spriteSize = window.getSize().x / game.getBuilding()->getCurrentRoom()->getDimX();
	Obstacle o;
	for(unsigned int x = 0; x < game.getBuilding()->getCurrentRoom()->getDimX(); ++x)
		for(unsigned int y = 0; y < game.getBuilding()->getCurrentRoom()->getDimY(); ++y) {
			o = game.getBuilding()->getCurrentRoom()->getObstacle(Vector2D(x,y));
			switch (o) {

				case nothing:
					{
						RectangleShape nothing(Vector2f(spriteSize, spriteSize));
						nothing.setPosition(x*spriteSize, y*spriteSize);
						nothing.setFillColor(Color (119, 136, 153));
						window.draw(nothing);
					}
					break;

				case barbedWire:
					{
						RectangleShape barbedWire(Vector2f(spriteSize, spriteSize));
						barbedWire.setPosition(x*spriteSize, y*spriteSize);
						barbedWire.setFillColor(Color (255, 69, 0));
						window.draw(barbedWire);
					}
					break;

				case block:
					{
						RectangleShape block(Vector2f(spriteSize, spriteSize));
						block.setPosition(x*spriteSize, y*spriteSize);
						block.setFillColor(Color (128, 128, 128));
						window.draw(block);
					}
					break;

				case door:
					{
						RectangleShape door(Vector2f(spriteSize, spriteSize));
						door.setPosition(x*spriteSize, y*spriteSize);
						door.setFillColor(Color (160, 82, 45));
						window.draw(door);
					}
					break;

				case ladder:
					{
						RectangleShape ladder(Vector2f(spriteSize, spriteSize));
						ladder.setPosition(x*spriteSize, y*spriteSize);
						ladder.setFillColor(Color (176, 196, 222));
						window.draw(ladder);
					}
					break;

				case trapdoor:
					{
						RectangleShape trapdoor(Vector2f(spriteSize, spriteSize));
						trapdoor.setPosition(x*spriteSize, y*spriteSize);
						trapdoor.setFillColor(Color (210, 105, 30));
						window.draw(trapdoor);
					}

				default:
					break;
			}
			Texture playerTexture;
			playerTexture.loadFromFile("data/player.png");
			playerTexture.setSmooth(true);
			Sprite player(playerTexture);
			player.setScale((float) spriteSize * 2 / 400, (float) spriteSize * 2 / 400);
			player.setPosition(game.getPlayer()->getPosition().getX()*spriteSize, game.getPlayer()->getPosition().getY()*spriteSize - spriteSize);
			window.draw(player);
		}
	window.display();
}