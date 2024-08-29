#include <stdlib.h>

int main(void)
{
    char *str1 = calloc(sizeof(char), 5);
    char *str2 = ft_calloc(sizeof(char), 5);
    printf("%s\n%s", str1, str2);

    return (0);
}