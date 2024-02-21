#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : wrong argument numbers" << std::endl;
		return (1);
	}

	try
	{
		RPN rpn;
		rpn.calculate(argv[1]);
		rpn.printResult();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}