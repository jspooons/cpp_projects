#pragma once

#include "Polygon2.h"
#include "Output.h"

class Rectangle : public Polygon2, public Output
{
public:
    int area()
    {
        return width * height;
    }
};

// class may inherit from more than one class by simply 
// specifying more base classes, separated by commas, in 
// the list of a class's base classes

// 