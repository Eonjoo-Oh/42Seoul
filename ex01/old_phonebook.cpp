#include <iostream>
#include <string>

class PhoneBook
{
	Contact contact[8];
};

class Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	NickName;
		std::string	PhoneNumber;
		std::string	DarkestSeceret;
};

int main()
{
	PhoneBook	PhoneBook;
	char	*command;

	while (1)
	{
		std::cout << "What service would you like to use?" << std::endl;
		std::cout << "1.ADD 2.SEARCH 3.EXIT";
		std::cin << command;
		if ()
	}

}
//string은 문자열이고, char *은?