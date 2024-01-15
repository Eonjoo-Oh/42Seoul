#pragma once

#include <iostream>

template <typename T>
class	Array
{
	private:
		T				*_arr;
		unsigned int	_n;
	public :
		Array();
		Array(unsigned int	n);
		Array(const Array &obj);
		Array &operator=(const Array &obj);
		T &operator[](int const index);
		const T &operator[](int const index) const;
		~Array();
		unsigned int	size();
		T 				*getArrAddr();
};

template <typename T>
Array<T>::Array() : _arr(NULL), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(NULL), _n(n)
{
	if (n > 0)
	{
		_arr = new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			_arr[n] = 0;
		}
	}
}

template <typename T>
Array<T>::Array(const Array<T> &obj)
{
	*this = obj;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &obj)
{
	if (obj._n == 0)
		_arr = NULL;
	else
	{
		_arr = new T[obj._n];
		for(unsigned int i = 0; i < obj._n; i++)
		{
			_arr[i] = obj._arr[i];
		}
	}
	_n = obj._n;
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int const index)
{
	if (index < 0 || index >= static_cast<int>(_n))
		throw (std::out_of_range("index out of range"));
	return (_arr[index]);
}

template <typename T>
const T &Array<T>::operator[](int const index) const
{
	if (index < 0 || index >= static_cast<int>(_n))
		throw (std::out_of_range("index out of range"));
	return (_arr[index]);
}

template <typename T>
Array<T>::~Array()
{
	if (_arr != NULL)
		delete[] _arr;
}

template <typename T>
unsigned int	Array<T>::size()
{
	return (_n);
}

template <typename T>
T	*Array<T>::getArrAddr()
{
	return (_arr);
}
