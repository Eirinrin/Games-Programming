/**
 * @file Game.cpp
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
 /**
 * Implementation of Game.h
 */
#include "Game.h"
#include <iostream>
#include "assert.h"
#include <ctime>;
bool collides=false;
/**Populate the shapes vector with radom shapes of random atributes.
* @param a size on shapes vector
*/
void Game::add(int a) {
	shapes.clear();//new random values every run
	srand((int)time(0));
	for(int i = 0;i<=a;i++){
		
	shapes.push_back
	(rand()%10 >5 ? 
			dynamic_cast<Shape*>(new Circle(rand()%21, rand()%21, rand()%21)) : dynamic_cast<Shape*>(new Square(rand()%21, rand()%21, rand()%21)));
	}
}
/**Move the shapes a random amount within a 20x20 grid
*/
void Game::move() {
	srand((int)time(0));//new random values every run
	for (std::size_t i = 0; i < shapes.size(); ++i) {
		int a = rand() % 21;
		int b = rand() % 21;
		shapes[i]->moveTo (a, b); 
		if (shapes[i]->getX() > MAX_X) {
			shapes[i]->rMoveTo(MAX_X - shapes[i]->getX(), 0);
		}
		if (shapes[i]->getY() > MAX_Y) {
			shapes[i]->rMoveTo(0,  MAX_Y - shapes[i]->getY()  );
		}
	}
}

/**Test every two shapes for overllaping and remove the ones that are
*/
void Game::testCollision() {
	for (std::size_t i = 0; i < shapes.size(); ++i) {							// iterate over all the shapes
		if (Square* square = dynamic_cast<Square*>(shapes[i]))					//check if first shape is square
		{
			if (Square* square2 = dynamic_cast<Square*>(shapes[i + 1])) {		//check if next shape is also square
				collides = square->Collision(square2);							//call square-square Collision() for 2 squares
				if (collides) {
					std::cout << "Square(x= " << square->getX() << ",y= " << square->getY() << ",width= " << square->getWidth()
						<< ") was overlapping \nSquare(x= " << square2->getX() << ",y= " << square2->getY() << ",width= " << square2->getWidth() << ")and they were removed.\n" << std::endl;
					shapes.erase(shapes.begin() + i + 1);
					shapes.erase(shapes.begin() + i);
				}
				
			}
			else if (Circle* circle = dynamic_cast<Circle*>(shapes[i + 1])) {	//if next shape wasn't square, check if it is circle. While thsi check may seem redundant, it makes easier to expand the program to more shapes.
				collides = square->Collision(circle);							//call square-circle Collision()  
				if (collides) {
					std::cout << "Square(x= " << square->getX() << ",y= " << square->getY() << ",width= " << square->getWidth()
						<< ") was overlapping \nCircle(x= " << circle->getX() << ",y= " << circle->getY() << ",radius= " << circle->getRadius() << ") and they were removed.\n" << std::endl;
					shapes.erase(shapes.begin() + i + 1);
					shapes.erase(shapes.begin() + i);
				}
			}
			 
		}
		else if (Circle* circle = dynamic_cast<Circle*>(shapes[i])) {			//if first shape wasn't square, check if it is circle	
			if (Circle* circle2 = dynamic_cast<Circle*>(shapes[i + 1])) {		//check if second shape is circle
				collides = circle->Collision(circle2);							//call circle-circle Collision()
				if (collides) {
					std::cout << "Circle(x= " << circle->getX() << ",y= " << circle->getY() << ",radius= " << circle->getRadius()
						<< ") was overlapping \nCircle(x= " << circle2->getX() << ",y= " << circle2->getY() << ",radius= " << circle2->getRadius() << ") and they were removed.\n"<<std::endl;
					shapes.erase(shapes.begin() + i + 1);
					shapes.erase(shapes.begin() + i);
				}
			}
			else if (Square* square = dynamic_cast<Square*>(shapes[i + 1])) {	//if second shape wasn't circle, check if it is square
				collides = circle->Collision(square);							//call circle-square Collision()
				if (collides) {
					std::cout << "Circle(x= " << circle->getX() << ",y= " << circle->getY() << ",radius= " << circle->getRadius()
						<< ") was overlapping\n Square(x= " << square->getX() << ",y= " << square->getY() << ",width= " << square->getWidth() << ") and they were removed.\n" << std::endl;
					shapes.erase(shapes.begin() + i + 1);
					shapes.erase(shapes.begin() + i);
					
				}
			}
		}
		
	}
}

int main() {
	Game g;
	g.add(10);
	g.move();
	g.testCollision();
}
