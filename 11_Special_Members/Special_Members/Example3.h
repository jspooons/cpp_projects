#pragma once

#include <iostream>
#include <string>
using namespace std; // need this for string 

class Example3
{
    string data;
public:
    Example3(const string& str) : data(str) {}
    Example3() {}
    const string& content() const { return data; }
};

