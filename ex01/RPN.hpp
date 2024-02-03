# pragma once

#include <iostream>
#include <stack>
#include <exception>
#include <stdexcept>

class	RPN
{
	private :
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
		std::stack<int>	_rpnStack;
		int				_rightValue;
		int				_leftValue;
		int				_result;

		bool			isOperator(char c);
	public :
		RPN();
		~RPN();

		void	calculate(std::string argv);
		void	printResult();
};