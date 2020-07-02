// Type_Conversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <typeinfo>
#include "B.h"
#include "A.h"
using namespace std;

int main()
{
    //IMPLICIT connversions

    // standard conversion
    short a = 2000;
    int b;
    b = a;

    // conversion from in to float known as PROMOSTION
    // and is guaranteed to produce exact same value

    // negative -> unsigned, resulting value corresponds to
    // its 2's complemente bitwise representation. ie -1 to
    // the largest value representable by type

    // false -> int, becomes zero or null pointer for
    // pointer types. true converted to equivalent of 1

    // some of these conversions may imply loss of precision

    // this can be avoided with EXPLICIT conversion

    // implicit cont..

    A foo;
    B bar = foo;    // calls constructor (single-argument constructors: allow implcit conversion from a particular type to initialize an object) [Copy constructor is called when a new object is created from an existing object, as a copy of the existing object]
    bar = foo;      // calls assignment (assignment operator: allow implcit conversion from a particular type on assignments) [And assignment operator is called when an already initialized object is assigned a new value from another existing object.]
    foo = bar;      // calls type-cast operator (Type-cast operator: allow implicit conversion to a particular type)
    // type-cast operator uses a particular syntax: it 
    // uses the operator keyword followed by the 
    // destination type and an empty set of parentheses. 
    // Notice that the return type is the destination type
    // and thus is not specified before the operator 
    // keyword.

    Dollars dollars{ 9 };
    printCents(dollars); // dollars will be implicitly cast to a Cents here
    cout << '\n'; // ^^ prints 900

    // c++ allows ONE implicit conversion to happen for each argument

    // explicit keyword restrcits arguments to specific type in function brackets

    //type-cast member functions can also be marked explicit
    // preventing implicit conversions in the same way as
    // in the same way as explicit-specified constructors do for
    // the destination type

    //constructors marked explicit can;t be called with 
    // assignment-like syntax

    // fn(foo); no allowed, cant do implicit conversion. due to explicit constructor of B
    fn(bar); // can do.

    // c++ is a strong-typed language

    // many conversions, require an explicit conversion
    // known as type-casting
    // there exists two main syntaxes for generic type-casting
    // functional and c-like

    double x = 10.3;
    int y;
    y = int(x); // functional
    y = (int)x; // c-like

    // type-casting is enough for most needs with fundamental data types
    // HOWEVER, these operators can be applied on classes
    // and pointers which can lead to code that, while 
    // syntactically correct, can cause runtime errors.
    // for example, below, the program decalres a pointer to
    // Addition, bu then it assigns to it a reference to an object
    // of another unrelated type using explicit type-casting: *
    Dummy d;
    Addition* padd;
    padd = (Addition*)&d; // *
    cout << padd->result();
    // unrestrcited explicit type-casting allows to convert
    // any pointer into any othe rpointer type.
    // the subsequent call to member result will produce either
    // a runtime-error or some other unexpected result

    // in order to control these conversions between classes,
    // we have 4 specific casting operators:

    // 1 - dynamic_cast:
    //------------------
    // can only be used with pointers and references to classes (or with void*)
    // purpose: ensure result of type conversion points to a
    //          valid complete object of the destination pointer
    // naturally includes pointer upcast (pointer-to-derived => pointer-to-base)
    // BUT, also allows downcast (pointer-to-base to pointer-to-derived)
    // polymorphic classes IFF the pointed object is a valid
    // complete object of the target type. ie:
    // dynamic_cast <new_type> (expression)
    try {
        Base* pba = new Derived;
        Base* pbb = new Base;
        Derived* pd;

        pd = dynamic_cast<Derived*>(pba);
        if (pd == 0) cout << "Null pointer on first type-cast.\n";

        pd = dynamic_cast<Derived*>(pbb);
        if (pd == 0) cout << "Null pointer on second type-cast.\n";

    }
    catch (exception& e) { cout << "Exception: " << e.what(); }
    // Even though both are pointers of type Base*, pba 
    // actually points to an object of type Derived, while
    // pbb points to an object of type Base. Therefore, 
    // when their respective type-casts are performed 
    // using dynamic_cast, pba is pointing to a full object
    // of class Derived, whereas pbb is pointing to an 
    // object of class Base, which is an incomplete object
    // of class Derived.

    // returns a null pointer to indicate the failure (ie 0)
    


    // 2 - static_cast:
    // ----------------
    // can perform conversions between pointers to related
    // classes, upcasts AND downcasts.
    // No checks performed in runtime to guarantee object 
    // being converted is in fact a full object of the 
    // destination type. So up to PROGRAMMER to ensure
    // that conversion is safe.
    // BUT, doesn;t incur overhead of type-safety of
    // dynamic_cast.
    SBase* a = new SBase;
    //SDerived* b = static_cast<SDerived*>(a); error
    //b points to an incomplete object if dereferenced



    // 3 - reinterpret_cast:
    // ---------------------
    // converts ANY pointer type to any other pointer type
    // can also cast pointers to or from integer types
    // ONLY guarante is that a pointer cast to an integer
    // type large enough to fully contain it is guaranteed
    // to be able to be cast back to a valid pointer.
    // Conversions that can't be performed by static_cast
    // and can here, are low-level operations based on
    // reinterpreting the binary representations of the types
    //, which on most cases results in code which is system-
    // specific, (non-portable).
    RA* a = new RA;
    RB* b = reinterpret_cast<RB*>(a);
    // this code compiles, but doesnt make much sense.
    // as now b points to an object of a totally unrelated
    // and likely incompatible class. dereferencing b is
    // unsafe



    // 4 - const_cast:
    // ---------------
    // manipulates the constness of the object pointed by a
    // pointer, either to be set or removed. example: in
    // order to pass a const pointer to a function that expects
    // a non-const argument:
    const char* c = "sample text";
    print(const_cast<char*> (c));
    //  function print does not write to the pointed object,
    // so guaranteed to work.
    // removing the constness of a pointed object to actually 
    // write to it causes undefined behavior



    // typeid allows to check the type of an expression
    // returns a reference to a constant object of type
    // 'type_info'
    // can return a null-terminateed character sequence 
    // representing the data type or class name using its
    // name() member.
    int* a, b;
    a = 0; b = 0;
    if (typeid(a) != typeid(b))
    {
        cout << "a and b are of different types:\n";
        cout << "a is: " << typeid(a).name() << '\n';
        cout << "b is: " << typeid(b).name() << '\n';
    }

    // When typeid is applied to an expression whose type 
    // is a polymorphic class, the result is the type of 
    // the most derived complete object: 
    try {
        Base* a = new Base;
        Base* b = new Derived;
        cout << "a is: " << typeid(a).name() << '\n'; // a is: class Base *
        cout << "b is: " << typeid(b).name() << '\n'; // b is: class Base *
        cout << "*a is: " << typeid(*a).name() << '\n'; // *a is: class Base
        cout << "*b is: " << typeid(*b).name() << '\n'; // *b is: class Derived
    }
    catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
    // Notice how the type that typeid considers for 
    //pointers is the pointer type itself (both a and b 
    //are of type class Base *). However, when typeid is 
    //applied to objects (like *a and *b) typeid yields 
    //their dynamic type (i.e. the type of their most
    //derived complete object).

    // if the type typeid evaluates is a pointer preced by 
    // the dereference operator, and this pointer has a null
    // value, typeid throws a bad_typeid exception.

}

void print(char* str)
{
    cout << str << '\n';
}

class RA { /* ... */ };
class RB { /* ... */ };

class Base { virtual void dummy() {} };
class Derived : public Base { int a; };

class SBase {};
class SDerived : public SBase {};

class Cents
{
private:
    int m_cents;
public:
    Cents(int cents = 0)
        : m_cents{ cents }
    {
    }

    // Overloaded int cast
    operator int() const { return m_cents; }

    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }
};

class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars = 0)
        : m_dollars{ dollars }
    {
    }

    // Allow us to convert Dollars into Cents
    operator Cents() const { return Cents(m_dollars * 100); }
};

void printCents(Cents cents)
{
    std::cout << cents; // cents will be implicitly cast to an int here
}

void fn(B x) {}

class Dummy {
    double i, j;
};

class Addition {
    int x, y;
public:
    Addition(int a, int b) { x = a; y = b; }
    int result() { return x + y; }
};
