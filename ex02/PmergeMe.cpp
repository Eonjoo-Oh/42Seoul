#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	if (!fillInputV(argv))
		throw std::runtime_error("Error: invalid argument input");
	if (!checkOnlyPositive())
		throw std::runtime_error("Error: only positive number can be entered");
	_lastElement = -1;
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

//---------------------utils
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

int PmergeMe::jacobsthal(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void	PmergeMe::printAllElement(std::vector<int> v)
{
	for(size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << " ";
	}
}

void	PmergeMe::printAllElement(std::deque<int> d)
{
	for(size_t i = 0; i < d.size(); i++)
	{
		std::cout << d[i];
		if (i < d.size() - 1)
			std::cout << " ";
	}
}

//------------------------sortVector
void	PmergeMe::sortVector()
{
	_vStartTime = clock();
	fillChain(_vPendingChain, _vInput, 0, 1);
	if (_vPendingChain.size() == 1)
	{
		_vMainChain.push_back(_vPendingChain[0]);
		_vEndTime = clock();
		return ;
	}
	groupAndCompare(_vPendingChain);
	recursiveSortLargeElement(_vPendingPair, 0, (_vPendingPair.size() - 1));
	fillMainChain(_vMainChain, _vPendingPair);
	binaryInsertSortUsingJacobsthal(_vMainChain, _vPendingPair);
	if (_lastElement != -1)
		binaryInsertSort(_vMainChain, _lastElement);
	_vEndTime = clock();
}

void	PmergeMe::fillChain(std::vector<int> &target, const std::vector<int> &origin, size_t index, size_t span)
{
	while (index < origin.size())
	{
		target.push_back(origin[index]);
		index += span;
	}
}

void	PmergeMe::fillMainChain(std::vector<int> &mainChain, std::vector<std::pair<int, int> >pendingPair)
{
	for(size_t i = 0; i < pendingPair.size(); i++)
	{
		mainChain.push_back(pendingPair[i].first);
	}
}


void	PmergeMe::groupAndCompare(std::vector<int> &pendingChain)
{

	if (pendingChain.size() % 2  == 1)
		_lastElement = pendingChain.back();
	pendingChain.erase(pendingChain.end() - 1);

	for(size_t i = 0; i < pendingChain.size(); i += 2)
	{
		if (pendingChain[i] < pendingChain[i + 1])
			std::swap(pendingChain[i], pendingChain[i + 1]);
		_vPendingPair.push_back(std::make_pair(pendingChain[i], pendingChain[i + 1]));
	}
}

void PmergeMe::recursiveSortLargeElement(std::vector<std::pair<int, int> >& v, int start, int end)
{
	if (start >= end)
		return ;

	int mid = (start + end) / 2;

	recursiveSortLargeElement(v, start, mid);
	recursiveSortLargeElement(v, mid + 1, end);

	std::vector<std::pair <int, int> > temp(end + 1);
	int tempIndex;
	int i, j;

	tempIndex = 0;
	i = start;
	j = mid + 1;

	while(i <= mid && j <= end)
	{
		if(v[i].first < v[j].first)
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

void	PmergeMe::binaryInsertSortUsingJacobsthal(std::vector<int> &mainChain, std::vector<std::pair<int, int> > &pendingPair)
{


	int	size = static_cast<int>(pendingPair.size() - 1);
	int	cnt = 1;
	int	beforeJacobsthalNum = 1;
	int	nowJacobsthalNum = 1;
	int	jacobsthalN = 2;
	int	targetIdx = 1;

	mainChain.insert(mainChain.begin(), pendingPair[0].second);

	while (cnt <= size)
	{
		if (cnt == 1)
		{
			targetIdx = 1;
		}
		else
		{
			targetIdx--;
			if (targetIdx <= beforeJacobsthalNum)
			{
				jacobsthalN++;
				beforeJacobsthalNum = nowJacobsthalNum;
				nowJacobsthalNum = jacobsthal(jacobsthalN);
				targetIdx = nowJacobsthalNum;
				if (targetIdx >= static_cast<int>(pendingPair.size()))
				{
					targetIdx = static_cast<int>(pendingPair.size() - 1);
				}
			}
		}
		binaryInsert(mainChain, pendingPair, targetIdx);
		cnt++;
	}
}

void	PmergeMe::binaryInsertSort(std::vector<int> &mainChain, int target)
{
	int left = 0;
	int right = mainChain.size() - 1;
	int insertPosition = -1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (mainChain[mid] == target)
		{
			insertPosition = mid;
			break;
		}
		else if (mainChain[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			insertPosition = mid;
			right = mid - 1;
		}
	}
	mainChain.insert(mainChain.begin() + insertPosition, target);
}

void	PmergeMe::binaryInsert(std::vector<int> &mainChain, std::vector<std::pair <int, int> > &pendingPair, int targetIdx)
{
	int	targetValue = pendingPair[targetIdx].second;

	std::vector<int>::iterator	it = std::find(mainChain.begin(), mainChain.end(), pendingPair[targetIdx].first);
	int	right = std::distance(mainChain.begin(), it);
	int	left = 0;
	for (int i = 1; i <= right; ++i)
	{
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mainChain[mid] > targetValue)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	mainChain.insert(mainChain.begin() + left, targetValue);
}


//------------------------sortDeque

void	PmergeMe::sortDeque()
{
	_dStartTime = clock();

	fillChain(_dPendingChain, _vInput, 0, 1);
	if (_dPendingChain.size() == 1)
	{
		_dMainChain.push_back(_dPendingChain[0]);
		_dEndTime = clock();
		return ;
	}
	groupAndCompare(_dPendingChain);
	recursiveSortLargeElement(_dPendingPair, 0, (_dPendingPair.size() - 1));
	fillMainChain(_dMainChain, _dPendingPair);
	binaryInsertSortUsingJacobsthal(_dMainChain, _dPendingPair);
	if (_lastElement != -1)
		binaryInsertSort(_dMainChain, _lastElement);
	_dEndTime = clock();
}

void	PmergeMe::fillChain(std::deque<int> &target, const std::vector<int> &origin, size_t index, size_t span)
{
	while (index < origin.size())
	{
		target.push_back(origin[index]);
		index += span;
	}
}

void	PmergeMe::groupAndCompare(std::deque<int> &pendingChain)
{
	if (pendingChain.size() % 2  == 1)
		_lastElement = pendingChain.back();
	pendingChain.erase(pendingChain.end() - 1);

	for(size_t i = 0; i < pendingChain.size(); i += 2)
	{
		if (pendingChain[i] < pendingChain[i + 1])
			std::swap(pendingChain[i], pendingChain[i + 1]);
		_dPendingPair.push_back(std::make_pair(pendingChain[i], pendingChain[i + 1]));
	}
}

void PmergeMe::recursiveSortLargeElement(std::deque<std::pair<int, int> >& v, int start, int end)
{
	if (start >= end)
		return ;

	int mid = (start + end) / 2;

	recursiveSortLargeElement(v, start, mid);
	recursiveSortLargeElement(v, mid + 1, end);

	std::deque<std::pair <int, int> > temp(end + 1);
	int tempIndex;
	int i, j;

	tempIndex = 0;
	i = start;
	j = mid + 1;

	while(i <= mid && j <= end)
	{
		if(v[i].first < v[j].first)
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

void	PmergeMe::fillMainChain(std::deque<int> &mainChain, std::deque<std::pair<int, int> >pendingPair)
{
	for(size_t i = 0; i < pendingPair.size(); i++)
	{
		mainChain.push_back(pendingPair[i].first);
	}
}

void	PmergeMe::binaryInsertSortUsingJacobsthal(std::deque<int> &mainChain, std::deque<std::pair<int, int> > &pendingPair)
{

	mainChain.insert(mainChain.begin(), pendingPair[0].second);//pendingChain의 0번째를 mainChain의 첫번째에 넣음
	
	int	size = static_cast<int>(pendingPair.size() - 1);
	int	cnt = 1;
	int	beforeJacobsthalNum = 1;
	int	nowJacobsthalNum = 1;
	int	jacobsthalN = 2;
	int	targetIdx = 1;

	while (cnt <= size)
	{
		if (cnt == 1)
		{
			targetIdx = 1;
		}
		else
		{
			targetIdx--;
			if (targetIdx <= beforeJacobsthalNum)
			{
				jacobsthalN++;
				beforeJacobsthalNum = nowJacobsthalNum;
				nowJacobsthalNum = jacobsthal(jacobsthalN);
				targetIdx = nowJacobsthalNum;
				if (targetIdx >= static_cast<int>(pendingPair.size()))
				{
					targetIdx = static_cast<int>(pendingPair.size() - 1);
				}
			}
		}
		binaryInsert(mainChain, pendingPair, targetIdx);
		cnt++;
	}
}

void	PmergeMe::binaryInsert(std::deque<int> &mainChain, std::deque<std::pair <int, int> > &pendingPair, int targetIdx)
{
	int	targetValue = pendingPair[targetIdx].second;

	std::deque<int>::iterator	it = std::find(mainChain.begin(), mainChain.end(), pendingPair[targetIdx].first);
	int	right = std::distance(mainChain.begin(), it);
	int	left = 0;
	for (int i = 1; i <= right; ++i) {
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mainChain[mid] > targetValue)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	mainChain.insert(mainChain.begin() + left, targetValue);
}

void	PmergeMe::binaryInsertSort(std::deque<int> &mainChain, int target)
{
	int left = 0;
	int right = mainChain.size() - 1;
	int insertPosition = -1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (mainChain[mid] == target)
		{
			insertPosition = mid;
			break;
		}
		else if (mainChain[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			insertPosition = mid;
			right = mid - 1;
		}
	}
	mainChain.insert(mainChain.begin() + insertPosition, target);
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

	std::cout << "Time to process a range of "  << _vInput.size() << " elements with std::vector : ";
	std::cout << (_vEndTime - _vStartTime) / (CLOCKS_PER_SEC / 1000000) << " us" << std::endl;
	std::cout << "Time to process a range of "  << _vInput.size() << " elements with std::deque : ";
	std::cout << (_dEndTime - _dStartTime) / (CLOCKS_PER_SEC / 1000000)<< " us" << std::endl;
}
