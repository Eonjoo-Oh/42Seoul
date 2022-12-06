#include <unistd.h>

int print_hexadecimal(char a)
{
	char    *hexa;

	hexa = "0123456789abcdef";
	write (1, &(hexa[a / 16]), 1);
	write (1, &(hexa[a % 16]), 1);
	return (2);
}

int main(void)
{
    print_hexadecimal('a');
    print_hexadecimal('A');
}