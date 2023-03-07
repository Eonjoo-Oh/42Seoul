#include "push_swap.h"

int check_sorted(t_list *stack)
{
    t_node *temp;

    temp = stack->head;

    if (temp->content > temp->next->content)
        return (1);
    temp = temp->next;
    while (temp->next != stack->head)
    {
       if ((temp->content < temp->prev->content) 
       || (temp->content > temp->next->content))
        return (1);
        temp = temp->next;
    }
    if (temp->content < temp->prev->content)
        return (1);
    return (-1);
}