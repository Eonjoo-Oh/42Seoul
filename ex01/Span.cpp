#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int	n) : N(n) {}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	v = obj.v;//std::vector의 복사 대입연산자에서 깊은 복사를 수행
	N = obj.N;
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_v.size() < n)
		_v.push_back(n);
	else
		throw (std::logic_error("array is full!"));
}

void	Span::addNumbers(std::vector<int> v)
{
//벡터와 벡터를 합치는 로직
}

unsigned int	Span::shortestSpan()
{
	if (_v.empty() || _v.size() == 1)
		throw(std::logic_error("no span can be found!"));
}

unsigned int	Span::longestSpan()
{
	if (_v.empty() || _v.size() == 1)
		throw(std::logic_error("no span can be found!"));

}
//longest span은 최댓값과 최댓값의 차, shortest span은 최솟값과 그 다음 최솟값의 차이