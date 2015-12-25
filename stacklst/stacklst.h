#ifndef stacklst_h
#define stacklst_h

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

template<class T>
class StackLst
{
public:
	StackLst() = default;
	StackLst(initializer_list<T> v);
	StackLst(const StackLst<T>& v);
	~StackLst();

	StackLst& operator= (const StackLst<T>& v);
	void push(const T v);
	bool isEmpty() const
	{
		return nullptr == head_;
	}
	void pop();

	T getTop();
	ostream& print(ostream& ostrim) const;
private:
	struct Element
	{
		T data_{ T{} };
		Element* next_{ nullptr };
	};
	Element* head_{ nullptr };

	void copy(const StackLst<T>& rhs);
};

template<typename T>
ostream& operator<<(ostream& ostrim, const StackLst<T>& z);

void test();

#endif