#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		std::cout << "test main address: " << &club << std::endl;
		//std::cout << "test: " << club.getType() << std::endl;
		//std::cout << "test: " << jim.weapon->getType() << std::endl;
		jim.attack();
	}
	return 0;
}

