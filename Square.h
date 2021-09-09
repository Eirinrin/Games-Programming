/**
 * @file Square.h
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
 /**
 *  Definition of a class defining a Square object derived from a Shape object.
 */
#pragma once
#include "Shape.h"
class Circle;
class Square :
    public Shape
{
    public:
        Square(int x, int y, int width);
        Square();
        int getWidth();
        void setWidth(int newwidth);
        bool Collision(Square* s);
        bool Collision(Circle* c);

    private:
        int width;
      

};

/**To expand the functionality to support cubes,
*min-max coordinates would also be stored.
*
*/