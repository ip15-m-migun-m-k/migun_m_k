#include "complex.h"

void main()
{
	cout << "Null constructor" << endl;
	cout << "Complex{} -> " << Complex{} << endl;
	cout << "\nSolo constructor" << endl;
	Complex r02{ 2 };
	cout << "Complex{} -> " << r02 << endl;

	cout << "\nTest Complex Constructor" << endl;
	testComplexConstructor(1, 2);
	testComplexConstructor(-1, 2);
	testComplexConstructor(1, -2);
	testComplexConstructor(-1, -2);

	Complex r03{ 35,-5 };
	Complex r04{ 3,-1 };

	cout << "\nTest Complex operator+" << endl;
	testComplexOpPlus(r03, -r03);
	testComplexOpPlus(r03, r04);

	cout << "\nTest Complex operator-" << endl;
	testComplexOpMinus(r03, r03);
	testComplexOpMinus(r03, r04);

	cout << "\nTest Complex operator*" << endl;
	testComplexOpMult(r03, r03);
	testComplexOpMult(r03, r04);

	cout << "\nTest Complex operator/" << endl;
	testComplexOpDiv(r03, r03);
	testComplexOpDiv(r03, r04);

	cout << "\nTest Complex operator==" << endl;
	testComplexOpCmpEq(r03, r03);
	testComplexOpCmpEq(r03, -r03);
	testComplexOpCmpEq(r03, r04);

	cout << "\nTest Complex operator!=" << endl;
	testComplexOpCmpNotEq(r03, r03);
	testComplexOpCmpNotEq(r03, -r03);
	testComplexOpCmpNotEq(r03, r04);

	cout << "\nTest Complex read from stream" << endl;
	testReadFromStream("");
	testReadFromStream("1");
	testReadFromStream("1,2");
	testReadFromStream("-4,5");
	testReadFromStream("3,-5");
	testReadFromStream("-5,-2");
	testReadFromStream("-5.0,-2");
}