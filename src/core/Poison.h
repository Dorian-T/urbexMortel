#ifndef _POISON
#define _POISON

#include "Potion.h"

/**
 * @brief work in progress
 */
class Poison
{
private:
    unsigned int timeLeft;
public:
    /**
     * @brief Constructeur de poison 
     * 
     * @param time
     */
    Poison();

    /**
     * @brief réduit le temps
     * 
     */
    void decreaseTime();

    /**
     * @brief augmente le temps
     * 
     * @param p 
     */
    void increaseTime();
};
#endif