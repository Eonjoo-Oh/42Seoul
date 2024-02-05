#include "RPN.hpp"

RPN::RPN() 
{
	_operatorCnt = 0;
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
				//size로 확인하는데 size가 0이면 0이라고 나오면 굳이 확인할 필요 없지않을까?

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
			//std::cout << "num : " << num << std::endl;
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
	//std::cout << rightValue << leftValue << anOperator << std::endl;
	if (anOperator == '+')
		return (rightValue + leftValue);
	else if (anOperator == '-')
		return (rightValue - leftValue);
	else if (anOperator == '*')
		return (rightValue * leftValue);
	else if (anOperator == '/')
		return (rightValue / leftValue);
	else
		throw(std::runtime_error("Error"));//이렇게 작성가능?
}