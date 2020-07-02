// Class_Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class T>
class mypair {
    T a, b;
public:
    mypair(T first, T second)
    {
        a = first; b = second;
    }
    T getmax();
};

template <class T>
T mypair<T>::getmax()
{
    T retval;
    retval = a > b ? a : b;
    return retval;
}
// There are three T's in this declaration: The first one 
// is the template parameter. The second T refers to the 
// type returned by the function. And the third T (the one 
// between angle brackets) is also a requirement: It 
// specifies that this function's template parameter is 
// also the class template parameter.



int main() {
    mypair <int> myobject(100, 75);
    cout << myobject.getmax();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
