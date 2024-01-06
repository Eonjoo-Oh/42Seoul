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

// int	ConverterUtil::determineType(const std::string &input)
// {
// 	if (isChar(input) == true)
// 		return (CHAR);
// 	else if (isInt(input) == true)
// 		return (INT);
// 	else if (isFloat(input) == true)
// 		return (FLOAT);
// 	else if (isDouble(intput) == true)
// 		return (DOUBLE);
// 	else
// 		return (OTHER);
// }

bool	ConverterUtil::isChar(const std::string &input)
{
	int					intValue;
	std::istringstream	iss(input);

	iss >> intValue;
	if (iss.fail() || !iss.eof())
		return (false);
	if (isValidRangeChar(intValue) \
		&& isDisplayableChar(intValue))
		return (true);
	return (false);
}

bool	ConverterUtil::isValidRangeChar(int num)
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

bool	ConverterUtil::isInt(const std::string &input)
{
	std::istringstream	iss(input);
	int					intValue;

	iss >> intValue;
	if (iss.fail() || !iss.eof())
		return (false);
	return (true);
}

bool	ConverterUtil::isValidInt(float num)
{
	if (num < -2147483648 || num > 2147483647)
		return (false);
	return (true);
}

bool	ConverterUtil::isFloat(std::string str)
{
	int		pointCnt = 0;
	size_t	length = str.length();

	if (length < 4)
		return (false);
	for(size_t i = 0; i < length; i++)
	{
		if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '.' && str[i] != 'f')
			return (false);
		if (str[i] == 'f' && i != length - 1)
			return (false);
		if (str[i] == '.' && !(i > 0 && i < length - 2))
			return (false);
		else if (str[i] == '.')
			pointCnt++;
	}
	if (str[length - 1] != 'f' || pointCnt != 1)
		return (false);
	return (true);
}

int	ConverterUtil::floatToInt(std::string str)
{
	if (str[str.length() - 1] == 'f')
		str.erase(str.length() - 1);

	float				floatConverted;
	std::istringstream	iss(str);

	iss >> floatConverted;
	if (isValidInt(floatConverted) == false)
		throw RangeException();
	return (static_cast<int>(floatConverted));
}

bool	ConverterUtil::isDouble(std::string str)
{
	int		pointCnt = 0;
	size_t	length = str.length();

	if (length < 3)
		return (false);
	for(size_t i = 0; i < length; i++)
	{
		if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '.')
			return (false);
		if (str[i] == '.' && (i > 0 && i < length - 2))
			return (false);
		else if (str[i] == '.')
			pointCnt++;
	}
	if (pointCnt != 1)
		return (false);
	return (true);
}

int	ConverterUtil::doubleToInt(std::string str)
{
	double				doubleonverted;
	std::istringstream	iss(str);

	iss >> doubleonverted;
	if (isValidInt(doubleonverted) == false)
		throw RangeException();
	return (static_cast<int>(doubleonverted));
}

const char	*ConverterUtil::RangeException::what(void) const throw()
{
	return ("impossible");
}

const char	*ConverterUtil::charDisplayException::what(void) const throw()
{
	return ("Non displayable");
}