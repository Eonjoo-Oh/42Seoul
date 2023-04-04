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

void do_a(t_list *stack_a, t_list *stack_b, t_node *min)
{
    t_node *close;
    int i;
    int size;

    close = find_close(stack_a, min);
    i = find_index(stack_a, close);
    size = count_node(stack_a);
    if (i == size - 1 && close->content < min->content)
    {
        pa(stack_a, stack_b);
        ra(stack_a);
    }
    else
    {
        while (min->tries != 0)
        {
            if (min->tries > 0)
            {
                ra(stack_a);
                (min->tries)--;
            }
            else if (min->tries < 0)
            {
                rra(stack_a);
                (min->tries)++;
            }
        }
        pa(stack_a, stack_b);
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
    while (stack_a->head->content != min->content)
    {
        if (min_idx <= size / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
}

void sort(t_list *stack_a, t_list *stack_b)
{
    t_node	*min_tries;
	t_node	*close;

    push_to_b(stack_a, stack_b);
    sort_few(stack_a, count_node(stack_a));

    while (stack_b->head != NULL)
    {
        count_to_top(stack_b);
        count_to_a(stack_a, stack_b);
        min_tries = find_min_tries(stack_b);
		close = find_close(stack_a, min_tries);
		if (find_index(stack_a, close) == count_node(stack_a) - 1 
		&& close->content < min_tries->content)
		{
			do_top(stack_b, min_tries);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
		{
        	do_both(stack_a, stack_b, min_tries);
			do_top(stack_b, min_tries);
			do_a(stack_a, stack_b, min_tries);
		}
    }
    do_last(stack_a);
}