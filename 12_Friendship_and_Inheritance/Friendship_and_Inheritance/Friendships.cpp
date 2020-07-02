// Friendships.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    //Rectangle foo;
    //Rectangle bar(2, 3);
    //foo = duplicate(bar);
    //cout << foo.area() << '\n';

    Rectangle rect;
    Square sqr(4);
    rect.convert(sqr);
    cout << rect.area();
}

Rectangle duplicate(const Rectangle& param)
{
    Rectangle res;
    res.width = param.width * 2;
    res.height = param.height * 2;
    return res;
}

// private and protected members of a class cannot be 
// accessed from outside the same class in which they are 
// declared

// This rule does not apply to 'friends'

// FRIENDS are functions or classes declared with the
// 'friend' keyword

// a non-member function can access private and protected
// members of a class if it is declared a 'friend' of that
// class

// That is done by including a declaration of this external
// function within the class, and preceding it with the 
// keyword friend

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Typical use cases of friend functions are operations 
// that are conducted between two different classes 
// accessing private or protected members of both.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// FRIEND CLASSES (moving on from friend functions)
// class whose members have access to the private or 
// protected members of another class

