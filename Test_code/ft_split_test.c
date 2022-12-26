#include <stdio.h>

int main(void)
{
    char *str1 = "a,bc,d,e";
    char *str2 = "     ";
    char set1 = ',';
    char set2 = ' ';
    char **result1 = split(str1, set1);
    char **result2 = split(str2, set2);

    for (int i = 0; i < 5; i++)
    {
        printf("%s", result1[i]);
    }
    for (int i = 0; i < 1; i++)
    {
        printf("%s", result2[i]);
    }
}
