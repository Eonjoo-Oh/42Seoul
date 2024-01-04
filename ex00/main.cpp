#include "ScalarConverter.hpp"

int	main()
{
	ScalarConverter::convert("42");
	ScalarConverter::convert("68");
	ScalarConverter::convert("2147");
	ScalarConverter::convert("2147483649");
	ScalarConverter::convert("127");
}