#include "push_swap.h"

void ra(t_list *stack_a)
{
    stack_a->head = stack_a->head->next;

    write (1, "ra\n", 3);
}

void rb(t_list *stack_b)
{
	if (count_node(stack_b) > 1)
    	stack_b->head = stack_b->head->next;

    write (1, "rb\n", 3);
}

void rr(t_list *stack_a, t_list *stack_b)
{
    stack_a->head = stack_a->head->next;
    stack_b->head = stack_b->head->next;

    write (1, "rr\n", 3);
}