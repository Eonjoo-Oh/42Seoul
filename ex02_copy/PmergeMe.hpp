#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <utility>

class	PmergeMe
{
	private :
		std::vector<int>	_vInput;

		std::vector<int>	_vMainChain;
		std::vector<int>	_vPendingChain;

		std::deque<int>		_dMainChain;
		std::deque<int>		_dPendingChain;

		std::vector<std::pair<int, int> >	_vPendingPair;
	
		clock_t				_vStartTime;
		clock_t				_vEndTime;
		clock_t				_dStartTime;
		clock_t				_dEndTime;
		
		int					_lastElement;
		
		bool				fillInputV(char **argv);
		bool				checkOnlyPositive();

		void				fillChain(std::vector<int> &target, const std::vector<int> &origin, size_t index, size_t span);
		void				fillMainChain();
		void				groupAndCompare(std::vector<int> &pendinChain);
		void				recursiveSortLargeElement(std::vector<std::pair<int, int> > &v, int start, int end);
		void				binaryInsertSort(std::vector<int> &mainChain, std::vector<int> &pendinChain);
		int					jacobsthal(int n);
		void				binaryInsert(std::vector<int> &mainChain, std::vector<int> &pendingChain, int targetIdx);
		//void				dFillPendingChain();
		//void				dGroupAndCompare();
		//void				dRecursiveSortLargeElement();
		//void				dBinaryInsertSort();
		void				printAllElement(std::vector<int> v);
		void				removePendingChain(std::vector<int> &pendingChain);

	public :
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
		~PmergeMe();

		void	SortVector();
		void	SortDeque();
		void	DisplayResult();
		//test
		void	printvInput() 
		{
			printAllElement(_vInput);
		};
		void	printvPendingChain() 
		{
			printAllElement(_vPendingChain);
		};
		void	printvMainChain() 
		{
			printAllElement(_vMainChain);
		};
};