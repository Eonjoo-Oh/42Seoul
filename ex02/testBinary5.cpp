 #include "PmergeMe.hpp"


PmergeMe::PmergeMe(const int argc, const char** argv)
: mArgc(argc)
, mArgv(argv)
{}

PmergeMe::PmergeMe(const PmergeMe& copy)
: mArgc(copy.mArgc)
, mArgv(copy.mArgv)
, mSequenceDeque(copy.mSequenceDeque)
, mSequenceVector(copy.mSequenceVector)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	(void) copy;
	return *this;
}

bool PmergeMe::run()
{
  mSequenceDeque.clear();
  mSequenceVector.clear();
	if (mArgc == 1)
	{
		std::cout << "Error" << std::endl;
		return false;
	}

	for (int i = 1; i < mArgc; ++i)
	{
		int num = std::atoi(mArgv[i]);
		if (isInt(std::string(mArgv[i])) == false
				|| num < 1)
		{
			std::cout << "Error" << std::endl;
			return false;
		}
	}

	clock_t start, end;

  start = clock();
	for (int i = 1; i < mArgc; ++i)
	{
		mSequenceDeque.push_back(std::atoi(mArgv[i]));
	}
	sort(mSequenceDeque);
	end = clock();
	double dequeTimeTaken = (double(end - start) / CLOCKS_PER_SEC) * 1000.0;

  start = clock();
	for (int i = 1; i < mArgc; ++i)
	{
		mSequenceVector.push_back(std::atoi(mArgv[i]));
	}
	sort(mSequenceVector);
	end = clock();
	double vectorTimeTaken = (double(end - start) / CLOCKS_PER_SEC) * 1000.0;

	
	
	std::cout << "Before:\t";
	printArgv();
	std::cout << "\nAfter:\t";
	printDeque();
	std::cout << "\nTime to process a range of "
						<< mArgc - 1
						<< " elements with std::deque : "
						<< static_cast<unsigned long>(dequeTimeTaken)
						<< " ms"
						<< std::endl;
	std::cout << "Time to process a range of "
						<< mArgc - 1
						<< " elements with std::vector : "
						<< static_cast<unsigned long>(vectorTimeTaken)
						<< " ms"
						<< std::endl;
	return true;
}

size_t PmergeMe::findInsertPoint(size_t x, const std::deque<size_t>& sequence)
{
  size_t left = 0, right = sequence.size();
  while (left < right)
  {
    size_t mid = left + (right - left) / 2;
    if (sequence[mid] < x) left = mid + 1;
    else right = mid;
  }
  return left;
}

size_t PmergeMe::findInsertPoint(size_t x, const std::vector<size_t>& sequence)
{
  size_t left = 0, right = sequence.size();
  while (left < right)
  {
    size_t mid = left + (right - left) / 2;
    if (sequence[mid] < x) left = mid + 1;
    else right = mid;
  }
  return left;
}

void PmergeMe::sort(std::deque<size_t>& sequence)
{
  if (sequence.size() < 2) return;

  unordered_map<size_t, std::deque<size_t> , std::deque<std::pair<size_t, std::deque<size_t> > > > partner;
  size_t half = sequence.size() / 2;
  for (size_t i = 0; i < half; ++i)
  {
    if (sequence[i] < sequence[i + half]) std::swap(sequence[i], sequence[i + half]);
    partner[sequence[i]].push_back(sequence[i + half]);
  }

  std::deque<size_t> firstHalf(sequence.begin(), sequence.begin() + half);
  sort(firstHalf);

  std::copy(firstHalf.begin(), firstHalf.end(), sequence.begin());
  std::deque<size_t> jacobsthalOrder = getJacobsthalOrderDeque(half);
  for (size_t i = 0; i < half; ++i)
  {
    size_t y = partner[sequence[jacobsthalOrder[i] - 1]].back(); partner[sequence[jacobsthalOrder[i] - 1]].pop_back();
    std::deque<size_t>::iterator it = firstHalf.begin();
    while (*it != sequence[jacobsthalOrder[i] - 1]) ++it;
    size_t idx = 0;
    if (i != 0)
      idx = findInsertPoint(y, std::deque<size_t>(firstHalf.begin(), it + 1));
    if (i == 0)
      firstHalf.push_front(y);
    else
      firstHalf.insert(firstHalf.begin() + idx, y);
  }
  if (sequence.size() & 1)
  {
    size_t i = sequence.size() - 1;
    size_t idx = findInsertPoint(sequence[i], firstHalf);
    firstHalf.insert(firstHalf.begin() + idx, sequence[i]);
  }
  std::copy(firstHalf.begin(), firstHalf.end(), sequence.begin());
}

