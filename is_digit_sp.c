#include "push_swap.h"

int is_digit_sp(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') ||
              ((str[i] >= 9 && str[i] <= 13) || str[i] == 32) || str[i] == '-'))
            return (-1);
        i++;
    }
    return (1);
}

int is_white_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
            return (1);
        i++;
    }
    return (-1);
}

int is_sign(char *str)
{
    int i;

    while (str[i])
    {
        if (str[i] == '+' || str[i] == '-')
            return (1);
        i++;
    }
    return (-1);
}