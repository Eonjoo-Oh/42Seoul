#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string infileName)
{
	_infileStream.open(infileName.c_str());
	if (!_infileStream.is_open())
		throw fileOpenException();
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
	(void)obj;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

const char	*BitcoinExchange::fileOpenException::what() const throw()
{
	return ("Error: cant't open infile");
}

void	BitcoinExchange::readCsvFile()
{
	std::string	line;

	_csvFileStream.open(_csvFileName.c_str());
	if (!_csvFileStream.is_open())
		throw fileOpenException();
	std::getline(_csvFileStream, line);
	while (!_csvFileStream.eof())
	{
		std::getline(_csvFileStream, line);
		if (isOnlyWhitespace(line) == true)
			continue ;
		std::istringstream	iss(line);
		std::string	sYear;
		std::string	sMonth;
		std::string	sDay;
		std::string	sRate;
		int			iDate;
		float		fRate;

		std::getline(iss, sYear, '-');
		std::getline(iss, sMonth, '-');
		std::getline(iss, sDay, ',');
		std::getline(iss, sRate);
		//std::cout << sYear << sMonth << sDay << std::endl;
		iDate = sDatetoiDate(sYear, sMonth, sDay);
		//std::cout << iDate << std::endl;
		fRate = static_cast<float>(std::strtod(sRate.c_str(), NULL));
		//std::cout << fRate << std::endl;
		_csvMap.insert(std::make_pair(iDate, fRate));
	}
	_csvFileStream.close();
}

int	BitcoinExchange::sDatetoiDate(std::string sYear, std::string sMonth, std::string sDay)
{
	int	year;
	int	month;
	int day;
	int	convertedDate;

	year = static_cast<int>(std::strtod(sYear.c_str(), NULL));
	month = static_cast<int>(std::strtod(sMonth.c_str(), NULL));
	day = static_cast<int>(std::strtod(sDay.c_str(), NULL));
	convertedDate = year * 1000 + month * 100 + day;
	return (convertedDate);
}

//-----------------------utils
bool	BitcoinExchange::isOnlyWhitespace(std::string stdstr)
{
	for (size_t i = 0; i < stdstr.length(); i++)
	{
		if (!((stdstr[i] >= 9 && stdstr[i] <= 13) || stdstr[i] == 32))
			return (false);
	}
	return (true);
}

//---------------------------------------
void	BitcoinExchange::testPrintAllMapElement()
{
	for(std::map<int, float>::iterator itr = _csvMap.begin(); itr != _csvMap.end(); ++itr)
	{
		std::cout << itr->first << ":" << itr->second << std::endl;
	}
}