#include "matrixnec.h"

template <class T>
MatrixNec<T>::MatrixNec(const ptrdiff_t nRow, const ptrdiff_t nCol)
	:cRow_{ nRow }, cCol_{ nCol }, _data{ new T*[nRow] }
{
	T* temp{ new T[nRow * nCol]() };
	for (ptrdiff_t i = 0; i < nRow; i++)
	{
		_data[i] = &temp[i * nCol];
	}
}

template <class T>
MatrixNec<T>::MatrixNec(const MatrixNec<T>& rhs)
	: MatrixNec{ rhs.cRow_, rhs.cCol_ }
{
	std::uninitialized_copy(rhs._data[0], rhs._data[0] + (rhs.cRow_ * rhs.cCol_), _data[0]);
}

template <class T>
MatrixNec<T>::~MatrixNec()
{
	_data = nullptr;
	delete[] _data;
}

template <class T>
MatrixNec<T>& MatrixNec<T>::operator=(const MatrixNec<T>& rhs)
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
bool MatrixNec<T>::operator==(const MatrixNec<T>& rhs) const
{
	if (cRow_ != rhs.cRow_ || cCol_ != rhs.cCol_)
	{
		return false;
	}
	for (ptrdiff_t i = 0; i < cRow_ * cCol_; i++)
	{
		if (*(_data[0] + i) != *(rhs._data[0] + i))
		{
			return false;
		}
	}
	return true;
}

template <class T>
T MatrixNec<T>::at(const ptrdiff_t znach) const
{
	ptrdiff_t tcr = (ptrdiff_t)znach / columns();
	ptrdiff_t tcc = (ptrdiff_t)znach % columns();
	return getIndexArray(tcr, tcc);
}

template <class T>
T& MatrixNec<T>::at(const ptrdiff_t znach)
{
	ptrdiff_t tcr = (ptrdiff_t)znach / columns();
	ptrdiff_t tcc = (ptrdiff_t)znach % columns();
	return getIndexArray(tcr, tcc);
}

template <class T>
std::ostream& MatrixNec<T>::print(std::ostream& ostrim) const
{
	T** temp = _data;
	ostrim << "MatrixNec(";
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
		ostrim << getIndexArray(i, 0);
		for (ptrdiff_t j = 1; j < cCol_; j++)
		{
			ostrim << ", " << getIndexArray(i, j);
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
T& MatrixNec<T>::getIndexArray(const ptrdiff_t cRow, const ptrdiff_t cCol) const
{
	assert(cRow >= 0);
	assert(cRow < cRow_);
	assert(cCol >= 0);
	assert(cCol < cCol_);
	return *(_data[cRow] + cCol);
}

template<class T>
std::ostream& operator<<(std::ostream& ostrim, const MatrixNec<T>& z)
{
	return z.print(ostrim);
}

void test()
{
	cout << "Test constructors" << endl;
	MatrixNec<int> s01;
	cout << "MatrixNec() = " << s01 << endl;
	MatrixNec<int> s02{ 1, 1 };
	cout << "MatrixNec(1, 1) = " << s02 << endl;
	MatrixNec<int> s03{ s02 };
	cout << "MatrixNec(MatrixArr(1, 1)) = " << s03 << endl;

	cout << "\nTest MatrixNec at" << endl;
	MatrixNec<int> s04{ 3, 4 };
	cout << s04 << endl;
	int x{ 1 };
	for (ptrdiff_t i = 0; i < 12; i++)
	{
		s04.at(i) = x;
		x++;
	}
	cout << s04 << endl;

	cout << "\nTest MatrixNec operator=" << endl;
	MatrixNec<int> s05{ 3, 4 };
	cout << s05 << endl;
	cout << "\ns05 = s04\n" << (s05 = s04) << endl;

	cout << "\nTest MatrixNec operator== and operator!=" << endl;
	cout << "s05 == s04 = " << boolalpha << (s05 == s04) << endl;
	cout << "s05 != s04 = " << boolalpha << (s05 != s04) << endl;
}