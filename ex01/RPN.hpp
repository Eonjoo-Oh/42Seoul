# pragma once

#include <iostream>
#include <stack>

class	RPN
{
	private :
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
		std::stack<int>	_rpnStack;
		int				_rightValue;
		int				_leftValue;
		int				_result;
	public :
		RPN();
		~RPN();

		void	calculate(std::string argv);
		void	printResult();
};