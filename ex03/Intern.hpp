#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public :
		Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern();
		AForm	*makeForm(std::string _formName, std::string _formTarget);
		AForm	*newShrubberyCreation(std::string target);
		AForm	*newRobotomyRequest(std::string target);
		AForm	*newPresidentialPardon(std::string target);
		class	NonExistFormException : public std::exception
		{
			public :
				const char *what(void) const throw();
		};
};

#endif