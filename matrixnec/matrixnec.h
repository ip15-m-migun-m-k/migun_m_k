#ifndef matrixnec_h
#define matrixnec_h

#include <iostream>
#include <cassert>
#include <memory>
#include <cstddef>

using namespace std;

template<class T>
class MatrixNec
{
public:
	MatrixNec() = default;
	MatrixNec(const ptrdiff_t nRow, const ptrdiff_t nCol);
	MatrixNec(const MatrixNec<T>& rhs);
	~MatrixNec();

	MatrixNec& operator= (const MatrixNec<T>& rhs);
	bool operator== (const MatrixNec<T>& rhs) const;
	bool operator!= (const MatrixNec<T>& rhs) const { return !operator== (rhs); };
	T at(const ptrdiff_t znach) const;
	T& at(const ptrdiff_t znach);
	ptrdiff_t rows() const { return cRow_; };
	ptrdiff_t columns() const { return cCol_; };
	std::ostream& print(std::ostream& ostrim) const;
private:
	ptrdiff_t cRow_{ 0 };
	ptrdiff_t cCol_{ 0 };
	T** _data{ nullptr };

	void checkOutOfRange(const ptrdiff_t cRow, const ptrdiff_t cCol) const;
	T& getIndexArray(const ptrdiff_t cRow, const ptrdiff_t cCol) const;
	void checkSizeRange(const MatrixNec<T>& rhs) const;
};

template<class T>
std::ostream& operator<<(std::ostream& ostrim, const MatrixNec<T>& z);
void test();


#endif