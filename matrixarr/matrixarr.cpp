#include "matrixarr.h"

template <class T>
MatrixArr<T>::MatrixArr(const ptrdiff_t cRow, const ptrdiff_t cCol)
	:cRow_{ cRow }, cCol_{ cCol }, _data{ new T[cRow * cCol]() } {}

template <class T>
MatrixArr<T>::MatrixArr(const MatrixArr<T>& rhs)
	: cRow_{ rhs.cRow_ }, cCol_{ rhs.cCol_ }, _data{ new T[cRow_ * cCol_] }
{
	std::uninitialized_copy(rhs._data, rhs._data + (rhs.cRow_ * rhs.cCol_), _data);
}

template <class T>
MatrixArr<T>::~MatrixArr()
{
	_data = nullptr;
	delete[] _data;
}

template <class T>
MatrixArr<T>& MatrixArr<T>::operator=(const MatrixArr<T>& rhs)
{
	assert(rhs.cRow_ == cRow_);
	assert(rhs.cCol_ == cCol_);
	if (this != &rhs)
	{
		cRow_ = rhs.cRow_;
		cCol_ = rhs.cCol_;
		_data = rhs._data;
	}
	return *this;
}

template <class T>
bool MatrixArr<T>::operator==(const MatrixArr<T>& rhs) const
{
	if (cRow_ != rhs.cRow_ || cCol_ != rhs.cCol_)
	{
		return false;
	}
	for (ptrdiff_t i = 0; i < cRow_ * cCol_; i++)
	{
		if (_data[i] != rhs._data[i])
		{
			return false;
		}
	}
	return true;
}

template <class T>
T MatrixArr<T>::at(const ptrdiff_t cRow, const ptrdiff_t cCol) const
{
	return _data[getIndexArray(cRow, cCol)];
}

template <class T>
T& MatrixArr<T>::at(const ptrdiff_t cRow, const ptrdiff_t cCol)
{
	return _data[getIndexArray(cRow, cCol)];
}

template <class T>
std::ostream& MatrixArr<T>::print(std::ostream& ostrim) const
{
	T *temp = _data;
	ostrim << "MatrixArr(";
	if (temp == nullptr || cCol_ == 0 || cRow_ == 0)
	{
		ostrim << "null)";
		return ostrim;
	}
	for (ptrdiff_t i = 0; i < cRow_; i++)
	{
		if (i > 0)
		{
			ostrim << "          ";
		}
		ostrim << _data[getIndexArray(i, 0)];
		for (ptrdiff_t j = 1; j < cCol_; j++)
		{
			ostrim << ", " << _data[getIndexArray(i, j)];
		}
		if (i != cRow_ - 1)
		{
			ostrim << "\n";
		}
	}
	ostrim << ")";
	return ostrim;
}

template <class T>
ptrdiff_t MatrixArr<T>::getIndexArray(const ptrdiff_t cRow, const ptrdiff_t cCol) const
{
	assert(cRow >= 0);
	assert(cRow < cRow_);
	assert(cCol >= 0);
	assert(cCol < cCol_);
	return cCol_ * cRow + cCol;
}

template<typename T>
std::ostream& operator<<(std::ostream& ostrim, const MatrixArr<T>& z)
{
	return z.print(ostrim);
}

void test()
{
	cout << "Test constructors" << endl;
	MatrixArr<int> s01;
	cout << "MatrixArr() = " << s01 << endl;
	MatrixArr<int> s02{ 1,1 };
	cout << "MatrixArr(1, 1) = " << s02 << endl;
	MatrixArr<int> s03{ s02 };
	cout << "MatrixArr(MatrixArr(1, 1)) = " << s03 << endl;

	cout << "\nTest MatrixArr at" << endl;
	MatrixArr<int> s04{ 3, 4 };
	cout << s04 << endl;
	int x{ 1 };
	for (ptrdiff_t i = 0; i < 3; i++)
	{
		for (ptrdiff_t j = 0; j < 4; j++)
		{
			cout << "s04.at(" << i << ", " << j << ") = " << x << ";  ";
			s04.at(i, j) = x;
			x++;
		}
		cout << "\n";
	}
	cout << s04 << endl;

	cout << "\nTest MatrixArr operator=" << endl;
	MatrixArr<int> s05{ 3, 4 };
	cout << s05 << endl;
	cout << "s05 = s04\n" << (s05 = s04) << endl;

	cout << "\nTest MatrixArr operator== and operator!=" << endl;
	cout << "s05 == s04 = " << boolalpha << (s05 == s04) << endl;
	cout << "s05 != s04 = " << boolalpha << (s05 != s04) << endl;
}