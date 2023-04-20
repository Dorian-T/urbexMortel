#include "Building.h"

#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <string>
#include <time.h> 

using namespace std;

const int NB_DIFFERENT_ROOM = 6;

Building::Building(unsigned int nb) {
    int n;
    string s;
    nbRoom = nb + 2;
    arrayRoom.resize(nbRoom);
    arrayRoom[0] = Room(PATH_ROOMS + "entrance.txt");
    for(unsigned int i = 0; i < nb; i++) {
        n = rand() % NB_DIFFERENT_ROOM + 1;
        s = PATH_ROOMS + "room" + to_string(n) + ".txt";
        arrayRoom[i+1] = Room(s);
    }
    arrayRoom[nbRoom-1] = Room(PATH_ROOMS + "exit.txt");
    currentRoom = 0;
    for(unsigned int i = 0; i < nbRoom; i++)
        totalTime += arrayRoom[i].getTime();
}

Building::Building(const string & filename) {
    nbRoom = 1;
    arrayRoom.resize(nbRoom);
    arrayRoom[0] = Room(filename);
    currentRoom = 0;
    totalTime = arrayRoom[0].getTime();
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

unsigned int Building::getTotalTime() {
    return totalTime;
}

void Building::setTotalTime(unsigned int t) {
    totalTime = t;
}

bool Building::finishRoom() {
    if(currentRoom == nbRoom-1) return false;
    else {
        currentRoom++;
        return true;
    }
}

void Building::regressionTest()
{
    cout << endl << "Test de la classe Building" << endl;

    assert(nbRoom == 3);
    assert(arrayRoom.capacity() == nbRoom && arrayRoom.size() == nbRoom);
    assert(currentRoom == 0);
    assert(totalTime != 0);
    cout << "\tconstructeur parametre : OK" << endl;

    Building B(PATH_ROOMS + "test.txt");
    assert(B.nbRoom == 1);
    assert(B.arrayRoom.capacity() == B.nbRoom && B.arrayRoom.size() == B.nbRoom);
    assert(B.currentRoom == 0);
    assert(B.totalTime == 1000);
    cout << "\tconstructeur depuis un fichier : OK" << endl;

    assert(getCurrentRoom() == &arrayRoom[currentRoom]);
    cout << "\tgetCurrentRoom : OK" << endl;

    assert(getIntCurrentRoom() == currentRoom);
    cout << "\tgetIntCurrentRoom : OK" << endl;

    assert(getNbRoom() == nbRoom);
    cout << "\tgetNbRoom : OK" << endl;

    assert(getTotalTime() == totalTime);
    cout << "\tgetTotalTime : OK" << endl;

    setTotalTime(20);
    assert(totalTime == 20);
    cout << "\tsetTotalTime : OK" << endl;

    assert(finishRoom());
    assert(currentRoom == 1);
    finishRoom();
    assert(!finishRoom());
    cout << "\tfinishRoom : OK" << endl;

    cout << "Test de la classe Building : OK" << endl;
}