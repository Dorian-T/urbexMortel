#include "Poison.h"

#include <iostream>

using namespace std;

Poison::Poison ()
{
    timeLeft = 600;
}

void Poison::decreaseTime ()
{
    timeLeft = timeLeft-1;
}

void Poison::increaseTime ()
{
    if (timeLeft<480)
    {
        timeLeft = timeLeft+120;
    }
    else
    {
        timeLeft = 600;
    }
}
