#ifndef _ENTITY
#define _ENTITY

#include "Vector2D.h"
/* J'ai volé se code du pacman*/
class Entity
{
private:
    Vector2D position;
    unsigned int h;
    unsigned int w;

public:
    Entity();

    Entity(Vector2D Eposition , unsigned int Eh, unsigned int Ew);

    unsigned int GetH();

    unsigned int GetW();

    Vector2D GetPosition();
};
#endif

