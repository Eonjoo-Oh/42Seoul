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
	std::cout << "type : " << type << std::endl;
	switch(type)
	{
		case (CHAR):
			ConverterUtil::printConvertedFromChar(joinedInput);
			break;
		case (INT):
			ConverterUtil::printConvertedFromInt(joinedInput);
			break;
		case (FLOAT):
			ConverterUtil::printConvertedFromFloat(joinedInput);
			break;
		case (DOUBLE) :
			ConverterUtil::printConvertedFromDouble(joinedInput);
			break;
		case (SPECIAL) :
			ConverterUtil::printSpecial(joinedInput);
			break;
		default:
			ConverterUtil::printDefault();
	}
}