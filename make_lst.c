#include "push_swap.h"

t_list *make_lst(void)
{
    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (0);
    new->prev = NULL;
    new->next = NULL;
    new->content = NULL;
    return (new);
}