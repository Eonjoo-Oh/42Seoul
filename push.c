#include "push_swap.h"

void pa(t_list *stack_a, t_list *stack_b)
{
    t_node *first_b;
    t_node *last_b;
    t_node *last_a;

    first_b = stack_b->head;
    last_b = first_b->prev;
    last_a = stack_a->head->prev;

    stack_b->head = first_b->next;
    first_b->next = stack_a->head;
    first_b->prev = last_a;
    stack_a->head->prev = first_b;
    last_a->next = first_b;
    stack_a->head = first_b;
    stack_b->head->prev = last_b;
    last_b->next = stack_b->head;
}

void pb(t_list *stack_a, t_list *stack_b)
{
    t_node *first_a;
    t_node *last_a;
    t_node *last_b;

    first_a = stack_a->head;
    last_a = first_a->prev;
    last_b = stack_b->head->prev;

    stack_a->head = first_a->next;
    first_a->next = stack_b->head;
    first_a->prev = last_b;
    stack_b->head->prev = first_a;
    last_b->next = first_a;
    stack_b->head = first_a;
    stack_a->head->prev = last_a;
    last_a->next = stack_a->head;
}