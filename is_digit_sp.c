#include "push_swap.h"

int is_digit_sp(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || 
        ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)))
            return (-1);
        i++;
    }
    return (1);
}
