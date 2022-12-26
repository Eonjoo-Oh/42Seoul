#include <string.h>
#include <stdio.h>

int main(void)
{
    char dest[] = "abcdefg";
    const char src[] = "12345";
    printf("%s\n", (char *)memcpy(dest, src, 3));
    printf("%s\n", (char *)ft_memcpy(dest, src, 3));

    return (0);
}