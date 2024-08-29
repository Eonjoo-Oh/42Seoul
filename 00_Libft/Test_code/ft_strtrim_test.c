#include <stdio.h>

int main(void)
{
    char const *s1 = "abc12345bca";
    char const *s2 = "abc123ab12abc";
    char const *set = "abc";
    char *result1;
    char *result2;

    result1 = ft_strtrim(s1, set);
    result2 = ft_strtrim(s2, set);
    printf("%s\n%s\n", result1, result2);
}