#pragma once

// A static data member of a class is also known as a 
// "class variable", because there is only one common 
// variable for all the objects of that same class, sharing 
// the same value: i.e., its value is not different from 
// one object of this class to another.

class CVector
{
public:
	int x, y;
	CVector() {};
	CVector(int a, int b) : x(a), y(b) {} //function name CVector (constructor)
	CVector operator + (const CVector&); //function that returns a CVector
	CVector& operator = (const CVector& param) {}
};

