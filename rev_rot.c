#include "push_swap.h"

void rra(t_list *stack_a)
{
    stack_a->head = stack_a->head->prev;
}

void rrb(t_list *stack_b)
{
    stack_b->head = stack_b->head->prev;
}
void rrr(t_list *stack_a, t_list *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}
