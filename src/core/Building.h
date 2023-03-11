#ifndef _BUILDING
#define _BUILDING

#include "Room.h"

const unsigned int NB_ROOM = 10;

/**
 * @brief Ensemble des niveaux du jeu
 */
class Building
{
    private:

        /**
         * @brief Tableau 1 dimension de salles
         */
        Room* arrayRoom;

        /**
         * @brief Salle courante
         */
        unsigned int currentRoom;

    public:

        /**
         * @brief Constructeur par defaut
         * 
         */
        Building();

        /**
         * @brief Destructeur
         * 
         */
        ~Building();

        /**
         * @brief Retourne la salle courante
         * @return Room* 
         */
        Room* getcurrentRoom();

        /**
         * @brief Passe à la salle suivante
         */
        void gotonextRoom();

        /**
         * @brief Test de regression
         */
        void regressionTest();
};

#endif
