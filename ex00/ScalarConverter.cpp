#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) 
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) 
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string input)
{
	std::string	joinedInput;
	char		charConverted;
	int			intConverted;
	//float		floatConverted;
	//double		doubleConverted;

	joinedInput = ConverterUtil::deleteWhiteSpace(input);
	try
	{
		std::istringstream	iss(joinedInput);
		int					tempInt;

		std::cout << "char: ";

		iss >> tempInt;
		if (iss.fail() || !iss.eof() || joinedInput.empty())
			throw	std::invalid_argument("impossible");
			
		if (ConverterUtil::isValidChar(tempInt) == false)
			throw	ConverterUtil::charRangeException();
		if (ConverterUtil::isDisplayableChar(tempInt) == false)
			throw	ConverterUtil::charDisplayException();

		charConverted = static_cast<char>(tempInt);
		std::cout << charConverted << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::istringstream	iss(joinedInput);

		std::cout << "int : ";
		iss >> intConverted;
		if (iss.fail() || !iss.eof() || joinedInput.empty())
			throw	std::invalid_argument("impossible");
		std::cout << intConverted << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
