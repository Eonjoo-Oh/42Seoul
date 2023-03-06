#include "push_swap.h"

void ra(t_list *stack_a)
{
    stack_a->head = stack_a->head->next;
}

void rb(t_list *stack_b)
{
    stack_b->head = stack_b->head->next;
}

void rr(t_list *stack_a, t_list *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}