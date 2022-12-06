#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int a = 32;
    int b = 0;

    printf("%d, %d\n", isprint(a), isprint(b));
    printf("%d, %d\n", ft_isprint(a), ft_isprint(b));

    return (0);
}