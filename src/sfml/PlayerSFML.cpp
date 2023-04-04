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

void PlayerSFML::update(float elapse) {

}