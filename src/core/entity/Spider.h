#ifndef SPIDER_H
#define SPIDER_H

#include "Vector2D.h"
#include "Entity.h"
#include "../building/Building.h"

class Building;

/**
 * @brief Classe représentant un spider
 * 
 * @details classe héritée de Entity
 */
class Spider: public Entity {
	private:

		/**
		 * @brief Direction du spider
		 */
		int direction;

		/**
		 * @brief Temps avant le prochain déplacement
		 */
		unsigned int time;

		/**
		 * @brief Verifie si le déplacement est possible
		 * 
		 * @param B
		 * @param V
		 * @return bool
		 */
		bool isMovePossible(Building *B, const Vector2D & V) const;


	public:

		/**
		 * @brief Constructeur par défaut
		 */
		Spider();

		/**
		 * @brief Constructeur paramétré
		 * 
		 * @param p
		 * @param h
		 * @param w
		 */
		Spider(Vector2D p, unsigned int h, unsigned int w);

		/**
		 * @brief Accesseur de la direction
		 * 
		 * @return int
		 */
		int getDirection() const;

		/**
		 * @brief Déplacement du spider
		 * 
		 * @param B
		 */
		void move(Building * B);

		/**
		 * @brief Test de non-régression
		 */
		void regressionTest();
};

#endif