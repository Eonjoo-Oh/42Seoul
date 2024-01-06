#include <iostream>
#include <sstream>
#include "../ConverterUtil.hpp"
/*
int main()
{
	char				c;
	int					i;
	std::string			a = "++42";
	std::istringstream	iss(a);

	iss >> i;
	try
	{
		if (iss.fail() || !iss.eof())
			throw	std::invalid_argument("impossible");
		std::cout << i;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
*/

int main()
{
	try
	{
		std::cout << ConverterUtil::isChar("-78") << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}