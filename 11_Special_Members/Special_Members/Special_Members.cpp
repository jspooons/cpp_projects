// Special_Members.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Example2.h"
#include "Example6.h"
using namespace std;

int main()
{
    Example2 ex(100); // okL calls constructor
    //Example2 ex; not valid: no default constructor
    
    //Therefore, if objects of this class need to be constructed
    //without arguments, the proper default constructor shall 
    //also be declared in the class [SEE Example3.h]

    Example6 foo("Exam");
    Example6 bar = Example6("ple");   // move-construction

    foo = foo + bar;                  // move-assignment

    cout << "foo's content: " << foo.content() << '\n';
}

// The 6 special member functions
// ======== SUMMARY ========
/*

Default Constructor
    
    if no construstors, this is called. objects initialized with 
    no arguments.
    ie Example ex;
    As soon as there is a constructor taking any number of
    parameters, the compiler no longer provides this implicit
    default constructor and no longer allows declaration of objects
    without arguments.
    If objects of a class need to be constructed without arguments
    then the proper default constructor shall also be declared
    in the class:
    Example3() {}


Destructor

    responsible for the necessary cleanup needed by a class when its 
    lifetime ends.
    useful to have a function called automatically at the end of the 
    object's life in charge of releasing this memory. To do this, 
    we use a destructor.
    ie ~Example4 () {delete ptr;}
    (takes no arguments like default constructor


Copy Constructor

    When an object is passed a named object of its own type as 
    argument, its copy constructor is invoked in order to 
    construct a copy.
    copy constructor is a constructor whose first parameter 
    is of type reference to the class itself (possibly const 
    qualified) and which can be invoked with a single argument
    of this type. ie MyClass::MyClass (const MyClass&);
    For:

    class MyClass {
    public:
        int a, b; string c;
    };

    copy constructor would be:
    MyClass::MyClass(const MyClass& x) : a(x.a), b(x.b), c(x.c) {}
    
    But this does shallow copies...
    So here the pointer value is copied, but not the content itself
    this means that both objects would be sharing a single string
    object. and at some point both objects would try to delete the
    same block of memory, causing a crash on runtime. this can be
    solved by defining the following custom copy constructor
    that performs a deep copy:
    ...
    string* ptr
    public:
        Example5 (const Example5& x) : ptr(new string(x.content())) {}
        // access content:
        const string& content() const {return *ptr;} // additional func
    ...
     deep copy performed by this copy constructor allocates 
     storage for a new string, which is initialized to contain 
     a copy of the original object. In this way, both objects 
     (copy and original) have distinct copies of the content 
     stored in different locations.
    

Copy Assignment
    
    can also be copied on any assignment operation. 
    See the difference:
    ...
    MyClass foo;
    MyClass bar (foo);       // object initialization: copy constructor called
    MyClass baz = foo;       // object initialization: copy constructor called
    foo = bar;               // object already initialized: copy assignment called
    
    copy assignment operator is an overload of operator=
    which takes a value or reference of the class itself as parameter
    return value is generally a reference to *this (although this is not required)
    copy assignment operator is also a special function 
    and is also defined implicitly if a class has no custom 
    copy nor move assignments (nor move constructor) defined.

    !implicit version performs a shallow copy which is suitable 
    for many classes, but not for classes with pointers to 
    objects they handle its storage!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //deletes the previous object and performs a deep copy
    Example5& operator= (const Example5& x) {
        delete ptr;                      // delete currently pointed string
        ptr = new string (x.content());  // allocate space for new string, and copy
        return *this;
    }


Move Constructor AND Move Assignment

    Moving also uses the value of an object to set the value 
    to another object.
    Unlike copying, the content is actually transferred from 
    one object (the source) to the other (the destination): 
    the source loses that content, which is taken over by the 
    destination.
    This moving only happens when the source of the value is 
    an unnamed object.
    Unnamed objects are objects that are temporary in nature
    ie return values of functions or type-casts.
    The move constructor is called when an object is 
    initialized on construction using an unnamed temporary. 
    Likewise, the move assignment is called when an object is 
    assigned the value of an unnamed temporary:

    MyClass fn();            // function returning a MyClass object
    MyClass foo;             // default constructor
    MyClass bar = foo;       // copy constructor
    MyClass baz = fn();      // move constructor
    foo = bar;               // copy assignment
    baz = MyClass();         // move assignment

    Copying from A to B means that new memory is allocated to B and then the entire content of A is copied to this new memory allocated for B.
    Moving from A to B means that the memory already allocated to A is transferred to B without allocating any new storage. It involves simply copying the pointer.
    
    // move constructor
    Example6 (Example6&& x) : ptr(x.ptr) {x.ptr=nullptr;}
    // move assignment
    Example6& operator= (Example6&& x) {
      delete ptr;
      ptr = x.ptr;
      x.ptr=nullptr;
      return *this;
    }

*/