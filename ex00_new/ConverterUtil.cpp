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
	// if (isChar(input) == true)
	// 	return (CHAR);
	if (input == "+inf" || input == "-inf" \
			|| input == "+inff" || input == "-inff" || input == "nan")
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

bool	ConverterUtil::isChar(const std::string &input)
{
	char	charValue;
	
	if (input.length() != 1)
		return (false);
	
	charValue = static_cast<char>(input[0]);
	std::cout << "charValue2: " << charValue << std::endl;
	if (ConverterUtil::isValidRangeChar(static_cast<int>(charValue)) == true)
		return true;
	else
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
	//floatValue = static_cast<float>((atof(input.c_str())));
	intValue = static_cast<int>(floatValue);
	std::cout << "floatValue: "<< floatValue << std::endl;
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
		int					intValue;

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

void	ConverterUtil::printConvertedFromDouble(std::string input)
{
	std::istringstream	iss(input);
	double				doubleValue;
	int					intValue;

	iss >> doubleValue;
	std::cout << "double : " << doubleValue << std::endl;
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
	if (input[0] == '+')
		std::cout << "+";
	std::cout << floatValue << "f" << std::endl;
	
	std::cout << "double: ";
	if (input[0] == '+')
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
// char	ConverterUtil::convertToChar(std::string input, int type)
// {
// 	if (type == INT)
// 	{
// 		std::istringstream	iss(input);
// 		int	value;
// 		if (isValidRangeChar(value) == false)
// 			throw(ConverterUtil::RangeException());
// 		if (isDisplayableChar(value) == false)
// 			throw(ConverterUtil::charDisplayException());
// 	}
// }
//---------------------------------------

bool	ConverterUtil::isValidInt(float num)
{
	if (num < -2147483648 || num > 2147483647)
		return (false);
	return (true);
}

// bool	ConverterUtil::isFloat(std::string str)
// {
// 	int		pointCnt = 0;
// 	size_t	length = str.length();

// 	if (length < 4)
// 		return (false);
// 	for(size_t i = 0; i < length; i++)
// 	{
// 		if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '.' && str[i] != 'f')
// 			return (false);
// 		if (str[i] == 'f' && i != length - 1)
// 			return (false);
// 		if (str[i] == '.' && !(i > 0 && i < length - 2))
// 			return (false);
// 		else if (str[i] == '.')
// 			pointCnt++;
// 	}
// 	if (str[length - 1] != 'f' || pointCnt != 1)
// 		return (false);
// 	return (true);
// }


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

// bool	ConverterUtil::isDouble(std::string str)
// {
// 	int		pointCnt = 0;
// 	size_t	length = str.length();

// 	if (length < 3)
// 		return (false);
// 	for(size_t i = 0; i < length; i++)
// 	{
// 		if (!(str[i] >= 48 && str[i] <= 57) && str[i] != '.')
// 			return (false);
// 		if (str[i] == '.' && (i > 0 && i < length - 2))
// 			return (false);
// 		else if (str[i] == '.')
// 			pointCnt++;
// 	}
// 	if (pointCnt != 1)
// 		return (false);
// 	return (true);
// }

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