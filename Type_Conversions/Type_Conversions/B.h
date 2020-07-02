#pragma once
class B
{
public:
	// conversion from A (constructor):
	explicit B(const A& x) {}
	// conversion from A (assignment):
	B& operator= (const A& x) { return *this; }
	// conversion to A (type-cast operator)
	operator A() { return A(); }
};

