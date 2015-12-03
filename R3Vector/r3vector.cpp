#include "r3vector.h"

using namespace std;


R3Vector operator+(const R3Vector& lhs, const R3Vector& rhs) { return R3Vector(lhs) += rhs; }
R3Vector operator+(const R3Vector& lhs, const double rhs) { return R3Vector(lhs) += rhs; }
R3Vector operator-(const R3Vector& lhs, const R3Vector& rhs) { return R3Vector(lhs) -= rhs; }
R3Vector operator-(const R3Vector& lhs, const double rhs) { return R3Vector(lhs) -= rhs; }
R3Vector operator*(const R3Vector& lhs, const double rhs) { return R3Vector(lhs) *= rhs; }
R3Vector operator*(const double lhs, const R3Vector& rhs) { return R3Vector(rhs) *= lhs; }
R3Vector operator/(const R3Vector& lhs, const double rhs) { return R3Vector(lhs) /= rhs; }

bool operator==(const R3Vector& lhs, const R3Vector& rhs)
{
	return ((lhs.x() == rhs.x()) && (lhs.y() == rhs.y()) && (lhs.z() == rhs.z()));
}
bool operator!=(const R3Vector& lhs, const R3Vector& rhs)
{
	return !operator==(lhs,rhs);
}

void testVectorByIndexRead(const R3Vector& v, const ptrdiff_t i)
{
	try
	{
		cout << "read v[" << i << "] -> ";
		cout << v[i];
	}
	catch (const out_of_range& ex)
	{
		cout << "exception caught " << ex.what();
	}
}

R3Vector::R3Vector(const double rX, const double rY, const double rZ)
	: data_{ rX,rY,rZ }
{
}

std::ostream & R3Vector::print(std::ostream& ostrm) const
{
	return ostrm << '(' << x() << ", " << y() << ", " << z() << ')';
}

std::istream& R3Vector::readFromTxt(std::istream& istrm)
{
	double x_{ 0 };
	istrm >> x_;
	char sep{ 0 };
	istrm >> sep;
	if (',' != sep)
	{
		istrm.setstate(ios_base::failbit);
	}
	double y_{ 0 };
	istrm >> y_;
	char sep2{ 0 };
	istrm >> sep2;
	if (',' != sep2)
	{
		istrm.setstate(ios_base::failbit);
	}
	double z_{ 0 };
	istrm >> z_;
	if (istrm)
	{
		data_[0] = x_;
		data_[1] = y_;
		data_[2] = z_;
	}
	return istrm;
}

double& R3Vector::operator[](const ptrdiff_t i)
{
	if ((i < 0) || (dim() <= i))
	{
		throw out_of_range("Index out of range in R3Vector::operator[]().");
	}
	return data_[i];
}

const double& R3Vector::operator[](const ptrdiff_t i) const
{
	if ((i < 0) || (dim() <= i))
	{
		throw out_of_range("Index out of range in R3Vector::operator[](). const");
	}
	return data_[i];
}

R3Vector R3Vector::operator-()
{
	return{ -x(), -y(), -z() };
}

R3Vector& R3Vector::operator+=(const R3Vector& rhs)
{
	for (ptrdiff_t i{ 0 }; i != dim(); i += 1)
	{
		data_[i] += rhs.data_[i];
	}
	return *this;
}

R3Vector& R3Vector::operator+=(const double rhs)
{
	for (auto& v: *this)
	{
		v += rhs;
	}
	return *this;
}

R3Vector& R3Vector::operator-=(const R3Vector& rhs)
{
	rx() -= rhs.x();
	ry() -= rhs.y();
	rz() -= rhs.z();
	return *this;
}

R3Vector& R3Vector::operator-=(const double rhs)
{
	for (auto iCur{ begin() }, iEnd{ end() }; iCur != iEnd; ++iCur)
	{
		*iCur -= rhs;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& ostrm, const R3Vector& v)
{
	return v.print(ostrm);
}

std::istream& operator>>(std::istream& istrm, R3Vector& v)
{
	return v.readFromTxt(istrm);
}


R3Vector& R3Vector::operator*=(const double rhs)
{
	rx() *= rhs;
	ry() *= rhs;
	rz() *= rhs;
	return *this;
}

R3Vector& R3Vector::operator/=(const double rhs)
{
	for (auto& coord : *this)
	{
		coord /= rhs;
	}
	return *this;
}

void testReadFromStream(const string& s)
{
	istringstream istrm(s);
	R3Vector v;
	istrm >> v;
	cout << "Read from text \"" << s << "\" -> " << v << ", stream state is " << boolalpha << !!istrm << endl;
}

void testR3VectorConstructor(const double x, const double y, const double z)
{
	cout << "R3Vector{" << x << ',' << y << ',' << z << "} -> " << flush;
	cout << R3Vector{ x, y, z } << endl;
}

void testR3VectorOpPlus(const R3Vector& lhs, const R3Vector& rhs)
{
	cout << lhs << " + " << rhs << " -> " << (lhs + rhs) << endl;
}

void testR3VectorOpPlus2(const R3Vector& lhs, const double rhs)
{
	cout << lhs << " + " << rhs << " -> " << (lhs + rhs) << endl;
}

void testR3VectorOpMinus(const R3Vector& lhs, const R3Vector& rhs)
{
	cout << lhs << " - " << rhs << " -> " << (lhs - rhs) << endl;
}

void testR3VectorOpMinus2(const R3Vector& lhs, const double rhs)
{
	cout << lhs << " - " << rhs << " -> " << (lhs - rhs) << endl;
}

void testR3VectorOpMult(const double lhs, const R3Vector& rhs)
{
	cout << lhs << " * " << rhs << " -> " << (lhs * rhs) << endl;
}

void testR3VectorOpMult2(const R3Vector& lhs, const double rhs)
{
	cout << lhs << " * " << rhs << " -> " << (lhs * rhs) << endl;
}

void testR3VectorOpDiv(const R3Vector& lhs, const double rhs)
{
	cout << lhs << " / " << rhs << " -> " << (lhs / rhs) << endl;
}

void testR3VectorOpCmpEq(const R3Vector& lhs, const R3Vector& rhs)
{
	cout << lhs << " == " << rhs << " -> " << boolalpha << (lhs == rhs) << endl;
}

void testR3VectorOpCmpNotEq(const R3Vector& lhs, const R3Vector& rhs)
{
	cout << lhs << " != " << rhs << " -> " << boolalpha << (lhs != rhs) << endl;
}