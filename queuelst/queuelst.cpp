#include "queuelst.h"

template <class T>
QueueLst<T>::QueueLst(std::initializer_list<T> rhs)
{
	T* data_{ new T[rhs.size()] };
	std::uninitialized_copy(rhs.begin(), rhs.end(), data_);
	for (size_t i = 0; i < rhs.size(); i++)
	{
		push(data_[i]);
	}
}

template <class T>
QueueLst<T>::QueueLst(const QueueLst<T>& rhs)
{
	copy(rhs);
}

template <class T>
QueueLst<T>::~QueueLst()
{
	clear();
}

template <class T>
QueueLst<T>& QueueLst<T>::operator=(const QueueLst<T>& rhs)
{
	if (this != &rhs)
	{
		copy(rhs);
	}
	return *this;
}

template <class T>
void QueueLst<T>::push(const T rhs)
{
	Element* temp{ new Element };
	temp->data_ = rhs;
	if (tail_ != nullptr)
	{
		tail_->next_ = temp;
	}
	tail_ = temp;
	if (isEmpty())
	{
		head_ = temp;
	}
}

template <class T>
void QueueLst<T>::pop()
{
	if (!isEmpty())
	{
		Element *temp{ head_->next_ };
		delete head_;
		head_ = temp;
	}
}

template <class T>
T QueueLst<T>::getFirst()
{
	assert(!isEmpty());
	return head_->data_;
}

template <class T>
std::ostream& QueueLst<T>::print(std::ostream& ostrim) const
{
	Element *temp = head_;
	ostrim << "QueueLst(";
	if (temp == nullptr)
	{
		ostrim << "null)";
		return ostrim;
	}
	ostrim << temp->data_;
	temp = temp->next_;
	while (temp != nullptr)
	{
		ostrim << ", " << temp->data_;
		temp = temp->next_;
	}
	ostrim << ")";
	return ostrim;
}

template <class T>
void QueueLst<T>::copy(const QueueLst<T>& rhs)
{
	clear();
	if (!rhs.isEmpty())
	{
		push(rhs.head_->data_);
		Element* last{ head_ };
		Element* tempRhs{ rhs.head_->next_ };
		while (tempRhs != nullptr)
		{
			Element* temp{ new Element };
			temp->data_ = tempRhs->data_;
			temp->next_ = last->next_;
			last->next_ = temp;
			last = temp;
			tempRhs = tempRhs->next_;
		}
	}
}

template <class T>
void QueueLst<T>::clear()
{
	while (!isEmpty())
	{
		pop();
	}
	tail_ = nullptr;
}

template<class T>
std::ostream& operator<<(std::ostream& ostrim, const QueueLst<T>& z)
{
	return z.print(ostrim);
}

void test()
{
	cout << "Test constructors" << endl;
	QueueLst<int> s01;
	cout << "QueueLst() = " << s01 << endl;
	QueueLst<int> s02{ 1 };
	cout << "QueueLst(5) = " << s02 << endl;
	QueueLst<int> s03{ s02 };
	cout << "QueueLst(s02) = " << s03 << endl;
	QueueLst<int> s05{ 20, 21, 23 };
	cout << "QueueLst(20, 21, 23) = " << s05 << endl;


	cout << "\nTest QueueLst operator=" << endl;
	QueueLst<int> s04{ 20 };
	cout << "QueueLst(20) = " << s04 << endl;
	s04 = s05;
	cout << "s04 = s05 " << s04 << endl;

	cout << "\nTest QueueLst push" << endl;
	cout << s02;
	s02.push(2);
	cout << ".push(2) = " << s02 << endl;
	cout << s02;
	s02.push(3);
	cout << ".push(3) = " << s02 << endl;
	cout << s02;
	s02.push(4);
	cout << ".push(4) = " << s02 << endl;

	cout << "\nTest QueueLst pop" << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;

	cout << "\nTest QueueLst getFirst" << endl;
	QueueLst<int> s06{ 20, 21, 22, 23, 24, 25 };
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
	s06.pop();
	cout << s06 << ".getFirst() = " << s06.getFirst() << endl;
}