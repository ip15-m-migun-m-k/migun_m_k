#ifndef queuearr_h
#define queuearr_h

using namespace std;

#include <iostream>
#include <cassert>
#include <memory>
#include <initializer_list>
#include <cstddef>

template<class T>
class QueueArr
{
public:
	QueueArr();
	QueueArr(const ptrdiff_t rhs);
	QueueArr(std::initializer_list<T> rhs);
	QueueArr(const QueueArr<T>& rhs);
	~QueueArr();

	QueueArr & operator= (const QueueArr<T>& rhs);
	void push(const T rhs);
	bool isEmpty() const { return tail_ == head_ && tail_ == 0; };
	void pop();
	T getFirst();
	ptrdiff_t dims() { return dims_; };
	std::ostream& print(std::ostream& ostrim) const;
private:
	T* data_{ nullptr };
	ptrdiff_t head_{ 0 };
	ptrdiff_t tail_{ 0 };
	ptrdiff_t dims_{ 0 };
};

template<class T>
std::ostream& operator<< (std::ostream& ostrim, const QueueArr<T>& z);

void test();
#endif
