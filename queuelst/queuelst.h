#ifndef queuelst_h
#define queuelst_h

using namespace std;

#include <iostream>
#include <cassert>
#include <initializer_list>
#include <memory>
#include <cstddef>

template<class T>
class QueueLst
{
public:
	QueueLst() = default;
	QueueLst(std::initializer_list<T> rhs);
	QueueLst(const QueueLst<T>& rhs);
	~QueueLst();
	QueueLst& operator=(const QueueLst<T>& rhs);
	void push(const T rhs);
	bool isEmpty() const { return head_ == nullptr; };
	void pop();
	T getFirst();
	std::ostream& print(std::ostream& ostrim) const;
private:
	struct Element
	{
		T data_{ T{} };
		Element* next_{ nullptr };
	};

	Element* head_{ nullptr };
	Element* tail_{ nullptr };

	void copy(const QueueLst<T>& rhs);
	void clear();
};

template<class T>
std::ostream& operator<<(std::ostream& ostrim, const QueueLst<T>& z);

void test();
#endif
