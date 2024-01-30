#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string infileName)
{
	_infileStream.open(_infileName.c_str());
	if (!_infileStream.is_open())
		throw fileOpenError();

	_infileName = infileName;
	_csvFileName = "data.csv";
	
	readCsvFile();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::fileOpenError::what()
{
	std::cout << "Error : can't open infile";
}

void	BitcoinExchange::readCsvFile()
{
	int	year;
	int	month;
	int	date;

	_csvFileStream.open(_csvFileName.c_str());
	if (!_csvFileStream.is_open())
		throw fileOpenError();
	
}