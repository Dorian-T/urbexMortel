#include "Vector2D.h"

#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(unsigned int Vx , unsigned int Vy) {
    x = Vx;
    y = Vy;
}

unsigned int Vector2D::getX() const {
    return x;
}

unsigned int Vector2D::getY() const {
    return y;
}

void Vector2D::setX(unsigned int Vx) {
    x = Vx;
}

void Vector2D::setY(unsigned int Vy) {
    y = Vy;
}

Vector2D Vector2D::operator+(const Vector2D & V) const {
    return Vector2D(x + V.x, y + V.y);
}

float Vector2D::distance(const Vector2D & V) const {
    return sqrt(pow(x - V.x, 2) + pow(y - V.y, 2));
}

void Vector2D::regressionTest() {
    cout << endl << "Test de la classe Vector2D" << endl;

    assert(x == 0 && y == 0);
    cout << "\tconstructeur par defaut : OK" << endl;

    Vector2D V(6,8);
    assert(V.x == 6 && V.y == 8);
    cout << "\tconstructeur parametre : OK" << endl;

    assert(V.getX() == 6 && V.getY() == 8);
    cout << "\tgetX et getY : OK" << endl;

    V.setX(3); V.setY(4);
    assert(V.x == 3 && V.y == 4);
    cout << "\tsetX et setY : OK" << endl;

    Vector2D W(1, 2);
    assert((V + W).x == 4 && (V + W).y == 6);
    cout << "\toperateur + : OK" << endl;

    assert(V.distance(W) == (float) sqrt(8));
    cout << "\tdistance : OK" << endl;

    cout << "Test de la classe Vector2D : OK" << endl;
}