#include "RPN.hpp"

RPN::RPN() 
{
	_operatorCnt = 0;
}

RPN::RPN(const RPN &obj) 
{
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj) 
{
	(void) obj;
	return (*this);
}

RPN::~RPN() {}

void	RPN::calculate(std::string argv)
{
	for(size_t i = 0; i < argv.length(); i++)
	{
		if (argv[i] == ' ')
			continue ;
		else if (isOperator(argv[i]) == true)
		{
			_operatorCnt++;
			if (_rpnStack.size() < 2)
				throw(std::runtime_error("Error"));
			if (_rpnStack.empty())
				throw(std::runtime_error("Error")); 

			int	rightValue;
			int	leftValue;

			leftValue = _rpnStack.top();
			_rpnStack.pop();
			rightValue = _rpnStack.top();
			_rpnStack.pop();
			_rpnStack.push(operate(rightValue, leftValue, argv[i]));
		}
		else if (isdigit(argv[i]) == true)
		{
			int	num;

			num = argv[i] - 48;
			_rpnStack.push(num);
		}
		else
			throw (std::runtime_error("Error"));
	}
}

void	RPN::printResult()
{
	if (_rpnStack.size() != 1)
		throw (std::runtime_error("Error"));
	if (_operatorCnt == 0)
		throw (std::runtime_error("Error"));
	std::cout << _rpnStack.top() << std::endl;
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int	RPN::operate(int rightValue, int leftValue, char anOperator)
{
	if (anOperator == '+')
		return (rightValue + leftValue);
	else if (anOperator == '-')
		return (rightValue - leftValue);
	else if (anOperator == '*')
		return (rightValue * leftValue);
	else if (anOperator == '/')
	{
		if (leftValue == 0)
			throw(std::runtime_error("Error : can't divide by 0"));
		return (rightValue / leftValue);
	}
	else
		throw(std::runtime_error("Error"));
}