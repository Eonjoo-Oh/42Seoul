#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

//void	leaks()
//{
//	system("leaks main");
//}

int main()
{
	//atexit(leaks);
	Intern	internA;
	Bureaucrat	master("master", 1);

	try
	{
		AForm	*shrubberyForm = internA.makeForm("shrubbery creation", "here");
		AForm	*robotForm = internA.makeForm("robotomy request", "toto");
		AForm	*pardonForm = internA.makeForm("presidential pardon", "prill");

		master.signForm(*shrubberyForm);
		master.executeForm(*shrubberyForm);
		std::cout << std::endl;

		master.signForm(*robotForm);
		master.executeForm(*robotForm);
		std::cout << std::endl;

		master.signForm(*pardonForm);
		master.executeForm(*pardonForm);
		std::cout << std::endl;
		delete shrubberyForm;
		delete robotForm;
		delete pardonForm;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	try
	{
		AForm *wrongForm = internA.makeForm("wrong form", "wrong");

		master.signForm(*wrongForm);
		master.executeForm(*wrongForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
}