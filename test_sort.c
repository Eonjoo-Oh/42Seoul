#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;

    if (argc < 2)
        return (0);
    stack_a = first_stack(argv);
    stack_b = make_stack();
    sort(stack_a, stack_b);
/*
    printf("\n------ contents ------\n");
    t_node *node_a;
    node_a = stack_a->head;
    node_a->prev->next = NULL;
    while (node_a != NULL)
    {
        printf("%d\n", node_a->content);
        node_a = node_a->next;
    }
*/
}