#include "Bureaucrat.hpp"

int  main()
{
	std::cout << "<< Copy Constructor Test >> " << std::endl;
	Bureaucrat choi("choi", 3);
	Bureaucrat Lim(choi);
	std::cout << choi;
	std::cout << Lim;
	Bureaucrat kang("Kang", 124);
	kang = choi;
	std::cout << kang;

	std::cout << std::endl << "<< Constructor Exception Test >> " << std::endl;
	Bureaucrat lee("Lee", -1);
	Bureaucrat kim("Kim", 151);
	Bureaucrat oh("Oh", 2);
	Bureaucrat park("Park", 150);

	std::cout << std::endl << "<< Operator << Overloading Test >> " << std::endl;
	std::cout << oh;
	std::cout << park;

	std::cout << std::endl << "<< Increase Grade Test >> " << std::endl;
	std::cout << oh;
	oh.increase_grade();
	std::cout << oh;
	oh.increase_grade();
	std::cout << oh;

	std::cout << std::endl << "<< Decrease Grade Test >> " << std::endl;
	std::cout << park;
	park.decrease_grade();
}