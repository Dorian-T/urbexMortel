#include "Building.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

Building::Building(unsigned int nb) {
    int n;
    nbRoom = nb;
    arrayRoom.resize(nbRoom);
    arrayRoom[0] = Room("data/entrance.txt");
    for(unsigned int i = 1; i < arrayRoom.size()-1; i++) {
        n = rand() % 3;
        if(n == 0)
            arrayRoom[i] = Room("data/room1.txt");
        else if(n == 1)
            arrayRoom[i] = Room("data/room2.txt");
        else
            arrayRoom[i] = Room("data/room3.txt");
    }
    arrayRoom[arrayRoom.size()-1] = Room("data/exit.txt");
    currentRoom = 0;
}

Building::Building(std::string filename) {
    nbRoom = 1;
    arrayRoom.resize(nbRoom);
    arrayRoom[0] = Room(filename);
    currentRoom = 0;
}

Room* Building::getCurrentRoom() {
    return &arrayRoom[currentRoom];
}

unsigned int Building::getIntCurrentRoom() {
    return currentRoom;
}

void Building::goToNextRoom() {
    currentRoom++;
}

bool Building::isLastRoom() {
    if(currentRoom == nbRoom-1) return true;
    return false;
}

bool Building::finish() {
    if(isLastRoom()) return false;
    else {
        goToNextRoom();
        return true;
    }
}

void Building::regressionTest()
{
    cout << endl << "Test de regression de la classe Building" << endl;

    assert(nbRoom != 0);
    assert(arrayRoom.capacity() == nbRoom && arrayRoom.size() == nbRoom);
    assert(currentRoom == 0);
    cout<<"\tconstructeur par defaut : OK"<<endl;

    Building B("data/entrance.txt");
    assert(nbRoom == 1);
    assert(B.arrayRoom.capacity() == B.nbRoom && B.arrayRoom.size() == B.nbRoom);
    assert(B.currentRoom == 0);
    cout<<"\tconstructeur depuis un fichier : OK"<<endl;

    goToNextRoom();
    assert(currentRoom == 1);
    cout<<"\tgoToNextRoom : OK"<<endl;

    assert(getCurrentRoom() == &arrayRoom[1]);
    cout<<"\tmethode getCurrentRoom : OK"<<endl;

    cout << "Test de regression de la classe Building : OK" << endl;
}