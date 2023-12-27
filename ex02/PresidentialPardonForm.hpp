#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

class	PresidentialPardonForm
{
	private :
		const int	_gradeRequiredToSign;
		const int	_gradeRequiredtoExecute;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();
};

#endif
