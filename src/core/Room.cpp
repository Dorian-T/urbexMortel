#include "Vector2D.h"
#include "Room.h"
#include <iostream>

Room::Room() {
    dimX = 0;
    dimY = 0;
    arrayObstacle = NULL;  
}

Room::Room(int X , int Y) {
    dimX = X;
    dimY = Y;
    arrayObstacle = new Obstacle[dimX*dimY];
}

Room::~Room() {
    if (arrayObstacle != NULL) delete [] arrayObstacle;
    arrayObstacle = NULL;
}

Obstacle Room::getObstacle(Vector2D V) {
    return arrayObstacle[V.getX()*dimX + V.getY()];
}

bool Room::isMovePossible(const Vector2D & Position) {
    // TODO
}

Vector2D* Room::pixelToCell(const Vector2D & Pixel) {
    // TODO
}