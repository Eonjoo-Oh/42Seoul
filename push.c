#include "push_swap.c"

void pa(t_list *stack_a, t_list *stack_b)
{
    t_node *a;
    t_node *b;
    t_node *first_b;
    t_node *last_a;

    a = stack_a->head;
    b = stack_b->head->next;
    first_b = stack_b->head;
    last_a = a->prev;
    stack_b->head = b;
    first_b->next = a;
    first_b->prev = last_a;
    a->prev = first_b;
    last_a->prev = first_b;
    stack_a->head = first_b;
}

void pb(t_list *stack_a, t_list *stack_b)
{
    t_node *a;
    t_node *b;
    t_node *first_a;
    t_node *last_b;

    a = stack_a->head->next;
    b = stack_b->head;
    first_a = stack_a->head;
    last_b = b->prev;
    stack_a->head = a;
    first_a->next = b;
    first_a->prev = last_b;
    b->prev = first_a;
    last_b->prev = first_a;
    stack_b->head = first_a;
}