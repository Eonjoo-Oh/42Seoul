#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern	internA;
	AForm *form;
	form = internA.makeForm("robotomy request", "robototo");
	std::cout << form->getName();
}