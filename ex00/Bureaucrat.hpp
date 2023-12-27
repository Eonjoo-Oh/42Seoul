#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private :
		const std::string	_name;
		int					_grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator =(const Bureaucrat &obj);
		~Bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		void		increase_grade();
		void		decrease_grade();
		class		GradeTooHighException : public std::exception
		{
			public :
				const char *what(void) const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			public :
				const char *what(void) const throw();
		};
};

std::ostream& operator << (std::ostream &os, const Bureaucrat &obj);

#endif