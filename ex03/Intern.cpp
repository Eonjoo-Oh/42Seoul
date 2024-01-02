#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &obj) 
{
	*this = obj;
}

Intern &Intern::operator = (const Intern &obj) 
{
	if (this != &obj)
		Intern::operator=(obj);
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	formNameArr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*formArr[3];
	AForm		*returnForm;

	formArr[0] = new ShrubberyCreationForm(formTarget);
	formArr[1] = new RobotomyRequestForm(formTarget);
	formArr[2] = new PresidentialPardonForm(formTarget);
	for(int i = 0; i < 3; i++)
	{
		if (formName == formNameArr[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formArr[i]);
			//delete[] formArr;
			//return (returnForm);
		}
	}
	//delete[] formArr;
	//throw std::invalid_argument("Invalid form name");
};