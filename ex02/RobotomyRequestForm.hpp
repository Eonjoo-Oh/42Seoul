#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

class	RobotomyRequestForm
{
	private :
		const int	_gradeRequiredToSign;
		const int	_gradeRequiredtoExecute;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();
};

#endif