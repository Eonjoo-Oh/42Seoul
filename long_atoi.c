#include "push_swap.h"

long long long_atoi(char *nptr)
{
    long long i;
    long long sign;
    long long result;

    sign = 1;
    result = 0;
    i = 0;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    if (!(nptr[i] >= '0' && nptr[i] <= '9'))
        return (0);
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = 10 * result + nptr[i] - '0';
        i++;
    }
    return (result * sign);
}
