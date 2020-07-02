#pragma once
class Polygon
{
protected:
    int width, height;
public:
    void set_values(int a, int b)
    {
        width = a; height = b;
    }

    virtual int area() { return 0; }
};

// if virtual is removed from the declaration of area in 
// the example above, all three calls to area would return 
// zero, because in all cases, the version of the base 
// class would have been called instead.

// what the virtual keyword does is to allow a member of a 
// derived class with the same name as one in the base 
// class to be appropriately called from a pointer, and 
// more precisely when the type of the pointer is a pointer
// to the base class that is pointing to an object of the 
// derived class

// A class that declares or inherits a virtual function is 
// called a polymorphic class.