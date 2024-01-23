# pragma once

#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public :
		MutantStack();
		MutantStack(const MutantStack &obj);
		MutantStack &operator=(const MutantStack &obj);
		~MutantStack();

		typedef typename MutantStack<T>::stack::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();
};

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &obj) 
{
	*this = obj;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &obj)
{
	(void)obj;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
MutantStack<T> iterator::begin()
{

}

template <typename T>
MutantStack<T> iterator:: end()
{

}