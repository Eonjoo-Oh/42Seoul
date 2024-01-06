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
	int			type;

	joinedInput = ConverterUtil::deleteWhiteSpace(input);
	type = ConverterUtil::determineType(joinedInput);

	try
	{
		char	result;

		std::cout << "char: ";
		result = ConverterUtil::convertToChar(joinedInput, type);
		std::cout << result << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// switch(type)
	// {
	// 	case (ConverterUtil::INT)
	// 		ConverterUtil::printConvertFromInt();
	// }
}