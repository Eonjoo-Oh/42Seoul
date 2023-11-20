#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Check the number of argument" << std::endl;
		return (1);
	}

	Harl		harl(argv[1]);

	if (harl.getFilterLevel() >= 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	harl.complainFilter("debug");
	harl.complainFilter("info");
	harl.complainFilter("warning");
	harl.complainFilter("error");
}