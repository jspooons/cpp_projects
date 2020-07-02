#include "CVector.h"

// The function operator+ of class CVector overloads 
// the addition operator (+) for that type

//pass-by-reference
// - powerful because it allows us to pass large objects 
//   into functions by giving another name to the object and 
//   not copying the large object, while also allowing us 
//   avoid the hairy complications of passing by pointer
CVector CVector::operator+ (const CVector& param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

CVector& CVector::operator= (const CVector& param)
{
	x = param.x;
	y = param.y;
	return *this;
}