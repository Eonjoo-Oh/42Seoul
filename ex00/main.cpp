#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: check argument number" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange	bitcoin(argv[1]);
		//bitcoin.testPrintAllMapElement();
	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}