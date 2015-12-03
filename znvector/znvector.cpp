#include "znvector.h"

using namespace std;

ZnVector::ZnVector(const IndexType dims) 
	: dims_{ dims } 
{ 
	data_ = new ValueType[dims_]; 
} 

ZnVector::ZnVector(const ZnVector& vec) 
	: dims_{ vec.dims_ } 
	, data_{ new ValueType[dims_] } 
{
	std::uninitialized_copy(vec.data_, vec.data_ + vec.dims_, data_); 
} 

ZnVector::ZnVector(ZnVector&& vec) 
	: dims_{ vec.dims_ } 
	, data_{ vec.data_ } 
{
	vec.dims_ = 0;
	vec.data_ = nullptr; 
} 

ZnVector::ZnVector(std::initializer_list<ValueType> vals)
	: dims_{ static_cast<IndexType>(vals.size()) }
	, data_{ new ValueType[dims_] }
{
	std::uninitialized_copy(vals.begin(), vals.end(), data_);
} 

ZnVector::~ZnVector() 
{
	delete[] data_; 
} 

ZnVector& ZnVector::operator=(const ZnVector& arr) 
{ 
	if (this != &arr)
	{
		ValueType diff = dims_ - arr.dims_;
		if (diff < 0)
		{
			dims_ = arr.dims_;
			delete[] data_;
			data_ = new ValueType[arr.dims_];
			uninitialized_copy(arr.data_, arr.data_ + arr.dims_, data_);
		}
		else
		{
			swap(ZnVector(arr));
		}
	}
	return *this; 
} 

ZnVector& ZnVector::operator=(ZnVector&& arr) 
{ 
	if (this != &arr) 
	{ 
		swap(arr); 
	} 
	return *this; 
} 

ZnVector::ValueType& ZnVector::operator[](const IndexType index) 
{ 
	assert(index >= 0); 
	assert(index < dims_); 
	if ((index < 0) || (dims_ <= index)) 
	{ 
		throw out_of_range("index out of range in ZnVector::operator[]");
	} 
	return data_[index];
} 

const ZnVector::ValueType& ZnVector::operator[](const IndexType index) const 
{ 
	assert(index >= 0); 
	assert(index < dims_); 
	if ((index < 0) || (dims_ <= index)) 
	{ 
		throw out_of_range("index out of range in ZnVector::operator[]"); 
	} 
	return data_[index]; 
} 

void ZnVector::swap(ZnVector& arr) 
{ 
	IndexType dims{ arr.dims_ }; 
	arr.dims_ = dims_; 
	dims_ = dims; 
	ValueType* data{ arr.data_ }; 
	arr.data_ = data_; 
	data_ = data; 
}

ZnVector ZnVector::operator-()
{
	ZnVector res(dims_);
	for (IndexType i{ 0 }; i < dims_; i += 1)
	{
		res.data_[i] = -data_[i];
	}
	return res;
} 

ZnVector operator+(const ZnVector& lhs, const ZnVector& rhs) { return ZnVector(lhs) += rhs; }
ZnVector operator+(const ZnVector& lhs, const int32_t rhs) { return ZnVector(lhs) += rhs; }
ZnVector operator-(const ZnVector& lhs, const ZnVector& rhs) { return ZnVector(lhs) -= rhs; }
ZnVector operator-(const ZnVector& lhs, const int32_t rhs) { return ZnVector(lhs) -= rhs; }
ZnVector operator*(const ZnVector& lhs, const int32_t rhs) {	return ZnVector(lhs) *= rhs; }
ZnVector operator*(const int32_t lhs, const ZnVector& rhs) {	return ZnVector(rhs) *= lhs; }
ZnVector operator/(const ZnVector& lhs, const int32_t rhs) {	return ZnVector(lhs) /= rhs; }
ZnVector& ZnVector::operator+=(const ZnVector& rhs) 
{
	IndexType i{ 0 };
	if (dims_ >= rhs.dims_)
	{
		for_each(data_, data_ + rhs.dims_, [rhs, i](ValueType& v) mutable { v += rhs[i]; i++; });
	}
	else
	{
		ZnVector tmp(*this);
		IndexType odims = dims_;
		delete[] data_;
		dims_ = rhs.dims_;
		data_ = new ValueType[rhs.dims_];
		uninitialized_copy(rhs.data_, rhs.data_ + rhs.dims_, data_);
		for_each(data_, data_ + tmp.dims_, [tmp, i](ValueType& v) mutable { v += tmp[i]; i++; });
	}
	return *this; 
} 

ZnVector& ZnVector::operator+=(const ValueType rhs)
{
	for_each(data_, data_ + dims_, [rhs](ValueType& v) { v += rhs; });
	return *this; 
}

ZnVector& ZnVector::operator-=(const ZnVector& rhs) 
{ 
	IndexType i{ 0 };
	if (dims_ >= rhs.dims_)
	{
		for_each(data_, data_ + rhs.dims_, [rhs, i](ValueType& v) mutable { v -= rhs[i]; i++; });
	}
	else
	{
		ZnVector tmp(*this);
		IndexType odims = dims_;
		delete[] data_;
		dims_ = rhs.dims_;
		data_ = new ValueType[rhs.dims_];
		uninitialized_copy(rhs.data_, rhs.data_ + rhs.dims_, data_);
		for_each(data_, data_ + tmp.dims_, [tmp, i](ValueType& v) mutable { v -= tmp[i]; i++; });
	}
	return *this; 
} 

ZnVector& ZnVector::operator-=(const ValueType rhs) 
{ 
	for (IndexType i{0}; i != dims_; ++i)
	{ 
		data_[i] -= rhs; 
	} 
	return *this; 
} 

ZnVector& ZnVector::operator*=(const ValueType rhs) 
{ 
	for (ValueType* i{data_}, *iEnd{data_ + dims_}; i != iEnd; ++i) 
	{
		*i *= rhs;
	} 
	return *this; 
} 

ZnVector& ZnVector::operator/=(const ValueType rhs) 
{ 
	for (int i = 0; i < dims_; i++)
	{
		data_[i] /= rhs;
	}
	return *this; 
}  

std::ostream& operator<<(std::ostream& ostrm, const ZnVector& v)
{
	return v.print(ostrm);
}

std::ostream & ZnVector::print(std::ostream& ostrm) const
{
	ostrm << "( ";
	for (int i = 0; i < dims_; i++)
	{
		if ((i + 1) < dims_)
			ostrm << data_[i] << ", ";
		else
			ostrm << data_[i];
	}
	ostrm << " )";
	return ostrm;
}

void testVectorByIndexRead(const ZnVector& v, const ptrdiff_t i)
{
	try
	{
		cout << "read v[" << i << "] -> ";
		cout << v[i];
	}
	catch (const out_of_range& ex)
	{
		cout << "exception caught " << ex.what();
	}
}
