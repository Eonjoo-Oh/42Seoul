#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str[] = "abcde123abc";
    int c = '1';

    printf("%s\n", strrchr(str, c));
    printf("%s\n", ft_strrchr(str, c));

    return (0);
}