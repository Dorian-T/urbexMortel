#ifndef _POTION
#define _POTION

#include "Vector2D.h"

class Potion
{
private:
    Vector2D position;
    unsigned int h;
    unsigned int w;
    bool HasBeenTaken;



public:
    Potion(Vector2D V);
    
    void SetHasBeenTaken(bool b);

};
#endif