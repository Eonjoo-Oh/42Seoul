#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    t_node *node_a;

    node_a = stack_a->head;

    stack_a = first_stack(argv);
    stack_b = make_stack();
    sort(stack_a, stack_b, count_node(stack_a));

    printf("\n------ contents ------\n");
    while (node_a->next != stack_a->head)
    {
        printf("%d\n", node_a->content);
        node_a = node_a->next;
    }
    printf("%d\n", node_a->content);
}