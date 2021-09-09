/**
 * @file Game.h
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <vector>
class Game
{
public:
	
	 std::vector<Shape*> shapes;
	 void move();
	 void testCollision();
	void add(int a);
private:
	 const int MAX_X = 20;
	 const int MAX_Y = 20;
	
};

