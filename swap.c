#include "push_swap.h"

void sa(t_list *stack_a)
{
    t_node *first = stack_a->head;
    t_node *second = stack_a->head->next;
    t_node *last = stack_a->head->prev;

    first->next = second->next;
    second->next->prev = first;
    first->prev = second;
    second->next = first;
    second->prev = last;
    last->next = second;

    stack_a->head = second;

    write(1, "sa\n", 3);
}

void sb(t_list *stack_b)
{
    t_node *first = stack_b->head;
    t_node *second = stack_b->head->next;
    t_node *last = stack_b->head->prev;

    first->next = second->next;
    second->next->prev = first;
    first->prev = second;
    second->next = first;
    second->prev = last;
    last->next = second;

    stack_b->head = second;

    write(1, "sa\n", 3);
}

void ss(t_list *stack_a, t_list *stack_b)
{
    sa(stack_a);
    sb(stack_b);

    write (1, "ss\n", 3);
}