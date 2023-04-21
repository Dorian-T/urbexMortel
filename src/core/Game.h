#ifndef _GAME
#define _GAME

#include "building/Building.h"
#include "entity/Player.h"
#include "entity/Rat.h"
#include "entity/Spider.h"

/**
 * @brief Classe représentant le jeu
 */
class Game {

    private :

        /**
         * @brief Pointeur vers le batiment
         */
        Building *building;

        /**
         * @brief Numéro de la salle actuelle
         */
        unsigned int room;

        /**
         * @brief Pointeur vers le joueur
         */
        Player *player;

        /**
         * @brief Vecteur de rats
         */
        std::vector<Rat*> rats;

        /**
         * @brief Vecteur d'araignées
         */
        std::vector<Spider*> spiders;

        /**
         * @brief Détecte un changement de salle
         * 
         * @return bool
         */
        bool changeRoom();

    public :

        /**
         * @brief Constructeur par défaut
         */
        Game();

        /**
         * @brief Destructeur
         */
        ~Game();

        /**
         * @brief Permet de changer le niveau de difficulté
         * 
         * @param difficulty 
         */
        void setDifficulty(unsigned int difficulty);

        /**
         * @brief Accesseur vers le batiment
         * 
         * @return Building*
         */
        Building* getBuilding() const;

        /**
         * @brief Accesseur vers le joueur
         * 
         * @return Player* 
         */
        Player* getPlayer() const;


        /**
         * @brief Retourne le nombre de rats
        */
        unsigned int getNbRat() const;

        /**
         * @brief Accesseur vers le rat n°i
         * 
         * @param i 
         * @return Rat* 
         */
        Rat* getRat(unsigned int i) const;

        /**
         * @brief ajoute dans le vecteur de rats ceux de la salle actuelle
         */
        void addRat();

        /**
         * @brief Détruit tous les rats
         */
        void removeRat();

        /**
         * @brief Test les collisions entre les rats et le joueur
         */
        void collisionRat();

        /**
         * @brief Retourne le nombre d'araignées
        */
        unsigned int getNbSpider() const;

        /**
         * @brief Accesseur vers l'araignée n°i
         * 
         * @param i 
         * @return Spider* 
         */
        Spider* getSpider(unsigned int i) const;

        /**
         * @brief Ajoute dans le vecteur d'araignées celles de la salle actuelle
         */
        void addSpider();

        /**
         * @brief Détruit toutes les araignées
         */
        void removeSpider();

        /**
         * @brief Test les collisions entre les areignées et le joueur
         */
        void collisionSpider();

        /**
         * @brief Réalisation des actions automatiques
         * 
         * @details retourne le nombre de ticks restants avant l'application de la gravité sur le joueur
         * @param time 
         * @return int 
         */
        int update(int time);

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