#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char dst1[10] = "abcdefghij";
    char dst2[10] = "abcdefghij";
    const char src1[5] = "12345";

    printf("%lu\n", strlcat(dst1, src1, 3));
    printf("%s\n", dst1);
    printf("%lu\n%lu\n", ft_strlcat(dst2, src1, 15), ft_strlcat(dst2, src1, 3));
    printf("%s\n", dst2);
    return (0);
}
