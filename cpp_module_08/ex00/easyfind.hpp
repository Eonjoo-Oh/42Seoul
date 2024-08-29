#pragma once
#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator	iter;
	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
	{
		throw std::runtime_error("value not found in the container!");
	}
	return (iter);
}