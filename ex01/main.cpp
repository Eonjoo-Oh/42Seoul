#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	command;
	while (1)
	{
		std::cout << "What service would you like to use?" << std::endl;
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::cin >> command;
		if (std::cin.eof())
			phonebook.whenEof();
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			std::cout<< "Bye Bye" << std::endl;
			break;
		}
		else
			std::cout << "Wrong command. Try again" << std::endl;
	}
}