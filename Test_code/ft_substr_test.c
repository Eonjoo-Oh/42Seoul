#include <stdio.h>

int main(void)
{
    char const *str = "abcdefg";
    char *res;

    res = ft_substr(str, 2, 3);
    printf("%s", res);

    return (0);
}