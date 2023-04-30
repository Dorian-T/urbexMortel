#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../core/Game.h"
#include <vector>

/*
vector des textures :			vector des skins :
00 : background					00 : lilithR
01 : barbedWire					01 : lilithL
02 : block						02 : doraR
03 : door1						03 : doraL
04 : door2
05 : ladder
06 : trapdoor
07 : potion
08 : heart
09 : poisonSkull
10 : poisonBar
11 : ratR
12 : ratL
13 : spider
14 : spiderWeb
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
		 * @brief Les skins des personnages
		 */
		std::vector<sf::Texture> skins;

		/**
		 * @brief La taille d'une case
		 */
		unsigned int spriteSize;

		/**
		 * @brief bool qui sert à savoir si on doit quitter le programme
		 * 
		 */
		bool close;

		/**
		 * @brief Musique du jeu
		 */
		// sf::Music music;

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
		 * @brief dessine l'arraignée
		 */
		void drawSpider(Spider * spider, const Room & room);

		/**
		 * @brief dessine le rat
		 */
		void drawRat(Rat * rat);

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
		 * @brief Charge les skins
		 */
		void loadSkins();

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
		 * @brief Easter egg
		 */
		void randomizeSkins();

		/**
		 * @brief Dessine l'histoire du jeu
		 */
		void drawStory();

		/**
		 * @brief Dessine le menu de difficulté
		 * 
		 * @param game 
		 */
		void drawDifficultyMenu(Game & game);

		/**
		 * @brief Dessine le menu de skin
		 * 
		 * @param game 
		 */
		void drawSkinMenu(Game & game);
};

#endif