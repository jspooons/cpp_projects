#pragma once

//as soon as a class has some constructor taking any number of 
//parameters explicitly declared, the compiler no longer 
//provides an implicit default constructor, and no longer 
//allows the declaration of new objects of that class without 
//arguments.

class Example2
{
public:
    int total;
    Example2(int initial_value) : total(initial_value) { };
    void accumulate(int x) { total += x; };
};

