#pragma once
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator	iter;
	iter = std::find(container.begin(), container.end(), value);
	//auto iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
	{
		throw std::logic_error("value not found in the container!");
	}
	return (iter);
}
//T를 정수형 컨테이너, (연관컨테이너는 처리하지 않아도 되니까 시퀀스컨테이너이다)
//컨테이너 안에 b가 있는지 찾는 함수 easyfind
//반환값은 뭘로 해야하지? ->dependent name