#include "Building.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h> 
#include <time.h> 
using namespace std;

Building::Building()
{
    int aleatoire;
    int min = 1, max = 3;
    int nombreDeValeurs = max - min + 1 ;
    srand((unsigned int)time(NULL));
    arrayRoom = new Room[NB_ROOM];
    string f="../../daty/entry.txt";
    arrayRoom[0]= Room(f);
    unsigned int i;
    for(i=1;i<NB_ROOM;i++)
    {
        aleatoire = (rand() % nombreDeValeurs) + min;
        f="../../daty/room" + aleatoire ;
        f= f + ".txt";
        arrayRoom[i]=f;
    }
    f="../../daty/exit.txt";
    arrayRoom[NB_ROOM]=f;
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