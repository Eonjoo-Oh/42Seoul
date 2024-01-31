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
	std::string	line;

	_csvFileStream.open(_csvFileName.c_str());
	if (!_csvFileStream.is_open())
		throw fileOpenError();
	while (!_csvFileStream.eof())
	{
		std::getline(_csvFileStream, line);
		std::istringstream	iss(line);
		std::string	sDate;
		std::string	sRate;
		int			iDate;
		float		fRate;

		std::getline(iss, sDate, ',');
		std::getline(iss, sRate);
		iDate = sDatetoiDate(sDate);
		fRate = static_cast<float>(std::strtod(sRate.c_str(), NULL));		
		_csvMap[iDate] = fRate;
	}
	_csvFileStream.close();
}

int	BitcoinExchange::sDatetoiDate(std::string sDate)
{
	int	year;
	int	month;
	int day;
	int	convertedDate;

	year = static_cast<int>(std::strtod(sDate.substr(0, 4).c_str(), NULL));
	month = static_cast<int>(std::strtod(sDate.substr(4, 2).c_str(), NULL));
	day = static_cast<int>(std::strtod(sDate.substr(6, 2).c_str(), NULL));
	convertedDate = year * 1000 + month * 100 + day;
	return (convertedDate);
}