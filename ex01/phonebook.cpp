#include <iostream>
#define UNDEFINED 0;
#define ADD 1;
#define SEARCH 2;
#define EXIT 3;

class	PhoneBook
{
	private:
		Contact contacts[8];
	public:
		SetPhoneBook();
		std::string	inputCommand;
		int		index;
		int		totalSaved;
		int		determineCommand(std::string inputCommand);
		void	addContact();
		void	searchContact();
};

PhoneBook::SetPhoneBook()
{
	index = 0;
	totalSaved = 0;
}

int	PhoneBook::determineCommand(std::string inputCommand)
{
	if (inputCommand.compare("ADD") == 0)
		return ADD;
	if (inputCommand.compare("SEARCH") == 0)
		return SEARCH;
	if (inputCommand.compare("EXIT") == 0)
		return EXIT;
	return UNDEFINED;
}

void	PhoneBook::addContact()
{
	index++;
	if (index > 8)
		index = 0;
	std::cout << "Enter first name" << std::endl;
	std::cin >> contacts[index].firstName;
	std::cout << "Enter last name" << std::endl;
	std::cin >> contacts[index].lastName;
	std::cout << "Enter nick name" << std::endl;
	std::cin >> contacts[index].nickName;
	std::cout << "Enter phone number" << std::endl;
	std::cin >> contacts[index].phoneNumber;
	std::cout << "Enter darkest seceret" << std::endl;
	std::cin >> contacts[index].darkestSecret;
	std::cout << "SAVED!" << std::endl;
	if (totalSaved < 8)
		totalSaved++;
}

void	PhoneBook::searchContact()
{


}

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSeceret;
};

int main()
{
	PhoneBook	phonebook;
	while (1)
	{
		std::cout << "What service would you like to use?" << std::endl;
		std::cout << "1.ADD 2.SEARCH 3.EXIT" << std::endl;
		std::cin >> phonebook.inputCommand;
		if (phonebook.determineCommand(phonebook.inputCommand) == ADD)
			phonebook.addContact();
		if (phonebook.determineCommand(phonebook.inputCommand) == SEARCH)
		if (phonebook.determineCommand(phonebook.inputCommand) == EXIT)
		{
			std::cout<< "Bye Bye" << std::endl;
			break;
		}
		else
			std::cout << "Wrong command. Try again" << std::endl;
		
	}
}