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
		std::vector<sf::Texture> texturesObstacles;

		/**
		 * @brief La taille d'une case
		 */
		unsigned int spriteSize;

		/**
		 * @brief Dessine le jeu dans la fenêtre
		 * 
		 * @param game 
		 * @param window 
		 */
		void draw(const Game & game);

		/**
		 * @brief Dessine le background dans la fenêtre
		 * 
		 * @param game 
		 */
		void drawBackground(const Room & room);

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
		void drawInfoPlayer(Player * player, Building * building);

		void drawMenu();

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
};

#endif