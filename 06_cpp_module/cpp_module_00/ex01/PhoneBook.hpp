#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <cstdio>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
		int		totalSaved;
	public:
		PhoneBook();
		std::string	inputCommand;
		std::string	whenEofAtADD();
		void		addContact();
		void		searchContact();
		void		showAllContact();
		void		showSelectedContact(int index);
		void		printRightAligned(std::string str);
		void		whenEof();
};

#endif