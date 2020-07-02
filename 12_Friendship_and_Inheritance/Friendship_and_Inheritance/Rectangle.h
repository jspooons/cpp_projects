#pragma once

#include "Square.h"

class Rectangle
{
	int width, height;
public:
	int area() { return width * height; }
	friend Rectangle duplicate(const Rectangle&);
	void convert(Square a);
};

