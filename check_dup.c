#include "push_swap.h"

int check_dup(t_list *stack)
{
    t_node *first_node;
    t_node *last_node;
    t_node *temp;

    first_node = stack->head;
    last_node = stack->head->prev;

    last_node->next = NULL;
    while (first_node != NULL)
    {
        temp = first_node->next;
        while (temp != NULL)
        {
            if (first_node->content == temp->content)
                return (-1);
            temp = temp->next;
        }
        first_node = first_node->next;
    }
    last_node->next = stack->head;
    return (1);
}