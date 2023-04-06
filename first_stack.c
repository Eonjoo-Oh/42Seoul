#include "push_swap.h"

t_list *first_stack(char **argv)
{
    int i;
    int j;
    char **splited;
    t_list *stack;
    t_node *node;

    i = 1;
    stack = (t_list *)malloc(sizeof(t_list));
    if (stack == 0)
        return (0);
    while (argv[i] != 0)
    {
		splited = ft_split(argv[i]);
		j = 0;
        while (splited[j] != 0)
        {
            if (check_range(long_atoi(splited[j])) == -1)
                return (0);
            node = (make_lst((int)long_atoi(splited[j])));
            lstadd_back(stack, node);
            j++;
        }
        i++;
    }
    return (stack);
}
