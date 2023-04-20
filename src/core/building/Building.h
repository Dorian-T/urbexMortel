#ifndef _BUILDING
#define _BUILDING

#include "Room.h"

#include <string>
#include <vector>

/**
 * @brief Ensemble des niveaux du jeu
 */
class Building {

    private:

        /**
         * @brief Tableau 1D de salles
         */
        std::vector<Room> arrayRoom;

        /**
         * @brief Indice de la salle courante
         */
        unsigned int currentRoom;

        /**
         * @brief Nombre de salles dans le Building
         */
        unsigned int nbRoom;

        /**
         * @brief Temps total en secondes avant le game over
        */
        unsigned int totalTime;

    public:

        /**
         * @brief Constructeur paramétré
         * 
         * @details construit un building avec nb salles aléatoires
         * @param nb
         */
        Building(unsigned int nb);

        /**
         * @brief Constructeur paramétré
         * 
         * @details construit un building avec la salle passée en paramètre
         * @param filename
         */
        Building(const std::string & filename);

        /**
         * @brief Retourne la salle courante
         * 
         * @return Room*
         */
        Room* getCurrentRoom();

        /**
         * @brief Retourne l'indice de la salle courante
         * 
         * @return unsigned int
         */
        unsigned int getIntCurrentRoom();

        /**
         * @brief Accesseur du nombre de salles
         * 
         * @return unsigned int 
         */
        unsigned int getNbRoom();

        /**
         * @brief Accesseur du temps total avant le game over
         * 
         * @return unsigned int
        */
        unsigned int getTotalTime();

        /**
         * @brief Mutateur du temps total avant le game over
         * 
         * @return void
        */
        void setTotalTime(unsigned int t);

        /**
         * @brief Permet de savoir si la partie est finie
         * 
         * @details renvoie vrai et change de salle si la partie n'est pas finie
         * @details renvoie faux si la partie est finie
         * @return bool
         */
        bool finishRoom();

        /**
         * @brief Test de non-regression
         */
        void regressionTest();
};

#endif
