#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"
#include "Room.h"

enum Skin {
    M,
    F
};

class Player : public Entity {
    private:

        /**
         * @brief choix du skin du joueur
         */
        Skin skin;

        /**
         * @brief Points de vie du joueur
         */
        unsigned int hp;

    public:

        /**
         * @brief Constructeur parametre
         * 
         * @param Pskin
         * @param Php
         */
        Player(Skin Pskin, unsigned int Php);

        /**
         * @brief Deplacement vers le haut (saut)
         * 
         * @param R 
         */
        void up(const Room & R) ;

        /**
         * @brief Deplacement vers la droite
         * 
         * @param R 
         */
        void right(const Room & R) ;

        /**
         * @brief Deplacement vers le bas
         * 
         * @param R 
         */
        void down(const Room & R) ;

        /**
         * @brief Deplacement vers la gauche
         * 
         * @param R 
         */
        void left(const Room & R) ;
};

#endif
