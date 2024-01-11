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

int	ConverterUtil::determineType(const std::string &input)
{
	if (input == "+inf" || input == "-inf" || input == "inf"\
			|| input == "+inff" || input == "-inff" || \
			input == "nan" || input == "+nan" || input == "-nan")
		return (SPECIAL);
	else if (isChar(input) == true)
		return (CHAR);
	else if (isInt(input) == true)
		return (INT);
	else if (isFloat(input) == true)
		return (FLOAT);
	else if (isDouble(input) == true)
		return (DOUBLE);
	else
		return (OTHER);
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

bool	ConverterUtil::onlyZeroBelowPoint(std::string input)
{
	size_t	i;

	i = 0;
	while (i < input.length())
	{
		if (input[i] == '.')
			break;
		i++;
	}
	i++;
	while (i < input.length())
	{
		if (input[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

bool	ConverterUtil::isChar(const std::string &input)
{
	char	charValue;
	
	if (input.length() != 1)
		return (false);
	
	charValue = static_cast<char>(input[0]);
	if (isdigit(charValue) == 1)
		return (false);
	if (ConverterUtil::isValidRangeChar(static_cast<int>(charValue)) == true)
		return (true);
	else
		return (false);
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

bool	ConverterUtil::isFloat(std::string input)
{
	if (input[input.length() - 1] != 'f')
		return (false);
	else
		input.erase(input.length() - 1);

	std::istringstream	iss(input);
	float				floatValue;

	iss >> floatValue;
	if (iss.fail() || !iss.eof())
		return (false);
	return (true);
}

bool	ConverterUtil::isDouble(const std::string &input)
{
	std::istringstream	iss(input);
	double				doubleValue;

	iss >> doubleValue;
	if (iss.fail() || !iss.eof())
		return (false);
	return (true);
}

void	ConverterUtil::printConvertedFromChar(std::string input)
{
	char	charValue;

	charValue = static_cast<char>(input[0]);
	std::cout << "char: " << static_cast<char>(charValue) << std::endl;
	std::cout << "int: " << static_cast<int>(charValue) << std::endl;
	std::cout << "float: " << static_cast<float>(charValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(charValue) << ".0" << std::endl;
}

void	ConverterUtil::printConvertedFromInt(std::string input)
{
	std::istringstream	iss(input);
	int	value;

	iss >> value;
	try
	{
		std::cout << "char: ";
		if (isValidRangeChar(value) == false)
			throw(ConverterUtil::RangeException());
		if (isDisplayableChar(value) == false)
			throw(ConverterUtil::charDisplayException());
		std::cout << static_cast<char>(value) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value);
	if (value > -999999 && value < 999999)
		std::cout << ".0f" << std::endl;
	else
		std::cout << std::endl;
	std::cout << "double: " << static_cast<double>(value);
	if (value > -999999 && value < 999999)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void	ConverterUtil::printConvertedFromFloat(std::string input)
{
	input.erase(input.length() - 1);

	std::istringstream	iss(input);
	float				floatValue;
	int					intValue;

	iss >> floatValue;
	intValue = static_cast<int>(floatValue);
	try
	{
		std::cout << "char: ";
		if (floatValue < std::numeric_limits<int>::min() || floatValue > std::numeric_limits<int>::max())
			throw (ConverterUtil::RangeException());
		if (onlyZeroBelowPoint(input) == false)
			throw (ConverterUtil::RangeException());
		if (isValidRangeChar(intValue) == false)
			throw(ConverterUtil::RangeException());
		if (isDisplayableChar(intValue) == false)
			throw(ConverterUtil::charDisplayException());
		std::cout << static_cast<char>(intValue) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "int: ";
		int	intValue;

		if (floatValue < std::numeric_limits<int>::min() || floatValue > std::numeric_limits<int>::max())
			throw (ConverterUtil::RangeException());
		intValue = static_cast<int>(floatValue);
		std::cout << intValue << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "float: " << floatValue;
	if (floatValue > -999999 && floatValue < 999999)
	{
		if (onlyZeroBelowPoint(input) == true)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
		std::cout << std::endl;
	
	std::cout << "double: " << static_cast<double>(floatValue);
	if (floatValue > -999999 && floatValue < 999999 && onlyZeroBelowPoint(input) == true)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void	ConverterUtil::printConvertedFromDouble(std::string input)
{
	std::istringstream	iss(input);
	double				doubleValue;
	int					intValue;

	iss >> doubleValue;
	intValue = static_cast<int>(doubleValue);
	try
	{
		std::cout << "char: ";
		if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max())
			throw (ConverterUtil::RangeException());
		if (onlyZeroBelowPoint(input) == false)
			throw (ConverterUtil::RangeException());
		if (isValidRangeChar(intValue) == false)
			throw(ConverterUtil::RangeException());
		if (isDisplayableChar(intValue) == false)
			throw(ConverterUtil::charDisplayException());
		std::cout << static_cast<char>(intValue) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "int: ";
		int					intValue;

		if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max())
			throw (ConverterUtil::RangeException());
		intValue = static_cast<int>(doubleValue);
		std::cout << intValue << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "float: " << static_cast<float>(doubleValue);
	if (doubleValue > -999999 && doubleValue < 999999)
	{
		if (onlyZeroBelowPoint(input) == true)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
		std::cout << std::endl;
	
	std::cout << "double: " << doubleValue;
	std::streamsize originalPrecision = std::cout.precision();
	if (doubleValue > -999999 && doubleValue < 999999 && onlyZeroBelowPoint(input) == true)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
	std::cout.precision(originalPrecision);
}

void	ConverterUtil::printSpecial(std::string input)
{
	float	floatValue;
	double	doubleValue;

	floatValue = atof((input).c_str());
	doubleValue = atof((input).c_str());

	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: ";
	if (input[0] == '+' && input != "+nan" && input != "-nan")
		std::cout << "+";
	std::cout << floatValue << "f" << std::endl;
	
	std::cout << "double: ";
	if (input[0] == '+' && input != "+nan" && input != "-nan")
		std::cout << "+";
	std::cout << doubleValue << std::endl;
}

void	ConverterUtil::printDefault(void)
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

const char	*ConverterUtil::RangeException::what(void) const throw()
{
	return ("impossible");
}

const char	*ConverterUtil::charDisplayException::what(void) const throw()
{
	return ("Non displayable");
}