#pragma once
class Rectangle
{
	int width, height;
public:
	Rectangle(); // can also overload constructors in c++
	Rectangle(int, int);
	//void set_values(int, int); prefer a constructor as what if area() called before this func.?

	// inline function
	int area() { return (width * height); };

	//constructors can also be inline
};

