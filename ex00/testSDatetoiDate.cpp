#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>

int sDatetoiDate(std::string sYear, std::string sMonth, std::string sDay)
{
	int	year;
	int	month;
	int day;
	int	convertedDate;

	year = static_cast<int>(std::strtod(sYear.c_str(), NULL));
	month = static_cast<int>(std::strtod(sMonth.c_str(), NULL));
	day = static_cast<int>(std::strtod(sDay.c_str(), NULL));
	convertedDate = (year * 10000) + (month * 100) + day;
	return (convertedDate);
}

int main()
{
	int	result = sDatetoiDate("2011", "01", "30");
	std::cout << result << std::endl;

}