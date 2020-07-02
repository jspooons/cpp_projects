#include "Rectangle.h"

Rectangle::Rectangle() {
	width = 5;
	height = 5;
}

Rectangle::Rectangle(int a, int b)
{
	width = a;
	height = b;
}

//different ways of creating constructors with use of member intitialisation
//Rectangle::Rectangle (int x, int y) : width(x) { height=y;}
//Rectangle::Rectangle (int x, int y) : width(x), height(y) { }

//member objects must be member initialised (after : and before { }, otherwise default constructor called regardless, then what if there is no default constructor in that class?)
