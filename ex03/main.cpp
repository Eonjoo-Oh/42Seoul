#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern	internA;
	Bureaucrat	master("master", 1);

	try
	{
		AForm	*shrubberyForm = internA.makeForm("shrubbery creation", "here");
		AForm	*robotForm = internA.makeForm("robotomy request", "toto");
		AForm	*pardonForm = internA.makeForm("presidential pardon", "prill");
		AForm	*wrongForm = internA.makeForm("wrong form", "wrong");

		master.signForm(*shrubberyForm);
		master.executeForm(*shrubberyForm);
		master.signForm(*robotForm);
		master.executeForm(*robotForm);
		master.signForm(*pardonForm);
		master.executeForm(*pardonForm);
		master.signForm(*wrongForm);
		master.executeForm(*wrongForm);
		// std::cout << "shrubberyForm name : " << shrubberyForm->getName() << std::endl;
		// std::cout << "robotForm name : " << robotForm->getName() << std::endl;
		// std::cout << "pardonForm name : " << pardonForm->getName() << std::endl;
		// std::cout << "wrongForm name : " << wrongForm->getName() << std::endl;
		delete shrubberyForm;
		delete robotForm;
		delete pardonForm;
	}
	catch (Intern::NonExistFormException &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
}