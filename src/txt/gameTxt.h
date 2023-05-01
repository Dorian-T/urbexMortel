#ifndef _gameTxt_H
#define _gameTxt_H

#include "../core/Game.h"
#include "winTxt.h"

/**
 * @brief Classe représentant le jeu dans la console
 */
class GameTXT {
	private:

		/**
		 * @brief La fenêtre du jeu (dans la console)
		 */
		WinTXT * window;

		/**
		 * @brief Dessine le jeu dans la console
		 * 
		 * @param G
		 */
		void draw(const Game & G);

	public:

		/**
		 * @brief Constructeur par défaut
		 */
		GameTXT(const Game & G);

		/**
		 * @brief La boucle principale du jeu
		 * 
		 * @param G 
		 */
		void loop(Game & G);
};

#endif