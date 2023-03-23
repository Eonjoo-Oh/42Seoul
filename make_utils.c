//make_stack, make_lst, first_stack

#include "push_swap.h"

t_list *make_stack(void)
{
    t_list *stack;

    stack = (t_list *)malloc(sizeof(t_list));
    if (!stack)
        return (0);
    return (stack);
}

t_node *make_lst(int data)
{
    t_node *new;
    new = (t_node *)malloc(sizeof(t_node));
    if (!new)
        return (0);
    new->content = data;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}

