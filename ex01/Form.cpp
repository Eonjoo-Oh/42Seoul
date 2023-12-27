#include "Form.hpp"

Form::Form() : _name("default"), _gradeRequiredToSign(1), _gradeRequiredtoExecute(1) {};

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredtoExecute) 
: _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredtoExecute(gradeRequiredtoExecute)
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