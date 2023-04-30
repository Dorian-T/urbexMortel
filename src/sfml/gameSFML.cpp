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
const string PATH_SKINS = "data/skins/";
const string PATH_FONTS = "data/fonts/";

// Constructeur et destructeur :

GameSFML::GameSFML(const Game & game): window(VideoMode(1920, 1080), "L'Urbex mortel !") {

	// initialisation de la fenêtre
	window.setFramerateLimit(30);

	// initialisation des textures
	loadTextures();
	loadSkins();

	// initialisation de la taille des sprites
	spriteSize = window.getSize().x / 32; // attention : ça ne se modifie plus automatiquement en fonction de la taille de la Room

	close=false;
}

void GameSFML::loadTextures() {
	Texture obstacle;

	obstacle.loadFromFile(PATH_TEXTURES + "background.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "barbedWire.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "block.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "door1.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "door2.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "ladder.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "trapdoor.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "potion.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "heart.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "poisonSkull.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "poisonBar.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "ratR.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "ratL.png");
	textures.push_back(obstacle);

	obstacle.loadFromFile(PATH_TEXTURES + "spider.png");
	textures.push_back(obstacle);
	
	obstacle.loadFromFile(PATH_TEXTURES + "spiderWeb.png");
	textures.push_back(obstacle);
}

void GameSFML::loadSkins() {
	Texture skin;

	skin.loadFromFile(PATH_SKINS + "batmanR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "batmanL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "coaraR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "coaraL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "daisyR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "daisyL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "doraR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "doraL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "gadgetR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "gadgetL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "lilithR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "lilithL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "maestroR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "maestroL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "pikminR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "pikminL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "tiboyouR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "tiboyouL.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "yumiR.png");
	skins.push_back(skin);

	skin.loadFromFile(PATH_SKINS + "yumiL.png");
	skins.push_back(skin);
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

	for(unsigned int i = 0; i < game.getNbRat(); i++) {
		Rat* rat = game.getRat(i);
		drawRat(rat);
	}
	for(unsigned int i = 0; i < game.getNbSpider(); i++) {
		Spider* spider = game.getSpider(i);
		drawSpider(spider, *game.getBuilding()->getCurrentRoom());
	}

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
				
				case ghostBlock:
					{
						RectangleShape block(Vector2f(spriteSize, spriteSize));
						block.setPosition(i*spriteSize, j*spriteSize);
						block.setTexture(&textures[2]);
						block.setFillColor(Color(255,255, 255, 200));
						window.draw(block);
					}
					break;
				
				case fakeBlock:
					{
						RectangleShape block(Vector2f(spriteSize, spriteSize));
						block.setPosition(i*spriteSize, j*spriteSize);
						block.setTexture(&textures[2]);
						block.setFillColor(Color(255,255, 255, 240));
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
	Sprite playerSprite;
	if(player->getOrientation())
		playerSprite.setTexture(skins[player->getSkin()]);
	else
		playerSprite.setTexture(skins[player->getSkin() + 1]);
	playerSprite.setScale((float) spriteSize / playerSprite.getTexture()->getSize().x, (float) spriteSize * 2 / playerSprite.getTexture()->getSize().y);
	playerSprite.setPosition(player->getPosition().getX()*spriteSize, player->getPosition().getY()*spriteSize - spriteSize);

	if(player->getTimeInvincible() > 0 && player->getTimeInvincible() % 2 == 0)
		playerSprite.setColor(Color(255, 0, 0, 128));
	window.draw(playerSprite);
}

void GameSFML::drawRat(Rat * rat) {
	RectangleShape ratRect(Vector2f(spriteSize, spriteSize));
	ratRect.setPosition(rat->getPosition().getX()*spriteSize, rat->getPosition().getY()*spriteSize);
	if(rat->getDirection() == -1)
		ratRect.setTexture(&textures[12]);
	else
		ratRect.setTexture(&textures[11]);
	window.draw(ratRect);
}

void GameSFML::drawSpider(Spider * spider, const Room & room) {
	RectangleShape spiderRect(Vector2f(spriteSize, spriteSize));
	spiderRect.setTexture(&textures[13]);
	spiderRect.setPosition(spider->getPosition().getX()*spriteSize, spider->getPosition().getY()*spriteSize);
	window.draw(spiderRect);

	RectangleShape spiderWebRect = RectangleShape(Vector2f(spriteSize, spriteSize));
	spiderWebRect.setTexture(&textures[14]);
	int i = 1;
	while(room.getObstacle(Vector2D(spider->getPosition().getX(), spider->getPosition().getY()-i)) == nothing) {
		spiderWebRect.setPosition(spider->getPosition().getX()*spriteSize, (spider->getPosition().getY()-i)*spriteSize);
		window.draw(spiderWebRect);
		i++;
	}
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

	RectangleShape poison(Vector2f(4*spriteSize * (1 - (float)game.getBuilding()->getTimeLeft() / (float)game.getBuilding()->getTotalTime()), spriteSize));
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
	wstring story5 = L"violemment. Il faut à tout prix sortir du bâtiment pour rejoindre l'hôpital le plus";
	wstring story6 = L"proche avant que vous ne soyez totalement infecté.";
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
			if(event.type == Event::Closed) {
				close=true;
				end =true;
			}
			if(event.type == Event::KeyPressed)
				end = true;
		}
	}
}

