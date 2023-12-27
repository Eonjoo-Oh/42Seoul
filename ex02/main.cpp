#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	ShrubberyCreationForm berry;
	Bureaucrat	karry("karry", 3);
	berry.execute(karry);

	RobotomyRequestForm robota;
	robota.execute(karry);
}