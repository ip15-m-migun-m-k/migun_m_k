#include "znvector.h"

using namespace std;

int main()
{
	ZnVector v0{5, -8, 12, 3, -1};
	cout << "ZnVector{} -> " << v0 << endl;
	ZnVector v1{ v0 };
	cout << endl << "ZnVector{} oT ZnVector'a -> " << v1 << endl;
	v1 *= 2;
	cout << endl << "New ZnVector{} ->" << v1 << endl;

	for (ptrdiff_t i{ 0 }; i < v1.dim(); i += 1)
	{
		testVectorByIndexRead(v1, i);
		cout << endl;
	}

	cout << endl << "Null constructor" << endl;
	cout << "ZnVector{} -> " << ZnVector{} << endl;

	ZnVector v03{ 35, -5, 25, 10 };
	ZnVector v04{ 6,-18, -12 };

	cout << "\nTest ZnVector operator+. Vector+Vector" << endl;
	cout << v03 << " + " << v04 << " = " << (v03 + v04) << endl;
	cout << v03 << " + " << -v03 << " = " << (v03 + -v03) << endl;
	cout << v04 << " + " << v03 << " = " << (v04 + v03) << endl;

	cout << "\nTest ZnVector operator+. Vector+Number" << endl;
	cout << v03 << " + 5" << " = " << (v03 + 5) << endl;
	cout << v04 << " + (-6)" << " = " << (v04 + -6) << endl;

	cout << "\nTest ZnVector operator-. Vector-Vector" << endl;
	cout << v03 << " - " << v04 << " = " << (v03 - v04) << endl;
	cout << v03 << " - " << -v03 << " = " << (v03 - -v03) << endl;
	cout << v04 << " - " << v03 << " = " << (v04 - v03) << endl;


	cout << "\nTest ZnVector operator-. Vector-Number" << endl;
	cout << v03 << " - 5" << " = " << (v03 - 5) << endl;
	cout << v04 << " - (-6)" << " = " << (v04 - -6) << endl;

	cout << "\nTest ZnVector operator*. Number*Vector" << endl;
	cout  << "5 * " << v03 << " = " << (5 * v03) << endl;
	cout << "(-6) * " << v04 << " = " << (-6 * v04) << endl;

	cout << "\nTest ZnVector operator*. Vector*Number" << endl;
	cout << v03 << " * 5" << " = " << (v03 * 5) << endl;
	cout << v04 << " * (-6)" << " = " << (v04 * -6) << endl;

	cout << "\nTest ZnVector operator/. Vector/Number" << endl;
	cout << v03 << " / 5" << " = " << (v03 / 5) << endl;
	cout << v04 << " / (-6)" << " = " << (v04 / -6) << endl;

}