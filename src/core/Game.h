#ifndef _GAME
#define _GAME

#include "building/Building.h"
#include "entity/Player.h"

/**
 * @brief Classe représentant le jeu
 */
class Game {

    private :

        /**
         * @brief Pointeur vers le batiment
         */
        Building * building;

        /**
         * @brief Pointeur vers le joueur 1
         */
        Player * player1;

        /**
         * @brief Pointeur vers le joueur 2
         */
        Player * player2;

        /**
         * @brief bool pour savoir si on est en 1 ou 2 joeur
         */
        bool multiplayer;

        // je pense que je vais rajouter les rats ici

    public :

        /**
         * @brief Constructeur par défaut
         */
        Game ();

        /**
         * @brief Destructeur
         */
        ~Game();

        /**
         * @brief Accesseur vers le batiment
         * 
         * @return Building*
         */
        Building * getBuilding() const;

        /**
         * @brief Accesseur vers le joueur
         * 
         * @return Player* 
         */
        Player * getPlayer () const;

        /**
         * @brief Réalisation des actions automatiques
         * 
         * @param time 
         * @return int 
         */
        int automaticAction (int time);

        /**
         * @brief Redistribution des actions clavier vers les fonctions de déplacement
         * 
         * @param touche
         * @return bool
         */
        bool keyboardAction (const char touche);

};

#endif