#include <stdio.h>
#include <string.h>

int main(void)
{
    const char s[] = "abcde";
    printf("%lu\n", strlen(s));
    printf("%lu\n", ft_strlen(s));

    return (0);
}