void GameSFML::drawEnd(bool victory) {
	wstring str;
	if(victory)
		str = L"Vous avez réussi à sortir à temps, vous êtes sauvé !";
	else
		str = L"Dommage, vous êtes mort...";

	Font font;
	font.loadFromFile(PATH_FONTS + "elegantTypeWriter-bold.ttf");
	Color color(220, 0, 0, 255);

	window.clear();
	drawBackground(32, 18);
	window.display();
	drawString(str, 1);
	Text text(str, font, spriteSize*2/3);
	text.setPosition(spriteSize, spriteSize*1);
	text.setFillColor(color);

	bool end = false;
	Event event;
	while(!end) {
		while(window.pollEvent(event)) {
			if(event.type == Event::Closed) {
				window.close();
				close=false;
				end = true;
			}
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
	if(close) {
			game.setDifficulty(1);
		}
	else {
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

	Text text5(L"Rappel des touches : ", font, spriteSize*2/3);
	text5.setPosition(spriteSize, spriteSize*7);
	text5.setFillColor(color);

	Text text6(L"échap : pour quitter", font, spriteSize*2/3);
	text6.setPosition(spriteSize, spriteSize*8);
	text6.setFillColor(color);

	Text text7(L"z : sauter", font, spriteSize*2/3);
	text7.setPosition(spriteSize, spriteSize*9);
	text7.setFillColor(color);

	Text text8(L"s : descendre", font, spriteSize*2/3);
	text8.setPosition(spriteSize, spriteSize*10);
	text8.setFillColor(color);

	Text text9(L"q : pour aller à gauche", font, spriteSize*2/3);
	text9.setPosition(spriteSize, spriteSize*11);
	text9.setFillColor(color);

	Text text10(L"d : pour aller à droite", font, spriteSize*2/3);
	text10.setPosition(spriteSize, spriteSize*12);
	text10.setFillColor(color);

	Text text11(L"r : pour une surprise", font, spriteSize*2/3);
	text11.setPosition(spriteSize, spriteSize*13);
	text11.setFillColor(color);

	Text text12(L"t : pour enlever la surprise", font, spriteSize*2/3);
	text12.setPosition(spriteSize, spriteSize*14);
	text12.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1);		window.draw(text2);		window.draw(text3);		window.draw(text4);
	window.draw(text5);		window.draw(text6);		window.draw(text7);		window.draw(text8);
	window.draw(text9);		window.draw(text10);	window.draw(text11);	window.draw(text12);
	window.display();

	bool isChoosen = false;
	Event event;
	while(!isChoosen) {
		while(window.pollEvent(event)) {
			if(event.type == Event::Closed) {
				close = true;
				isChoosen = true;
				game.setDifficulty(1);
			}
			if(event.type == Event::KeyPressed)
				switch(event.key.code) {
					case Keyboard::Num1:
					case Keyboard::Numpad1:
						isChoosen = true;
						game.setDifficulty(1);
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
}

void GameSFML::drawSkinMenu(Game & game) {
	if(!close) {
		Font font;
		font.loadFromFile(PATH_FONTS + "elegantTypeWriter-bold.ttf");

		Color color(245, 245, 245, 255);

		Text text1(L"Choisissez votre skin :", font, spriteSize*2/3);
		text1.setPosition(spriteSize, spriteSize*1);
		text1.setFillColor(color);

		Text text2(L"0 - Batman", font, spriteSize*2/3);
		text2.setPosition(spriteSize, spriteSize*2);
		text2.setFillColor(color);

		Text text3(L"1 - Coara", font, spriteSize*2/3);
		text3.setPosition(spriteSize, spriteSize*3);
		text3.setFillColor(color);

		Text text4(L"2 - Daisy", font, spriteSize*2/3);
		text4.setPosition(spriteSize, spriteSize*4);
		text4.setFillColor(color);

		Text text5(L"3 - Dora", font, spriteSize*2/3);
		text5.setPosition(spriteSize, spriteSize*5);
		text5.setFillColor(color);

		Text text6(L"4 - Inspecteur Gadget", font, spriteSize*2/3);
		text6.setPosition(spriteSize, spriteSize*6);
		text6.setFillColor(color);

		Text text7(L"5 - Lilith", font, spriteSize*2/3);
		text7.setPosition(spriteSize, spriteSize*7);
		text7.setFillColor(color);

		Text text8(L"6 - Maestro", font, spriteSize*2/3);
		text8.setPosition(spriteSize, spriteSize*8);
		text8.setFillColor(color);

		Text text9(L"7 - Pikmin rouge", font, spriteSize*2/3);
		text9.setPosition(spriteSize, spriteSize*9);
		text9.setFillColor(color);

		Text text10(L"8 - Tiboyou", font, spriteSize*2/3);
		text10.setPosition(spriteSize, spriteSize*10);
		text10.setFillColor(color);

		Text text11(L"9 - Yumi", font, spriteSize*2/3);
		text11.setPosition(spriteSize, spriteSize*11);
		text11.setFillColor(color);

		window.clear();
		drawBackground(32, 18);
		window.draw(text1);
		window.draw(text2); window.draw(text3); window.draw(text4); window.draw(text5); window.draw(text6);
		window.draw(text7); window.draw(text8); window.draw(text9); window.draw(text10); window.draw(text11);
		window.display();

		bool isChoosen = false;
		Event event;
		while(!isChoosen) {
			while(window.pollEvent(event)) {
				if(event.type == Event::Closed) {
					isChoosen = true;
					close = true;
					game.getPlayer()->setSkin(lilith);
				}
				if(event.type == Event::KeyPressed)
					switch(event.key.code) {
						case Keyboard::Num0:
						case Keyboard::Numpad0:
							isChoosen = true;
							game.getPlayer()->setSkin(batman);
							break;

						case Keyboard::Num1:
						case Keyboard::Numpad1:
							isChoosen = true;
							game.getPlayer()->setSkin(coara);
							break;

						case Keyboard::Num2:
						case Keyboard::Numpad2:
							isChoosen = true;
							game.getPlayer()->setSkin(daisy);
							break;

						case Keyboard::Num3:
						case Keyboard::Numpad3:
							isChoosen = true;
							game.getPlayer()->setSkin(dora);
							break;

						case Keyboard::Num4:
						case Keyboard::Numpad4:
							isChoosen = true;
							game.getPlayer()->setSkin(gadget);
							break;

						case Keyboard::Num5:
						case Keyboard::Numpad5:
							isChoosen = true;
							game.getPlayer()->setSkin(lilith);
							break;

						case Keyboard::Num6:
						case Keyboard::Numpad6:
							isChoosen = true;
							game.getPlayer()->setSkin(maestro);
							break;

						case Keyboard::Num7:
						case Keyboard::Numpad7:
							isChoosen = true;
							game.getPlayer()->setSkin(pikmin);
							break;

						case Keyboard::Num8:
						case Keyboard::Numpad8:
							isChoosen = true;
							game.getPlayer()->setSkin(tiboyou);
							break;

						case Keyboard::Num9:
						case Keyboard::Numpad9:
							isChoosen = true;
							game.getPlayer()->setSkin(yumi);
							break;

						default:
							break;
					}
			}
		}
	}
}

void GameSFML::drawMenu() {
	Font font;
	font.loadFromFile(PATH_FONTS + "elegantTypeWriter-bold.ttf");
	bool loop = true;
	Event event;
	Color color(245, 245, 245, 255);

	Text text1(L"Vous êtes en pause", font, spriteSize*2/3);
	text1.setPosition(spriteSize, spriteSize*2);
	text1.setFillColor(color);

	Text text2(L"Appuyer sur les touches suivantes :", font, spriteSize*2/3);
	text2.setPosition(spriteSize, spriteSize*3);
	text2.setFillColor(color);

	Text text3(L"R : pour reprendre la partie", font, spriteSize*2/3);
	text3.setPosition(spriteSize, spriteSize*4);
	text3.setFillColor(color);

	Text text4(L"échap : pour quitter", font, spriteSize*2/3);
	text4.setPosition(spriteSize, spriteSize*5);
	text4.setFillColor(color);

	Text text5(L"Rappel des touches : ", font, spriteSize*2/3);
	text5.setPosition(spriteSize, spriteSize*7);
	text5.setFillColor(color);

	Text text6(L"échap : pour quitter", font, spriteSize*2/3);
	text6.setPosition(spriteSize, spriteSize*8);
	text6.setFillColor(color);

	Text text7(L"z : sauter", font, spriteSize*2/3);
	text7.setPosition(spriteSize, spriteSize*9);
	text7.setFillColor(color);

	Text text8(L"s : descendre", font, spriteSize*2/3);
	text8.setPosition(spriteSize, spriteSize*10);
	text8.setFillColor(color);

	Text text9(L"q : pour aller à gauche", font, spriteSize*2/3);
	text9.setPosition(spriteSize, spriteSize*11);
	text9.setFillColor(color);

	Text text10(L"d : pour aller à droite", font, spriteSize*2/3);
	text10.setPosition(spriteSize, spriteSize*12);
	text10.setFillColor(color);

	Text text11(L"r : pour un bonus", font, spriteSize*2/3);
	text11.setPosition(spriteSize, spriteSize*13);
	text11.setFillColor(color);

	window.clear();
	drawBackground(32, 18);
	window.draw(text1); window.draw(text2); window.draw(text3); window.draw(text4);
	window.draw(text5); window.draw(text6); window.draw(text7); window.draw(text8);
	window.draw(text9); window.draw(text10); window.draw(text11);  
	window.display();

	while(loop)
	{
		while(window.pollEvent(event)) {
			if(event.type == Event::Closed) {
				window.close();	
				close=false;
				loop=false;
			}
			if(event.type == Event::KeyPressed)
				switch(event.key.code) {
					case Keyboard::R:
						loop = false;
						break;

					case Keyboard::Escape:
						window.close();	
						close=false;
						loop=false;
						break;

					default:
						break;
				}
		}
	}
}

void GameSFML::Loop(Game & game) {
	if(close) {
		window.close(); 
	}
	else {
	window.setKeyRepeatEnabled(false);
	Clock cl;
	int time = 3;
	bool finish;
	while(window.isOpen() || close) {
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
						finish=game.getPlayer()->right(game.getBuilding());
						if(!finish) {
							drawEnd(true);
							window.close();
						}
						break;

					case Keyboard::S:
						game.getPlayer()->down(game.getBuilding());
						break;

					case Keyboard::Q:
						game.getPlayer()->left(game.getBuilding());
						break;

					case Keyboard::R:
						randomizeTextures();
						randomizeSkins();
						break;

					case Keyboard::T:
						textures.clear();
						loadTextures();
						skins.clear();
						loadSkins();
						break;

					case Keyboard::Escape:
						drawMenu();
						break;

					default:
						break;
				}
        }
		draw(game);
		if(game.getPlayer()->getHp()==0 || game.getBuilding()->getTimeLeft() == 0) {
			drawEnd(false);
			window.close();
		}
    }
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

void GameSFML::randomizeSkins() {
	Texture tmp;
	for(unsigned int i = 0; i < skins.size()/2; ++i) {
		int j = rand() % skins.size()/2;
		tmp = skins[i*2];
		skins[i*2] = skins[j*2];
		skins[j*2] = tmp;
	}
	for(unsigned int i = 0; i < skins.size()/2; ++i) {
		int j = rand() % skins.size()/2;
		tmp = skins[i*2+1];
		skins[i*2+1] = skins[j*2+1];
		skins[j*2+1] = tmp;
	}
}

