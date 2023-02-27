#include "push_swap.h"

t_list *make_lst(int data)
{
    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (0);
    new->content = data;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}