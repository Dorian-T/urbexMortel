#ifndef _ENTITY
#define _ENTITY

#include "Vector2D.h"
#include "Room.h"

class Entity {
    private:

        /**
         * @brief Position de l'entite
         * 
         */
        Vector2D position;

        /**
         * @brief Hauteur de la hitbox de l'entite
         * 
         */
        unsigned int h;

        /**
         * @brief Largeur de la hitbox de l'entite
         * 
         */
        unsigned int w;

    public:

        /**
         * @brief Constructeur par defaut de l'entite
         * 
         */
        Entity();

        /**
         * @brief Constructeur parametre de l'entite
         * 
         * @param Eposition 
         * @param Eh 
         * @param Ew 
         */
        Entity(Vector2D Eposition , unsigned int Eh, unsigned int Ew);

        /**
         * @brief Accesseur de la hauteur de la hitbox de l'entite
         * 
         * @return unsigned int 
         */
        unsigned int getH();

        /**
         * @brief Accesseur de la largeur de la hitbox de l'entite
         * 
         * @return unsigned int 
         */
        unsigned int getW();

        /**
         * @brief Accesseur de la position de l'entite
         * 
         * @return Vector2D 
         */
        Vector2D getPosition();

        /**
         * @brief Deplacement vers le haut
         */
        void up(const Room & R);

        /**
         * @brief Deplacement vers la droite
         */
        void right(const Room & R);

        /**
         * @brief Deplacement vers le bas
         */
        void down(const Room & R);

        /**
         * @brief Deplacement vers la gauche
         */
        void left(const Room & R);

        /**
         * @brief Test de non-regression
         */
        void regressionTest();
};
#endif

