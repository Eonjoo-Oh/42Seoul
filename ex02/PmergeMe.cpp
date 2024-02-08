#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	if (!fillInputV(argv))
		throw std::runtime_error("Error: invalid argument input");
	if (!checkOnlyPositive())
		throw std::runtime_error("Error: only positive number can be entered");
	if (_vInput.size() <= 1)
		throw std::runtime_error("Error: input must be at least two");
	else
		_inputLength = _vInput.size();
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
			//std::cout << "num : " << num << std::endl;
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

//---------------------- getters
unsigned int	PmergeMe::getInputLength()
{
	return (_inputLength);
}

//-----------------printFuncs
void	PmergeMe::printBefore()
{
	std::cout << "Before : ";
	printAllElementVInput(_vInput);
	std::cout << std::endl;
}
//---------------------- test
void PmergeMe::printAllElementVInput(std::vector<int> v)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		std::cout << _vInput[i];
		if (i < _inputLength - 1)
			std::cout << " ";
	}
}

//void PmergeMe::printAllElementVInput(vector<int> v)
//{
//	for(unsigned int i = 0; i < v.length(); i++)
//	{
//		std::cout << _vInput[i];
//		if (i < _inputLength - 1)
//			std::cout << " ";
//	}
//}