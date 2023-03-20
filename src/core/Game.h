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
    int actionsAutomatiques (int time);
    bool actionClavier(const char touche);          

};


#endif