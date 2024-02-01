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

		void	readCsvFile();
		int		sDatetoiDate(std::string sYear, std::string sMonth, std::string sDay);
	public :
		BitcoinExchange(std::string infileName);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();
		class	fileOpenError : public std::exception
		{
			void	what();
		};


};