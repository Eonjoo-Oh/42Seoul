#include <string.h>
#include <stdio.h>

int main(void)
{
    char dest[] = "abcdefg";
    const char src[] = "12345";
    printf("%s\n", (char *)memmove(dest, &(dest[2]), 3));
    printf("%s\n", (char *)memmove(&(dest[3]), &(dest[2]), 3));
    printf("%s\n", (char *)memmove(dest, src, 3));
    printf("%s\n", (char *)ft_memmove(dest, &(dest[2]), 3));
    printf("%s\n", (char *)ft_memmove(&(dest[3]), &(dest[2]), 3));
    printf("%s\n", (char *)ft_memmove(dest, src, 3));

    return (0);
}