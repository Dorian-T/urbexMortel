#include "../Vector2D.h"
#include "Entity.h"
#include <iostream>
#include <assert.h>
using namespace std;

Entity::Entity() {
    position = Vector2D(0, 0);
    height = 0;
    width = 0;
}

Entity::Entity(const Vector2D & p, unsigned int h, unsigned int w) {
    position = p;
    height = h;
    width = w;
}

unsigned int Entity::getHeight() const {
    return height;
}

unsigned int Entity::getWidth() const {
    return width;
}

Vector2D Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const Vector2D & p) {
    position = p; //mettre un assert pour verifier que la position est dans la room ?
}

void Entity::up(const Room & R) {}

void Entity::right(const Room & R) {}

void Entity::down(const Room & R) {}

void Entity::left(const Room & R) {}

void Entity::gravity(const Room & R) {}

void Entity::regressionTest() {
    cout << endl << "Test de la classe Entity" << endl;

    assert(position.getX() == 0 && position.getY() == 0 && height == 0 && width == 0);
    cout << "\tconstructeur par defaut : OK" << endl;

    Entity e(Vector2D(1, 2), 3, 4);
    assert(e.position.getX() == 1 && e.position.getY() == 2 && e.height == 3 && e.width == 4);
    cout << "\tconstructeur parametre : OK" << endl;

    assert(e.getPosition().getX() == 1 && e.getPosition().getY() == 2); assert(e.getHeight() == 3); assert(e.getWidth() == 4);
    cout << "\taccesseurs : OK" << endl;

    cout << "Test de la classe Entity : OK" << endl;
}