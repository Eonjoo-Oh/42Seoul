#include "push_swap.h"

int is_digit_sp(char *str)
{
    int i;

    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') ||
              ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)))
            return (-1);
    }
    return (1);
}