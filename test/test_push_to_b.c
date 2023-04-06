#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_node *node;

    if (argc < 2)
        return (0);
    stack_a = first_stack(argv);
    stack_b = make_stack();
    sort(stack_a, stack_b);

    node = stack_b->head;
    node->prev->next = NULL;
    while (node != NULL)
    {
        printf("%d\n", node->content);
        node = node->next;
    }
    return (0);
}