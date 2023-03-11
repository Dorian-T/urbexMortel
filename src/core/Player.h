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

        /**
         * @brief bool pour savoir si le joeur vient d'être blésser
         * 
         */
        bool hurted;

        /**
         * @brief temps où le joeur est invincible
         * 
         */
        unsigned int TimeInvincible;

    public:
        /**
         * @brief Constructeur par défaut
         * 
         */
        Player();

        /**
         * @brief Constructeur parametre
         * 
         * @param Pskin
         * @param Php
         */
        Player(Skin Pskin, unsigned int Php);

        /**
         * @brief modifie les points de vie du joeur
         * 
         * @param H 
         */
        void setHp(unsigned int H);

        /**
         * @brief Deplacement vers le haut (saut)
         * 
         * @param R 
         */
        void up(Room *R) ;

        /**
         * @brief Deplacement vers la droite
         * 
         * @param R 
         */
        void right(Room * R) ;

        /**
         * @brief Deplacement vers le bas
         * 
         * @param R 
         */
        void down(Room * R) ;

        /**
         * @brief Deplacement vers la gauche
         * 
         * @param R 
         */
        void left(Room * R) ;

        /**
         * @brief applique la gravité
         * 
         * @param R 
         */
        void gravity(Room * R);

        /**
         * @brief fonction qui change l'état du joueur quand il est bléssé
         * 
         */
        void Hurted();       

        /**
         * @brief fonction qui baisse le temps d'invincibilité
         * 
         */
        void decreaseTimeInvincible();

        /**
         * @brief fonction qui dit si le joueur est en vie ou pas
         * 
         * @return true 
         * @return false 
         */
        bool isDead();
};

#endif
