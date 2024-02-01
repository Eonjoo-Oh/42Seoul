# pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>

class	BitcoinExchange
{
	private :
		BitcoinExchange();
		std::ifstream			_infileStream;
		std::ifstream			_csvFileStream;
		std::string				_infileName;
		std::string				_csvFileName;
		std::map<int, float>	_csvMap;
		std::string				_sDate;
		float					_fRate;

		void	readCsvFile();
		int		sDatetoiDate(std::string sYear, std::string sMonth, std::string sDay);
		void	displayResult();
		//------------------utils
		bool	isOnlyWhitespace(std::string);
		bool	isRightForm(std::string line);
		bool	isValidDate();
		bool	isLeapYear(int year);
	public :
		BitcoinExchange(std::string infileName);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();
		class	fileOpenException : public std::exception
		{
			public :
				const char *what(void) const throw();
		};
		void	readInputFile();
		//---------------------------
		void	testPrintAllMapElement();

};