#pragma once
#include <iostream>
#include <vector>

class	Span
{
	private :
		std::vector<int>	v;
		unsigned int	N; //저장할 수 있는 정수의 갯수
	public :
		Span();
		Span(unsigned int N);
		Span(const Span &obj);
		Span &operator=(const Span &obj);
		~Span();

		void			addNumber(int	N);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
}