#pragma once

#include "Polygon2.h"
#include "Output.h"

class Triangle: public Polygon2, public Output
{
public:
    int area()
    {
        return width * height / 2;
    }
};


// The members inherited by Rectangle and Triangle have 
// the same access permissions as they had in their base 
// class Polygon.
// This is because the inheritance relation has been 
// declared using the public keyword on each of the 
// derived classes

// With protected, all public members of the base class 
// are inherited as protected in the derived class

// Conversely, if the most restricting access level is
// specified (private), all the base class members are 
// inherited as private

// this would not restrict derived classes from declaring 
// its own public members

// publicly derived class inherits access to ever member 
// of a base class except its:
// constructors and destructor
// assignment operator members (operator=)
// friends
// private members

// Unless otherwise specified, the constructors of a 
// derived class calls the default constructor of its base
// classes