#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential", 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("presidential", 25, 5)
{
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
		AForm::operator=(obj);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {};

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (true);
}