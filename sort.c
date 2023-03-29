#include "push_swap.h"

void do_both(t_list *stack_a, t_list *stack_b, t_node *min)
{
    if (min->top > 0 && min->tries > 0)
    {
        while (min->top > 0 && min->tries > 0)
        {
            rr(stack_a, stack_b);
            (min->top)--;
            (min->tries)--;
        }
    }
    else if (min->top < 0 && min->tries < 0)
    {
        while (min->top < 0 && min->tries < 0)
        {
            rrr(stack_a, stack_b);
            (min->top)++;
            (min->tries)++;
        }
    }
}

void do_top(t_list *stack_b, t_node *min)
{
    while (min->top != 0)
    {
        if (min->top > 0)
        {
            rb(stack_b);
            (min->top)--;
        }
        else if (min->top < 0)
        {
            rrb(stack_b);
            (min->top)++;
        }
    }
}

void do_a(t_list *stack_a, t_node *min)
{
    while (min->tries != 0)
    {
        if (min->tries > 0)
        {
            ra(stack_a);
            (min->top)--;
        }
        else if (min->top < 0)
        {
            rra(stack_a);
            (min->top)++;
        }
    }
}

void do_last(t_list *stack_a)
{
    t_node *min;
    int min_idx;
    int size;

    size = count_node(stack_a);
    min = find_min_node(stack_a);
    min_idx = find_index(stack_a, min);
    while (min != stack_a->head)
    {
        if (min_idx < size / 2)
            rra(stack_a);
        else
            ra(stack_a);
    }
}

void sort(t_list *stack_a, t_list *stack_b)
{
    t_node *min_node;

    push_to_b(stack_a, stack_b);
    sort_few(stack_a, count_node(stack_a));

    while (stack_b->head != NULL)
    {
        count_to_top(stack_b);
        count_to_a(stack_a, stack_b);
        min_node = find_min_node(stack_b);
        do_both(stack_a, stack_b, min_node);
        do_top(stack_b, min_node);
        do_a(stack_a, min_node);
        pa(stack_a, stack_b);
    }
    do_last(stack_a);
}