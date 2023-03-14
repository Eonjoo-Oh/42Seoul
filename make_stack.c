#include "push_swap.h"

t_list *make_stack(void)
{
    t_list *stack;

    stack = (t_list *)malloc(sizeof(t_list));
    if (!stack)
        return (0);
    return (stack);
}