#include <strings.h>
#include <stdio.h>

int main(void)
{
    unsigned char str1[] = "abcde";
    unsigned char str2[] = "abcde";

    bzero(str1, 3);
    ft_bzero(str2, 3);
    printf("%s\n%s\n", str1, str2);

    return (0);
}