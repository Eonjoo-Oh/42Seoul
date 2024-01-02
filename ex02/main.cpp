#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	ShrubberyCreationForm	shrubbery("home");
	RobotomyRequestForm		robotomy("robot");
	PresidentialPardonForm	pardon("president");

	Bureaucrat				amy("Amy", 130); //only can shrubbery
	Bureaucrat				bella("Bella", 70); //can shrubbery, robotomy sign
	Bureaucrat				coco("Coco", 30); //can shrubbery, robotomy
	Bureaucrat				dorae("Dorae", 2); // can do anything
	Bureaucrat				elle("Elle", 150); //can't do anything

	std::cout << "-------------------- get target test -------------------" << std::endl;
	std::cout << "shrubbery target : " << shrubbery.getTarget() << std::endl;
	std::cout << "robotomy target : " << robotomy.getTarget() << std::endl;
	std::cout << "pardon target : " << pardon.getTarget() << std::endl;

	std::cout << std::endl << "-------------------- execute unsigned form test -------------------" << std::endl;
	amy.executeForm(shrubbery);
	coco.executeForm(robotomy);
	dorae.executeForm(pardon);

	dorae.signForm(shrubbery);
	dorae.signForm(robotomy);
	dorae.signForm(pardon);

	std::cout << std::endl << "-------------------- execute SHRUBBERY test -------------------" << std::endl;
	elle.executeForm(shrubbery);
	amy.executeForm(shrubbery);
	coco.executeForm(shrubbery);

	std::cout << std::endl << "-------------------- execute ROBOTOMY test -------------------" << std::endl;
	amy.executeForm(robotomy);
	bella.executeForm(robotomy);
	coco.executeForm(robotomy);
	
	std::cout << std::endl << "-------------------- execute PARDON test -------------------" << std::endl;
	amy.executeForm(pardon);
	dorae.executeForm(pardon);
}