#ifndef _ROOM
#define _ROOM

#include "../entity/Vector2D.h"
#include <string>

const unsigned int DIM_ROOM_X = 16;
const unsigned int DIM_ROOM_Y = 9;
const unsigned int PIXEL_ROOM_X = 9;
const unsigned int PIXEL_ROOM_Y = 16;

/**
 * @brief Enumeration des obstacles
 */
enum Obstacle {
	nothing = 0,
	barbedWire = 1,
	block = 2,
    door = 3,
	ladder = 4,
	trapdoor = 5,
};

/**
 * @brief Les niveaux du jeu
 */
class Room {

    private:

        /**
         * @brief Dimension de la salle en X
         */
        unsigned int dimX;

        /**
         * @brief Dimension de la salle en Y
         */
        unsigned int dimY;

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
         * @brief Constructeur depuis un fichier texte
         * 
         * @param filename
         */
        Room(const std::string & filename);

        /**
         * @brief Destructeur
         */
        ~Room();

        /**
         * @brief Retourne la dimension en X
         * 
         * @return unsigned int 
         */
        unsigned int getDimX() const;

        /**
         * @brief Retourne la dimension en Y
         * 
         * @return unsigned int 
         */
        unsigned int getDimY() const;

        /**
         * @brief Retourne l'obstacle a la position V
         * 
         * @param V 
         * @return Obstacle 
         */
        Obstacle getObstacle(const Vector2D & V) const; // pas besoin ? ah bon ?

        /**
         * @brief verifie si le deplacement est possible
         * 
         * @details retourne -1 si le deplacement est possible
         * @details retourne un entier positif indiquant le nb de dégats si le déplacement est impossible
         * 
         * @param Position 
         * @return int
         */
        int isMovePossible(const Vector2D & Position) const;
};

#endif