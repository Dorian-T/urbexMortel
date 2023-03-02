#ifndef _PLAYER
#define _PLAYER

#include "Entity.h"
#include "Room.h"

class Player : public Entity
{
private:
    bool gender;
    unsigned int hp;
public:
    Player(unsigned int Pgender, unsigned int Php);
    ~Player();

    void up(const Room & R) ;
    void right(const Room & R) ;
    void down(const Room & R) ;
    void left(const Room & R) ;

};

#endif
