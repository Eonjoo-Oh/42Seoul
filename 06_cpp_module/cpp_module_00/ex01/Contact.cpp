#include "Contact.hpp"

void	Contact::setFirstName(std::string input)
{
	firstName = input;
}

void	Contact::setLastName(std::string input)
{
	lastName = input;
}

void	Contact::setNickName(std::string input)
{
	nickName = input;
}

void	Contact::setPhoneNumber(std::string input)
{
	phoneNumber = input;
}

void	Contact::setDarkestSecret(std::string input)
{
	darkestSecret = input;
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
