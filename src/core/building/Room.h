#ifndef _ROOM
#define _ROOM

#include "../entity/Vector2D.h"

#include <string>
#include <vector>

/**
 * @brief Chemin vers le dossier des salles
 */
const std::string PATH_ROOMS = "data/rooms/";

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
    potion = 'P',
    ghostBlock = '%'
};

/**
 * @brief Les niveaux du jeu
 */
class Room {

    private:

        /**
         * @brief Taille de la salle en X
         */
        unsigned int dimX;

        /**
         * @brief Taille de la salle en Y
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

        /**
         * @brief Tableau des positions des spider
         */
        std::vector<Vector2D> arraySpider;

    public:

        /**
         * @brief Constructeur depuis un fichier texte
         * 
         * @param filename
         */
        Room(const std::string & filename);

        /**
         * @brief Accesseur de la taille en X
         * 
         * @return unsigned int 
         */
        unsigned int getDimX() const;

        /**
         * @brief Accesseur de la taille en Y
         * 
         * @return unsigned int 
         */
        unsigned int getDimY() const;

        /**
         * @brief Accesseur de l'obstacle à la position V
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
         * @brief Retourne le nombre d'araignées
         * 
         * @return unsigned int 
         */
        unsigned int getNbSpider() const;

        /**
         * @brief Retourne la position de l'araignée i
         * 
         * @param i 
         * @return Vector2D 
         */
        Vector2D* getSpider(unsigned int i);

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