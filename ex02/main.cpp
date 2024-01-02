#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <thread>

//s 145/137
//r 72/45
//p 25/5

int main()
{
	ShrubberyCreationForm	shrubbery;
	RobotomyRequestForm		robotomy;
	PresidentialPardonForm	pardon;

	Bureaucrat				amy("Amy", 130); //only can shrubbery
	Bureaucrat				bella("Bella", 70); //can shrubbery, robotomy sign
	Bureaucrat				coco("Coco", 30); //can shrubbery, robotomy
	Bureaucrat				dorae("Dorae", 2); // can do anything
	Bureaucrat				elle("Elle", 150); //can't do anything

	std::cout << "-------------------- execute unsigned form test -------------------" << std::endl;
	amy.executeForm(shrubbery); //she is qualified but form is not signed
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
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	dorae.executeForm(robotomy);
	
	std::cout << std::endl << "-------------------- execute PARDON test -------------------" << std::endl;
	amy.executeForm(pardon);
	dorae.executeForm(pardon);
}