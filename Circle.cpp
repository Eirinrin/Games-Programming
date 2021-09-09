/**
 * @file Circle.cpp
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
 /**
 * Implementation of Circle.h
 */
#include "Circle.h"
#include <iostream>
#include "Math.h"
#include <algorithm>
#include "Square.h"
using namespace std;

/** Parameterised constructor for the Circle object
*/
Circle::Circle(int x, int y, int radius) : Shape(x, y) {
    setRadius(radius);
}
/** Default constructor for the Circle object
*/
Circle::Circle() {
    setRadius(1);
}
// accessors for the radius
int Circle::getRadius() { return radius; }
void Circle::setRadius(int radius) { this->radius = radius; }

/**Determine wether two Circle objects overlap
*
* @param c second circle tested for collision
*/
bool Circle:: Collision(Circle* c) {
    int dx = getX() - c->getX();
    int dy = getY() - c->getY();
    int dist = sqrt(dx * dx + dy * dy);         //compute the ditance between the two circles' centre points
    if (dist < getRadius() + c->getRadius()) {   //if dist is smaller than the sum of the two radii, the circles are colliding
        return true;
    }


}
/**Determine wether a Circle object overlaps a Square object
*
* @param s Square tested for collision
*/
bool Circle::Collision(Square* s) {
    int square_center_x = s->getX() + s->getWidth() / 2;          //calculate the x coord of the square's center
    int square_center_y = s->getY() + s->getWidth() / 2;         //calculate the y coord of the square's center
    if (square_center_x == 0 && square_center_y == 0) {         //if the square is at the origin,test for collision 
        int dx = min(getX(), (int)(s->getWidth() * .5));
        int dx1 = max(dx, (int)(-s->getWidth() * .5));
        int dy = min(getY(), (int)(s->getWidth() * .5));
        int dy1 = max(dy, (int)(-s->getWidth() * .5));
        return(dx1 - getX()) * (dx1 - getX()) +
            (dy1 - getY()) * (dy1 - getY()) <= getRadius() * getRadius();
    }
    else {                                                      //if the square is not at origin, move it there and test for collision
        setX(getX() - square_center_x);
        setY(getY() - square_center_y);
        int dx = min(getX(), (int)(s->getWidth() * .5));
        int dx1 = max(dx, (int)(-s->getWidth() * .5));
        int dy = min(getY(), (int)(s->getWidth() * .5));
        int dy1 = max(dy, (int)(-s->getWidth() * .5));
        return(dx1 - getX()) * (dx1 - getX()) +
            (dy1 - getY()) * (dy1 - getY()) <= getRadius() * getRadius();
    }
}
/**To test sphere-sphere collision, we'd check
*the distance between the spheres' centers is <= the sum of the radii.
*/