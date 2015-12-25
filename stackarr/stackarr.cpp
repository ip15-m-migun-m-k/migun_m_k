#include "stackarr.h"

StackArr::StackArr()
	: size{ 2 }, data{ new double[size] }
{

}
StackArr::~StackArr()
{
	delete[] data;
}
void StackArr::push(const double v)
{
	if (itop == size)
	{
		double* newData{ new double[size * 2] };
		for (int i{ 0 }; i < size; i++)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		size *= 2;
	}
	data[itop] = v;
	itop++;
}
bool StackArr::isempty()
{
	return 0 == itop;
}
double StackArr::pop()
{
	if (!isempty())
	{
		itop--;
		double res = data[itop];
		return res;
	}
	else throw out_of_range("stack is empty");

}