#ifndef _PLAYERSFM
#define _PLAYERSFM

#include "../core/entity/Player.h"

class PlayerSFML
{
private:
  Player * P;  
public:
    /**
     * @brief Constructeur par défaut 
     * 
     */
    PlayerSFML();

    /**
     * @brief Destructeur
     * 
     */
    ~PlayerSFML();

    /**
     * @brief fonction permettant de déplacer le joueur
     * 
     * @param elapse 
     */
    void update(float elapse);
};

#endif