#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str1[] = "12345";
    char str2[] = "-12345";
    char str3[] = "0";
    char str4[] = "2147483647";
    char str5[] = "-2147483648";

    printf("atoi :\n");
    printf("%d\n%d\n%d\n%d\n%d\n\n", atoi(str1), atoi(str2), atoi(str3), atoi(str4), atoi(str5));
    printf("ft_atoi :\n");
    printf("%d\n%d\n%d\n%d\n%d\n", ft_atoi(str1), ft_atoi(str2), ft_atoi(str3), ft_atoi(str4), ft_atoi(str5));
}