#include "../Vector2D.h"
#include "Building.h"
#include "Room.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

Room::Room() {
    dimX = DIM_ROOM_X;
    dimY = DIM_ROOM_Y;
    arrayObstacle = NULL;  
}

Room::Room(const std::string & filename) {
    ifstream file;
    file.open(filename);
    if(file.is_open()) {
        file >> dimX;
        file >> dimY;
        arrayObstacle = new Obstacle[dimX*dimY];
        for(unsigned int i = 0; i < dimX*dimY; i++) {
            int tmp;
            file >> tmp;
            arrayObstacle[i] = (Obstacle)tmp;
        }
    }
    else {
        cout << "Erreur lors de l'ouverture du fichier " << filename << endl;
        cout << "Initialisation de la salle par defaut" << endl;
        dimX = DIM_ROOM_X;
        dimY = DIM_ROOM_Y;
        arrayObstacle = NULL;
    }
}

Room::~Room() {
    if (arrayObstacle != NULL) delete [] arrayObstacle;
    arrayObstacle = NULL;
}

unsigned int Room::getDimX() const {
    return dimX;
}

unsigned int Room::getDimY() const {
    return dimY;
}

Obstacle Room::getObstacle(const Vector2D & V) const {
    return arrayObstacle[V.getY()*dimX + V.getX()];
}

// TODO : ajouter la gestion des autres obstacles
bool Room::isMovePossible(const Vector2D & Position) const {
    if(getObstacle(Position) == nothing) return true;
    else return false;
}