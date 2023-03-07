#ifndef _BUILDING
#define _BUILDING

#include "Room.h"

const unsigned int NB_ROOM = 10;
const unsigned int DIM_ROOM_X = 16;
const unsigned int DIM_ROOM_Y = 9;

/**
 * @brief Ensemble des niveaux du jeu
 */
class Building
{
    private:

        /**
         * @brief Tableau des salles
         */
        Room* arrayRoom;

        /**
         * @brief Salle courante
         */
        Room* currentRoom;

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
        Room* getRoom(unsigned int i);

        /**
         * @brief Retourne la salle courante
         * @return Room* 
         */
        Room* getcurrentRoom();
};

#endif
