#include <stdio.h>

int check_range(long long n);

int main(void)
{
    long long num1 = -2147483648;
    long long num2 = 214748364789;
    long long num3 = -21474836489;

    printf("%d\n", check_range(num1));
    printf("%d\n", check_range(num2));
    printf("%d\n", check_range(num3));

    return (0);
}