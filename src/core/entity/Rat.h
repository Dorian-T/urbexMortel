#ifndef RAT_H
#define RAT_H

#include "Vector2D.h"
#include "Entity.h"
#include "Player.h"
#include "../building/Building.h"

class Building;

class Rat: public Entity {
	private:

		/**
		 * @brief Direction du rat
		 */
		unsigned int direction;

		/**
		 * @brief Temps avant le prochain déplacement
		 */
		unsigned int time;

		/**
		 * @brief Choisi une direction
		 * 
		 * @param B 
		 */
		void findDirection(Building * B, Player * P);

		/**
		 * @brief Verifie si le joueur est a proximité
		 * 
		 * @param B 
		 * @return bool
		 */
		bool isPlayerArround(Building * B, Player * P) const;

		/**
		 * @brief Verifie si le déplacement est possible
		 * 
		 * @param B
		 * @param V
		 * @return bool
		 */
		bool isMovePossible(Building *B, const Vector2D & V) const;

		/**
		 * @brief Verifie si le déplacement vers le bas est possible
		 * 
		 * @param position
		 * @param R
		 * @return bool
		 */
		bool isMovePossibleGravity(const Vector2D & position, Room * R) const;

	public:

		/**
		 * @brief Constructeur par défaut
		 */
		Rat();

		/**
		 * @brief Constructeur paramétré
		 * 
		 * @param p
		 * @param h
		 * @param w
		 * @param d
		 */
		Rat(Vector2D p, unsigned int h, unsigned int w);

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
		void move(Building * B, Player * P);

		/**
		 * @brief Application de la gravité
		 * 
		 * @param B
		 */
		void gravity(Building * B);

		/**
		 * @brief Test de non-régression
		 */
		void regressionTest();
};

#endif