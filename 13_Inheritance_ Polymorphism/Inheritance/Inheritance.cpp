// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Polygon2.h"
using namespace std;

int main()
{
    Rectangle rect;
    Triangle trgl;
    rect.set_values(4, 5);
    trgl.set_values(4, 5);
    cout << rect.area() << '\n';
    cout << trgl.area() << '\n';

    rect.print(rect.area());
    Triangle::print(trgl.area());


    Polygon* ppoly1 = &rect;
    Polygon* ppoly2 = &trgl; // Such assignments are valid, since both Rectangle and Triangle are classes derived from Polygon.
    ppoly1->set_values(4, 5);
    ppoly2->set_values(4, 5); // Dereferencing ppoly1 and ppoly2 (with *ppoly1 and *ppoly2) is valid and allows us to access the members of their pointed objects
    cout << rect.area() << '\n';
    cout << trgl.area() << '\n';
    // But because the type of ppoly1 and ppoly2 is pointer
    // to Polygon (and not pointer to Rectangle nor pointer
    // to Triangle), only the members inherited from 
    // Polygon can be accessed, and not those of the 
    // derived classes Rectangle and Triangle.
    // That is why the program above accesses the area 
    // members of both objects using rect and trgl directly,
    // instead of the pointers; the pointers to the base 
    // class cannot access the area members.

    Polygon poly;
    Polygon* ppoly3 = &rect; // errors because i used Polygon2 for belows examples on abstract base classes
    Polygon* ppoly4 = &trgl;
    Polygon* ppoly5 = &poly;
    ppoly3->set_values(4, 5);
    ppoly4->set_values(4, 5);
    ppoly5->set_values(4, 5);
    cout << ppoly3->area() << '\n'; // 20
    cout << ppoly4->area() << '\n'; // 10
    cout << ppoly5->area() << '\n'; // 0

    // But an abstract base class is not totally useless.
    // It can be used to create pointers to it:
    // taking advantage of all its polymorphic abilities
    //Polygon2* ppoly1;
    //Polygon2* ppoly2;

    Rectangle newrect;
    Triangle newtrgl;
    Polygon2* pppoly1 = &newrect;
    Polygon2* pppoly2 = &newtrgl;
    pppoly1->set_values(4, 5);
    pppoly2->set_values(4, 5);
    //cout << ppoly1->area() << '\n';
    //cout << ppoly2->area() << '\n';
    pppoly1->printarea();
    pppoly2->printarea();
}

// inheritance, involves a base class and a derived class
// The derived class inherits the members of the base class
// on top of which it can add its own members

// The inheritance relationship of two classes is declared 
// in the derived class

// Members with accessible levels are inherited with those 
// accessible levels

// The protected access specifier used in class Polygon is 
// similar to private.
// Its only difference occurs in fact with inheritance:
// When a class inherits another one, the members of the 
// derived class can access the protected members 
// inherited from the base class, but not its private 
// members.

// By declaring width and height as protected instead of 
// private, these members are also accessible from the 
// derived classes Rectangle and Triangle, instead of just 
// from members of Polygon. If they were public, they could
// be accessed just from anywhere.



// ===== POLYMORPISM ========================

// One of the key features of class inheritance is 
// that a pointer to a derived class is type-compatible 
// with a pointer to its base class.
// Polymorphism is the art of taking advantage of this
// simple but powerful and versatile feature



// VIRTUAL MEMBERS
/*
a virtual member is a member function that can be redefined
in a derived class while preserving its calling properties
through references. The syntac for a function to become
virtual is to precede its declaration with the 'virtual'
keyword.


*/