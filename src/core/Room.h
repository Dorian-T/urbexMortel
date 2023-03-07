#ifndef _ROOM
#define _ROOM

#include "Vector2D.h"

/**
 * @brief Enumeration des obstacles
 */
enum Obstacle {
	nothing = 0,
	barbedWire = 1,
	block = 2,
	ladder = 3,
	trapdoor = 4,
};

/**
 * @brief Les niveaux du jeu
 */
class Room {

    private:

        /**
         * @brief Dimension de la salle en X
         */
        int dimX;

        /**
         * @brief Dimension de la salle en Y
         */
        int dimY;

        /**
         * @brief Tableau des obstacles
         */
        Obstacle* arrayObstacle;

    public:

        /**
         * @brief Constructeur par defaut
         */
        Room();

        /**
         * @brief Constructeur parametre
         * 
         * @param X 
         * @param Y 
         */
        Room(int X , int Y);

        /**
         * @brief Destructeur
         */
        ~Room();

        /**
         * @brief Retourne l'obstacle a la position V
         * 
         * @param V 
         * @return obstacle 
         */
        Obstacle getObstacle(Vector2D V) ;

        /**
         * @brief Verifie si le deplacement est possible
         * 
         * @param Position 
         * @return bool 
         */
        bool isMovePossible(const Vector2D & Position);

        /**
         * @brief Convertit les coordonnees en pixels en coordonnees en cellules
         * 
         * @param Pixel 
         * @return Vector2D*
         */
        Vector2D* pixelToCell(const Vector2D & Pixel);
};


#endif
