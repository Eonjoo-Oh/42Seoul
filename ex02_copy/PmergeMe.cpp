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

// void	printPair(std::pair<int, int> &p)
// {
// 	for(size_t i = 0; i < 5; i++)
// 	{
// 		std::cout << "pair[" << i << "]" << std::endl;
// 		std::cout << p[i].first << ", " p[i].second << std::endl;
// 	}
// }
//------------------------sortVector
void	PmergeMe::SortVector()
{
	_vStartTime = clock();
	fillChain(_vPendingChain, _vInput, 0, 1);
	groupAndCompare(_vPendingChain);
	std::cout << "pending : " << std::endl;
	for(size_t i = 0; i < _vPendingPair.size(); i++)
	{
		std::cout << i << ": " << _vPendingPair[i].first << ", " << _vPendingPair[i].second << std::endl;
	}
	
	recursiveSortLargeElement(_vPendingPair, 0, (_vPendingPair.size() - 1));
	std::cout << "pending2 : " << std::endl;
	for(size_t i = 0; i < _vPendingPair.size(); i++)
	{
		std::cout << i << ": " << _vPendingPair[i].first << ", " << _vPendingPair[i].second << std::endl;
	}
	
	fillMainChain();
	std::cout << "main: " << std::endl;
	printvMainChain();
	
	binaryInsertSortUsingJacobsthal();
	std::cout << std::endl << "sorted main: " << std::endl;
	printvMainChain();

	std::cout << "_lastElement: " << _lastElement << std::endl;
	if (_lastElement != -1)
		binaryInsertSort(_vMainChain, _lastElement);
	std::cout << std::endl << "sorted main2: " << std::endl;
	printvMainChain();
	// //fillChain(_vMainChain, _vPendingChain, 1, 2);


	// std::cout << std::endl << "first main: ";
	// printvMainChain();
	
	// recursiveSortLargeElement(_vMainChain, 0, static_cast<int>(_vMainChain.size()) - 1);
	
	// std::cout << std::endl <<"after recursive main: ";
	// printvMainChain();

	// std::cout << std::endl << "pending: ";
	// printvPendingChain();

	// binaryInsertSort(_vMainChain, _vPendingChain);
	// std::cout << std::endl;
	// printvMainChain();
	_vEndTime = clock();

	std::cout << std::endl << "time: " << _vEndTime << " - " << _vStartTime << " = " << _vEndTime - _vStartTime << std::endl;
}

void	PmergeMe::fillMainChain()
{
	for(size_t i = 0; i < _vPendingPair.size(); i++)
	{
		_vMainChain.push_back(_vPendingPair[i].first);
	}
}

void	PmergeMe::fillChain(std::vector<int> &target, const std::vector<int> &origin, size_t index, size_t span)
{
	while (index < origin.size())
	{
		target.push_back(origin[index]);
		index += span;
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

int PmergeMe::jacobsthal(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


void	PmergeMe::binaryInsertSortUsingJacobsthal()
{

	_vMainChain.insert(_vMainChain.begin(), _vPendingPair[0].second);//pendingChain의 0번째를 mainChain의 첫번째에 넣음
	
	int	size = static_cast<int>(_vPendingPair.size() - 1);
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
				if (targetIdx >= static_cast<int>(_vPendingPair.size()))
				{
					targetIdx = static_cast<int>(_vPendingPair.size() - 1);
				}
			}
		}
		std::cout << std::endl << "target Idx: " << targetIdx;
		binaryInsert(_vMainChain, _vPendingPair, targetIdx);
		cnt++;
	}
}

void	PmergeMe::binaryInsertSort(std::vector<int> &mainChain, int target)
{
    int left = 0;
    int right = mainChain.size() - 1;
    int insertPosition = -1; // target이 삽입될 위치

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mainChain[mid] == target) {
            // 중복된 값이 있을 경우 mid의 왼쪽에 삽입합니다.
            insertPosition = mid;
            break;
        } else if (mainChain[mid] < target) {
            left = mid + 1;
        } else {
            // mid의 왼쪽에 삽입되어야 하므로 insertPosition을 갱신합니다.
            insertPosition = mid;
            right = mid - 1;
        }
    }

    // target을 삽입합니다.
	std::cout << "insertPosition: " << insertPosition << std::endl;
    mainChain.insert(mainChain.begin() + insertPosition, target);
}
/*
void	PmergeMe::binaryInsert(std::vector<int> &mainChain, std::vector<int> &pendingChain, int targetIdx)
{
	int	targetValue = pendingChain[targetIdx];

	int left = 0;
	int right = mainChain.size();
	//int insertPosition = -1; // targetValue가 삽입될 위치

	while (left < right)
	{
		int mid = (left + right) / 2;

		if (mainChain[mid] <= targetValue)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	// 삽입 위치를 찾은 후에 targetValue를 삽입합니다.
	mainChain.insert(mainChain.begin() + left, targetValue);
}
*/
void	PmergeMe::binaryInsert(std::vector<int> &mainChain, std::vector<std::pair <int, int> > &pendingPair, int targetIdx)
{
	int	targetValue = pendingPair[targetIdx].second;

	std::vector<int>::iterator	it = std::find(mainChain.begin(), mainChain.end(), pendingPair[targetIdx].first);
	int	right = std::distance(mainChain.begin(), it);
	int	left = 0;
	std::cout << std::endl << "right : " << right;
	std::cout << std::endl << "target: " << targetValue << std::endl;
	for (int i = 1; i <= right; ++i) {
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (_vMainChain[mid] > targetValue)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	_vMainChain.insert(_vMainChain.begin() + left, targetValue);
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

//ㅇㅖ오ㅣ케이스 5 4 3 2 1₩