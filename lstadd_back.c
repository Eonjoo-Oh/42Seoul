#include "push_swap.h"

void lstadd_back(t_list **lst, int data)
{
    t_list *new;
    t_list *temp;

    if (*lst == 0)
    {
        (*lst)->content = data;
        return;
    }
    temp = *lst;
    while ((*lst)->next != NULL)
        (*lst) = (*lst)->next;
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return;
    new->prev = *lst;
    new->next = NULL;
    new->content = data;
    (*lst)->next = new;
    *lst = temp;
}