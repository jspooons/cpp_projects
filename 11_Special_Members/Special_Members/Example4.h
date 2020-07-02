#pragma once

#include <iostream>
#include <string>
using namespace std;

// destructors are responsible for 'cleanup'
// .. for necessary cleanup needed by a class
// when its lifetime ends
// takes no arguments and returns nothing, not even void.
// preceded with a tilde sign (~)

class Example4
{
    string* ptr;
public:
    // constructors:
    Example4() : ptr(new string) {}
    Example4(const string& str) : ptr(new string(str)) {}
    // destructor:
    ~Example4() { delete ptr; }
    // access content:
    const string& content() const { return *ptr; }
};

