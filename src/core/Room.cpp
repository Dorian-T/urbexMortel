#include "Vector2D.h"
#include "Building.h"
#include "Room.h"
#include <iostream>

Room::Room() {
    dimX = 0;
    dimY = 0;
    arrayObstacle = NULL;  
}
/* en haut avec les constantes et en bas sup*/
Room::Room(int X , int Y) {
    dimX = X;
    dimY = Y;
    arrayObstacle = new Obstacle[dimX*dimY];
}

Room::~Room() {
    if (arrayObstacle != NULL) delete [] arrayObstacle;
    arrayObstacle = NULL;
}

Obstacle Room::getObstacle(const Vector2D & V) const {
    return arrayObstacle[V.getX()*dimX + V.getY()];
}

// TODO : ajouter la gestion des autres obstacles
bool Room::isMovePossible(const Vector2D & Position) const {
    if(getObstacle(Position) == nothing) return true;
    else return false;
}

Vector2D* Room::pixelToCell(const Vector2D & Pixel) const {
    Vector2D* V = new Vector2D(Pixel.getX()*DIM_ROOM_X/PIXEL_ROOM_X, Pixel.getY()*DIM_ROOM_Y/PIXEL_ROOM_Y);
    return V;
}