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

unsigned int Vector2D::getX()
{
    return x;
}

unsigned int Vector2D::getY()
{
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

void Vector2D::displayVector()
{
    cout << "coordonnee x : " << x << endl;
    cout << "coordonnee y : " << y << endl;
}

void Vector2D::regressionTest()
{
    Vector2D V;
    assert(V.getX() == 0);
    assert(V.getY() == 0);

    Vector2D W(6,8) ;
    assert(W.getX() == 6);
    assert(W.getY() == 8);

    V.setX(42);
    V.setY(63);
    assert(V.getX() == 42);
    assert(V.getY() == 63);

    V.displayVector();
    W.displayVector();
}