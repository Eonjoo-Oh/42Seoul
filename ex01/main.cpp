#include "Zombie.hpp"
#include <cstdio>

Zombie* zombieHorde(int N, std::string name);

void	whenEof()
{
	std::clearerr(stdin);
	std::cin.clear();
	std::cout << std::endl;
}

int main()
{
	Zombie		*zombies;
	std::string	name;
	int			n;

	std::cout << "Enter the name of zombie" << std::endl;
	std::getline(std::cin >> std::ws, name);
	while (1)
	{
		std::cout << "How many " << name << "s do you want?" << std::endl;
		std::cin >> n;
		if (std::cin.eof() || std::cin.fail())
		{
			whenEof();
			std::cin.ignore(255, '\n');
			std::cout << "Wrong input!" << std::endl;
		}
		else
			break ;
	}
	zombies = zombieHorde(n, name);
	for(int i = 1; i <= n; i++)
	{
		zombies[i - 1].announceInOrder(i);
	}
	delete[] zombies;
}