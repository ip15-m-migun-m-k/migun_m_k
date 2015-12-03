#include "r3vector.h"

using namespace std;

void main()
{
	constexpr ptrdiff_t nSize{ 3 * R3Vector::dim() };
	R3Vector v0;
	cout << "x=" << v0.x() << " y=" << v0.y() << " z=" << v0.z() << endl;
	R3Vector v1{ 0.2, 0.6, -5.8 };
	cout << v1 << endl;
	R3Vector v2{ v1 };
	cout << v2 << endl;
	v2.rx() *= 2;
	v2.ry() *= 2;
	v2.rz() *= 2;
	cout << v2 << endl;

	for (ptrdiff_t i{ -2 }; i <= v2.dim(); i += 1)
	{
		testVectorByIndexRead(v2, i);
		cout << endl;
	}

	cout << "Null constructor" << endl;
	cout << "R3Vector{} -> " << R3Vector{} << endl;

	cout << "\nTest R3Vector Constructor" << endl;
	testR3VectorConstructor(1, 2, 3);
	testR3VectorConstructor(-1, 2, 5);
	testR3VectorConstructor(1, -2, -4);
	testR3VectorConstructor(-1, -2, -2.543);
	
	R3Vector v03{ 35.4312,-5, 25.8821 };
	R3Vector v04{ 3,-1.12, -12.1231 };
	
	cout << "\nTest R3Vector operator+. Vector+Vector" << endl;
	testR3VectorOpPlus(v03, -v03);
	testR3VectorOpPlus(v03, v04);

	cout << "\nTest R3Vector operator+. Vector+Number" << endl;
	testR3VectorOpPlus2(v03, 5.1235);
	testR3VectorOpPlus2(v03, 1.242);

	cout << "\nTest R3Vector operator-. Vector-Vector" << endl;
	testR3VectorOpMinus(v03, v03);
	testR3VectorOpMinus(v03, v04);

	cout << "\nTest R3Vector operator-. Vector-Number" << endl;
	testR3VectorOpMinus2(v03, 21.123);
	testR3VectorOpMinus2(v03, -12.4123);

	cout << "\nTest R3Vector operator*. Number*Vector" << endl;
	testR3VectorOpMult(-1.5, v03);
	testR3VectorOpMult(3.33, v04);

	cout << "\nTest R3Vector operator*. Vector*Number" << endl;
	testR3VectorOpMult2(v03, 2.5);
	testR3VectorOpMult2(v04, -1.5);

	cout << "\nTest R3Vector operator/. Vector/Number" << endl;
	testR3VectorOpDiv(v03, 1.25);
	testR3VectorOpDiv(v04, -3.33);
	
	cout << "\nTest R3Vector operator==" << endl;
	testR3VectorOpCmpEq(v03, v03);
	testR3VectorOpCmpEq(v03, -v03);
	testR3VectorOpCmpEq(v03, v04);

	cout << "\nTest R3Vector operator!=" << endl;
	testR3VectorOpCmpNotEq(v03, v03);
	testR3VectorOpCmpNotEq(v03, -v03);
	testR3VectorOpCmpNotEq(v03, v04);

	cout << "\nTest R3Vector read from stream" << endl;
	testReadFromStream("");
	testReadFromStream("1");
	testReadFromStream("1,2,3");
	testReadFromStream("-4,5,-6");
	testReadFromStream("3,-5,7");
	testReadFromStream("-5,-2,1");
	testReadFromStream("-5.0,-2,1.214131");

}
