#include "push_swap.h"

void ra(t_list *stack_a)
{
    stack_a->head = stack_a->head->next;

    write (1, "ra\n", 3);
}

void rb(t_list *stack_b)
{
    stack_b->head = stack_b->head->next;

    write (1, "rb\n", 3);
}

void rr(t_list *stack_a, t_list *stack_b)
{
    ra(stack_a);
    rb(stack_b);

    write (1, "rr\n", 3);
}