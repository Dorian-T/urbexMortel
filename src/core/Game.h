#ifndef _GAME
#define _GAME

#include "building/Building.h"
#include "entity/Player.h"

class Game
{

private :

	Building * bui;
	Player * pla;


public :

    Game ();
    ~Game();

    Building * getBuilding() const;                      
    Player * getPlayer () const;                                                     
    void actionsAutomatiques ();
    void actionClavier(const char touche);          

};


#endif