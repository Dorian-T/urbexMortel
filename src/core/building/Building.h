#ifndef _BUILDING
#define _BUILDING

#include "Room.h"
#include <vector>
const unsigned int NB_ROOM = 10;

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

    public:

        /**
         * @brief constructeur par defaut
         */
        Building();

        /**
         * @brief Retourne la salle courante
         * 
         * @return Room* 
         */
        Room* getCurrentRoom();

        /**
         * @brief Passe à la salle suivante
         */
        void goToNextRoom();

        /**
         * @brief Test de regression
         */
        void regressionTest();
};

#endif
