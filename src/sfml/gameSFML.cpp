#include <SFML/Graphics.hpp>
#include "../core/entity/Vector2D.h"
#include "../core/building/Room.h" // utile ?
#include "../core/Game.h"
#include "gameSFML.h"

#include <iostream>
#include <string>

using namespace std;
using namespace sf;


const string PATH_TEXTURES = "data/textures/";
const string PATH_FONTS = "data/fonts/";

// Constructeur et destructeur :

GameSFML::GameSFML(const Game & game): window(VideoMode(1920, 1080), "L'Urbex mortel !") {

	// initialisation de la fenêtre
	window.setFramerateLimit(30);

	// initialisation des textures
	Texture backgroundTexture;
	backgroundTexture.loadFromFile(PATH_TEXTURES + "background.png");
	textures.push_back(backgroundTexture);

	Texture barbedWireTexture;
	barbedWireTexture.loadFromFile(PATH_TEXTURES + "barbedWire.png");
	textures.push_back(barbedWireTexture);

	Texture blockTexture;
	blockTexture.loadFromFile(PATH_TEXTURES + "block.png");
	textures.push_back(blockTexture);

	Texture door1Texture;
	door1Texture.loadFromFile(PATH_TEXTURES + "door1.png");
	textures.push_back(door1Texture);

	Texture door2Texture;
	door2Texture.loadFromFile(PATH_TEXTURES + "door2.png");
	textures.push_back(door2Texture);

	Texture ladderTexture;
	ladderTexture.loadFromFile(PATH_TEXTURES + "ladder.png");
	textures.push_back(ladderTexture);

	Texture trapdoorTexture;
	trapdoorTexture.loadFromFile(PATH_TEXTURES + "trapdoor.png");
	textures.push_back(trapdoorTexture);

	Texture potionTexture;
	potionTexture.loadFromFile(PATH_TEXTURES + "potion.png");
	textures.push_back(potionTexture);

	Texture heartTexture;
	heartTexture.loadFromFile(PATH_TEXTURES + "heart.png");
	textures.push_back(heartTexture);

	Texture poisonSkullTexture;
	poisonSkullTexture.loadFromFile(PATH_TEXTURES + "poisonSkull.png");
	textures.push_back(poisonSkullTexture);

	Texture poisonBarTexture;
	poisonBarTexture.loadFromFile(PATH_TEXTURES + "poisonBar.png");
	textures.push_back(poisonBarTexture);

	// TODO : Player et Rat

	// initialisation de la taille des sprites
	spriteSize = window.getSize().x / 32; // attention : ça ne se modifie plus automatiquement en fonction de la taille de la Room
}

GameSFML::~GameSFML() {
	window.close();
}


// Affichage :

void GameSFML::draw(const Game & game) {
	window.clear(Color::Black);

	drawBackground(game.getBuilding()->getCurrentRoom()->getDimX(), game.getBuilding()->getCurrentRoom()->getDimY());

	drawObstacles(*game.getBuilding()->getCurrentRoom());

	drawPlayer(game.getPlayer());

	drawInfoPlayer(game);

	window.display();
}

void GameSFML::drawBackground(unsigned int dimX, unsigned int dimY) {
	unsigned int width = 0;
	unsigned int height = 0;
	unsigned int backgroundSize = textures[0].getSize().x;
	while(height < dimY * spriteSize) {
		while(width < dimX * spriteSize) {
			RectangleShape background(Vector2f(backgroundSize, backgroundSize));
			background.setPosition(width, height);
			background.setTexture(&textures[0]);
			window.draw(background);
			width += backgroundSize;
		}
		width = 0;
		height += backgroundSize;
	}
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
						barbedWire.setTexture(&textures[1]);
						window.draw(barbedWire);
					}
					break;

				case block:
					{
						RectangleShape block(Vector2f(spriteSize, spriteSize));
						block.setPosition(i*spriteSize, j*spriteSize);
						block.setTexture(&textures[2]);
						window.draw(block);
					}
					break;

				case door:
					{
						RectangleShape door(Vector2f(spriteSize, spriteSize));
						door.setPosition(i*spriteSize, j*spriteSize);
						if(j == 1 || j == 15)
							door.setTexture(&textures[3]);
						else
							door.setTexture(&textures[4]);
						window.draw(door);
					}
					break;

				case ladder:
					{
						RectangleShape ladder(Vector2f(spriteSize, spriteSize));
						ladder.setPosition(i*spriteSize, j*spriteSize);
						ladder.setTexture(&textures[5]);
						window.draw(ladder);
					}
					break;

				case trapdoor:
					{
						RectangleShape trapdoor(Vector2f(spriteSize, spriteSize));
						trapdoor.setPosition(i*spriteSize, j*spriteSize);
						trapdoor.setTexture(&textures[6]);
						window.draw(trapdoor);
					}
					break;

				case potion:
					{
						RectangleShape potion(Vector2f(spriteSize, spriteSize));
						potion.setPosition(i*spriteSize, j*spriteSize);
						potion.setTexture(&textures[7]);
						window.draw(potion);
					}
					break;
			}
		}
}

