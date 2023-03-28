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
        n = rand() % 4;
        if(n == 0)
            arrayRoom[i] = Room("data/room1.txt");
        else if(n == 1)
            arrayRoom[i] = Room("data/room2.txt");
        else if(n==2)
            arrayRoom[i] = Room("data/room3.txt");
        else
            arrayRoom[i] = Room("data/room4.txt");
    }
    arrayRoom[arrayRoom.size()-1] = Room("data/exit.txt");
    currentRoom = 0;
    for(unsigned int i=0;i<arrayRoom.size();i++) {timetot+=arrayRoom[i].getTime();}
}

Building::Building(string filename) {
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

unsigned int Building::getNbRoom() {
    return nbRoom;
}

bool Building::finishRoom() {
    if(currentRoom == nbRoom-1) return false;
    else {
        currentRoom++;
        return true;
    }
}

unsigned int Building::getTimetot() {
    return timetot;
}

void Building::setTimetot(unsigned int t) {
    timetot = t;
}

void Building::regressionTest()
{
    cout << endl << "Test de regression de la classe Building" << endl;

    assert(nbRoom != 0);
    assert(arrayRoom.capacity() == nbRoom && arrayRoom.size() == nbRoom);
    assert(currentRoom == 0);
    cout << "\tconstructeur par defaut : OK" << endl;

    Building B("data/test.txt");
    assert(B.nbRoom == 1);
    assert(B.arrayRoom.capacity() == B.nbRoom && B.arrayRoom.size() == B.nbRoom);
    assert(B.currentRoom == 0);
    cout << "\tconstructeur depuis un fichier : OK" << endl;

    finishRoom();
    assert(currentRoom == 1);
    cout << "\tgoToNextRoom : OK" << endl;

    assert(getCurrentRoom() == &arrayRoom[1]);
    cout << "\tmethode getCurrentRoom : OK" << endl;

    cout << "Test de regression de la classe Building : OK" << endl;
}