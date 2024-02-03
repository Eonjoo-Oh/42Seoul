#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc <= 3)
	{
		std::cout << "Error : too few argument" << std::endl;
	}

	RPN rpn;
	
	rpn.calculate(argv);
	rpn.printResult();
}