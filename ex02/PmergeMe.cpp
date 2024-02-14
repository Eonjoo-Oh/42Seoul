#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	if (!fillInputV(argv))
		throw std::runtime_error("Error: invalid argument input");
	if (!checkOnlyPositive())
		throw std::runtime_error("Error: only positive number can be entered");
}

PmergeMe::PmergeMe(const PmergeMe &obj) 
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	(void)obj;
	return (*this);
}

PmergeMe::~PmergeMe() {}

//---------------------consturctor utils
bool	PmergeMe::fillInputV(char **argv)
{
	for(int i = 1; argv[i]; i++)
	{
		std::istringstream	iss(argv[i]);
		std::string			token;
	
		while (iss >> token)
		{
			int					num;
			std::istringstream	tokenStream(token);

			if (!(tokenStream >> num))
				return (false);
			_vInput.push_back(num);
		}
	}
	return (true);
}

bool	PmergeMe::checkOnlyPositive()
{
	for(size_t i = 0; i < _vInput.size(); i++)
	{
		if (_vInput[i] < 0)
			return (false);
	}
	return (true);
}

//------------------------sortVector
void	PmergeMe::SortVector()
{
	_vStartTime = clock();
	vFillPendingChain();
	vGroupAndCompare();
	vRecursiveSortLargeElement();
	vBinaryInsertSort();
	_vEndTime = clock();
}

//------------------------sortDeque
void	PmergeMe::SortDeque()
{
	_dStartTime = clock();
	dFillPendingChain();
	dGroupAndCompare();
	dRecursiveSortLargeElement();
	dBinaryInsertSort();
	_dEndTime = clock();
}

//---------------------Display
void	PmergeMe::DisplayResult()
{
	std::cout << "Before : ";
	printAllElement(_vInput);
	std::cout << std::endl;

	std::cout << "After : ";
	printAllElement(_vMainChain);
	std::cout << std::endl;

	std::cout << "Time to process a range of"  << _vInput.size() << " elements with std::vector : ";
	std::cout << (_vStartTime - _vEndTime) * 1000 << " us" << std::endl;
	std::cout << "Time to process a range of"  << _vInput.size() << " elements with std::deque : ";
	std::cout << (_dStartTime - _dEndTime) * 1000 << " us" << std::endl;
}

//-------------------Utils