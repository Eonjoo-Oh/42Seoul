#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Form
{
	private :
		const std::string	_name;
		bool	isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredtoExecute; 
	public :
		Form();
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredtoExecute);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();
		void	getName();
		void	getGradeRequiredToSign();
		void	getGradeRequiredtoExecure();
		void	beSigned();
		class	GradeTooHighException : public std::exception
		{
			public :
				const char *what(void) const throw()
				{
				
				}
		}
		class	GradeTooLowException : public std::exception
		{
			public :
				const char *what(void) const throw()
				{
				
				}
		}

};

std::ostream& operator << (std::ostream &os, const Form &obj);

#endif