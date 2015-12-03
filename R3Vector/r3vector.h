#ifndef r3vector
#define r3vector

#include <iostream>
#include <cstddef>
#include <iterator>
#include <stdexcept>
#include <sstream>
#include <string>

using namespace std;

class R3Vector
{
public:
	R3Vector() noexcept = default;
	R3Vector(const R3Vector&) noexcept = default;
	R3Vector(const double rX, const double rY, const double rZ);
	~R3Vector() noexcept = default;
	R3Vector& operator= (const R3Vector&) noexcept = default;
	std::ostream& R3Vector::print(std::ostream& ostrm) const;
	std::istream& R3Vector::readFromTxt(std::istream& istrm);

	static constexpr ptrdiff_t dim() { return dimCount_; }
	double& operator[] (const ptrdiff_t i);
	const double& operator[](const ptrdiff_t i) const;

	double x() const { return data_[0]; }
	double y() const { return data_[1]; }
	double z() const { return data_[2]; }
	double& rx() { return data_[0]; }
	double& ry() { return data_[1]; }
	double& rz() { return data_[2]; }

	R3Vector operator-();
	R3Vector& operator+=(const R3Vector& rhs);
	R3Vector& operator+=(const double rhs);
	R3Vector& operator-=(const R3Vector& rhs);
	R3Vector& operator-=(const double rhs);
	R3Vector& operator*=(const double rhs);
	R3Vector& operator/=(const double rhs);

	double* begin() { return data_; }
	double* end() { return data_ + dimCount_; }
	const double* cbegin() { return data_; }
	const double* cend() { return data_ + dimCount_; }

private:
	static const ptrdiff_t dimCount_{ 3 };
	double data_[dimCount_] = { 0.0 };
};

R3Vector operator+(const R3Vector& lhs, const R3Vector& rhs);
R3Vector operator+(const R3Vector& lhs, const double rhs);
R3Vector operator-(const R3Vector& lhs, const R3Vector& rhs);
R3Vector operator-(const R3Vector& lhs, const double rhs);
R3Vector operator*(const R3Vector& lhs, const double rhs);
R3Vector operator*(const double lhs, const R3Vector& rhs);
R3Vector operator/(const R3Vector& lhs, const double rhs);
bool operator==(const R3Vector& lhs, const R3Vector& rhs);
bool operator!=(const R3Vector& lhs, const R3Vector& rhs);

std::ostream& operator<<(std::ostream& ostrm, const R3Vector& v);
std::istream& operator>>(std::istream& istrm, R3Vector& v);

void testVectorByIndexRead(const R3Vector& v, const ptrdiff_t i);
void testReadFromStream(const string& s);
void testR3VectorConstructor(const double x, const double y, const double z);
void testR3VectorOpPlus(const R3Vector& lhs, const R3Vector& rhs);
void testR3VectorOpPlus2(const R3Vector& lhs, const double rhs);
void testR3VectorOpMinus(const R3Vector& lhs, const R3Vector& rhs);
void testR3VectorOpMinus2(const R3Vector& lhs, const double rhs);
void testR3VectorOpMult(const double lhs, const R3Vector& rhs);
void testR3VectorOpMult2(const R3Vector& lhs, const double rhs);
void testR3VectorOpDiv(const R3Vector& lhs, const double rhs);
void testR3VectorOpCmpEq(const R3Vector& lhs, const R3Vector& rhs);
void testR3VectorOpCmpNotEq(const R3Vector& lhs, const R3Vector& rhs);

#endif