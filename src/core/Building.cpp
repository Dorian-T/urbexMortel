#include <iostream>

#include "Building.h"

Building::Building()
{
    arrayRoom=NULL;
    currentRoom=0;
}

Building::~Building()
{
    if (arrayRoom != NULL) delete [] arrayRoom;
    arrayRoom = NULL;
}

Room* Building::getcurrentRoom()
{

}

void Building::gotonextRoom()
{

}