#include <iostream>
#include <assert.h>
#include "Vector2D.h"


using namespace std;

Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(unsigned int Vx , unsigned int Vy)
{
    x = Vx;
    y = Vy;
}

unsigned int Vector2D::getX() const {
    return x;
}

unsigned int Vector2D::getY() const {
    return y;
}

void Vector2D::setX(unsigned int Vx)
{
    x = Vx;
}

void Vector2D::setY(unsigned int Vy)
{
    y = Vy;
}

void Vector2D::regressionTest() {
    cout << endl << "Test de la classe Vector2D" << endl;

    assert(x == 0 && y == 0);
    cout << "\tconstructeur par defaut : OK" << endl;

    Vector2D V(6,8);
    assert(V.x == 6 && V.y == 8);
    cout << "\tconstructeur parametre : OK" << endl;

    assert(V.getX() == 6 && V.getY() == 8);
    cout << "\taccesseurs : OK" << endl;

    V.setX(42); V.setY(63);
    assert(V.x == 42 && V.y == 63);
    cout << "\tmodificateurs : OK" << endl;

    cout << "Test de la classe Entity : OK" << endl;
}