#ifndef matrixarr_h
#define matrixarr_h

#include <iostream>
#include <cassert>
#include <memory>
#include <cstddef>

using namespace std;

template<class T>
class MatrixArr
{
public:
	MatrixArr() = default;
	MatrixArr(const ptrdiff_t cRow, const ptrdiff_t cCol);
	MatrixArr(const MatrixArr<T>& rhs);
	~MatrixArr();

	MatrixArr& operator= (const MatrixArr<T>& rhs);
	bool operator== (const MatrixArr<T>& rhs) const;
	bool operator!= (const MatrixArr<T>& rhs) const { return !operator== (rhs); };
	T at(const ptrdiff_t cRow, const ptrdiff_t cCol) const;
	T& at(const ptrdiff_t cRow, const ptrdiff_t cCol);
	ptrdiff_t rows() const { return cRow_; };
	ptrdiff_t columns() const { return cCol_; };
	std::ostream& print(std::ostream& ostrim) const;
private:
	ptrdiff_t cRow_{ 0 };
	ptrdiff_t cCol_{ 0 };
	T* _data{ nullptr };

	void checkOutOfRange(const ptrdiff_t cRow, const ptrdiff_t cCol) const;
	ptrdiff_t getIndexArray(const ptrdiff_t cRow, const ptrdiff_t cCol) const;
	void checkSizeRange(const MatrixArr<T>& rhs) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& ostrim, const MatrixArr<T>& z);

void test();
#endif
