#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredtoExecute; 
	public :
		Form();
		Form(std::string name, int gradeRequiredToSign, int gradeRequiredtoExecute);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form();
		std::string	getName() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredtoExecure() const;
		bool		getIsSigned() const;
		void		beSigned(const Bureaucrat &bureaucrat);
		class	GradeTooHighException : public std::exception
		{
			public :
				const char *what(void) const throw()
				{
					return ("Bureaucrat's Grade is Too High");
				}
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				const char *what(void) const throw()
				{
					return ("Bureaucrat's Grade is Too Low!");
				}
		};//cpp 파일로 분리하기
};

std::ostream& operator << (std::ostream &os, const Form &obj);

#endif