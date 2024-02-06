#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::cout << "Error: too few argument" << std::endl;
		return (1);
	}

	PmergeMe pmerge(argv);

}