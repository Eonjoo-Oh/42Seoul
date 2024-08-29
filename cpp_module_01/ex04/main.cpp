#include <fstream>
#include <iostream>
#include "Sed.hpp"

int main(int argc, char **argv)
{
	std::string	oldWord;
	std::string	newWord;

	if (argc != 4)
	{
		std::cout << "Check the number of argument" << std::endl;
		return (1);
	}
	oldWord = argv[2];
	newWord = argv[3];
	if (oldWord == newWord || oldWord == "")
	{
		std::cout << "invalid input!" << std::endl;
		return (1);
	}
	Sed	sed(argv[1], argv[2], argv[3]);
	if (sed.fileProcess() == false)
		return (1);
	if (sed.rewriteProcess() == false)
		return (1);
	sed.closeFile();
	return (0);
}