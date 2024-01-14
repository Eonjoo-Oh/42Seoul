#pragma once

#include <iostream>

template<typename T>
void	iter(T *arrayAdd, size_t arrayLength, void (*f)(const T&))
{
	for(size_t i = 0; i < arrayLength; i++)
	{
		f(arrayAdd[i]);
		if (i < arrayLength - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

template<typename T>
void	printEveryElementOfArray(const T &element)
{
	std::cout << element;
}
