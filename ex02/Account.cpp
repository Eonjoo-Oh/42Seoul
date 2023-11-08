#include <iostream>
#include <ctime>
//#include "Account.hpp"

class Account{
	public:
		void	_displayTimestamp(void);
};

void	Account::_displayTimestamp(void)
{
	std::time_t timestamp = std::time(nullptr);
	char	buffer[16];
	std::strftime(buffer, 16, "%Y%m%d_%H%M%S", std::localtime(&timestamp));
	std::cout << "[" << buffer << "]" << std::endl;
}

int main()
{
	Account account;

	account._displayTimestamp();
}