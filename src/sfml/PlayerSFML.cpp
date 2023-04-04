#include "PlayerSFML.h"

#include <iostream>

using namespace std;

PlayerSFML::PlayerSFML() {
    P = new Player();
}

PlayerSFML::~PlayerSFML() {
    if(P!=NULL)
    {
        delete P;
    }
}

void PlayerSFML::update(float elapse, Building * B) {
    if (!P->getIsFailling() && !P->standingOnBlock(B))
    {
        P->setIsFailling(true);
    }
    if (P->getIsFailling() && P->standingOnBlock(B))
    {
        P->setIsFailling(false);
    }
    if(P->getIsMoving()) {
        if(P->getDirection()) {P->right(B);}
        else{P->left(B);}
    }

}