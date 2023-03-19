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
    arrayObstacle.resize(DIM_ROOM_X*DIM_ROOM_Y);
    for(unsigned int i = 0; i < DIM_ROOM_X*DIM_ROOM_Y; i++)
        arrayObstacle[i] = nothing;
}

Room::Room(const std::string & filename) {
    ifstream file;
    file.open(filename);
    if(file.is_open()) {
        file >> dimX;
        file >> dimY;
        arrayObstacle.resize( dimX*dimY);        
        for(unsigned int i = 0; i < dimX*dimY; i++) {
            char tmp;
            file >> tmp;
            arrayObstacle[i] = (Obstacle)tmp;
        }
    }
    else {
        cout << "Erreur lors de l'ouverture du fichier " << filename << endl;
        cout << "Initialisation de la salle par defaut" << endl;
        dimX = DIM_ROOM_X;
        dimY = DIM_ROOM_Y;
        arrayObstacle.resize(DIM_ROOM_X*DIM_ROOM_Y);
        for(unsigned int i = 0; i < DIM_ROOM_X*DIM_ROOM_Y; i++)
            arrayObstacle[i] = nothing;
    }
    file.close();
}

unsigned int Room::getDimX() const {
    return dimX;
}

unsigned int Room::getDimY() const {
    return dimY;
}

Obstacle Room::getObstacle(const Vector2D & V) const {
    assert(V.getY() < dimY && V.getX() < dimX);
    return arrayObstacle[V.getY()*dimX + V.getX()];
}

void Room::regressionTest() {
    cout << endl << "Test de la classe Room" << endl;

    assert(dimX == DIM_ROOM_X && dimY == DIM_ROOM_Y);
    assert(arrayObstacle.capacity() == DIM_ROOM_X*DIM_ROOM_Y && arrayObstacle.size() == DIM_ROOM_X*DIM_ROOM_Y);
    for(unsigned int i = 0; i < DIM_ROOM_Y; i++)
        for(unsigned int j = 0; j < DIM_ROOM_X; j++)
            assert(arrayObstacle[j*i] == nothing);
    cout << "\tTest du constructeur par defaut : OK" << endl;

    assert(getDimX() == dimX);
    assert(getDimY() == dimY);
    cout << "\tTest de getDimX et getDimY : OK" << endl;

    assert(getObstacle(Vector2D(0, 0)) == arrayObstacle[0]);
    cout << "\tTest de getObstacle : OK" << endl;

    Room R("data/test.txt");
    Obstacle o;
    assert(R.getDimX() == 15 && R.getDimY() == 10);
    assert(R.arrayObstacle.capacity() == 15*10 && R.arrayObstacle.size() == 15*10);
    for(unsigned int i = 0; i < 10; i++)
        for(unsigned int j = 0; j < 15; j++) {
            o = (Obstacle)R.getObstacle(Vector2D(j, i));
            assert(o == nothing || o == barbedWire || o == block || o == door || o == ladder || o == trapdoor);
        }
    cout << "\tTest du constructeur depuis un fichier : OK" << endl;

    cout << "Test de la classe Room : OK" << endl;
}