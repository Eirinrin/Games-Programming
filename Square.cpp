/**
 * @file Square.cpp
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
 /**
 * Implementation of Square.h
 */
#include "Square.h"
#include <iostream>
#include <algorithm>
#include "Circle.h"

using namespace std;
/** Parameterised constructor for the Square object
*/
 Square::Square(int x, int y, int width) : Shape(x, y) {
    setWidth(width);
    
}
 /** Default constructor for the Square object
*/
 Square::Square() {
     setWidth(1);
     
 }

// accessors for width and height
int Square::getWidth() { return Square::width; }
void Square::setWidth(int width) { this->width= width; }

/**Determine wether two Square objects overlap
* 
* @param s second square tested for collision
*/
bool Square::Collision(Square* s) {
    if (getX() < s->getX() + s->getWidth() &&
        getX() + getWidth() > s->getX() &&
        getY() < s->getY() + s->getWidth() &&
        getY() + getWidth() > s->getY()
        )
        return true;
}

/**Determine wether a Square object overlaps a Circle object
*
* @param c Circle tested for collision
*/
bool Square::Collision(Circle* c) {

        int square_center_x = getX() + getWidth() / 2;          //calculate the x coord of the square's center
        int square_center_y = getY() + getWidth() / 2;          //calculate the y coord of the square's center
        if (square_center_x == 0 && square_center_y == 0) {     //if the square is at the origin,test for collision
            int dx = min(c->getX(), (int)(getWidth() * .5));
            int dx1 = max(dx, (int)(-getWidth() * .5));
            int dy = min(c->getY(), (int)(getWidth() * .5));
            int dy1 = max(dy, (int)(-getWidth() * .5));
            return(dx1 - c->getX()) * (dx1 - c->getX()) +
                (dy1 - c->getY()) * (dy1 - c->getY()) <= c->getRadius() * c->getRadius();
        }
        else {                                                  //if the square is not at origin, move it there and test for collision
            c->setX( c->getX() - square_center_x);
            c->setY(c->getY() - square_center_y);
            int dx = min(c->getX(), (int)(getWidth() * .5));
            int dx1 = max(dx, (int)(-getWidth() * .5));
            int dy = min(c->getY(), (int)(getWidth() * .5));
            int dy1 = max(dy, (int)(-getWidth() * .5));
            return(dx1 - c->getX()) * (dx1 - c->getX()) +
                (dy1 - c->getY()) * (dy1 - c->getY()) <= c->getRadius() * c->getRadius();
        }


}
/**To test cube-cube collision every axis would have to be tested.
*e.g. over the X-axis, do the ranges AminX–AmaxX and BminX–BmaxX overlap?
*/
/**To test cube-sphere collision, the distance between the closest point of the cube to the sphere 
would be compared to the radius, if it is smaller then the objects are colliding.
The closest point's coordinates are defined as max(cube.minX, min(sphere.x, cube.maxX).
*
*/

