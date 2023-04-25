#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include "../core/Game.h"
#include <vector>

/*
Dans le vector de textures, on a :
00 : background
01 : barbedWire
02 : block
03 : door1
04 : door2
05 : ladder
06 : trapdoor
07 : potion
08 : heart
09 : poisonSkull
10 : poisonBar
11 : playerR
12 : playerL
13 : ratR
14 : ratL
15 : spider
*/

class GameSFML {

	private:

		/**
		 * @brief La fenêtre du jeu
		 */
		sf::RenderWindow window;

		/**
		 * @brief Les textures des obstacles
		 */
		std::vector<sf::Texture> textures;

		/**
		 * @brief La taille d'une case
		 */
		unsigned int spriteSize;

		/**
		 * @brief Dessine le jeu dans la fenêtre
		 * 
		 * @param game 
		 */
		void draw(const Game & game);

		/**
		 * @brief Dessine le background dans la fenêtre
		 * 
		 * @param game 
		 */
		void drawBackground(unsigned int dimX, unsigned int dimY);

		/**
		 * @brief Dessine les obstacles dans la fenêtre
		 * 
		 * @param obstacle
		 */
		void drawObstacles(const Room & room);

		/**
		 * @brief Dessine le joueur dans la fenêtre
		 * 
		 * @param player
		 */
		void drawPlayer(Player * player);

		/**
		 * @brief Dessine les infos du joueur
		 * 
		 */
		void drawInfoPlayer(const Game & game);

		/**
		 * @brief Dessine une string caractère par caractère
		 */
		void drawString(const std::wstring & str, unsigned int y);

		/**
		 * @brief Dessine le menu
		 * 
		 */
		void drawMenu();

		/**
		 * @brief Dessine l'écran de fin du jeu
		 * 
		 * @param victory
		 */
		void drawEnd(bool victory);

		/**
		 * @brief dessine l'arraignée
		 * 
		 */
		void drawSpider(Spider * spider);

		/**
		 * @brief dessine le rat
		 * 
		 */
		void drawRat(Rat * rat);

	public:

		/**
		 * @brief Constructeur paramétré
		 */
		GameSFML(const Game & game);

		/**
		 * @brief Charge les textures
		 */
		void loadTextures();

		/**
		 * @brief Destructeur
		 */
		~GameSFML();

		/**
		 * @brief La boucle principale du jeu
		 * 
		 * @param game 
		 * @param window 
		 */
		void Loop(Game & game);

		/**
		 * @brief Easter egg
		 */
		void randomizeTextures();

		/**
		 * @brief Dessine l'histoire du jeu
		 */
		void drawStory();

		/**
		 * @brief Dessine le menu de difficulté
		 */
		void drawDifficultyMenu(Game & game);
};

#endif