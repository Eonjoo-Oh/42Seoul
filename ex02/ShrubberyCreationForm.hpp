#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private :
		std::ofstream	outFile;
		bool			executeResult;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();
		bool	execute(Bureaucrat const &executor) const;
};

#endif