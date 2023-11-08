#include <iostream>
#include "contact.h"
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#define UNDEFINED 0
#define ADD 1
#define SEARCH 2
#define EXIT 3

class	PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
		int		totalSaved;
	public:
		PhoneBook();
		std::string	inputCommand;
		int			determineCommand(std::string inputCommand);
		void		addContact();
		void		searchContact();
		void		showAllContact();
		void		showSelectedContact(int index);
		void		printRightAligned(std::string str);
};

PhoneBook::PhoneBook()
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
	if (index == 8)
		index = 0;
	if (totalSaved < 8)
		totalSaved++;
	contacts[index].setContact();
	index++;
}

void	PhoneBook::searchContact()
{
	int	enteredIndex;

	if (totalSaved == 0)
	{
		std::cout << "Your phone book is empty!" << std::endl;
		return ;
	}
	showAllContact();
	std::cout << "Enter the index number" << std::endl;
	std::cin >> enteredIndex;
	while (!(enteredIndex > 0 && enteredIndex <= totalSaved))
	{
		std::cout << "Wrong index. Try again" << std:: endl;
		std::cin >> enteredIndex;
	}
	showSelectedContact(enteredIndex - 1);
}

void	PhoneBook::showAllContact()
{
	for(int i = 1; i <= totalSaved; i++)
	{
		std::cout << "         " << i << '|';
		printRightAligned(contacts[i - 1].getFirstName());
		std::cout << '|';
		printRightAligned(contacts[i - 1].getLastName());
		std::cout << '|';
		printRightAligned(contacts[i - 1].getNickName());
		std::cout << std::endl;
	}
}

void	PhoneBook::showSelectedContact(int index)
{
	std::cout << contacts[index].getFirstName() << std::endl;
	std::cout << contacts[index].getLastName() << std::endl;
	std::cout << contacts[index].getNickName() << std::endl;
	std::cout << contacts[index].getPhoneNumber() << std::endl;
	std::cout << contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::printRightAligned(std::string str)
{
	std::string	aligned;

	aligned = str;
	if (aligned.length() > 10)
	{
		aligned = aligned.substr(0,9);
		aligned.append(".");
	}
	for(int i = 0; i < 10 - aligned.length(); i++)
	{
		std::cout << " ";
	}
	std::cout << aligned;
}

#endif