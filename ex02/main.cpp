#include "Identify.hpp"
//#include <unistd.h>


int main()
{
	Base	*base = generate();
	identify(base);

	//usleep(2000000);
	Base	*base2 = generate();
	identify(base2);

	delete base;
	delete base2;
}