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

t_list **first_stack(char **argv);

int main(int argc, char **argv)
{
    t_list **stack;
    t_node *test;
    
    test = NULL;
    if (argc == 1)
        exit(1);
    stack = first_stack(argv);
    (*stack)->head = test;
    while (test->next != (*stack)->head)
    {
        printf("%d\n", test->content);
        test = test->next;
    }
    printf("%d\n", test->content);
    //system("leaks a.out");
    return (0);
}