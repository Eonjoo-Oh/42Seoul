#include <string.h>
#include <stdio.h>

int main(void)
{
    const char *str1 = "abcde";
    const char *str2 = "abcde";
    const char *str3 = "avcde";

    printf("%d\n", memcmp(str1, str2, 5));
    printf("%d\n", memcmp(str1, str2, 3));
    printf("%d\n", memcmp(str1, str3, 5));
    printf("%d\n", ft_memcmp(str1, str2, 5));
    printf("%d\n", ft_memcmp(str1, str2, 3));
    printf("%d\n", ft_memcmp(str1, str3, 5));

    return (0);
}