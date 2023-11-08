#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"
#define ADD 1
#define SEARCH 2
#define EXIT 3

int main()
{
	PhoneBook	phonebook;
	int			command;
	while (1)
	{
		std::cout << "What service would you like to use?" << std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::cin >> phonebook.inputCommand;
		command = phonebook.determineCommand(phonebook.inputCommand);
		if (command == ADD)
			phonebook.addContact();
		else if (command == SEARCH)
			phonebook.searchContact();
		else if (command == EXIT)
		{
			std::cout<< "Bye Bye" << std::endl;
			break;
		}
		else
			std::cout << "Wrong command. Try again" << std::endl;
	}
}