void GameSFML::drawPlayer(Player * player) {
	bool clock = true;
	Texture playerTexture; // TODO : ne pas la recréer à chaque fois
	playerTexture.loadFromFile(PATH_TEXTURES + "player.png");
	playerTexture.setSmooth(true);
	Sprite playerSprite(playerTexture);
	playerSprite.setScale((float) spriteSize * 2 / 400, (float) spriteSize * 2 / 400);
	playerSprite.setPosition(player->getPosition().getX()*spriteSize, player->getPosition().getY()*spriteSize - spriteSize);

	if(player->getTimeInvincible() > 0) // à refaire
		if(clock) playerSprite.setColor(Color(255, 255, 255, 128));
	clock = !clock;
	window.draw(playerSprite);
}

void GameSFML::drawInfoPlayer(const Game & game) {
	// HP :
	for(unsigned int i = 0; i < game.getPlayer()->getHp(); ++i) {
		RectangleShape heart(Vector2f(spriteSize, spriteSize));
		heart.setPosition(i*spriteSize + spriteSize, 0);
		heart.setTexture(&textures[8]);
		window.draw(heart);
	}

	// Poison :
	RectangleShape poisonSkull(Vector2f(spriteSize, spriteSize));
	poisonSkull.setPosition(game.getBuilding()->getCurrentRoom()->getDimX()*spriteSize - 6*spriteSize, 0);
	poisonSkull.setTexture(&textures[9]);
	window.draw(poisonSkull);

	RectangleShape poison(Vector2f(4*spriteSize * (1 - (float)game.getTimeLeft() / (float)game.getBuilding()->getTimetot()), spriteSize));
	poison.setPosition(game.getBuilding()->getCurrentRoom()->getDimX()*spriteSize - 5*spriteSize, 0);
	poison.setFillColor(Color(138, 34, 156, 255));
	window.draw(poison);

	RectangleShape poisonBar(Vector2f(4*spriteSize, spriteSize));
	poisonBar.setPosition(game.getBuilding()->getCurrentRoom()->getDimX()*spriteSize - 5*spriteSize, 0);
	poisonBar.setTexture(&textures[10]);
	window.draw(poisonBar);
}


// Menus :

void GameSFML::drawStory() {
	wstring story1 = L"Passionné d'urbex, vous décidez en ce 2 mai 2123 d'explorer un très vieux laboratoire,";
	wstring story2 = L"le bâtiment Nautibus. Alors que vous vous êtes déjà bien enfoncé dans ce lieu de légende,";
	wstring story3 = L"vous faites tomber une fiole étrange au sol...";
	wstring story4 = L"MALHEUR ! Elle se brise et son contenu s'évapore rapidement. Vous commencez à tousser";
	wstring story5 = L"violement. Il faut à tout prix sortir du bâtiment pour rejoindre l'hôpital le plus proche";
	wstring story6 = L"avant que vous ne soyez totalement infecté.";
	wstring story7 = L"DEPECHEZ-VOUS !";

	Font font;
	font.loadFromFile(PATH_FONTS + "elegantTypeWriter-bold.ttf");
	Color color(245, 245, 245, 255);

	window.clear();
	drawBackground(32, 18);
	window.display();
	drawString(story1, 1);
	Text text1(story1, font, spriteSize*2/3);
	text1.setPosition(spriteSize, spriteSize*1);
	text1.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1);
	window.display();
	drawString(story2, 2);
	Text text2(story2, font, spriteSize*2/3);
	text2.setPosition(spriteSize, spriteSize*2);
	text2.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1); window.draw(text2);
	window.display();
	drawString(story3, 3);
	Text text3(story3, font, spriteSize*2/3);
	text3.setPosition(spriteSize, spriteSize*3);
	text3.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1); window.draw(text2); window.draw(text3);
	window.display();
	drawString(story4, 4);
	Text text4(story4, font, spriteSize*2/3);
	text4.setPosition(spriteSize, spriteSize*4);
	text4.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1); window.draw(text2); window.draw(text3); window.draw(text4);
	window.display();
	drawString(story5, 5);
	Text text5(story5, font, spriteSize*2/3);
	text5.setPosition(spriteSize, spriteSize*5);
	text5.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1); window.draw(text2); window.draw(text3); window.draw(text4); window.draw(text5);
	window.display();
	drawString(story6, 6);
	Text text6(story6, font, spriteSize*2/3);
	text6.setPosition(spriteSize, spriteSize*6);
	text6.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1); window.draw(text2); window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
	window.display();
	drawString(story7, 7);
	Text text7(story7, font, spriteSize*2/3);
	text7.setPosition(spriteSize, spriteSize*7);
	text7.setFillColor(color);

	bool end = false;
	Event event;
	while(!end) {
		while(window.pollEvent(event)) {
			if(event.type == Event::Closed)
				window.close();
			if(event.type == Event::KeyPressed)
				end = true;
		}
	}
}

