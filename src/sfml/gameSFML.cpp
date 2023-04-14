#include <SFML/Graphics.hpp>
#include "../core/entity/Vector2D.h"
#include "../core/building/Room.h" // utile ?
#include "../core/Game.h"
#include "gameSFML.h"
#include <iostream>
using namespace sf;


// Constructeur et destructeur :

GameSFML::GameSFML(const Game & game): window(VideoMode(1920, 1080), "L'Urbex mortel !") {

	// initialisation de la fenêtre
	window.setFramerateLimit(30);


	// initialisation des textures des obstacles

	Texture barbedWireTexture;
	barbedWireTexture.loadFromFile("data/barbedWire.png");
	texturesObstacles.push_back(barbedWireTexture);

	Texture blockTexture;
	blockTexture.loadFromFile("data/block.png");
	texturesObstacles.push_back(blockTexture);

	Texture ladderTexture;
	ladderTexture.loadFromFile("data/ladder.png");
	texturesObstacles.push_back(ladderTexture);

	Texture trapdoorTexture;
	trapdoorTexture.loadFromFile("data/trapdoor.png");
	texturesObstacles.push_back(trapdoorTexture);

	Texture potionTexture;
	potionTexture.loadFromFile("data/potion.png");
	texturesObstacles.push_back(potionTexture);


	// TODO : Player et Rat

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

void GameSFML::drawObstacles(const Room & room) {
	for(unsigned int i = 0; i < room.getDimX(); ++i)
		for(unsigned int j = 0; j < room.getDimY(); ++j) {
			switch(room.getObstacle(Vector2D(i, j))) {

				case nothing:
					break;

				case barbedWire:
					{
						RectangleShape barbedWire(Vector2f(spriteSize, spriteSize));
						barbedWire.setPosition(i*spriteSize, j*spriteSize);
						barbedWire.setTexture(&texturesObstacles[0]);
						window.draw(barbedWire);
					}
					break;

				case block:
					{
						RectangleShape block(Vector2f(spriteSize, spriteSize));
						block.setPosition(i*spriteSize, j*spriteSize);
						block.setTexture(&texturesObstacles[1]);
						window.draw(block);
					}
					break;

				case door:
					{
						RectangleShape door(Vector2f(spriteSize, spriteSize));
						door.setPosition(i*spriteSize, j*spriteSize);
						door.setFillColor(Color (139, 69, 19));
						window.draw(door);
					}
					break;

				case ladder:
					{
						RectangleShape ladder(Vector2f(spriteSize, spriteSize));
						ladder.setPosition(i*spriteSize, j*spriteSize);
						ladder.setTexture(&texturesObstacles[2]);
						window.draw(ladder);
					}
					break;

				case trapdoor:
					{
						RectangleShape trapdoor(Vector2f(spriteSize, spriteSize));
						trapdoor.setPosition(i*spriteSize, j*spriteSize);
						trapdoor.setTexture(&texturesObstacles[3]);
						window.draw(trapdoor);
					}
					break;

				case potion:
					{
						RectangleShape potion(Vector2f(spriteSize, spriteSize));
						potion.setPosition(i*spriteSize, j*spriteSize);
						potion.setTexture(&texturesObstacles[4]);
						window.draw(potion);
					}
					break;
			}
		}
}

void GameSFML::drawInfoPlayer(Player * player) {
	Text Hp;
	Hp.setString(std::to_string(player->getHp()));
	Hp.setString("suce");
	Color red(232, 21, 14, 255);
	Hp.setFillColor(red);
	Hp.setCharacterSize(800);
	Hp.setPosition(0*spriteSize,0*spriteSize);
	Hp.setScale((float) spriteSize * 1 / 400, (float) spriteSize * 1 / 400);
	window.draw(Hp);

}

void GameSFML::draw(const Game & game) {
	window.clear(Color::Black);

	// affichage du fond
	RectangleShape background(Vector2f(spriteSize*game.getBuilding()->getCurrentRoom()->getDimX(), spriteSize*game.getBuilding()->getCurrentRoom()->getDimY()));
	background.setPosition(0, 0);
	background.setFillColor(Color (119, 136, 153));
	window.draw(background);

	// affichage des obstacles
	drawObstacles(*game.getBuilding()->getCurrentRoom());

	drawPlayer(*game.getPlayer());

	drawInfoPlayer(game.getPlayer());
	
	window.display();
}

void GameSFML::Loop(Game & game) {
	window.setKeyRepeatEnabled(false);
	Clock cl;
	int time = 3;
	while(window.isOpen()) {
		float elapsed = cl.getElapsedTime().asMilliseconds();
		if(elapsed > 100) {
		time = game.automaticAction(time);
		cl.restart();
		};
		Event event;
		while(window.pollEvent(event)) {
			elapsed = cl.getElapsedTime().asMilliseconds();
			if(elapsed > 100) {
			time = game.automaticAction(time);
			cl.restart();
			};
			if(event.type == Event::Closed)
			window.close();
			else if(event.type == Event::KeyPressed) 
				switch(event.key.code) {
					case Keyboard::Z:
						if(game.getPlayer()->standingOnBlock(game.getBuilding())) time = 3;
						game.getPlayer()->up(game.getBuilding());
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