#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private :
		std::string	_target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();
		std::string	getTarget() const;
		void		setTarget(std::string target);
		bool		execute(Bureaucrat const &executor) const;
		AForm		*makeNew();
};

#endif