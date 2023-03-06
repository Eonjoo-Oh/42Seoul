#include "push_swap.h"

void lstadd_back(t_list *lst, t_node *new_node)
{
    t_node  *tmp;

    if (lst->head == NULL)
    {
        lst->head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else if (lst->head != NULL)
    {
        tmp = lst->head;
        while (tmp->next != lst->head)
            tmp = tmp->next;
        tmp->next = new_node;
        new_node->prev = tmp;
        new_node->next = lst->head;
        lst->head->prev = new_node;
    }
}