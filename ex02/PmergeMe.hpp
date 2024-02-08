#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <exception>
#include <stdexcept>

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
		bool			fillInputV(char **argv);
		bool			checkOnlyPositive();
		unsigned int	getInputLength();

		//------------------ test
		void	printAllElementVInput();
};