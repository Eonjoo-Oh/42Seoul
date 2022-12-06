#include <stdio.h>
#include <string.h>

int main(void)
{
    const char s1[] = "abcde";
    const char s2[] = "abcde";
    const char s3[] = "abzde";

    printf("%d\n%d\n", strncmp(s1, s2, 5), strncmp(s1, s3, 4));
    printf("%d\n%d\n", ft_strncmp(s1, s2, 5), ft_strncmp(s1, s3, 4));

    return (0);
}