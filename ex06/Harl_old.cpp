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

int		Harl::getFilterLevel(std::string input)
{
	std::string	complainTypeArr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	filterLevel = 0;

	while (filterLevel < 4)
	{
		if (input == complainTypeArr[filterLevel])
		{
			std::cout << "[" << complainTypeArr[filterLevel] << "]" << std::endl;
			return (filterLevel);
		}
		filterLevel++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (filterLevel);
}

int		Harl::getComplainType(std::string input)
{
	std::string	complainTypeArr[4] = {"debug", "info", "warning", "error"};
	int			complainType = 0;

	while (complainType < 4)
	{
		if (input == complainTypeArr[complainType])
			break;
		complainType++;
	}
	return (complainType);
}

void	Harl::complainFilter(std::string inputfilterLevel, std::string level)
{
	int		filterLevel = getFilterLevel(inputfilterLevel);
	int		complainType = getComplainType(level);
	void	(Harl::*executeComplain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (filterLevel >= 4)
		return ;
	std::cout << "complain Type : " << complainType << std::endl;
	switch(complainType)
	{
		case 0:
			(this->*executeComplain[0])();
		case 1:
			(this->*executeComplain[1])();
		case 2:
			(this->*executeComplain[2])();
		case 3:
			(this->*executeComplain[3])();
			break;
		default:
			std::cout << "Wrong complain type input" << std::endl;
	}
}