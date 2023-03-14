#include "../entity/Vector2D.h"
#include "Building.h"
#include "Room.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <assert.h>
#include <unistd.h>
using namespace std;

Room::Room() {
    dimX = DIM_ROOM_X;
    dimY = DIM_ROOM_Y;
    //arrayObstacle = NULL;  
}

Room::Room(const std::string & filename) {
    ifstream file;
    file.open(filename);
    if(file.is_open()) {
        file >> dimX;
        file >> dimY;
        arrayObstacle.resize( dimX*dimY);
        //cout<<dimX<<" "<<dimY<<" "<<arrayObstacle<<endl;
        
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
        //arrayObstacle = NULL;
        arrayObstacle.resize(0);
    }
}

Room::~Room() {
    //if (arrayObstacle != NULL) delete [] arrayObstacle;
    //arrayObstacle = NULL;
    //cout<<"delete"<<endl;
    //sleep(1);
}

unsigned int Room::getDimX() const {
    return dimX;
}

unsigned int Room::getDimY() const {
    return dimY;
}

Obstacle Room::getObstacle(const Vector2D & V) const {
    assert( V.getY()*dimX + V.getX() < dimX*dimY);
    //cout<<arrayObstacle<<" "<<V.getX()<<" "<<V.getY()<<endl;
    return arrayObstacle[V.getY()*dimX + V.getX()];
}