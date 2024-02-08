#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	//if (argc <= 1)
	//{
	//	std::cout << "Error: too few argument" << std::endl;
	//	return (1);
	//}
	(void) argc;

	try
	{
		PmergeMe pmerge(argv);
		pmerge.printAllElementVInput();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	//std::cout << pmerge.getInputLength() << std::endl;

}