#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <ctime>

class	PmergeMe
{
	private :
		std::vector<int>	_vInput;

		std::vector<int>	_vMainChain;
		std::vector<int>	_vPendingChain;

		std::deque<int>		_dMainChain;
		std::deque<int>		_dPendingChain;

		clock_t				_vStartTime;
		clock_t				_vEndTime;
		clock_t				_dStartTime;
		clock_t				_dEndTime;
		
		bool				fillInputV(char **argv);
		bool				checkOnlyPositive();

		void				vFillPendingChain();
		void				vGroupAndCompare();
		void				vRecursiveSortLargeElement();
		void				vBinaryInsertSort();

		void				dFillPendingChain();
		void				dGroupAndCompare();
		void				dRecursiveSortLargeElement();
		void				dBinaryInsertSort();

		void				printAllElement(std::vector<int> v);
	public :
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();

		void	SortVector();
		void	SortDeque();
		void	DisplayResult();
};