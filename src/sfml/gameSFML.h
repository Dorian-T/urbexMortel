#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include "../core/Game.h"
#include <vector>

/*
Dans le vector de textures, on a :
0 : background
1 : barbedWire
2 : block
3 : door1
4 : door2
5 : ladder
6 : trapdoor
7 : potion
8 : heart
9 : poisonBar
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
		 * @brief dessine l'écran de mort 
		 * 
		 */
		void drawGameOver();

		/**
		 * @brief dessine l'écran de victoire
		 * 
		 */
		void drawVictory();

		/**
		 * @brief dessine l'arraigné
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