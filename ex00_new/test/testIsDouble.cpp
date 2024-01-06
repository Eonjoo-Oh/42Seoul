#include <iostream>
#include <sstream>
#include "../ConverterUtil.hpp"

int main()
{
	try
	{
		std::cout << ConverterUtil::isDouble("398298378170938398") << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}