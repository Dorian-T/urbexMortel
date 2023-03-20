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
         * @brief constructeur avec paramètre de nombre de salle 
         */
        Building(unsigned int Nb);

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
         * @brief Passe à la salle suivante
         */
        void goToNextRoom();

        /**
         * @brief renvoi si on est à la dernière Room
         * 
         * @return true 
         * @return false 
         */
        bool isLastRoom();

        /**
         * @brief renvoi si on a atteint la sortie de la dernière salle
         * 
         * @return true pas la sortie
         * @return false la sortie
         */
        bool finish();

        /**
         * @brief Test de regression
         */
        void regressionTest();
};

#endif
