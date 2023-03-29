//make_stack, make_lst, first_stack

#include "push_swap.h"

t_list *make_stack(void)
{
    t_list *stack;

    stack = (t_list *)malloc(sizeof(t_list));
    if (!stack)
        return (0);
    return (stack);
}

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

int *make_arr(t_list *stack_a, int size)
{
    int *arr;
    int i;
    t_node *temp;

    arr = (int *)malloc(sizeof(int));
    if (!arr)
        return (NULL);
    i = 0;
    temp = stack_a->head;
    while (i < size)
    {
        arr[i] = temp->content;
        temp = temp->next;
        i++;
    }
    return (arr);
}

int make_dif(node *a_node, node *b_node)
{
    int dif;

    dif = a_node - b_node;
    if (dif < 0)
        dif *= -1;
    return (dif);
}