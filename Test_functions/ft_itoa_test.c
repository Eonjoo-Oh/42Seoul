#include <stdio.h>

int main(void)
{
    int a = 123;
    int b = -123;
    int c = 0;
    int d = 2147483647;
    int e = -2147483648;

    printf("%s", ft_itoa(a));
    printf("%s", ft_itoa(b));
    printf("%s", ft_itoa(c));
    printf("%s", ft_itoa(d));
    printf("%s", ft_itoa(e));

    return (0);
}