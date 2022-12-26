#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int a = 'A';
    int b = '1';

    printf("%c\n%c\n", tolower(a), tolower(b));
    printf("%c\n%c\n", ft_tolower(a), ft_tolower(b));
}