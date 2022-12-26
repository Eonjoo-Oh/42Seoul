#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char a = '0';
    char b = 'A';
    char c = 'a';

    printf("%d, %d, %d\n", isdigit(a), isdigit(b), isdigit(c));
    printf("%d, %d, %d\n", ft_isdigit(a), ft_isdigit(b), ft_isdigit(c));

    return (0);
}