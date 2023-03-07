#include <iostream>

#include "Building.h"

Building::Building()
{
    arrayRoom=NULL;
    currentRoom=0;
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

void Building::gotonextRoom()
{
    currentRoom++;
}

void Building::regressionTest()
{
    cout << "Test de non-regression de la classe Building" << endl;
    
}