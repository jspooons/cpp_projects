#pragma once

using namespace std;

class Polygon2
{
protected:
    int width, height;
public:
    void set_values(int a, int b)
    {
        width = a; height = b;
    }
    virtual int area() = 0; // !!!
    // definition; this has been replaced by =0, which 
    // makes it a pure virtual function

    // even possible for a member of the abstract base 
    // class Polygon to use the special pointer this to 
    // access the proper virtual members, even though 
    // Polygon itself has no implementation for this 
    // function
    void printarea()
    {
        cout << this->area() << '\n';
    }
};

// ABSTRACT base classes are classes that can only be used 
// as base classes, and thus are allowed to have virtual 
// member functions without definition (known as pure 
// virtual functions).
// !!! The syntax is to replace their definition by =0 
// (an equal sign and a zero)

// Classes that contain at least one pure virtual 
// function are known as abstract base classes.

// Abstract base classes cannot be used to instantiate 
// objects.