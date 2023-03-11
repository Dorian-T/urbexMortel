#ifndef _GAME
#define _GAME

#include "Building.h"
#include "Player.h"

class Game
{

private :

	Building bui;
	Player pla;


public :

    Game ();

    const Building& getBuilding() const;                      
    const Player& getPlayer () const;                                                     
    void actionsAutomatiques ();
    void actionClavier(const char touche);          

};


#endif