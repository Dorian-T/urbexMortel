#ifndef _ENTITY
#define _ENTITY

#include "Vector2D.h"
#include "Room.h"

class Entity {
    private:

        /**
         * @brief Position du coin en haut gauche de la hitbox
         */
        Vector2D position;

        /**
         * @brief Hauteur de la hitbox
         */
        unsigned int height;

        /**
         * @brief Largeur de la hitbox
         */
        unsigned int width;

    public:

        /**
         * @brief Constructeur par defaut
         */
        Entity();

        /**
         * @brief Constructeur parametre
         * 
         * @param p 
         * @param h 
         * @param w 
         */
        Entity(Vector2D p, unsigned int h, unsigned int w);

        /**
         * @brief Accesseur de la hauteur de la hitbox
         * 
         * @return unsigned int 
         */
        unsigned int getHeight();

        /**
         * @brief Accesseur de la largeur de la hitbox
         * 
         * @return unsigned int 
         */
        unsigned int getWidth();

        /**
         * @brief Accesseur de la position
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
         * @brief Applique la gravite
         * 
         * @param R 
         */
        void gravity(const Room & R);

        /**
         * @brief Test de non-regression
         */
        void regressionTest();
};
#endif

