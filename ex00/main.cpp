#include "ScalarConverter.hpp"

int	main()
{
	ScalarConverter::convert("42");
	ScalarConverter::convert("68");
	ScalarConverter::convert("2147");
	ScalarConverter::convert("2147483649");
	ScalarConverter::convert("-12");
	ScalarConverter::convert("127");
	ScalarConverter::convert("32.8");
	ScalarConverter::convert("32.8f");
	//ScalarConverter::convert("32.8f");
	//ScalarConverter::convert("32jkkjl");
	
}