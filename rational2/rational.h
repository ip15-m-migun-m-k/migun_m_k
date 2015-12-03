#ifndef rational
#define rational

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <math.h>

using namespace std;

class Rational
{
public:
	Rational() noexcept;
	Rational(const int num) noexcept;
	Rational(const int num, const int den);

	Rational(const Rational& rhs) noexcept = default;
	Rational& operator=(const Rational& rhs) = default;
	Rational& operator=(Rational&& rhs) = default;

	int num() const;
	int den() const;
	Rational operator-() const;
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
	bool operator== (const Rational& rhs) const;
	bool operator!= (const Rational& rhs) const;
	bool operator< (const Rational& rhs) const;
	bool operator<= (const Rational& rhs) const;
	bool operator> (const Rational& rhs) const;
	bool operator>= (const Rational& rhs) const;
	ostream& writeToTxt(std::ostream& ostrm) const;
	istream& readFromTxt(std::istream& istrm);

private:
	int num_;
	int den_;

	void normalize();
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
std::ostream& operator<<(std::ostream& ostrm, const Rational& r);
std::istream& operator>>(std::istream& istrm, Rational& r);
void testRationalConstructor(const int num, const int den);
void testRationalOpPlus(const Rational& lhs, const Rational& rhs);
void testRationalOpMinus(const Rational& lhs, const Rational& rhs);
void testRationalOpMult(const Rational& lhs, const Rational& rhs);
void testRationalOpDiv(const Rational& lhs, const Rational& rhs);
void testRationalOpCmpEq(const Rational& lhs, const Rational& rhs);
void testRationalOpCmpNotEq(const Rational& lhs, const Rational& rhs);
void testRationalOpCmpLess(const Rational& lhs, const Rational& rhs);
void testRationalOpCmpNotLess(const Rational& lhs, const Rational& rhs);
void testRationalOpCmpMore(const Rational& lhs, const Rational& rhs);
void testRationalOpCmpNotMore(const Rational& lhs, const Rational& rhs);
void testReadFromStream(const string& s);
void testRationalNormalize(const Rational& lhs);
int gcd(int a, int b);
#endif
