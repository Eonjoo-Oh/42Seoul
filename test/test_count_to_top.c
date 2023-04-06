#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_node *node;
    int size;

    stack_a = first_stack(argv);
    node = stack_a->head;
    size = count_node(stack_a);
    node->prev->next = NULL;
    while (node != NULL)
    {
        count_to_top(stack_a, node, size);
        node = node->next;
    }
    node = stack_a->head;
    while (node != NULL)
    {
        printf("%d\n", node->tries);
        node = node->next;
    }
}