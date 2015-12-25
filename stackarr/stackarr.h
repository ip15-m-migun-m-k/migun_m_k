#ifndef stackarr_h
#define stackarr_h

#include <iostream>
#include <stdexcept>

using namespace std;

class StackArr
{
public:
	StackArr();
	~StackArr();
	void push(const double v);
	bool isempty();
	double pop();

private:
	int size{ 0 };
	double* data{ nullptr };
	int itop{ 0 };
};

#endif