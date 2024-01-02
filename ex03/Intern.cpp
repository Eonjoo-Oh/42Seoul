#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &obj) 
{
	*this = obj;
}

Intern &Intern::operator = (const Intern &obj) 
{
	(void)obj;
	return (*this);
}

Intern::~Intern() {}

AForm	*Intern::newShrubberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::newRobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::newPresidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	formNameArr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*newForm[3])(std::string);

	newForm[0] = &Intern::newShrubberyCreation;
	newForm[1] = &Intern::newRobotomyRequest;
	newForm[2] = &Intern::newPresidentialPardon;

	for(int i = 0; i < 3; i++)
	{
		if (formName == formNameArr[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			AForm *returnForm = (this->*newForm[i])(formTarget);
			return (returnForm);
		}
	}
	throw NonExistFormException();
}

const char *Intern::NonExistFormException::what(void) const throw()
{
	return ("Form isn't exist");
}