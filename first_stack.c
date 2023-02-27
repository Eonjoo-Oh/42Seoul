#include "push_swap.h"
#include <stdio.h>

t_list *first_stack(char **argv)
{
    int i;
    int j;
    char **splited;
    t_list *first_stack;
    t_list *node;

    i = 1;
    first_stack = NULL;
    while (argv[i] != 0)
    {
        if (is_digit_sp(argv[i]) == -1)
            return (0);
        splited = ft_split(argv[i]);
        j = 0;
        while (splited[j] != 0)
        {
            if (check_range(long_atoi(splited[j])) == -1)
                return (0);
            node=(make_lst((int)long_atoi(splited[j])));
            lstadd_back(&first_stack, node);
            j++;
        }
        i++;
    }
    return (first_stack);
}
