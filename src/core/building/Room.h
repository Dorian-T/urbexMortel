#ifndef _ROOM
#define _ROOM

#include "../entity/Vector2D.h"
// #include "../entity/Rat.h"
#include <string>
#include <vector>

// class Rat;

const unsigned int DIM_ROOM_X = 16;
const unsigned int DIM_ROOM_Y = 9;
const unsigned int PIXEL_ROOM_X = 9;
const unsigned int PIXEL_ROOM_Y = 16;

/**
 * @brief Enumeration des obstacles
 */
enum Obstacle {
	nothing = '.',
	barbedWire = '*',
	block = '#',
    door = 'D',
	ladder = 'H',
	trapdoor = '-',
    potion = 'P'
};

/**
 * @brief Les niveaux du jeu
 */class Room {

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
         * @brief Temps pour sortir de la salle
        */
        unsigned int time;

        /**
         * @brief Tableau des obstacles
         */
        std::vector<Obstacle> arrayObstacle;

        /**
         * @brief Tableau des positions des rats
         */
        std::vector<Vector2D> arrayRat;

    public:

        /**
         * @brief Constructeur par défaut
         */
        Room();

        /**
         * @brief Constructeur depuis un fichier texte
         * 
         * @param filename
         */
        Room(const std::string & filename);

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
         * @brief Retourne l'obstacle à la position V
         * 
         * @param V 
         * @return Obstacle 
         */
        Obstacle getObstacle(const Vector2D & V) const;

        /**
         * @brief Modifie l'obstacle à la position V
        */
        void setObstacle(const Vector2D & V, Obstacle o);

        /**
         * @brief Retourne le nombre de rats
         * 
         * @return unsigned int 
         */
        unsigned int getNbRat() const;

        /**
         * @brief Retourne la position du rat i
         * 
         * @param i 
         * @return Vector2D 
         */
        Vector2D* getRat(unsigned int i);

        /**
         * @brief Retourne le temps pour sortir de la salle
         * 
         * @return unsigned int
        */
        unsigned int getTime() const;

        /**
         * @brief Tests de non-regression
         */
        void regressionTest();
};

#endif