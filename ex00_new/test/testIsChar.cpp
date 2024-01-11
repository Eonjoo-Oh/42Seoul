#include <iostream>
#include <sstream>
#include "../ConverterUtil.hpp"

bool	isChar(const std::string &input)
{
	char				charValue;
	int					intValue;
	std::istringstream	iss(input);
	
	if (input.length() != 1)
		return (false);
	iss >> intValue;
	if (ConverterUtil::isValidRangeChar(intValue) == true)
		return true;
	else
		return (false);
}

int main()
{
	std::string	c = "a";
	std::cout << isChar(c) << std::endl;
}