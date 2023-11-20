#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(std::string inputFilterLevel)
{
	filterLevelArr[0] = "DEBUG";
	filterLevelArr[1] = "INFO";
	filterLevelArr[2] = "WARNING";
	filterLevelArr[3] = "ERROR";
	complainLevelArr[0] = "debug";
	complainLevelArr[1] = "info";
	complainLevelArr[2] = "warning";
	complainLevelArr[3] = "error";
	setFilterLevel(inputFilterLevel);
}

Harl::~Harl() {}

void	Harl::setFilterLevel(std::string input)
{
	filterLevel = 0;

	while (filterLevel < MAX_NUMBER_OF_COMPLAIN)
	{
		if (input == filterLevelArr[filterLevel])
			break;
		filterLevel++;
	}
}

int	Harl::getFilterLevel(void)
{
	return (filterLevel);
}

int	Harl::getComplainLevel(std::string input)
{
	int			complainLevel = 0;

	while (complainLevel < 4)
	{
		if (input == complainLevelArr[complainLevel])
			break;
		complainLevel++;
	}
	return (complainLevel);
}

void	Harl::complainFilter(std::string level)
{
	void	(Harl::*executeComplain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		complainLevel = getComplainLevel(level);

	if (complainLevel >= this->filterLevel)
	{
		std::cout << "[" << filterLevelArr[complainLevel] << "]" << std::endl;
		switch(complainLevel)
		{
			case 0:
				(this->*executeComplain[0])();
				std::cout << std::endl;
				break;
			case 1:
				(this->*executeComplain[1])();
				std::cout << std::endl;
				break;
			case 2:
				(this->*executeComplain[2])();
				std::cout << std::endl;
				break;
			case 3:
				(this->*executeComplain[3])();
				std::cout << std::endl;
				break;
			default:
				std::cout << "Wrong complain level input" << std::endl;
		}
	}
}
