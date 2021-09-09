/**
 * @file Shape.h
 *
 * @author Andreea Elena Velea
 * Student Number:b7075007
 *
 */
 /**
 *  Definition of a class defining a Square object that stores x,y coordinates.
 */
#pragma once
class Shape
{
	

	public:
		Shape(int x, int y);
		Shape();
		int getX();
		int getY();
		void setX(int newx);
		void setY(int newy);
		void moveTo(int newx, int newy);
		void rMoveTo(int deltax, int deltay);
		virtual bool Collision() { return false; }
		
		
		
	private:
		int x;
		int y;
	};


