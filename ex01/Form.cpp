#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeRequiredToSign(1), _gradeRequiredtoExecute(1) {};

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredtoExecute) 
: _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredtoExecute(gradeRequiredtoExecute)
{
	try 
	{
		if (_gradeRequiredToSign < 1 || _gradeRequiredtoExecute < 1)
			throw GradeTooHighException();
		else if (_gradeRequiredToSign > 150 || _gradeRequiredtoExecute > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << "Error! : " << e.what() << std::endl;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << "Error! : " << e.what() << std::endl;
	}
}

Form::Form(const Form &obj)
: _name(obj._name), _isSigned(false), _gradeRequiredToSign(obj._gradeRequiredToSign), _gradeRequiredtoExecute(obj._gradeRequiredtoExecute) {}

Form &Form::operator = (const Form &obj)
{
	_isSigned = obj._isSigned;
	return (*this);
}

std::ostream& operator << (std::ostream &os, const Form &obj)
{
	std::cout << "Form name : " << obj.getName() << std::endl;
	std::cout << "Grade Required to Sign : " << obj.getGradeRequiredToSign() << std::endl;
	std::cout << "Grade Required to Execute : " << obj.getGradeRequiredtoExecure() << std::endl;
	std::cout << "Signed : " << obj.getIsSigned() << std::endl;
	return (os);
}

Form::~Form() {};

std::string Form::getName() const
{
	return (_name);
}

int	Form::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int	Form::getGradeRequiredtoExecure() const
{
	return (_gradeRequiredtoExecute);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw GradeTooLowException();
	else
	{
		_isSigned = true;
		std::cout << bureaucrat.getName() << " can sign this Form!" << std::endl;
	}
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's Grade is Too High to sign");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's Grade is Too Low to sign");
}