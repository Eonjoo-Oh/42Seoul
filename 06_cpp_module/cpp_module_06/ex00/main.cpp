#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "check num of argv" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}