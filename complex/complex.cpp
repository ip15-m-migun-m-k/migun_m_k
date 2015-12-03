#include "complex.h"

Complex::Complex() noexcept
	: Complex{ 0, 0 }
{
};

Complex::Complex(double r) noexcept
	: Complex{ r, 0 }
{
}

Complex::Complex(double r, double i)
	:re{ r }
	, im{ i }
{
}

Complex::Complex(const Complex &c)
{
	re = c.re;
	im = c.im;
}

Complex Complex::operator-() const
{
	return Complex{ -re, -im };
}

double Complex::abs()
{
	return sqrt(re * re + im * im);
}

Complex& Complex::operator = (Complex &c)
{
	re = c.re;
	im = c.im;

	return (*this);
}

Complex& Complex::operator += (const Complex &c)
{
	re += c.re;
	im += c.im;
	return *this;
}

Complex& Complex::operator -= (const Complex &c)
{
	re -= c.re;
	im -= c.im;
	return *this;
}

Complex& Complex::operator *= (const Complex &c)
{
	Complex temp;
	temp.re = re * c.re - im * c.im;
	temp.im = re * c.im + im * c.re;
	re = temp.re;
	im = temp.im;
	return *this;
}

Complex& Complex::operator /= (const Complex &rhs)
{
	Complex temp;
	double r = rhs.re * rhs.re + rhs.im * rhs.im;
	temp.re = (re * rhs.re + im * rhs.im) / r;
	temp.im = (rhs.re * im - re * rhs.im) / r;
	re = temp.re;
	im = temp.im;
	return *this;
}

bool Complex::operator== (const Complex& c) const
{
	return (re == c.re && im == c.im);
}

bool Complex::operator!= (const Complex& c) const
{
	return !operator==(c);
}

ostream& Complex::writeToTxt(std::ostream& ostrm) const
{
	ostrm << '(' << re << ',' << im << ')';
	return ostrm;
}

istream& Complex::readFromTxt(std::istream& istrm)
{
	double re_{ 0 };
	istrm >> re_;
	char sep{ 0 };
	istrm >> sep;
	if (',' != sep)
	{
		istrm.setstate(ios_base::failbit);
	}
	double im_{ 0 };
	istrm >> im_;
	if (istrm)
	{
		re = re_;
		im = im_;
	}
	return istrm;
}


Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex summ{ lhs };
	summ += rhs;
	return summ;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex summ{ lhs };
	summ -= rhs;
	return summ;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex summ{ lhs };
	summ *= rhs;
	return summ;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex summ{ lhs };
	summ /= rhs;
	return summ;
}

std::ostream& operator<<(std::ostream& ostrm, const Complex& c)
{
	return c.writeToTxt(ostrm);
}

std::istream& operator>>(std::istream& istrm, Complex& c)
{
	return c.readFromTxt(istrm);
}

void testComplexConstructor(const double re, const double im)
{
	cout << "Complex{" << re << ',' << im << "} -> " << flush;
	cout << Complex{ re, im } << endl;
}

void testComplexOpPlus(const Complex& lhs, const Complex& rhs)
{
	cout << lhs << " + " << rhs << " -> " << (lhs + rhs) << endl;
}

void testComplexOpMinus(const Complex& lhs, const Complex& rhs)
{
	cout << lhs << " - " << rhs << " -> " << (lhs - rhs) << endl;
}

void testComplexOpMult(const Complex& lhs, const Complex& rhs)
{
	cout << lhs << " * " << rhs << " -> " << (lhs * rhs) << endl;
}

void testComplexOpDiv(const Complex& lhs, const Complex& rhs)
{
	cout << lhs << " / " << rhs << " -> " << (lhs / rhs) << endl;
}

void testComplexOpCmpEq(const Complex& lhs, const Complex& rhs)
{
	cout << lhs << " == " << rhs << " -> " << boolalpha << (lhs == rhs) << endl;
}

void testComplexOpCmpNotEq(const Complex& lhs, const Complex& rhs)
{
	cout << lhs << " != " << rhs << " -> " << boolalpha << (lhs != rhs) << endl;
}

void testReadFromStream(const string& s)
{
	istringstream istrm(s);
	Complex c;
	istrm >> c;
	cout << "Read from text \"" << s << "\" -> " << c << ", stream state is " << boolalpha << !!istrm << endl;
}