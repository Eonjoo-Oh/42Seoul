#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char s[] = "abcde";
    int a = 'a';
    int e = 'e';

    printf("%s\n%s\n", strchr(s, a), strchr(s, e));
    printf("%s\n%s\n", ft_strchr(s, a), ft_strchr(s, e));

    return (0);
}