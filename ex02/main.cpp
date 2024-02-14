#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: too few argument" << std::endl;
		return (1);
	}

	try
	{
		PmergeMe pmerge(argv);
		//pmerge.printvInput();
		pmerge.SortVector();
		pmerge.printvPendingChain();
		std::cout << std::endl;
		pmerge.printvMainChain();

		//pmerge.SortDeque();
		//pmerge.DisplayResult();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}