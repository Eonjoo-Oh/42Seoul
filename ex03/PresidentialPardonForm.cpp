#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential", 25, 5) 
{
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential", 25, 5) 
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("presidential", 25, 5)
{
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	_target = obj.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {};

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
};

void	PresidentialPardonForm::setTarget(std::string target)
{
	_target = target;
}

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return (true);
}

AForm	*PresidentialPardonForm::makeNew()
{
	return (new PresidentialPardonForm(*this));
}