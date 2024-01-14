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
		T &operator[](unsigned int index);
		~Array();
		int	size();
};

template <typename T>
Array<T>::Array()
{
	_arr = new T;
	*_arr = NULL;
	n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_arr = new T[n];
	_n = n;
	for (unsigned int i = 0; i < n; i++)
	{
		_arr[n] = 0;
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
	_arr = new Arr[obj._n];
	for(unsigned int i = 0; i < obj._n; i++)
	{
		_arr[i] = obj._arr[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	try
	{
		T	element;

		element = _arr[index];
		return (element);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

template <typename T>
Array<T>::~Array()
{
	if (_arr != NULL)
		delete[] _arr;
}

template <typename T>
int	Array<T>::size()
{
	return (_n);
}