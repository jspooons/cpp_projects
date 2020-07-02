#pragma once

#include <iostream>
using namespace std;

class Mother
{
public:
    Mother()
    {
        cout << "Mother: no parameters\n";
    }
    Mother(int a)
    {
        cout << "Mother: int parameter\n";
    }
};

