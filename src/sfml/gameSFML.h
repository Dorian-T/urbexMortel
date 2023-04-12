#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include "../core/Game.h"
#include <vector>

/* Version finie :
Dans le vector de textures, on a :
0 : barbedWire
1 : block
2 : door
3 : ladder
4 : trapdoor
5 : potion
*/

/* Pour l'instant :
Dans le vector de textures, on a :
0 : block
1 : ladder
2 : trapdoor
3 : potion
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

		std::vector<sf::Sprite> spritesObstacles; // TODO

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
		 * @brief Dessine le joueur dans la fenêtre
		 * 
		 * @param player
		 */
		void drawPlayer(const Player & player);

		/**
		 * @brief Dessine les obstacles dans la fenêtre
		 * 
		 * @param obstacle
		 */
		void drawObstacles(const Room & room);

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