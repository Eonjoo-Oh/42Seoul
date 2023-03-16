#include "push_swap.h"

int find_min(t_list *stack_a)
{
    t_node *node;
    int i;
    int min;

    i = 0;
    node = stack_a->head;

    min = node->content;
    node = node->next;
    while (i < 2)
    {
        if (min > node->content)
            min = node->content;
        node = node->next;
        i++;
    }
    return (min);
}

int find_max(t_list *stack_a)
{
    t_node *node;
    int i;
    int max;

    i = 0;
    node = stack_a->head;

    max = node->content;
    node = node->next;
    while (i < 2)
    {
        if (max < node->content)
            max = node->content;
        node = node->next;
        i++;
    }
    return (max);
}

void sort_three(t_list *stack_a)
{
    int min;
    int max;
    t_node *first;
    t_node *second;
    t_node *last;

    min = find_min(stack_a);
    max = find_max(stack_a);
    first = stack_a->head;
    second = first->next;
    last = first->prev;

    if (min == first->content && max == second->content)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (min == second->content && max == first->content)
        ra(stack_a);
    else if (min == second->content && max == last->content)
        sa(stack_a);
    else if (min == last->content && max == first->content)
    {
        ra(stack_a);
        sa(stack_a);
    }
    else if (min == last->content && max == second->content)
        rra(stack_a);
}

void sort_few(t_list *stack_a, int size)
{
    //정렬이 되어있지 않은 경우만 여기 들어올 수 있다.
    if (check_sorted(stack_a) == -1)
        return ;
    if (size == 2)
    {
        sa(stack_a);
        return ;
    }
    else if (size == 3)
    {
        sort_three(stack_a);
        return ;
    }
}