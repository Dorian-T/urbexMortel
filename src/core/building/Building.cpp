#include "Building.h"
#include <iostream>
#include <assert.h>
using namespace std;

Building::Building()
{
    arrayRoom = new Room[NB_ROOM];
    currentRoom = 0;
}

Building::~Building()
{
    if (arrayRoom != NULL) delete [] arrayRoom;
    arrayRoom = NULL;
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

    assert(arrayRoom != NULL && currentRoom == 0);
    cout<<"\tconstructeur par defaut : OK"<<endl;

    goToNextRoom();
    assert(currentRoom == 1);
    cout<<"\tmethode gotonextRoom : OK"<<endl;

    assert(getcurrentRoom() == &arrayRoom[1]);
    cout<<"\tmethode getcurrentRoom : OK"<<endl;

    cout << "Test de regression de la classe Building : OK" << endl;

}