#include "Building.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

Building::Building(unsigned int nb) {
    int n;
    Nb_ROOM=nb;
    arrayRoom.resize(Nb_ROOM);
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
    if(currentRoom ==Nb_ROOM-1) return true;
    return false;
}

void Building::regressionTest()
{
    cout << endl << "Test de regression de la classe Building" << endl;

    assert(arrayRoom.capacity() == Nb_ROOM && arrayRoom.size() == Nb_ROOM);
    assert(currentRoom == 0);
    cout<<"\tconstructeur par defaut : OK"<<endl;

    goToNextRoom();
    assert(currentRoom == 1);
    cout<<"\tgoToNextRoom : OK"<<endl;

    assert(getCurrentRoom() == &arrayRoom[1]);
    cout<<"\tmethode getCurrentRoom : OK"<<endl;

    cout << "Test de regression de la classe Building : OK" << endl;
}