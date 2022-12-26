#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str = "abcde";
    int a = 'a';
    int e = 'e';

    printf("%s\n%s\n", (char *)memchr(str, a, 5), (char *)memchr(str, e, 1));
    printf("%s\n%s\n", (char *)ft_memchr(str, a, 5), (char *)ft_memchr(str, e, 1));
    return (0);
}