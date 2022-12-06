#include <stdio.h>
#include <string.h>

int main(void)
{
    const char src[] = "abcde";
    char *result1;
    char *result2;

    result1 = strdup(src);
    result2 = ft_strdup(src);

    printf("%s\n%s", result1, result2);

    return (0);
}