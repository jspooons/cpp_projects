// Program_Flow_II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";

    x = sum<int>(10, 20);
    y = sum(5, 6);
    z = sum(2.5, 3.5);


    // scopes

    int x = 10;
    int y = 20;
    {
        int x;   // ok, inner scope.
        x = 50;  // sets value to inner x
        y = 50;  // sets value to (outer) y
        cout << "inner block:\n";
        cout << "x: " << x << '\n';
        cout << "y: " << y << '\n';
    }
    cout << "outer block:\n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';


    // namespace + 'using'

    using first::x;
    using second::y;
    cout << x << '\n'; // 5
    cout << y << '\n'; // 2.7183
    cout << first::y << '\n'; // 10
    cout << second::x << '\n'; // 3.1416

    {
        using namespace first;
        cout << x << endl;
    }

    {
        using namespace second;
        cout << x << endl;
    }
}

// overloading functions is all good, but what if for functions with the same implementation? such as:

/*int sum(int a, int b)
{
    return a + b;
}

double sum(double a, double b)
{
    return a + b;
}*/

// can use templates though:

template <class SomeType>
SomeType sum(SomeType a, SomeType b)
{
    return a + b;
}

//Classes are data types. They are an expanded concept of 
//structures, they can contain data members, but they can 
//also contain functions as members whereas a namespace is 
//simply an abstract way of grouping items together.

namespace first
{
    int x = 5;
    int y = 10;
}

namespace second
{
    double x = 3.1416;
    double y = 2.7183;
}

//'using' and 'using namepsace' have validity only in the
//same block. can create a block as simple as ' {    } '

//exisiting namespaces can be aliased with new names, with the following syntax:
//namespace new_name = current_name;

// variables with static storage (ie gloabal variables) that are not explictily initialized are automatically initialized to zeroes
// variables with automatic storage (ie local variables) that are not explictily initialized are left unitialized, and thus have an undetermined value. (their actual output may vary)