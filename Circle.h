/**
 * @file Circle.h
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
/**
*  Definition of a class defining a Circle object derived from a Shape object.
*/
#pragma once
#include "Shape.h"
class Square;
class Circle :
    public Shape
{
public:
    Circle(int x, int y, int radius);
    Circle();
    int getRadius();
    void setRadius(int radius);
    bool Collision(Circle* c);
    bool Collision(Square* s);
    

private:
    int radius;
};


