#include "push_swap.h"

int count_node(t_list *stack)
{
    t_node *temp;
    int size;

    temp = stack->head;
    size = 1;

    while ((temp != NULL) && (temp->next != stack->head))
    {
        size++;
        temp = temp->next;
    }
    return (size);
}