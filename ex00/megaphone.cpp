#include <iostream>
#define DefaultMessage "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

class Megaphone
{
	public:
		char	capitalConverter(int c);
};

char	Megaphone::capitalConverter(int c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;
	else
		return c;
}

int main(int argc, char **argv)
{
	Megaphone megaphone;

	if (argc == 1)
		std::cout << DefaultMessage;
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j] != '\0'; j++)
				std::cout << megaphone.capitalConverter(argv[i][j]);
		}
	}
	std::cout << std::endl;
}