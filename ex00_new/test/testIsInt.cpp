#include <iostream>
#include <sstream>
#include "../ConverterUtil.hpp"

int main()
{
	try
	{
		std::cout << ConverterUtil::isInt("++213") << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}