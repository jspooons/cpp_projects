#pragma once

#include <iostream>
#include "Mother.h"
using namespace std;

class Son : public Mother {
public:
    Son(int a) : Mother(a)
    {
        cout << "Son: int parameter\n\n";
    }
};
