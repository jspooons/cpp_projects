#pragma once

#include <iostream>
#include <string>
using namespace std;

// If a class has no custom copy nor move constructors 
// (or assignments) defined, an implicit copy constructor is 
// provided. [performs a shallow copy]

// This default copy constructor may suit the needs of many 
//classes. But shallow copies only copy the members of the 
//class themselves, and this is probably not what we expect 
//for classes like class Example4 we defined above, because it 
//contains pointers of which it handles its storage. For that 
//class, performing a shallow copy means that the pointer 
//value is copied, but not the content itself; This means 
//that both objects (the copy and the original) would be 
//sharing a single string object (they would both be pointing 
//to the same object), and at some point (on destruction) both 
//objects would try to delete the same block of memory,
//probably causing the program to crash on runtime.

// so we will solve this isue by defining a custom copy
// constructor that performs a 'deep copy'

class Example5
{
    string* ptr;
public:
    Example5(const string& str) : ptr(new string(str)) {}
    ~Example5() { delete ptr; }
    // copy constructor:
    Example5(const Example5& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const { return *ptr; }

    // copy assign operator
    Example5& operator= (const Example5& x) {
        delete ptr; // delete currently pointed string
        ptr = new string(x.content()); // allocate space for new string, and copy
        return *this;

        // even better, since string member is not constant could re-utilize the same string object:
        //*ptr = x.content();
    }
};

//The deep copy performed by this copy constructor allocates 
//storage for a new string, which is initialized to contain a 
//copy of the original object
// so now both objects have distinct copies of the content
// stored in different locations

// copy assignment operator is an overload of operator=