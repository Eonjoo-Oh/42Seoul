#include "push_swap.h"

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