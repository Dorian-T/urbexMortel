#ifndef _ROOM
#define _ROOM

#include "Vector2D.h"

enum obstacle {
	nothing = 0,
	barbedWire = 1,
	block = 2,
	ladder = 3,
	trapdoor = 4,
};


class Room
{
private:
    int DIMX ;
    int DIMY ;
    obstacle* arrayObstacle;
public:
    Room();

    Room(int X , int Y);

    ~Room();

    obstacle getObstacle(Vector2D V) ;
    
    bool isMovePossible(const Vector2D & Position);

};


#endif
