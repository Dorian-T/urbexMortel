#include "Vector2D.h"
#include "Entity.h"
#include <iostream>
#include <cassert>
using namespace std;

Entity::Entity() {
    position = Vector2D(0, 0);
    h = 0;
    w = 0;
}

Entity::Entity(Vector2D Eposition , unsigned int Eh, unsigned int Ew) {
    position = Eposition;
    h = Eh;
    w = Ew;
}

unsigned int Entity::getH() {
    return h;
}

unsigned int Entity::getW() {
    return w;
}

Vector2D Entity::getPosition() {
    return position;
}

void Entity::regressionTest() {
    cout << "Test de non-regression de la classe Entity" << endl;
    assert(position.getX() == 0 && position.getY() == 0 && h == 0 && w == 0);
    cout << "\tconstructeur par defaut : OK" << endl;
    Entity e = Entity(Vector2D(1, 2), 3, 4);
    assert(e.position.getX() == 1 && e.position.getY() == 2 && e.h == 3 && e.w == 4);
    cout << "\tconstructeur parametre : OK" << endl;
    assert(e.getPosition.getX() == 1 && e.getPosition.getY() == 2); assert(e.getH() == 3); assert(e.getW == 4);
    cout << "\taccesseurs : OK" << endl;
    cout << "Test de non-regression de la classe Entity : OK" << endl;
}