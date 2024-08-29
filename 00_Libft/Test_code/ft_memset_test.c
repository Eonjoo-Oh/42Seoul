#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "abcdefg";
    printf("%s\n", (char *)memset(str, 'a', 3));
    printf("%s\n", (char *)ft_memset(str, 'a', 3));

    return (0);
}