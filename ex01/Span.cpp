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


