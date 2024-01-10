#include "ScalarConverter.hpp"
int	main(int argc, char **argv)
{
//	std::string	input;

	if (argc != 2)
	{
		std::cout << "check num of argv" << std::endl;
		return (1);
	}
//	input = argv[1];
	ScalarConverter::convert(argv[1]);
}

/*
int	main()
{
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("68");
	std::cout << std::endl;
	ScalarConverter::convert("2147");
	std::cout << std::endl;
	ScalarConverter::convert("-99999990");
	std::cout << std::endl;
	ScalarConverter::convert("-12");
	std::cout << std::endl;
	ScalarConverter::convert("127");
	std::cout << std::endl;
	ScalarConverter::convert("42.0");
	std::cout << std::endl;
	ScalarConverter::convert("42.3");
	std::cout << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
	ScalarConverter::convert("21474.34f");
	std::cout << std::endl;
	ScalarConverter::convert("2147836490.34f");
	std::cout << std::endl;
	ScalarConverter::convert("2147836490.34f");
	std::cout << std::endl;
	ScalarConverter::convert("32.8fdkjlkj");
	std::cout << std::endl;
	ScalarConverter::convert("-9,223,372,036,854,775,808");
	std::cout << std::endl;
}
*/