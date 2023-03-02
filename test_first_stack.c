#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    struct s_node *prev;
    struct s_node *next;
    int content;
} t_node;

typedef struct s_list
{
    t_node *head;
} t_list;

t_list *first_stack(char **argv);

int main(int argc, char **argv)
{
    t_list *stack;
    t_node *node;

    if (argc == 1)
        return (0);
    stack = first_stack(argv);
    node = stack->head;
    while (node->next != stack->head)
    {
        printf("%d\n", node->content);
        node = node->next;
    }
    printf("%d\n", node->content);
    //system ("leaks a.out");
    return (0);
}