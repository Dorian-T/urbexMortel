#include <SFML/Graphics.hpp>
#include "../core/entity/Vector2D.h"
#include "../core/building/Room.h" // utile ?
#include "../core/Game.h"
#include "gameSFML.h"
using namespace sf;


// Constructeur et destructeur :

GameSFML::GameSFML(const Game & game): window(VideoMode(1920, 1080), "L'Urbex mortel !") {

	// initialisation de la fenêtre
	window.setFramerateLimit(30);


	// initialisation des textures

	Texture blockTexture;
	blockTexture.loadFromFile("data/block.png");
	textures.push_back(blockTexture);

	Texture ladderTexture;
	ladderTexture.loadFromFile("data/ladder.png");
	textures.push_back(ladderTexture);

	Texture trapdoorTexture;
	trapdoorTexture.loadFromFile("data/trapdoor.png");
	textures.push_back(trapdoorTexture);

	Texture potionTexture;
	potionTexture.loadFromFile("data/potion.png");
	textures.push_back(potionTexture);

	Texture playerTexture;
	playerTexture.loadFromFile("data/player.png");
	textures.push_back(playerTexture);

	Texture ratTexture;
	ratTexture.loadFromFile("data/rat.png");
	textures.push_back(ratTexture);


	// initialisation des sprites
	Obstacle o;
	for(unsigned int i = 0; i < game.getBuilding()->getCurrentRoom()->getDimX(); ++i)
		for(unsigned int j = 0; j < game.getBuilding()->getCurrentRoom()->getDimY(); ++j) {
			o = game.getBuilding()->getCurrentRoom()->getObstacle(Vector2D(i, j));
			switch (o) {

				case nothing:
					{
						RectangleShape nothing(Vector2f(spriteSize, spriteSize));
						nothing.setPosition(i*spriteSize, j*spriteSize);
						nothing.setFillColor(Color (119, 136, 153));
						window.draw(nothing);
					}
					break;

				case barbedWire:
					{
						RectangleShape barbedWire(Vector2f(spriteSize, spriteSize));
						barbedWire.setPosition(i*spriteSize, j*spriteSize);
						barbedWire.setFillColor(Color (255, 69, 0));
						window.draw(barbedWire);
					}
					break;

				case block: // TODO : faire avec textures
					{
						RectangleShape block(Vector2f(spriteSize, spriteSize));
						block.setPosition(i*spriteSize, j*spriteSize);
						block.setFillColor(Color (128, 128, 128));
						window.draw(block);
					}
					break;

				case door:
					{
						RectangleShape door(Vector2f(spriteSize, spriteSize));
						door.setPosition(i*spriteSize, j*spriteSize);
						door.setFillColor(Color (0, 0, 0));
						window.draw(door);
					}
					break;

				case ladder: // TODO : faire avec textures
					{
						RectangleShape ladder(Vector2f(spriteSize, spriteSize));
						ladder.setPosition(i*spriteSize, j*spriteSize);
						ladder.setFillColor(Color (0, 0, 0));
						window.draw(ladder);
					}
					break;

				case trapdoor: // TODO : faire avec textures
					{
						RectangleShape trapdoor(Vector2f(spriteSize, spriteSize));
						trapdoor.setPosition(i*spriteSize, j*spriteSize);
						trapdoor.setFillColor(Color (0, 0, 0));
						window.draw(trapdoor);
					}
					break;

				case potion: // TODO : faire avec textures
					{
						RectangleShape potion(Vector2f(spriteSize, spriteSize));
						potion.setPosition(i*spriteSize, j*spriteSize);
						potion.setFillColor(Color (0, 0, 0));
						window.draw(potion);
					}
					break;
			}
		}


	// initialisation de la taille des sprites
	spriteSize = window.getSize().x / game.getBuilding()->getCurrentRoom()->getDimX();
}


GameSFML::~GameSFML() {
	window.close();
}


// Affichage :

void GameSFML::drawPlayer(const Player & player) {
	Texture playerTexture;
	playerTexture.loadFromFile("data/player.png");
	playerTexture.setSmooth(true);
	Sprite playerSprite(playerTexture);
	playerSprite.setScale((float) spriteSize * 2 / 400, (float) spriteSize * 2 / 400);
	playerSprite.setPosition(player.getPosition().getX()*spriteSize, player.getPosition().getY()*spriteSize - spriteSize);
	window.draw(playerSprite);
}

void GameSFML::draw(const Game & game) {
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
			drawPlayer(*game.getPlayer());
		}
	window.display();
}

void GameSFML::Loop(Game & game) {
	window.setKeyRepeatEnabled(false);
	Clock cl;
	int time = 1;
	while(window.isOpen()) {
		float elapsed = cl.getElapsedTime().asMicroseconds();
		if(elapsed > 50) {
		time = game.automaticAction(time);
		cl.restart();
		};
		Event event;
		while(window.pollEvent(event)) {
			elapsed = cl.getElapsedTime().asMicroseconds();
			if(elapsed > 50) {
			time = game.automaticAction(time);
			cl.restart();
			};
			if(event.type == Event::Closed)
			window.close();
			else if(event.type == Event::KeyPressed) 
				switch(event.key.code) {
					case Keyboard::Z:
						game.getPlayer()->up(game.getBuilding());
						time = 1;
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
		draw(game);
		if(game.getPlayer()->getHp()==0) window.close();
    }
}