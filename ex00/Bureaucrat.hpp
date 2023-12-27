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
		Bureaucrat &operator <<(const Bureaucrat &obj);
		~Bureaucrat();
		std::string	get_name();
		int			get_grade();
		void		increase_grade();
		void		decrease_grade();
		class		GradeTooHighException : public std::exception
		{
			public :
				const char *what(void) const throw()
				{
					return ("Grade is Too High!\n");
				}
		};
		class		GradeTooLowException : public std::exception
		{
			public :
				const char *what(void) const throw()
				{
					return ("Grade is Too Low!\n");
				}
		};
};

#endif