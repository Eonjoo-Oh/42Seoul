#include "push_swap.h"

void lstadd_back(s_list *lst, int data)
{
    t_list *new;
    t_list *tmp;

    if (!lst)
        return ;
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return ;
    new->content = data;
	if (lst->head == NULL)
	{
        lst->head = new;
        new->prev = new;
        new->next = new;
		return ;
	}
    else
    {
        tmp = lst->head->prev;
        tmp->next = new;
        new->prev = tmp;
        new->next = lst->head;
        lst->head->prev = new;
    }
}

/*
void lstadd_back(s_list **lst, t_list *new_node)
{
    t_list  *tmp;

    if (lst == NULL)
        return ;
    if (*lst == NULL)
    {
        (*lst)->head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else if (*lst != NULL)
    {
        tmp = (*lst)->head;
        while (tmp->next != (*lst)->head)
            tmp = tmp->next;
        tmp->next = new_node;
        new_node->prev = tmp;
        new_node->next = (*lst)->head;
        (*lst)->head->prev = new_node;
    }
}
*/