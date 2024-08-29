#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "abcd1234abcd";
    const char find[] = "1234";

    printf("%s\n%s\n", strnstr(str, find, 15), strnstr(str, find, 0));
    printf("%s\n%s\n", ft_strnstr(str, find, 15), ft_strnstr(str, find, 15));

    return (0);
}