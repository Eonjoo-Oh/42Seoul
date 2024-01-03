#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeRequiredToSign(1), _gradeRequiredtoExecute(1) {};

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredtoExecute) 
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

AForm::AForm(const AForm &obj)
: _name(obj._name), _isSigned(false), _gradeRequiredToSign(obj._gradeRequiredToSign), _gradeRequiredtoExecute(obj._gradeRequiredtoExecute) {}

AForm &AForm::operator = (const AForm &obj)
{
	_isSigned = obj._isSigned;
	return (*this);
}

std::ostream& operator << (std::ostream &os, const AForm &obj)
{
	std::cout << "AForm name : " << obj.getName() << std::endl;
	std::cout << "Grade Required to Sign : " << obj.getGradeRequiredToSign() << std::endl;
	std::cout << "Grade Required to Execute : " << obj.getGradeRequiredtoExecute() << std::endl;
	std::cout << "Signed : " << obj.getIsSigned() << std::endl;
	return (os);
}

AForm::~AForm() {};

std::string AForm::getName() const
{
	return (_name);
}

int	AForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int	AForm::getGradeRequiredtoExecute() const
{
	return (_gradeRequiredtoExecute);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw GradeTooLowException();
	else
	{
		_isSigned = true;
		std::cout << bureaucrat.getName() << " can sign this AForm!" << std::endl;
	}
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's Grade is Too High to sign");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's Grade is Too Low to sign");
}

const char	*AForm::UnsignedException::what(void) const throw()
{
	return ("Form is not signed");
}