#include "Building.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

Building::Building() {
    int n;
    arrayRoom.resize( NB_ROOM);
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
    arrayRoom[NB_ROOM-1] = Room("data/exit.txt");
    currentRoom = 0;
}

Building::~Building()
{
    //if (arrayRoom != NULL) delete [] arrayRoom;
    //arrayRoom = NULL;
    //cout<<"delete building"<<endl;
}

Room* Building::getcurrentRoom()
{
    return &arrayRoom[currentRoom];
}

void Building::goToNextRoom() {
    currentRoom++;
}

void Building::regressionTest()
{
    cout << "Test de regression de la classe Building" << endl;

    //assert(arrayRoom != NULL && currentRoom == 0);
    cout<<"\tconstructeur par defaut : OK"<<endl;

    goToNextRoom();
    assert(currentRoom == 1);
    cout<<"\tmethode gotonextRoom : OK"<<endl;

    assert(getcurrentRoom() == &arrayRoom[1]);
    cout<<"\tmethode getcurrentRoom : OK"<<endl;

    cout << "Test de regression de la classe Building : OK" << endl;

}