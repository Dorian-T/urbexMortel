#ifndef _BUILDING
#define _BUILDING

#include "Room.h"

class Building
{
    private :
    Room* arrayRoom;
    Room* currentRoom;

    public :
    Building();

    ~Building();

    Room* getRoom();

    Room* getcurrentRoom();


};

#endif