void GameSFML::drawString(const wstring & str, unsigned int y) {
	Font font;
	font.loadFromFile(PATH_FONTS + "elegantTypeWriter-bold.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(spriteSize*2/3);
	text.setFillColor(Color(245, 245, 245, 255));

	unsigned int i = 0;
	while(str[i] != '\0') {
		text.setPosition(spriteSize, spriteSize*y);
		text.setString(str.substr(0, i));
		i++;
		window.draw(text);
		window.display();
	}
}

void GameSFML::drawDifficultyMenu(Game & game) {
	Font font;
	font.loadFromFile(PATH_FONTS + "elegantTypeWriter-bold.ttf");

	Color color(245, 245, 245, 255);

	Text text1(L"Choisissez votre difficulté :", font, spriteSize*2/3);
	text1.setPosition(spriteSize, spriteSize*1);
	text1.setFillColor(color);

	Text text2(L"1 - Facile", font, spriteSize*2/3);
	text2.setPosition(spriteSize, spriteSize*2);
	text2.setFillColor(color);

	Text text3(L"2 - Moyen", font, spriteSize*2/3);
	text3.setPosition(spriteSize, spriteSize*3);
	text3.setFillColor(color);

	Text text4(L"3 - Difficile", font, spriteSize*2/3);
	text4.setPosition(spriteSize, spriteSize*4);
	text4.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1); window.draw(text2); window.draw(text3); window.draw(text4);
	window.display();

	bool isChoosen = false;
	Event event;
	while(!isChoosen) {
		while(window.pollEvent(event)) {
			if(event.type == Event::Closed)
				window.close();
			if(event.type == Event::KeyPressed)
				switch(event.key.code) { // à vérifier
					case Keyboard::Num1:
					case Keyboard::Numpad1:
						isChoosen = true;
						game.setDifficulty(1);
						cout << "1" << endl;
						break;

					case Keyboard::Num2:
					case Keyboard::Numpad2:
						isChoosen = true;
						game.setDifficulty(2);
						break;

					case Keyboard::Num3:
					case Keyboard::Numpad3:
						isChoosen = true;
						game.setDifficulty(3);
						break;

					default:
						break;
				}
		}
	}
}

void GameSFML::drawMenu() {
	// Font font;
	// font.loadFromFile(PATH_FONTS + "arial.ttf");

	// Color red(232, 21, 14, 255);

	// Text Hp;
	// Hp.setFont(font);
	// Hp.setFillColor(red);
	// Hp.setCharacterSize(spriteSize);
	// Hp.setString(to_string(player->getHp()));
	// Hp.setPosition(1*spriteSize,0*spriteSize);
	// window.draw(Hp);
}

void GameSFML::Loop(Game & game) {
	window.setKeyRepeatEnabled(false);
	Clock cl;
	int time = 3;
	while(window.isOpen()) {
		float elapsed = cl.getElapsedTime().asMilliseconds();
		if(elapsed > 100) {
		time = game.update(time);
		cl.restart();
		};
		Event event;
		while(window.pollEvent(event)) {
			elapsed = cl.getElapsedTime().asMilliseconds();
			if(elapsed > 100) {
			time = game.update(time);
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

					case Keyboard::R:
						randomizeTextures();
						break;

					default:
						break;
				}
        }
		draw(game);
		if(game.getPlayer()->getHp()==0) window.close();
    }
}

void GameSFML::randomizeTextures() {
	Texture tmp;
	for(unsigned int i = 0; i < textures.size(); ++i) {
		int j = rand() % textures.size();
		tmp = textures[i];
		textures[i] = textures[j];
		textures[j] = tmp;
	}
}