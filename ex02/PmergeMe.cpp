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
	printvPendingChain();
	std::cout << std::endl;
	printvMainChain();
	recursiveSortLargeElement(_vMainChain, 0, static_cast<int>(_vMainChain.size()) - 1);
	std::cout << std::endl;
	printvMainChain();
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

void PmergeMe::recursiveSortLargeElement(std::vector<int>& v, int start, int end)
{
	if (start >= end) 
		return ;

	int mid = (start + end) / 2;

	recursiveSortLargeElement(v, start, mid);
	recursiveSortLargeElement(v, mid + 1, end);

	std::vector<int> temp(end + 1);
	int tempIndex;
	int i, j;
	tempIndex = 0;
	i = start;
	j = mid + 1;

	while(i <= mid && j <= end)
	{
		if(v[i] < v[j])
			temp[tempIndex++] = v[i++];
		else
			temp[tempIndex++] = v[j++];
	}

	while(i <= mid)
		temp[tempIndex++] = v[i++];
	while(j <= end)
		temp[tempIndex++] = v[j++];

	for(int k = start, tempIndex = 0 ; k <= end ; k++, tempIndex++)
	{
		v[k] = temp[tempIndex];
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