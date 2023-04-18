#include "Room.h"
#include "../entity/Vector2D.h"
#include "Building.h"

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <unistd.h>

using namespace std;


Room::Room() {
    dimX = DIM_ROOM_X;
    dimY = DIM_ROOM_Y;
    time = 0;
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
        file >> time;
        arrayObstacle.resize( dimX*dimY);
        char tmp;
        for(unsigned int y = 0; y < dimY; y++)
            for(unsigned int x = 0; x < dimX; x++) {
                file >> tmp;
                if(tmp == 'R') {
                    arrayRat.push_back(Vector2D(x, y));
                    tmp = '.';
                }
                if(tmp == 'S') {
                    arraySpider.push_back(Vector2D(x, y));
                    tmp = '.';
                }
                arrayObstacle[y*dimX + x] = (Obstacle)tmp;
            }
    }
    else {
        cout << "Erreur lors de l'ouverture du fichier " << filename << endl;
        cout << "Initialisation de la salle par defaut" << endl;
        dimX = DIM_ROOM_X;
        dimY = DIM_ROOM_Y;
        time = 0;
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

void Room::setObstacle(const Vector2D & V, Obstacle o) {
    assert(V.getY() < dimY && V.getX() < dimX);
    arrayObstacle[V.getY()*dimX + V.getX()] = o;
}

unsigned int Room::getTime() const {
    return time;
}

unsigned int Room::getNbRat() const {
    return arrayRat.size();
}

Vector2D* Room::getRat(unsigned int i) {
    assert(i < arrayRat.size());
    return &arrayRat[i];
}

unsigned int Room::getNbSpider() const {
    return arraySpider.size();
}

Vector2D* Room::getSpider(unsigned int i) {
    assert(i < arraySpider.size());
    return &arraySpider[i];
}

void Room::regressionTest() {
    cout << endl << "Test de la classe Room" << endl;

    assert(dimX == DIM_ROOM_X && dimY == DIM_ROOM_Y);
    assert(arrayObstacle.capacity() == DIM_ROOM_X*DIM_ROOM_Y && arrayObstacle.size() == DIM_ROOM_X*DIM_ROOM_Y);
    assert(time == 0);
    for(unsigned int i = 0; i < DIM_ROOM_Y; i++)
        for(unsigned int j = 0; j < DIM_ROOM_X; j++)
            assert(arrayObstacle[j*i] == nothing);
    cout << "\tTest du constructeur par defaut : OK" << endl;

    assert(getDimX() == dimX);
    assert(getDimY() == dimY);
    cout << "\tTest de getDimX et getDimY : OK" << endl;

    assert(getObstacle(Vector2D(0, 0)) == arrayObstacle[0]);
    cout << "\tTest de getObstacle : OK" << endl;

    assert(getTime() == 0);
    cout << "\tTest de getTime : OK" << endl;

    assert(getNbRat() == 0);
    cout << "\tTest de getNbRat : OK" << endl;

    Room R(PATH_ROOMS + "test.txt");
    Obstacle o;
    assert(R.getDimX() == 6 && R.getDimY() == 9);
    assert(R.arrayObstacle.capacity() == 6*9 && R.arrayObstacle.size() == 6*9);
    assert(R.getTime() == 1000);
    for(unsigned int i = 0; i < 9; i++)
        for(unsigned int j = 0; j < 6; j++) {
            o = (Obstacle)R.getObstacle(Vector2D(j, i));
            assert(o == nothing || o == barbedWire || o == block || o == door || o == ladder || o == trapdoor);
        }
    assert(R.getNbRat() == 1); assert(R.getRat(0)->getX() == 1 && R.getRat(0)->getY() == 1);
    cout << "\tTest du constructeur depuis un fichier : OK" << endl;
    cout << "\tTest de getRat : OK" << endl;

    R.setObstacle(Vector2D(0, 0), ladder);
    assert(R.getObstacle(Vector2D(0, 0)) == ladder);
    cout << "\tTest de setObstacle : OK" << endl;

    cout << "Test de la classe Room : OK" << endl;
}