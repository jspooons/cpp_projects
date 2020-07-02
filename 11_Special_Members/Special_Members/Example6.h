#pragma once

#include <iostream>
#include <string>
using namespace std;

// 'moving' means memory already allocated, so only involves copying the pointer
// while 'copying' means new memory is allocated, and then entire content copied to new allocated memory

// move constructor called when an object is initialized on construction using an unnamed temporary name
// move assignment is called when an object is assigned the value of an unnamed temporary

class Example6
{
    string* ptr;
public:
    Example6(const string& str) : ptr(new string(str)) {}
    ~Example6() { delete ptr; }
    // move constructor
    Example6(Example6&& x) : ptr(x.ptr) { x.ptr = nullptr; }
    // move assignment
    Example6& operator= (Example6&& x) {
        delete ptr; // deallocate
        ptr = x.ptr; // allocate
        x.ptr = nullptr; // deallocate 
        return *this; // returns reference to the object
    }
    // access content:
    const string& content() const { return *ptr; }
    // addition:
    Example6 operator+(const Example6& rhs) {
        return Example6(content() + rhs.content());
    }
};

