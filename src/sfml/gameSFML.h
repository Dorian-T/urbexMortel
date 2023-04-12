#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include "../core/Game.h"
#include <vector>

/* Version finie :
Dans le vector de textures, on a :
0 : nothing
1 : barbedWire
2 : block
3 : door
4 : ladder
5 : trapdoor
6 : potion
7 : player
8 : rat
*/

/* Pour l'instant :
Dans le vector de textures, on a :
0 : block
1 : ladder
2 : trapdoor
3 : potion
4 : player
5 : rat
*/

class GameSFML {

	private:

		/**
		 * @brief La fenêtre du jeu
		 */
		sf::RenderWindow window;

		/**
		 * @brief Les textures du jeu
		 */
		std::vector<sf::Texture> textures;

		std::vector<sf::Sprite> sprites; // TODO

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