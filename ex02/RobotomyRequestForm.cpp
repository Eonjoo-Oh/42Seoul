#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("robotomy", 72, 45) 
{
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
		AForm::operator=(obj);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {};

bool	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	int	randNum = 0;
	std::cout << "Drillllllllllll........." << std::endl;
	std::cout << "with a 50% chance..." << std::endl;
	randNum = rand();
	std::cout << "randNum: " << randNum << std::endl;
	if (randNum % 2  == 0)
	{
		std::cout << executor.getName() << " has been robotomized!" << std::endl;
	}
	else
	{
		std::cout << executor.getName() << " robotomized is failed!" << std::endl;
	}
	return (true);
}