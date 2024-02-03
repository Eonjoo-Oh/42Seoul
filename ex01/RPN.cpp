#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void	RPN::calculate(std::string argv)
{
	for(size_t i = 0; i < argv.length(); i++)
	{
		if (argv[i] == ' ')
			continue ;
		else if (isOperator(argv[i]) == true)
		{
			if (_rpnStack.size() != 2)
				throw(std::runtime_error("Error"))
		}
		else if (isdigit(argv[i]) == true)
		{
		
		}
		else
			throw (std::runtime_error("Error"))
	}
}

void	RPN::printResult()
{
	std::cout << _result << std::endl;
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}