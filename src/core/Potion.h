#ifndef _POTION
#define _POTION

#include "Vector2D.h"

/**
 * @brief work in progress
 */
class Potion
{
private:
    Vector2D position;
    unsigned int h;
    unsigned int w;
    bool HasBeenTaken;

public:
    /**
     * @brief Constructeur avec paramètre de potion
     * 
     * @param V 
     */
    Potion(Vector2D V);
    
    /**
     * @brief modéfie HasBeenTaken
     * 
     * @param b 
     */
    void SetHasBeenTaken(bool b);

};
#endif