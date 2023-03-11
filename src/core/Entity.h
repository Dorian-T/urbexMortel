#ifndef _ENTITY
#define _ENTITY

#include "Vector2D.h"
#include "Room.h"

class Entity {
    private:

        /**
         * @brief position du coin haut gauche de la hitbox
         */
        Vector2D position;

        /**
         * @brief hauteur de la hitbox
         */
        unsigned int height;

        /**
         * @brief largeur de la hitbox
         */
        unsigned int width;

    public:

        /**
         * @brief constructeur par défaut
         */
        Entity();

        /**
         * @brief constructeur paramètre
         * 
         * @param p 
         * @param h 
         * @param w 
         */
        Entity(Vector2D p, unsigned int h, unsigned int w);

        /**
         * @brief accesseur de la hauteur de la hitbox
         * 
         * @return unsigned int 
         */
        unsigned int getHeight();

        /**
         * @brief accesseur de la largeur de la hitbox
         * 
         * @return unsigned int 
         */
        unsigned int getWidth();

        /**
         * @brief accesseur de la position
         * 
         * @return Vector2D 
         */
        Vector2D getPosition();

        /**
         * @brief modificateur de la position
         */
        void setPosition(Vector2D p);

        /**
         * @brief déplacement vers le haut
         */
        void up(const Room & R);

        /**
         * @brief déplacement vers la droite
         */
        void right(const Room & R);

        /**
         * @brief déplacement vers le bas
         */
        void down(const Room & R);

        /**
         * @brief déplacement vers la gauche
         */
        void left(const Room & R);

        /**
         * @brief application de la gravité
         * 
         * @param R 
         */
        void gravity(const Room & R);

        /**
         * @brief test de non-regression
         */
        void regressionTest();
};
#endif

