#include "stacklst.h"

template <class T>
StackLst<T>::StackLst(initializer_list<T> v)
{
	vector <T> temp;
	temp.insert(temp.end(), v.begin(), v.end());
	for (size_t i = 0; i < temp.size(); i++)
	{
		push(temp[i]);
	}
}

template<typename T>
StackLst<T>::StackLst(const StackLst<T>& rhs)
{
	copy(rhs);
}

template<typename T>
StackLst<T>::~StackLst()
{
	while (!isEmpty())
	{
		pop();
	}
}

template <class T>
StackLst<T>& StackLst<T>::operator=(const StackLst<T>& rhs)
{
	if (this != &rhs)
	{
		head_ = nullptr;
		copy(rhs);
	}
	return *this;
}

template<typename T>
void StackLst<T>::push(const T v)
{
	Element* temp{ new Element };
	temp->data_ = v;
	temp->next_ = head_;
	head_ = temp;
}

template<typename T>
void StackLst<T>::pop()
{
	if (!isEmpty())
	{
		Element *temp{ head_->next_ };
		delete head_;
		head_ = temp;
	}
}

template<typename T>
T StackLst<T>::getTop()
{
	assert(!isEmpty());
	return head_->data_;
}

template<typename T>
ostream& StackLst<T>::print(ostream& ostrim) const
{
	Element *temp = head_;
	ostrim << "StackLst(";
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
void StackLst<T>::copy(const StackLst<T>& rhs)
{
	Element* tempRhs{ rhs.head_ };
	while (tempRhs != nullptr)
	{
		if (isEmpty())
		{
			push(tempRhs->data_);
		}
		else
		{
			Element* tempLhs{ head_ };
			while (tempLhs->next_ != nullptr)
			{
				tempLhs = tempLhs->next_;
			}
			Element* nE{ new Element };
			nE->data_ = tempRhs->data_;
			tempLhs->next_ = nE;
		}
		tempRhs = tempRhs->next_;
	}
}

template<typename T>
ostream& operator<<(ostream& ostrim, const StackLst<T>& z)
{
	return z.print(ostrim);
}

void test()
{
	cout << "Test constructors" << endl;
	StackLst<int> s01;
	cout << "StackLst() = " << s01 << endl;
	StackLst<int> s02{ 13 };
	cout << "StackLst(5) = " << s02 << endl;
	StackLst<int> s03{ s02 };
	cout << "StackLst(StackLst(s02)) = " << s03 << endl;
	StackLst<int> s05{ 6, 666, 66 };
	cout << "StackLst(6, 666, 66) = " << s05 << endl;

	cout << "\nTest StackLst operator=" << endl;
	StackLst<int> s04{ 432 };
	cout << "StackLst(432) = " << s04 << endl;
	s04 = s02;
	cout << "s04 = s02 " << s04 << endl;

	cout << "\nTest StackLst push" << endl;
	cout << s02;
	s02.push(567);
	cout << ".push(567) = " << s02 << endl;
	cout << s02;
	s02.push(812);
	cout << ".push(812) = " << s02 << endl;
	cout << s02;
	s02.push(22);
	cout << ".push(22) = " << s02 << endl;

	cout << "\nTest Stack pop" << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;
	cout << s02 << ".pop() = ";
	s02.pop();
	cout << s02 << endl;

	cout << "\nTest Stack getTop" << endl;
	cout << s02 << ".getTop() = " << s02.getTop() << endl;
	s02.push(92);
	cout << s02 << ".getTop() = " << s02.getTop() << endl;
	s02.push(71);
	cout << s02 << ".getTop() = " << s02.getTop() << endl;
	s02.push(42);
	cout << s02 << ".getTop() = " << s02.getTop() << endl;
}