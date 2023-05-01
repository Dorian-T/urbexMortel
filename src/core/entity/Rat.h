#ifndef RAT_H
#define RAT_H

#include "Vector2D.h"
#include "Entity.h"
#include "Player.h"
#include "../building/Room.h"


/**
 * @brief Classe représentant un rat
 * 
 * @details classe héritée de Entity
 */
class Rat: public Entity {
	private:

		/**
		 * @brief Direction du rat
		 */
		int direction;

		/**
		 * @brief Temps avant le prochain déplacement
		 */
		unsigned int time;

		/**
		 * @brief Choisi une direction
		 * 
		 * @param B 
		 */
		void findDirection(const Player & P);

		/**
		 * @brief Verifie si le joueur est a proximité
		 * 
		 * @param B 
		 * @return bool
		 */
		bool isPlayerArround(const Player & P) const;

		/**
		 * @brief Verifie si le déplacement est possible
		 * 
		 * @param B
		 * @param V
		 * @return bool
		 */
		bool isMovePossible(const Room & R, const Vector2D & V) const;

		/**
		 * @brief Verifie si le déplacement vers le bas est possible
		 * 
		 * @param position
		 * @param R
		 * @return bool
		 */
		bool isMovePossibleGravity(const Room & R, const Vector2D & V) const;

	public:

		/**
		 * @brief Constructeur paramétré
		 * 
		 * @param p
		 */
		Rat(Vector2D p);

		/**
		 * @brief Accesseur de la direction
		 * 
		 * @return Vector2D
		 */
		int getDirection() const;

		/**
		 * @brief Déplacement du rat
		 * 
		 * @param B
		 */
		void move(const Room & R, const Player & P);

		/**
		 * @brief Application de la gravité
		 * 
		 * @param B
		 */
		void gravity(const Room & R);

		/**
		 * @brief Test de non-régression
		 */
		void regressionTest();
};

#endif