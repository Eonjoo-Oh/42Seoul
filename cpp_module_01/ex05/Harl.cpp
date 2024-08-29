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

void	Harl::complain(std::string level)
{
	void		(Harl::*executeComplain[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	complainTypeArr[4] = {"debug", "info", "warning", "error"};
	int			complainType = 0;

	while (complainType < 4)
	{
		if (level == complainTypeArr[complainType])
			break;
		complainType++;
	}

	switch(complainType)
	{
		case 0:
			(this->*executeComplain[0])();
			break;
		case 1:
			(this->*executeComplain[1])();
			break;
		case 2:
			(this->*executeComplain[2])();
			break;
		case 3:
			(this->*executeComplain[3])();
			break;
		default:
			std::cout << "Wrong complaint type input" << std::endl;
	}
}
