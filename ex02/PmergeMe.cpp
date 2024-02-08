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

//---------------------- get functions
unsigned int	PmergeMe::getInputLength()
{
	return (_inputLength);
}

//---------------------- test
void PmergeMe::printAllElementVInput()
{
	for(unsigned int i = 0; i < _inputLength; i++)
	{
		std::cout << _vInput[i];
		if (i < _inputLength - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}