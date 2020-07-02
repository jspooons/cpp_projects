#pragma once

#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
    int width, height;
public:
    Rectangle(int x, int y) : width(x), height(y) {}
    Rectangle() = default;
    Rectangle(const Rectangle & other) = delete;
    int area() { return width * height; }
};

// Here, Rectangle can be constructed either with two int 
// arguments or be default-constructed (with no arguments).
// It cannot however be copy-constructed from another 
// Rectangle object, because this function has been deleted. 

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// In general, and for future compatibility, classes that 
// explicitly define one copy/move constructor or one 
// copy/move assignment but not both, are encouraged to 
// specify either delete or default on the other special 
// member functions they don't explicitly define.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!