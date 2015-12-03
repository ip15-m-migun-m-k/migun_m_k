#include "rational.h"

using namespace std;

Rational::Rational() noexcept
	: Rational{ 0, 1 }
{
}

Rational::Rational(const int num) noexcept
	: Rational{ num,1 }
{
}

Rational::Rational(const int num, const int den)
: num_{ num }
, den_{ den }
{
	if (0 == den_)
	{
		throw domain_error("zero denominator in Rational");
	}
	normalize();
}

int Rational::num() const
{
	return num_;
}

int Rational::den() const
{
	return den_;
}

Rational Rational::operator-() const
{
	return Rational{ -num_, den_ };
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num_ = num_ * rhs.den_ + den_ * rhs.num_;
	den_ *= rhs.den_;
	normalize();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	num_ = num_ * rhs.den_ - den_ * rhs.num_;
	den_ *= rhs.den_;
	normalize();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num_ *= rhs.num_;
	den_ *= rhs.den_;
	normalize();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num_ *= rhs.den_;
	den_ *= rhs.num_;
	normalize();
	return *this;
}

bool Rational::operator== (const Rational& rhs) const
{
	return (num_ == rhs.num_) && (den_ == rhs.den_);
}

bool Rational::operator!= (const Rational& rhs) const
{
	return !operator==(rhs);
}

bool Rational::operator< (const Rational& rhs) const
{
	return (num_ * rhs.den_) < (rhs.num_ * den_);
}

bool Rational::operator<= (const Rational& rhs) const
{
	return (num_ * rhs.den_) <= (rhs.num_ * den_);
}

bool Rational::operator> (const Rational& rhs) const
{
	return !operator<=(rhs);
}

bool Rational::operator>= (const Rational& rhs) const
{
	return !operator<(rhs);
}

ostream& Rational::writeToTxt(std::ostream& ostrm) const
{
	ostrm << num_ << '/' << den_;
	return ostrm;
}

istream& Rational::readFromTxt(std::istream& istrm)
{
	int num{ 0 };
	istrm >> num;
	char sep{ 0 };
	istrm >> sep;
	if ('/' != sep)
	{
		istrm.setstate(ios_base::failbit);
	}
	int den{ 0 };
	istrm >> den;
	if (istrm)
	{
		num_ = num;
		den_ = den;
		normalize();
	}
	return istrm;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational summ{ lhs };
	summ += rhs;
	return summ;
}
Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational summ{ lhs };
	summ -= rhs;
	return summ;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational summ{ lhs };
	summ *= rhs;
	return summ;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational summ{ lhs };
	summ /= rhs;
	return summ;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& r)
{
	return r.writeToTxt(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& r)
{
	return r.readFromTxt(istrm);
}

void testRationalConstructor(const int num, const int den)
{
	cout << "Rational{" << num << ',' << den << "} -> " << flush;
	cout << Rational{ num, den } << endl;
}

void testRationalOpPlus(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " + " << rhs << " -> " << (lhs + rhs) << endl;
}

void testRationalOpMinus(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " - " << rhs << " -> " << (lhs - rhs) << endl;
}

void testRationalOpMult(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " * " << rhs << " -> " << (lhs * rhs) << endl;
}

void testRationalOpDiv(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " / " << rhs << " -> " << (lhs / rhs) << endl;
}

void testRationalOpCmpEq(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " == " << rhs << " -> " << boolalpha << (lhs == rhs) << endl;
}

void testRationalOpCmpNotEq(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " != " << rhs << " -> " << boolalpha << (lhs != rhs) << endl;
}

void testRationalOpCmpLess(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " < " << rhs << " -> " << boolalpha << (lhs < rhs) << endl;
}

void testRationalOpCmpNotLess(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " >= " << rhs << " -> " << boolalpha << (lhs >= rhs) << endl;
}

void testRationalOpCmpMore(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " > " << rhs << " -> " << boolalpha << (lhs > rhs) << endl;
}

void testRationalOpCmpNotMore(const Rational& lhs, const Rational& rhs)
{
	cout << lhs << " <= " << rhs << " -> " << boolalpha << (lhs <= rhs) << endl;
}

void testReadFromStream(const string& s)
{
	istringstream istrm(s);
	Rational r;
	istrm >> r;
	cout << "Read from text \"" << s << "\" -> " << r << ", stream state is " << boolalpha << !!istrm << endl;
}

void Rational::normalize()
{
	if (0 == num_)
	{
		den_ = 1;
	}
	else if (den_ < 0)
	{
		num_ *= -1;
		den_ *= -1;
	}
	if ((abs(num_) < den_) && (0 != num_))
	{
		int a = abs(num_), b = den_, c;
		c = gcd(a, b);
		if (c > 1)
		{
			num_ /= c;
			den_ /= c;
		}
	}
	else if (abs(num_) > den_)
	{
		int a = abs(num_%den_), b = den_, c;
		c = gcd(a, b);
		if (c > 1)
		{
			num_ /= c;
			num_ /= den_;
			den_ /= c;
		}
		else
		{
			num_ %= den_;
		}
	}
}

int gcd(int a, int b) 
{
	int c;
	while (b) 
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}

void testRationalNormalize(const Rational& lhs)
{
	cout << lhs << endl;
}
