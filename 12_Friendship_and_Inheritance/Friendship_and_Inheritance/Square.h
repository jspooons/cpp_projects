#pragma once
class Square
{
	friend class Rectangle;
private:
	int side;
public:
	Square(int a) : side(a) {}
};

// class Rectangle is a friend of class Square allowing 
// Rectangle's member functions to access private and 
// protected members of Square

// Rectangle can access the member variables Square::side

// Another property of friendships is that they are NOT 
// transitive: The friend of a friend is not considered a 
// friend unless explicitly specified.