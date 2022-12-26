#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a = 'a';
    char b = 'A';
    char c = '0';

    printf("%d, %d, %d\n", isalpha(a), isalpha(b), isalpha(c));
    printf("%d, %d, %d\n", ft_isalpha(a), ft_isalpha(b), ft_isalpha(c));

    return (0);
}