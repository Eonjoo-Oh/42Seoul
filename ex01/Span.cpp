#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int	n) : N(n) {}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	_v = obj._v;//std::vector의 복사 대입연산자에서 깊은 복사를 수행
	N = obj.N;
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_v.size() < n)
		_v.push_back(n);
	else
		throw (spanFullException());
}

void	Span::addNumbers(std::vector<int> toBePutV)
{
	if (_v.size() + toBePutV.size() > N)
		throw (spanFullException());
	_v.insert(_v.end(), toBePutV.begin(), toBePutV.end());
//벡터와 벡터를 합치는 로직
}//매개변수를 뭘로 받아야하지?

unsigned int	Span::shortestSpan()
{
	if (_v.empty() || _v.size() == 1)
		throw(spanExistException());
	sort(_v.begin(), _v.end());
	return (abs(_v[0] - _v[1]));
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
//longest span은 최댓값과 최댓값의 차, shortest span은 최솟값과 그 다음 최솟값의 차이

const char	*Span::spanExistException::what() const throw()
{
	std::cout << "no span can be found!";
}

const char	*Span::spanFullException::what() const throw()
{
	std::cout << "span is Full!";
}