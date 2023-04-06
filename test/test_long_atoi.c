#include <stdio.h>

long long long_atoi(char *nptr);

int main(void)
{
    char *num1 = "21474836479";
    char *num2 = "-14748364890";
    char *num3 = "12";

    long long res1 = long_atoi(num1);
    printf("%lld\n", res1);
    long long res2 = long_atoi(num2);
    printf("%lld\n", res2);
    long long res3 = long_atoi(num3);
    printf("%lld\n", res3);
}