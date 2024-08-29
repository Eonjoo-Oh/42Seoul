#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char dst1[] = "abcde";
    char dst2[] = "abcde";
    const char src[] = "12345";

    printf("%lu\n", strlcpy(dst1, src, 3));
    printf("%s\n", dst1);
    printf("%zu\n", ft_strlcpy(dst2, src, 3));
    printf("%s\n", dst2);

    return (0);
}