#ifndef _POISON
#define _POISON

#include "Potion.h"

class Poison
{
private:
    unsigned int timeLeft
public:
    Poison(int time);
    void decreaseTime();
    void increaseTime(Potion p);
};
#endif