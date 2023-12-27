#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <cstdlib>
#include <random>

class	RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();
		bool	execute(Bureaucrat const &executor) const;
};

#endif