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
	vFillChain(_vPendingChain, _vInput, 0, 1);
	vGroupAndCompare();
	vFillChain(_vMainChain, _vPendingChain, 1, 2);
	//vRecursiveSortLargeElement();
	//vBinaryInsertSort();
	_vEndTime = clock();
}

void	PmergeMe::vFillChain(std::vector<int> &target, const std::vector<int> &origin, size_t index, size_t span)
{
	while (index < origin.size())
	{
		target.push_back(origin[index]);
		index += span;
	}
}
void	PmergeMe::vFillPendingChain()
{
	for(size_t i = 0; i < _vInput.size(); i++)
	{
		_vPendingChain.push_back(_vInput[i]);
		//_vPendingChain[i] = _vInput[i];
	}
}

void	PmergeMe::vGroupAndCompare()
{
	for(size_t i = 0; i < _vPendingChain.size(); i += 2)
	{
		int	temp;

		if (i + 1 == _vPendingChain.size())
			break ;
		if (_vPendingChain[i] > _vPendingChain[i + 1])
		{
			temp = _vPendingChain[i];
			_vPendingChain[i] = _vPendingChain[i + 1];
			_vPendingChain[i + 1] = temp;
		}//이걸 함수로 빼려면 레퍼런스? 굳이 안빼는게 더 직관적인것 같기도 일단 구현해보기?
	}
}

//void	PmergeMe::vRecursiveSortLargeElement()
//{
//	for (int i = 1; i < _vPendingChain.size(); i += 2)
//	{
//		_vMainChain.push_back(_vPendingChain[i]);
//	}


//}
//------------------------sortDeque
/*
void	PmergeMe::SortDeque()
{
	_dStartTime = clock();
	dFillPendingChain();
	dGroupAndCompare();
	dRecursiveSortLargeElement();
	dBinaryInsertSort();
	_dEndTime = clock();
}
*/
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

void	PmergeMe::printAllElement(std::vector<int> v)
{
	for(size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << " ";
	}
}