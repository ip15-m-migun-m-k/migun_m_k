#ifndef complex
#define complex
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <math.h>

using namespace std;

class Complex
{
public:

	Complex() noexcept;
	Complex(double r) noexcept;
	Complex(double r, double i);
	Complex(const Complex &c);
	Complex operator-() const;
	double abs();
	Complex& operator = (Complex &c);
	Complex& operator += (const Complex &c);
	Complex& operator -= (const Complex &c);
	Complex& operator *= (const Complex &c);
	Complex& operator /= (const Complex &rhs);
	bool operator== (const Complex& c) const;
	bool operator!= (const Complex& c) const;
	ostream& writeToTxt(std::ostream& ostrm) const;
	istream& readFromTxt(std::istream& istrm);

private:
	double re, im;
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
std::ostream& operator<<(std::ostream& ostrm, const Complex& c);
std::istream& operator>>(std::istream& istrm, Complex& c);
void testComplexConstructor(const double re, const double im);
void testComplexOpPlus(const Complex& lhs, const Complex& rhs);
void testReadFromStream(const string& s);
void testComplexOpCmpEq(const Complex& lhs, const Complex& rhs);
void testComplexOpCmpNotEq(const Complex& lhs, const Complex& rhs);
void testComplexOpDiv(const Complex& lhs, const Complex& rhs);
void testComplexOpMult(const Complex& lhs, const Complex& rhs);
void testComplexOpMinus(const Complex& lhs, const Complex& rhs);
#endif