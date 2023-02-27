#include "push_swap.h"
/*
void lstadd_back(t_list **lst, int data)
{
    t_list *new;
    t_list *temp;

	if (*lst == NULL)
	{
		(*lst)->content = data;
		return ;
	}
    temp = *lst;
    while ((*lst)->next != NULL)
        *lst = (*lst)->next;
	new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return;
    new->prev = *lst;
    new->next = NULL;
    new->content = data;
    (*lst)->next = new;
    *lst = temp;
}
*/
void lstadd_back(t_list **lst, t_list *new_node)
{
    t_list  *tmp;

    if (lst == NULL)
        return ;
    if (*lst == NULL)
    {
        *lst = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else if (*lst != NULL)
    {
        tmp = *lst;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
        new_node->prev = tmp;
        new_node->next = NULL;
    }
}