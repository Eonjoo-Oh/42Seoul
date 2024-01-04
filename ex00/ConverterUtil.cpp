#include "ConverterUtil.hpp"

ConverterUtil::ConverterUtil() {}

ConverterUtil::ConverterUtil(const ConverterUtil &obj) { *this = obj; }

ConverterUtil &ConverterUtil::operator=(const ConverterUtil &obj) 
{
	(void)obj;
	return (*this);
}

ConverterUtil::~ConverterUtil() {}

std::string	ConverterUtil::deleteWhiteSpace(const std::string &input)
{
	std::string	joinedInput;

	for(std::size_t i = 0; i < input.length(); i++)
	{
		if (!(input[i] == 32 || (input[i] >= 9 && input[i] <= 13)))
			joinedInput += input[i];
	}
	return (joinedInput);
}

bool	ConverterUtil::isValidChar(int num)
{
	if (num < 0 || num > 127)
		return (false);
	return (true);
}

bool	ConverterUtil::isDisplayableChar(int num)
{
	if ((num >= 0 && num <= 8) || \
		(num >= 14 && num <= 31) || num == 127)
		return (false);
	return (true);
}
const char	*ConverterUtil::charRangeException::what(void) const throw()
{
	return ("impossible");
}

const char	*ConverterUtil::charDisplayException::what(void) const throw()
{
	return ("Non displayable");
}