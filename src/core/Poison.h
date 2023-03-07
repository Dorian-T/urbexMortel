#ifndef _POISON
#define _POISON

#include "Potion.h"

class Poison
{
private:
    unsigned int timeLeft;
public:
    /**
     * @brief Constructeur de poison avec paramètre
     * 
     * @param time 
     */
    Poison(int time);

    /**
     * @brief réduit le temps de 1
     * 
     */
    void decreaseTime();

    /**
     * @brief augmente le temps
     * 
     * @param p 
     */
    void increaseTime(Potion p);
};
#endif