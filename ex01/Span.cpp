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

unsigned int	Span::shortestSpan()
{
	int	shortestSpan;

	if (_v.empty() || _v.size() == 1)
		throw(spanExistException());

	shortestSpan = abs(_v[0] - _v[1]);
	for (size_t i = 1; i < _v.size() - 1; i++)
	{
		if (shortestSpan > abs(_v[i] - _v[i + 1]))
			shortestSpan = abs(_v[i] - _v[i + 1]);
	}
	return (static_cast<unsigned int>(shortestSpan));
}

unsigned int	Span::longestSpan()
{
	int	maxElement;
	int	minElement;

	if (_v.empty() || _v.size() == 1)
		throw(spanExistException());
	maxElement = *(std::max_element(_v.begin(), _v.end()));
	minElement = *(std::min_element(_v.begin(), _v.end()));
	return (abs(maxElement - minElement));
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
