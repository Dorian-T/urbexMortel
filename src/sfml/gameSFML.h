#ifndef _GAME_SFML
#define _GAME_SFML

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../core/Game.h"
#include <vector>

/*
	vector des skins :		vector des textures :
00	batmanL					background
01	batmanR					barbedWire
02	coaraaL					block
03	coaraaR					door1
04	daisyL					door2
05	daisyR					ladder
06	doraL					trapdoor
07	doraR					potion
08	gadgetL					heart
09	gadgetR					poisonSkull
10	lilithL					poisonBar
11	lilithR					ratR
12	maestroL				ratL
13	maestroR				spider
14	pikminL					spiderWeb
15	pikminR
16	tiboyouL
17	tiboyouR
18	yumiL
19	yumiR
*/


/**
 * @brief Classe s'occupant de l'affichage SFML du jeu
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
		void loop(Game & game);

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