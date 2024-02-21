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
		std::deque<std::pair<int, int> >	_dPendingPair;
	
		clock_t				_vStartTime;
		clock_t				_vEndTime;
		clock_t				_dStartTime;
		clock_t				_dEndTime;
		
		int					_lastElement;
		
		bool				fillInputV(char **argv);
		bool				checkOnlyPositive();

		void				fillChain(std::vector<int> &target, const std::vector<int> &origin, size_t index, size_t span);
		void				fillMainChain(std::vector<int> &mainChain, std::vector<std::pair<int, int> >pendingPair);
		void				groupAndCompare(std::vector<int> &pendinChain);
		void				recursiveSortLargeElement(std::vector<std::pair<int, int> > &v, int start, int end);
		void				binaryInsertSort(std::vector<int> &mainChain, std::vector<int> &pendinChain);
		void				binaryInsertSortUsingJacobsthal(std::vector<int> &mainChain, std::vector<std::pair<int, int> > &pendingPair);
		void				binaryInsertSort(std::vector<int> &mainChain, int target);

		int					jacobsthal(int n);
		void				binaryInsert(std::vector<int> &mainChain, std::vector<int> &pendingChain, int targetIdx);
		void				binaryInsert(std::vector<int> &mainChain, std::vector<std::pair <int, int> > &pendingPair, int targetIdx);
		
		
		//--------------deque
		void				fillChain(std::deque<int> &target, const std::vector<int> &origin, size_t index, size_t span);
		void				groupAndCompare(std::deque<int> &pendingChain);
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

		void	sortVector();
		void	sortDeque();
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
		void	printAllDequeElement(std::deque<int> &d)
		{
			for(size_t i = 0; i < d.size(); i++)
			{
				std::cout << d[i] << " ";
			}
		}
		
};