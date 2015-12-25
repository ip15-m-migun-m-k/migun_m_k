#include "stackarr.h"

int main()
{
	StackArr s;
	cout << "is stack empty: " << s.isempty() << endl;
	for (double i = 0; i < 10; i++)
	{
		s.push(i);
		cout << "push(" << i << ")" << endl;
	}

	while (!s.isempty()) {
		cout << "pop() = " << s.pop() << endl;
	}
	try {
		cout << "pop() = " << s.pop() << endl;
	}
	catch (const out_of_range& ex)
	{
		cout << "exception caught " << ex.what() << endl;
	}
}