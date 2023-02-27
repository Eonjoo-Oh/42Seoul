#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s);

int main(void)
{
    int i;
    char **result;
    char *str1 = "123 45 6";
    char *str2 = "1234";
    char *str3 = "1245  6 ";

    result = ft_split(str1);
    i = 0;
    while(result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    result = ft_split(str2);
    i = 0;
    while(result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    result = ft_split(str3);
    i = 0;
    while(result[i])
    {
        printf("%s\n", result[i]);
        i++;
    }
    return (0);
}