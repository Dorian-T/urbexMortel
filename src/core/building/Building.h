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
         * @brief tableau 1D de salles
         */
        std::vector<Room> arrayRoom;

        /**
         * @brief indice de la salle courante
         */
        unsigned int currentRoom;

        /**
         * @brief nombre de salle dans le buiding
         */
        unsigned int nbRoom;

    public:

        /**
         * @brief Constructeur paramétré
         * 
         * @param nb
         */
        Building(unsigned int nb);

        /**
         * @brief Constructeur paramétré
         * 
         * @param filename
         */
        Building(std::string filename);

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
         * @brief Retourne le nombre de salle
         * 
         * @return unsigned int 
         */
        unsigned int getNbRoom();
      

        /**
         * @brief Renvoie faux si on a atteint la sortie de la dernière salle sinon renvoie vrai
         * et change de salle
         * 
         * @return bool
         */
        bool finishRoom();

        /**
         * @brief Test de regression
         */
        void regressionTest();
};

#endif
