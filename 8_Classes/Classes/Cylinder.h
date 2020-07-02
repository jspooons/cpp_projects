#pragma once
#include "Circle.h"

class Cylinder
{
    Circle base;
    double height;
public:
    Cylinder(double r, double h) : base(r), height(h) {}
    double volume() { return base.area() * height; }
};

