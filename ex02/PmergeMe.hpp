#pragma once
#include <iostream>
#include <vector>
#include <sstream>

class	PmergeMe
{
	private :
		std::vector<int>	_vInput;
		unsigned int		_inputLength;
	public :
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();
		void	getVInput(char **argv);
};