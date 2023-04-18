#ifndef _GAME
#define _GAME

#include "building/Building.h"
#include "entity/Player.h"
#include "entity/Rat.h"

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
         * @brief Numéro de la salle actuelle
         */
        unsigned int room;

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

        /**
         * @brief vecteur de rats
         */
        std::vector<Rat*> rats;

        /**
         * @brief Détecte un changement de salle
         * 
         * @return bool
         */
        bool changeRoom();

    public :

        /**
         * @brief Constructeur par défaut en fonction de la difficulté
         */
        Game (int difficulty = 1);

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
         * @brief Retourne le nombre de rats
        */
        unsigned int getNbRat() const;

        /**
         * @brief Accesseur vers le rat i
         * 
         * @param i 
         * @return Rat* 
         */
        Rat * getRat (unsigned int i) const;

        /**
         * @brief ajoute dans rats les rats de la salle
         * 
         */
        void addRat();

        /**
         * @brief Enlève tous les rats de la salle
         */
        void removeRat();

        /**
         * @brief collisions entre les rats et le joueur
         */
        void collisionRat();

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

        /**
         * @brief Tests de non-regression
         */
        void regressionTest();
};

#endif