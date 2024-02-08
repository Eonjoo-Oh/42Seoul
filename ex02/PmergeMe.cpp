#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	try
	{
		fillInputV(argv);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

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

void	PmergeMe::fillInputV(char **argv)
{
	for(int i = 1; argv[i]; i++)
	{
		std::istringstream	iss(argv[i]);
		int					num;

		while (iss >> num)
		{
			if (iss.fail())//에러처리)
				throw (std::runtime_error("Error: invalid argument input"));
			_vInput.push_back(num);
			iss.ignore(); //이게 필요한지 알아봐야겠다
		}
	}
}

//---------------------- get functions
unsigned int	PmergeMe::getInputLength()
{
	return (_inputLength);
}