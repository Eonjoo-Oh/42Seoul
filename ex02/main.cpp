#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	//if (argc <= 1)
	//{
	//	std::cout << "Error: too few argument" << std::endl;
	//	return (1);
	//}
	(void) argc;
	PmergeMe pmerge(argv);
	std::cout << pmerge.getInputLength() << std::endl;
	if (pmerge.getInputLength() <= 1)
	{
		std::cout << "Error: input must be at least two" << std::endl;
		return (1);
	}

}