#include "rational.h"

int main()
{
	cout << "Rational{} -> " << Rational{} << endl;
	Rational r02{ 2 };
	cout << "Rational{} -> " << r02 << endl;
	testRationalConstructor(1, 2);
	testRationalConstructor(-1, 2);
	testRationalConstructor(1, -2);
	testRationalConstructor(-1, -2);
	try
	{
		testRationalConstructor(5, 0);
	}
	catch (domain_error& e)
	{
		cout << "exception caught (" << e.what() << ')' << endl;
	}
	Rational r03{ -1,5 };
	Rational r04{ -2,3 };
	Rational r05{ 3,9 };
	Rational r06{ -3,9 };
	Rational r07{ 8,3 };
	Rational r08{ -20,3 };

	cout << "\nTest Rational operator+" << endl;
	testRationalOpPlus(r03, -r03);
	testRationalOpPlus(r03, r04);

	cout << "\nTest Rational operator-" << endl;
	testRationalOpMinus(r03, r03);
	testRationalOpMinus(r03, r04);

	cout << "\nTest Rational operator*" << endl;
	testRationalOpMult(r03, r03);
	testRationalOpMult(r03, r04);

	cout << "\nTest Rational operator/" << endl;
	testRationalOpDiv(r03, r03);
	testRationalOpDiv(r03, r04);

	cout << "\nTest Rational operator==" << endl;
	testRationalOpCmpEq(r03, r03);
	testRationalOpCmpEq(r03, -r03);
	testRationalOpCmpEq(r03, r04);

	cout << "\nTest Rational operator!=" << endl;
	testRationalOpCmpNotEq(r03, r03);
	testRationalOpCmpNotEq(r03, -r03);
	testRationalOpCmpNotEq(r03, r04);

	cout << "\nTest Rational operator<" << endl;
	testRationalOpCmpLess(r03, r03);
	testRationalOpCmpLess(r03, -r03);
	testRationalOpCmpLess(r03, r04);

	cout << "\nTest Rational operator>=" << endl;
	testRationalOpCmpNotLess(r03, r03);
	testRationalOpCmpNotLess(r03, -r03);
	testRationalOpCmpNotLess(r03, r04);

	cout << "\nTest Rational operator>" << endl;
	testRationalOpCmpMore(r03, r03);
	testRationalOpCmpMore(r03, -r03);
	testRationalOpCmpMore(r03, r04);

	cout << "\nTest Rational operator<=" << endl;
	testRationalOpCmpNotMore(r03, r03);
	testRationalOpCmpNotMore(r03, -r03);
	testRationalOpCmpNotMore(r03, r04);

	cout << "\nTest Rational read from stream" << endl;
	testReadFromStream("");
	testReadFromStream("1");
	testReadFromStream("1/2");
	testReadFromStream("-4/5");
	testReadFromStream("3/-5");
	testReadFromStream("-5/-2");
	testReadFromStream("-5.0/-2");

	cout << "\nTest Rational Normalize" << endl;
	testRationalNormalize(r05);
	testRationalNormalize(r06);
	testRationalNormalize(r07);
	testRationalNormalize(r08);
}