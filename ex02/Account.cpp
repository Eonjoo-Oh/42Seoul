#include <iostream>
#include <ctime>
//#include "Account.hpp"

class Account{
	private:
		int	deposit[7];
		int	index;
		Account();
	public:
		Account(int inital_deposit);
		void	_displayTimestamp(void);
		void	displayAccountsInfos(void);
};

Account::Account()
{
	index = 0;
}

Account::Account(int inital_deposit)
{
	deposit[index] = inital_deposit;
	std::cout << _displayTimestamp() << " " << "index: "
	index++;
}

void	Account::_displayTimestamp(void)
{
	std::time_t timestamp = std::time(nullptr);
	char	buffer[16];
	std::strftime(buffer, 16, "%Y%m%d_%H%M%S", std::localtime(&timestamp));
	std::cout << "[" << buffer << "]" << std::endl;
}

void	Account::displayAccoutsInfos(void)
{

}

int main()
{
	Account	account();
	account._displayTimestamp();
}