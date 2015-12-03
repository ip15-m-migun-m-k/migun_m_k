#ifndef ZNVECTOR
#define ZNVECTOR

#include <cassert>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <memory>
#include <iostream>

using namespace std;

class ZnVector
{
public:
	using ValueType = int32_t;
	using IndexType = ptrdiff_t;
public:
	ZnVector() = default;
	ZnVector(const IndexType dims);
	ZnVector(std::initializer_list<ValueType> list);

	ptrdiff_t dim() { return dims_; }

	ZnVector(const ZnVector& arr);
	ZnVector(ZnVector&& vec);
	~ZnVector();
	ZnVector& operator=(const ZnVector& vec);
	ZnVector& operator=(ZnVector&& vec);

	ZnVector operator-();
	ZnVector& operator+=(const ZnVector& rhs);
	ZnVector& operator+=(const ValueType rhs);
	ZnVector& operator-=(const ZnVector& rhs);
	ZnVector& operator-=(const ValueType rhs);
	ZnVector& operator*=(const ValueType rhs);
	ZnVector& operator/=(const ValueType rhs);

	ValueType& operator[](const IndexType index);
	const ValueType& operator[](const IndexType index) const;
	ValueType* begin() { return data_; }
	ValueType* end() { return data_ + dims_; }
	const ValueType* cbegin() { return data_; }
	const ValueType* cend() { return data_ + dims_; }


	std::ostream& ZnVector::print(std::ostream& ostrm) const;

private:
	IndexType dims_{ 0 };
	ValueType* data_{nullptr};
private:
	void swap(ZnVector& arr);
};

ZnVector operator+(const ZnVector& lhs, const ZnVector& rhs);
ZnVector operator+(const ZnVector& lhs, const int32_t rhs);
ZnVector operator-(const ZnVector& lhs, const ZnVector& rhs);
ZnVector operator-(const ZnVector& lhs, const int32_t rhs);
ZnVector operator*(const ZnVector& lhs, const int32_t rhs);
ZnVector operator*(const int32_t lhs, const ZnVector& rhs);
ZnVector operator/(const ZnVector& lhs, const int32_t rhs);
std::ostream& operator<<(std::ostream& ostrm, const ZnVector& v);
void testVectorByIndexRead(const ZnVector& v, const ptrdiff_t i);
#endif