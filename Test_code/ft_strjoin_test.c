#include <stdio.h>

int main(void)
{
    char const *str1 = "abcd";
    char const *str2 = "efgh";
    char *result;

    result = ft_strjoin(str1, str2);
    printf("%s", result);
}
