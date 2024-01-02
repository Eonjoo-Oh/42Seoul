#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("shrubbery", 145, 137) 
{
	*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
		AForm::operator=(obj);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

bool	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		outFileName;
	std::ofstream	outFile;

	try
	{
		outFileName = executor.getName().append("_shruberry");
		outFile.open(outFileName.c_str());
		if (!outFile.is_open())
			throw std::runtime_error("outFile open error");
    	outFile << "       ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n"
    	           "      /|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
    	           "      /|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
    	           "      /|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";
		outFile.close();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (false);
	}
	return (true);
}
