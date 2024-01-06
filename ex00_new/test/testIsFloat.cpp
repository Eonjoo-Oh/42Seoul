#include <iostream>
#include <sstream>
#include "../ConverterUtil.hpp"

int main()
{
	try
	{
		std::cout << ConverterUtil::isFloat("42.02983010f") << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}