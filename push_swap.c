#include "push_swap.h"
#include <stdio.h>
/*
void push_swap(int argc, char **argv)
{
    t_list *stack_a;
    
    if (argc == 1)
        exit(1);
    stack_a = first_stack(argv);
    if (stack_a == 0)
        exit(1);
}
*/
void push_swap(int argc, char **argv)
{
    t_list *stack_a;
    t_node *node;

    if (argc == 1)
        exit(1);
    stack_a = first_stack(argv);
    if (stack_a == 0)
    {
        write (2, "Error\n", 6);
        exit(1);
    }
    node = stack_a->head;

    if ((check_dup(node) == -1))
    {
        write(2, "Error\n", 6);
        exit(1);
    }

    // test_makestack;
    while (node->next != stack_a->head)
    {
        printf("%d\n", node->content);
        node = node->next;
    }
    printf("%d\n", node->content);
}

int main(int argc, char ** argv)
{
    push_swap(argc, argv);
    //system ("leaks a.out");
    return (0);
}