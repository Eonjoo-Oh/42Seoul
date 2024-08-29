#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = '1';
    char b = 'a';
    char c = 'A';
    char d = ' ';

    printf("%d, %d, %d, %d\n", isalnum(a), isalnum(b), isalnum(c), isalnum(d));
    printf("%d, %d, %d, %d\n", ft_isalnum(a), ft_isalnum(b), ft_isalnum(c), ft_isalnum(d));
}
