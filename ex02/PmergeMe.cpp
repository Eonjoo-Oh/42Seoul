#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	getVInput(argv);
	_inputLength = _vInput.size();
}

PmergeMe::PmergeMe(const PmergeMe &obj) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	(void)obj;
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::getVInput(char **argv)
{
	for(int i = 1; argv[i]; i++)
	{
		std::istringstream	iss(argv[i]);
		int					num;

		while (iss >> num)
		{
			if (iss.//에러처리)
		}
	}
}