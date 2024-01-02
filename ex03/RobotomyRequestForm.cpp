#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45) 
{
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy", 72, 45) 
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("robotomy", 72, 45) 
{
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	_target = obj.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {};

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	_target = target;
}

AForm	*RobotomyRequestForm::makeNew()
{
	AForm	*newForm = new RobotomyRequestForm();

	return (newForm);
}

bool	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::srand(static_cast<unsigned>(std::time(0)));
	int	randNum = 0;
	std::cout << "Drillllllllllll........." << std::endl;
	std::cout << "with a 50% chance..." << std::endl;
	randNum = rand();
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