#pragma once

#include <iostream>
#include "Mother.h"
using namespace std;

class Daughter : public Mother
{
public:
    Daughter(int a)
    {
        cout << "Daughter: int parameter\n\n";
    }
};

