#ifndef _ENTITY
#define _ENTITY

#include "../entity/Vector2D.h"
#include "../building/Room.h"

/**
 * @brief Classe abstraite représentant une entité
 */
class Entity {

    private:

        /**
         * @brief Position du coin bas gauche de la hitbox
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
         * @brief Constructeur par défaut
         */
        Entity();

        /**
         * @brief Constructeur paramétré
         * 
         * @param p 
         * @param h 
         * @param w 
         */
        Entity(const Vector2D & p, unsigned int h, unsigned int w);

        /**
         * @brief Accesseur de la hauteur de la hitbox
         * 
         * @return unsigned int 
         */
        unsigned int getHeight() const;

        /**
         * @brief Accesseur de la largeur de la hitbox
         * 
         * @return unsigned int 
         */
        unsigned int getWidth() const;

        /**
         * @brief Accesseur de la position
         * 
         * @return Vector2D 
         */
        Vector2D getPosition() const; // le type de retour fait plus de 8 octets

        /**
         * @brief Modificateur de la position
         */
        void setPosition(const Vector2D & p);

        /**
         * @brief Déplacement vers le haut
         */
        void up(const Room & R);

        /**
         * @brief Déplacement vers la droite
         */
        void right(const Room & R);

        /**
         * @brief Déplacement vers le bas
         */
        void down(const Room & R);

        /**
         * @brief Déplacement vers la gauche
         */
        void left(const Room & R);

        /**
         * @brief Application de la gravité
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

