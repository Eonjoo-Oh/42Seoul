#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : too few argument" << std::endl;
	}

	RPN rpn;
	//argv를 하나로 다 이어서 std::string으로 만드는 함수 -> 인자는 묶어서 하나로만 들어옴
	try
	{
		rpn.calculate(argv[1]);
		rpn.printResult();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}