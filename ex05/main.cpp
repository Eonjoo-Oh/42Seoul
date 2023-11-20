#include "Harl.hpp"

int main()
{
	std::string	level;
	Harl		harl;

	std::cout << "Hello Harl, Please enter your Angry Level" << std::endl;
	std::cout << "debug | info | warning | error" << std::endl;
	std::cin >> level;
	harl.complain(level);
}