#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int a = 'a';
    int b = '1';

    printf("%c\n%c\n", toupper(a), toupper(b));
    printf("%c\n%c\n", ft_toupper(a), ft_toupper(b));
}