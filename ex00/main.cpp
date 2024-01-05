#include "ScalarConverter.hpp"

int	main()
{
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("68");
	std::cout << std::endl;
	ScalarConverter::convert("2147");
	std::cout << std::endl;
	ScalarConverter::convert("2147483649");
	std::cout << std::endl;
	ScalarConverter::convert("-12");
	std::cout << std::endl;
	ScalarConverter::convert("127");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("21474.34");
	std::cout << std::endl;
	//ScalarConverter::convert("32.8f");
	//ScalarConverter::convert("32jkkjl");
	
}