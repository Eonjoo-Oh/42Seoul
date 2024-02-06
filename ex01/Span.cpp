#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int	n) : N(n) {}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	_v = obj._v;
	N = obj.N;
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (static_cast<unsigned int>(_v.size()) < N)
		_v.push_back(n);
	else
		throw (spanFullException());
}

const char	*Span::spanExistException::what() const throw()
{
	return ("no span can be found!");
}

const char	*Span::spanFullException::what() const throw()
{
	return ("span is Full!");
}

void	Span::addNumbers(std::vector<int> toBePutV)
{
	if (_v.size() + toBePutV.size() > N)
		throw (spanFullException());
	_v.insert(_v.end(), toBePutV.begin(), toBePutV.end());
}

long long	Span::shortestSpan()
{
	long long	shortestSpan;
	long long	temp;
	if (_v.empty() || _v.size() == 1)
		throw(spanExistException());

	shortestSpan = abs(static_cast<long long>(_v[0]) - static_cast<long long>(_v[1]));
	for (size_t i = 1; i < _v.size() - 1; i++)
	{
		temp = abs(static_cast<long long>(_v[i]) - static_cast<long long>(_v[i + 1]));
		if (shortestSpan > temp)
			shortestSpan = temp;
	}
	return (shortestSpan);
}

long long	Span::longestSpan()
{
	long long	maxElement;
	long long	minElement;
	long long	longestSpan;

	if (_v.empty() || _v.size() == 1)
		throw(spanExistException());
	maxElement = *(std::max_element(_v.begin(), _v.end()));
	minElement = *(std::min_element(_v.begin(), _v.end()));
	longestSpan = maxElement - minElement;
	return (longestSpan);
}

void	Span::printAllElement()
{
	for(size_t	i = 0; i < _v.size(); i++)
	{
		std::cout << _v[i];
		if (i < _v.size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}
