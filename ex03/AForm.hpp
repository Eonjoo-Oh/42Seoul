#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredtoExecute; 
	public :
		AForm();
		AForm(std::string name, int gradeRequiredToSign, int gradeRequiredtoExecute);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm();
		std::string	getName() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredtoExecute() const;
		bool		getIsSigned() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		virtual AForm	*makeNew() = 0;
		virtual bool	execute(Bureaucrat const &executor) const = 0;
		class	GradeTooHighException : public std::exception
		{
			public :
				const char *what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				const char *what(void) const throw();
		};
};

std::ostream& operator << (std::ostream &os, const AForm &obj);

#endif