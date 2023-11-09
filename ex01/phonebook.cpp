#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	totalSaved = 0;
}

void	PhoneBook::addContact()
{
	std::string	input;

	if (index == 8)
		index = 0;
	if (totalSaved < 8)
		totalSaved++;
	std::cout << "Enter first name: " << std::endl;
	std::cin >> input;
	if (std::cin.eof())
		input = whenEofAtADD();//eof가 들어오면 계속 받는 코드를 짤것
	contacts[index].setFirstName(input);
	std::cout << "Enter last name: " << std::endl;
	std::cin >> input;
	if (std::cin.eof())
		input = whenEofAtADD();
	contacts[index].setLastName(input);
	std::cout << "Enter nick name: " << std::endl;
	std::cin >> input;
	if (std::cin.eof())
		input = whenEofAtADD();
	contacts[index].setNickName(input);
	std::cout << "Enter phone number: " << std::endl;
	std::cin >> input;
	if (std::cin.eof())
		input = whenEofAtADD();
	contacts[index].setPhoneNumber(input);
	std::cout << "Enter darkest secret: " << std::endl;
	std::cin >> input;
	if (std::cin.eof())
		input = whenEofAtADD();
	contacts[index].setDarkestSecret(input);
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
	while (1) 
	{
		std::cout << "Enter an index: ";
		std::cin >> enteredIndex;
		if (std::cin.fail() || enteredIndex <= 0 || enteredIndex > totalSaved) 
		{
			std::cout << "Wrong index. Try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
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
		aligned = aligned.substr(0,9) + ".";
	for(int i = 0; i < (int)(10 - aligned.length()); i++)
	{
		std::cout << " ";
	}
	std::cout << aligned;
}

void	PhoneBook::whenEof()
{
	std::clearerr(stdin);
	std::cin.clear();
}

std::string PhoneBook::whenEofAtADD()
{
	std::string	result;

	while (std::cin.eof())
	{
		whenEof();
		std::cout << "Wrong input. Try again" << std::endl;
		std::cin >> result;
	}
	return result;
}