#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"
#include "../building/Room.h"

enum Skin {
    M,
    F
};

class Player : public Entity {
    private:

        /**
         * @brief choix du skin
         */
        Skin skin;

        /**
         * @brief points de vie
         */
        unsigned int hp;

        /**
         * @brief temps où le joueur est invincible après s'être pris un coup
         */
        unsigned int timeInvincible;

    public:
        /**
         * @brief constructeur par défaut
         */
        Player();

        /**
         * @brief constructeur paramétré
         * 
         * @param s
         * @param h
         */
        Player(const Vector2D & p, unsigned int h, unsigned int w, Skin s, unsigned int health);

        /**
         * @brief baisse les points de vie
         * 
         * @details si le joueur est invincible, les points de vie ne sont pas baissés
         * @details renvoie faux si le joueur est mort
         * 
         * @param h
         * 
         * @return bool
         */
        bool decreaseHp(unsigned int h);

        /**
         * @brief baisse le temps d'invincibilité
         */
        void decreaseTimeInvincible();

        /**
         * @brief déplacement vers le haut (saut)
         * 
         * @param R
         */
        void up(const Room & R);

        /**
         * @brief déplacement vers la droite
         * 
         * @param R 
         */
        void right(const Room & R);

        /**
         * @brief déplacement vers le bas
         * 
         * @param R 
         */
        void down(const Room & R);

        /**
         * @brief déplacement vers la gauche
         * 
         * @param R 
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