void PmergeMe::sort(std::vector<size_t>& sequence)
{
  if (sequence.size() < 2) return;

  unordered_map<size_t, std::vector<size_t> , std::vector<std::pair<size_t, std::vector<size_t> > > > partner;
  size_t half = sequence.size() / 2;
  for (size_t i = 0; i < half; ++i)
  {
    if (sequence[i] < sequence[i + half]) std::swap(sequence[i], sequence[i + half]);
    partner[sequence[i]].push_back(sequence[i + half]);
  }

  std::vector<size_t> firstHalf(sequence.begin(), sequence.begin() + half);
  sort(firstHalf);

  std::copy(firstHalf.begin(), firstHalf.end(), sequence.begin());
  std::vector<size_t> jacobsthalOrder = getJacobsthalOrderVector(half);
  for (size_t i = 0; i < half; ++i)
  {
    size_t y = partner[sequence[jacobsthalOrder[i] - 1]].back(); partner[sequence[jacobsthalOrder[i] - 1]].pop_back();
    std::vector<size_t>::iterator it = firstHalf.begin();
    while (*it != sequence[jacobsthalOrder[i] - 1]) ++it;
    size_t idx = 0;
    if (i != 0)
      idx = findInsertPoint(y, std::vector<size_t>(firstHalf.begin(), it + 1));
    firstHalf.insert(firstHalf.begin() + idx, y);
  }
  if (sequence.size() & 1)
  {
    size_t i = sequence.size() - 1;
    size_t idx = findInsertPoint(sequence[i], firstHalf);
    firstHalf.insert(firstHalf.begin() + idx, sequence[i]);
  }
  std::copy(firstHalf.begin(), firstHalf.end(), sequence.begin());
}

void PmergeMe::printArgv() const
{
	for (int i = 1; i < mArgc; ++i)
		std::cout << mArgv[i] << " ";
}

void PmergeMe::printDeque() const
{
	for (std::deque<size_t>::const_iterator it = mSequenceDeque.begin();
			 it != mSequenceDeque.end(); ++it)
		std::cout << *it << " ";
}

bool	PmergeMe::isInt(const std::string& literal) const
{
	char* endPtr = NULL;
	const char* cStr = literal.c_str();
	long longValue = std::strtol(cStr, &endPtr, 10);
	if (literal.length() != 0
		&& *endPtr == '\0'
		&& (static_cast<long>(std::numeric_limits<int>::min()) <= longValue 
			&& longValue <= static_cast<long>(std::numeric_limits<int>::max())))
		return true;
	else
		return false;
}

std::vector<size_t> PmergeMe::getJacobsthalOrderVector(size_t size)
{
  std::vector<size_t> res(size);
  for (size_t i = 1; i <= size; ++i) res[i - 1] = i;
  if (size == 1) return res;
  std::vector<size_t>::iterator start = res.begin() + 1, end = res.begin();
  for (size_t i = 2; end != res.end(); ++i)
  {
    size_t jacobsthalNumber = (std::pow(2, i + 1) + std::pow(-1, i)) / 3;
    while (*end != jacobsthalNumber && end != res.end()) ++end;
    std::reverse(start, end + (end == res.end() ? 0 : 1));
    start = end + (end == res.end() ? 0 : 1);
  }
  return res;
}

std::deque<size_t> PmergeMe::getJacobsthalOrderDeque(size_t size)
{
  std::deque<size_t> res(size);
  for (size_t i = 1; i <= size; ++i) res[i - 1] = i;
  if (size == 1) return res;
  std::deque<size_t>::iterator start = res.begin() + 1, end = res.begin();
  for (size_t i = 2; end != res.end(); ++i)
  {
    size_t jacobsthalNumber = (pow(2, i + 1) + pow(-1, i)) / 3;
    while (*end != jacobsthalNumber && end != res.end()) ++end;
    std::reverse(start, end + (end == res.end() ? 0 : 1));
    start = end + (end == res.end() ? 0 : 1);
  }
  return res;
}