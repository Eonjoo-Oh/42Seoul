#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    int *arr;
    int size;
    t_list *stack;

    stack = first_stack(argv);
    size = count_node(stack);
    arr = make_arr(stack, size);

    if (argc == 1)
        return (0);
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }

    return (0);
}