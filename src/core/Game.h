#ifndef _GAME
#define _GAME

#include "building/Building.h"
#include "entity/Player.h"

class Game
{

private :

    /**
     * @brief Pointeur vers le batiment
     */
	Building * bui;

    /**
     * @brief Pointeur vers le joueur
     */
	Player * pla;

public :

    /**
     * @brief Constructeur par defaut
     */
    Game ();

    /**
     * @brief Destructeur
     */
    ~Game();

    /**
     * @brief Accesseur vers le batiment
     * 
     * @return Building*
     */
    Building * getBuilding() const;

    /**
     * @brief Accesseur vers le joueur
     * 
     * @return Player* 
     */
    Player * getPlayer () const;

    /**
     * @brief Fonction qui gère les actions automatiques
     * 
     * @param time 
     * @return int 
     */
    int actionsAutomatiques (int time);

    /**
     * @brief Fonction qui gère les actions du clavier
     * 
     * @param touche 
     * @return bool 
     */
    bool actionClavier(const char touche);

};


#endif