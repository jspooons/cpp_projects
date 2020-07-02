#pragma once
class Circle
{
    double radius;
public:
    Circle(double r) { radius = r; }
    double area() { return radius * radius * 3.14159265; }
    double circum() { return 2 * radius * 3.14159265; }
};

