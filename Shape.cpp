/**
 * @file Shape.cpp
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
 /**
 * Implementation of Shape.h
 */
#include "Shape.h"
Shape::Shape(int x, int y) {
	moveTo(x, y);
}
Shape::Shape() {
	moveTo(0, 0);
}

// accessors for x & y
int Shape::getX() { return x; }
int Shape::getY() { return y; }
void Shape::setX(int x) { this->x = x; }
void Shape::setY(int y) { this->y = y; }

/*Teleport the shape in 2D space
* 
* @param newx x coordinate of new position
* @param newy y coordinate of the new position
*/
void Shape::moveTo(int newx, int newy) {
	setX(newx);
	setY(newy);
}
/*Move the shape in 2D space by an amount
*
* @param deltax distance to move the x coordinate 
* @param deltay distance to move the y coordinate of the new position
*/
void Shape::rMoveTo(int deltax, int deltay) {
	moveTo(getX() + deltax, getY() + deltay);
}


/*To expand the functionality to 3D objects,
*a z coordinate would also be stored 
*moveTo() and rMoveTo() would also be modified to accomodate the aditional atribute.
*/

