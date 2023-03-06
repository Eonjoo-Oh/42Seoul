#include <stdio.h>
#include "push_swap.h"

void test_push(t_list *stack_a, t_list *stack_b)
{
    t_node *a_head;
    t_node *b_head;

    printf("------ test pa ------\n");
    pa(stack_a, stack_b);
    a_head = stack_a->head;
    a_head->prev->next = NULL;
    printf("stack_a :\n");
    while (a_head != NULL)
    {
        printf("%d\n", a_head->content);
        a_head = a_head->next;
    }

    b_head = stack_b->head;
    b_head->prev->next = NULL;
    printf("stack_b :\n");
    while (b_head != NULL)
    {
        printf("%d\n", b_head->content);
        b_head = b_head->next;
    }

    printf("------ test pb ------\n");
    pb(stack_a, stack_b);
    a_head = stack_a->head;
    a_head->prev->next = NULL;
    printf("stack_a :\n");
    while (a_head != NULL)
    {
        printf("%d\n", a_head->content);
        a_head = a_head->next;
    }

    b_head = stack_b->head;
    b_head->prev->next = NULL;
    printf("stack_b :\n");
    while (b_head != NULL)
    {
        printf("%d\n", b_head->content);
        b_head = b_head->next;
    }
}

int main(void)
{
    t_list *stack;
    t_list *stack_b;
    t_node *temp;
    t_node *new;
    int i;

    i = 2;
    temp = NULL;

    stack = (t_list *)malloc(sizeof(t_list));
    if (!stack)
        return (0);
    stack_b = (t_list *)malloc(sizeof(t_list));
    if (!stack_b)
        return (0);

    stack->head = make_lst(1);
    stack->head->prev = stack->head;
    stack->head->next = stack->head;
    temp = stack->head;

    while (i < 6)
    {
        new = make_lst(i);
        new->prev = temp;
        new->next = stack->head;
        temp->next = new;
        stack->head->prev = new;
        temp = temp->next;
        i++;
    }
    // make stack_a

    stack_b->head = make_lst(10);
    stack_b->head->prev = stack_b->head;
    stack_b->head->next = stack_b->head;
    temp = stack_b->head;
    i = 11;
    while (i < 16)
    {
        new = make_lst(i);
        new->prev = temp;
        new->next = stack_b->head;
        temp->next = new;
        stack_b->head->prev = new;
        temp = temp->next;
        i++;
    }
    // make_stack_b

    /*
    i = 0;
    temp = stack_b->head;
    while (i < 6)
    {
        printf("%d\n", temp->content);
        temp = temp->next;
        i++;
    }
    */
    // test_make_stack

    test_push(stack, stack_b);
}
