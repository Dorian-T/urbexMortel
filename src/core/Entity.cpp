#include <iostream>

#include "Vector2D.h"
#include "Entity.h"

Entity::Entity()
{
    position = Vector2D(0,0);
    h = 0;
    w = 0;
}

Entity::Entity(Vector2D Eposition , unsigned int Eh, unsigned int Ew)
{
    position = Eposition;
    h = Eh;
    Ew = w;
}

unsigned int Entity::GetH()
{
    return h;
}

unsigned int Entity::GetW()
{
    return w;
}


Vector2D Entity::GetPosition()
{
    return position;
}
