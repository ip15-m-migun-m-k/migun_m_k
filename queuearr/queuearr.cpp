#include "queuearr.h"

template <class T>
QueueArr<T>::QueueArr()
	: QueueArr{ ptrdiff_t{ 0 } } {}

template <class T>
QueueArr<T>::QueueArr(const ptrdiff_t rhs)
	: data_{ new T[rhs] }, head_{ 0 }, tail_{ 0 }, dims_{ rhs } {}

template <class T>
QueueArr<T>::QueueArr(std::initializer_list<T> rhs)
	: data_{ new T[rhs.size()] }, head_{ 0 }, tail_{ (ptrdiff_t)rhs.size() }, dims_{ (ptrdiff_t)rhs.size() }
{
	std::uninitialized_copy(rhs.begin(), rhs.end(), data_);
}

template <class T>
QueueArr<T>::QueueArr(const QueueArr<T>& rhs)
	: data_{ new T[rhs.dims_] }, head_{ rhs.head_ }, tail_{ rhs.tail_ }, dims_{ rhs.dims_ }
{
	std::uninitialized_copy(rhs.data_, rhs.data_ + rhs.dims_, data_);
}

template <class T>
QueueArr<T>::~QueueArr()
{
	data_ = nullptr;
	delete[] data_;
}

template <class T>
QueueArr<T>& QueueArr<T>::operator=(const QueueArr<T>& rhs)
{
	if (this != &rhs)
	{
		data_ = rhs.data_;
		head_ = rhs.head_;
		dims_ = rhs.dims_;
		tail_ = rhs.tail_;
	}
	return *this;
}

template <class T>
void QueueArr<T>::push(const T rhs)
{
	if (!isEmpty())
	{
		if (dims_ == tail_ && head_ == 0)
		{
			T* newData_{ new T[dims_ * 2] };
			std::uninitialized_copy(data_, data_ + dims_, newData_);
			delete[] data_;
			data_ = newData_;
			dims_ *= 2;
		}
		else if (dims_ == tail_ && head_ > 0)
		{
			tail_ = 0;
		}
		else if (head_ == tail_)
		{
			T* newData_{ new T[dims_ * 2] };
			std::uninitialized_copy(data_ + head_, data_ + dims_, newData_);
			std::uninitialized_copy(data_, data_ + tail_, newData_ + dims_ - head_);
			delete[] data_;
			data_ = newData_;
			tail_ = dims_ - head_ + tail_;
			head_ = 0;
			dims_ *= 2;
		}
	}
	data_[tail_] = rhs;
	tail_++;
}

template <class T>
void QueueArr<T>::pop()
{
	if (!isEmpty())
	{
		head_++;
	}
}

template <class T>
T QueueArr<T>::getFirst()
{
	if (isEmpty())
	{
		throw ("Queue is empty");
	}
	return data_[head_];
}

template <class T>
std::ostream& QueueArr<T>::print(std::ostream& ostrim) const
{
	ostrim << "QueenArr(";

	if (isEmpty())
	{
		ostrim << "null)";
		return ostrim;
	}

	ostrim << data_[head_];
	for (ptrdiff_t i = head_ + 1; i < tail_; i++)
	{
		ostrim << ", " << data_[i];
	}

	if (tail_ <= head_)
	{
		for (ptrdiff_t i = 0; i < tail_; i++)
		{
			ostrim << ", " << data_[i];
		}
	}
	ostrim << ")";
	return ostrim;
}

template<class T>
std::ostream& operator<< (std::ostream& ostrim, const QueueArr<T>& z)
{
	return z.print(ostrim);
}

void test()
{
	cout << "Test constructors" << endl;
	QueueArr<int> s01;
	cout << "QueenArr() = " << s01 << endl;
	QueueArr<int> s02{ 5 };
	cout << "QueenArr(5) = " << s02 << endl;
	QueueArr<int> s03{ s02 };
	cout << "QueenArr(s02) = " << s03 << endl;
	QueueArr<int> s05{ 20, 21, 23 };
	cout << "QueenArr(20, 21, 23) = " << s05 << endl;

	cout << "\nTest QueenArr operator=" << endl;
	QueueArr<int> s04{ 20 };
	cout << "QueenArr(20) = " << s04 << endl;
	s04 = s05;
	cout << "s04 = s05 " << s04 << endl;

	cout << "\nTest QueenArr push" << endl;
	cout << s02;
	s02.push(2);
	cout << ".push(2) = " << s02 << endl;
	cout << s02;
	s02.push(3);
	cout << ".push(3) = " << s02 << endl;
	cout << s02;
	s02.push(4);
	cout << ".push(4) = " << s02 << endl;

	cout << "\nTest QueenArr pop" << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;

	cout << "\nTest QueenArr getFirst" << endl;
	QueueArr<int> s06{ 20, 21, 22, 23, 24, 25 };
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;

	cout << "\nTest QueenArr recreate data_" << endl;
	QueueArr<int> s07{ 1 };
	cout << s07 << ".push(2) = ";
	s07.push(2);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".pop() = ";
	s07.pop();
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(3) = ";
	s07.push(3);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(4) = ";
	s07.push(4);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(5) = ";
	s07.push(5);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".pop() = ";
	s07.pop();
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".pop() = ";
	s07.pop();
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(6) = ";
	s07.push(6);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(7) = ";
	s07.push(7);
	cout << s07 << " size data_ = " << s07.dims() << endl;
	cout << s07 << ".push(8) = ";
	s07.push(8);
	cout << s07 << " size data_ = " << s07.dims() << endl;
}