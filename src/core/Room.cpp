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

obstacle Room::getObstacle(Vector2D V)
{
    
}

bool Room::isMovePossible(const Vector2D & Position)
{

}

Vector2D* Room::pixelToCell(const Vector2D & Pixel)
{

}