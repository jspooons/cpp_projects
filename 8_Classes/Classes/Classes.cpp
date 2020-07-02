// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
using namespace std;

int main()
{
    Rectangle rect(3, 4);
    Rectangle rectb; // empty parentheses cannot be used to call the default constructor:
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;

    // 4 ways to construct objects of a class whose constructor takes a single parameter
    Circle foo(10.0);   // functional form
    Circle bar = 20.0;   // assignment init.
    Circle baz{ 30.0 };   // uniform init.
    Circle qux = { 40.0 }; // POD-like
    //An advantage of uniform initialization over functional form is that, unlike parentheses, 
    //cannot be confused with function declarations, and thus can be used to explicitly call default constructors
    //so can do rectd{}, [but not rectd()]

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
