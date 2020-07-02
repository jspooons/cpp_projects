// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    //declaration of a pointer needs to include the data type 
    //the pointer is going to point to.
    // ie
    int* number;
    char* character;
    double* decimals;

    // * says its a pointer
    // not to confuse with dereference operator

    //pointer example

    int firstValue, secondValue;
    int* myPointer; // declaring

    myPointer = &firstValue;
    *myPointer = 10; // dereferencing and assigning
    myPointer = &secondValue;
    *myPointer = 20;
    cout << "firstValue is " << firstValue << endl;
    cout << "secondValue is " << secondValue << endl;
    //values set to two values indirectly by myPointer.

    int* p1, * p2; // declaring two pointers, need to two asterix, if only one with p1, p2 would be an int

    //pointers related to arrays
    //array can be implicitly converted to the pointer

    // mypointer = myarray; (cant do other way around, myarray can never be assigned anything

    // arrays and pointers example
    int numbers[5];
    int* p;
    p = numbers;  *p = 10;
    p++;  *p = 20;
    p = &numbers[2];  *p = 30;
    p = numbers + 3;  *p = 40;
    p = numbers;  *(p + 4) = 50;
    for (int n = 0; n < 5; n++)
        cout << numbers[n] << ", ";

    // The main difference being that pointers can be assigned 
    // new addresses, while arrays cannot.

    int a[5];
    a[5] = 0;       // a [offset of 5] = 0
    *(a + 5) = 0;     // pointed to by (a+5) = 0

    // if an array, its name can be used just like a pointer 
    // to its first element.

    //Pointers can be initialized either to the address of a 
    //variable (such as in the case above), or to the value of 
    //another pointer (or array)
    int myvar;
    int* foo = &myvar;
    int* bar = foo;

    // only addition and subtraction operations are allowed; 
    // the others make no sense in the world of pointers.

    //Remembering operator precedence rules, we can recall that
    //postfix operators, such as incrementand decrement, have 
    //higher precedence than prefix operators, such as the 
    //dereference operator (*)

    *p++;  // same as *(p++): increment pointer, and dereference unincremented address
    *++p;   // same as *(++p): increment pointer, and dereference incremented address
    ++* p;   // same as ++(*p): dereference pointer, and increment the value it points to
    (*p)++; // dereference pointer, and post-increment the value it points to 

    // *p++ = *q++; equivalent to:

    //*p = *q;
    //++p;
    //++q;

    //brackets reduce confusion and increase readability as always with expressions


    int x;
          int *       p1 = &x;  // non-const pointer to non-const int
    const int *       p2 = &x;  // non-const pointer to const int
          int * const p3 = &x;  // const pointer to non-const int
    const int * const p4 = &x;  // const pointer to const int 

    
    // pointers to pointers
    char a;
    char* b;
    char** c;
    a = 'z';
    b = &a;
    c = &b;
    // extra * for level of pointer (pointer to a pointer)
    //c is of type char** and a value of 8092
    //*c is of type char* and a value of 7230
    //**c is of type char and a value of 'z'

    //void pointers are pointers that point to a value 
    //that has no type
    //this gives void pointers a great flexibility
    //by being able to point to any data type

    // they have a great limitation : the data pointed to by 
    // them cannot be directly dereferenced(which is logical, 
    // since we have no type to dereference to), and for that 
    // reason, any address in a void pointer needs to be 
    // transformed into some other pointer type that points to 
    // a concrete data type before being dereferenced.

    char a = 'x';
    int b = 1602;
    increase(&a, sizeof(a));
    increase(&b, sizeof(b));
    cout << a << ", " << b << '\n';


    // A null pointer is a value that any pointer can take to 
    // represent that it is pointing to "nowhere", while a void 
    // pointer is a type of pointer that can point to somewhere 
    // without a specific type


    // C++ allows operations with pointers to functions. 
    // The typical use of this is for passing a function as an 
    // argument to another function

    int m, n;
    int (*minus)(int, int) = subtraction;

    m = operation(7, 5, addition);
    n = operation(20, m, minus);
    cout << n;



}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}



void increase(void* data, int psize)
{
    if (psize == sizeof(char))
    {
        char* pchar; pchar = (char*)data; ++(*pchar);
    }
    else if (psize == sizeof(int))
    {
        int* pint; pint = (int*)data; ++(*pint);
    }
}
