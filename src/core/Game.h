#ifndef _GAME
#define _GAME

#include "building/Building.h"
#include "entity/Player.h"

/**
 * @brief Classe représentant le jeu
 */
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
     * @brief Constructeur par défaut
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
     * @brief Réalisation des actions automatiques
     * 
     * @param time 
     * @return int 
     */
    int automaticAction (int time);

    /**
     * @brief Redistribution des actions clavier vers les fonctions de déplacement
     * 
     * @param touche
     * @return bool
     */
    bool keyboardAction (const char touche);
};

#endif