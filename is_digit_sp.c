#include "push_swap.h"

int is_digit_sp(char **str)
{
    int i;
    int j;

    i = 1;

    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            if (!((str[i][j] >= '0' && str[i][j] <= '9') ||
              ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32) 
              || str[i][j] == '+' || str[i][j] == '-'))
                return (-1);
            j++;
        }
        i++;
    }
    return (1);
}//숫자, whitespace, 부호가 아닐시 error

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
}//split에서 사용

int is_sign(char *str)
{
    int i;

	i = 0;
    while (str[i])
    {
        if (str[i] == '+' || str[i] == '-')
            return (1);
        i++;
    }
    return (-1);
}