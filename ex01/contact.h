#include <iostream>
#ifndef CONTACT_H
#define CONTACT_H

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		void		setContact();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};

void	Contact::setContact()
{
	std::cout << "Enter first name: " << std::endl;
	std::cin >> firstName;
	std::cout << "Enter last name: " << std::endl;
	std::cin >> lastName;
	std::cout << "Enter nick name: " << std::endl;
	std::cin >> nickName;
	std::cout << "Enter phone number: " << std::endl;
	std::cin >> phoneNumber;
	std::cout << "Enter darkest seceret: " << std::endl;
	std::cin >> darkestSecret;
	std::cout << "SAVED!" << std::endl;
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNickName()
{
	return (nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (darkestSecret);
}

#endif