#include <iostream>

#include "Vector2D.h"
#include "Room.h"

Room::Room()
{
    DIMX = 0 ;
    DIMY = 0 ;
    arrayObstacle = NULL;    
}

Room::Room(int X , int Y)
{
    DIMX = X;
    DIMY = Y;
    arrayObstacle = new obstacle[DIMX*DIMY];
}

Room::~Room()
{
    if (arrayObstacle != NULL)
    {
        delete [] arrayObstacle ;
    }
    DIMX = 0;
    DIMY = 0;
    arrayObstacle = NULL;
}