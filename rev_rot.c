#include "push_swap.h"

void rra(t_list *stack_a)
{
    stack_a->head = stack_a->head->prev;

    write (1, "rra\n", 4);
}

void rrb(t_list *stack_b)
{
    stack_b->head = stack_b->head->prev;

    write (1, "rrb\n", 4);
}
void rrr(t_list *stack_a, t_list *stack_b)
{
    rra(stack_a);
    rrb(stack_b);

    write (1, "rrr\n", 4);
}
