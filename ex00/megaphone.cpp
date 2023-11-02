#include <iostream>
#define DefaultMessage "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

class Megaphone
{
	public:
		char	ConvertToCapital(int c)
		{
			if (c >= 'a' && c <= 'z')
				return c - 32;
			else
				return c;
		}
};

int main(int argc, char **argv)
{
	Megaphone Megaphone;

	if (argc == 1)
		std::cout << DefaultMessage;
	for(int i = 1; i < argc; i++)
	{
		for(int j = 0; argv[i][j] != '\0'; j++)
			std::cout << Megaphone.ConvertToCapital(argv[i][j]);
	}
	std::cout << std::endl;
}