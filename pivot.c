#include "push_swap.h"

void sort_arr(int *arr, int size)
{
    int i;
    int temp;

    while (size > 1)
    {
        i = 0;
        while (i + 1 < size)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            i++;
        }
        size--;
    }
}

int find_to_push(t_list *stack_a, int pivot)
{
    t_node *node;
    int result;

    result = -1;
    node = stack_a->head;
    node->prev->next = NULL;
    while (node != NULL)
    {
        if (node->content < pivot)
        {
            result = find_index(stack_a, node);
            break;
        }
        node = node->next;
    }
    stack_a->head->prev->next = stack_a->head;
    return (result);
}

void push_first_pivot(t_list *stack_a, t_list *stack_b, int first_pivot)
{
    t_node *node;
    int size;
    int i;
    int j;
    size = count_node(stack_a);
    while (size > 3)
    {
        node = stack_a->head;
        i = find_to_push(stack_a, first_pivot);
        if (i == -1)
            break ;
        else if (i > size / 2)
            j = size - i;
        else
            j = i;
        while (j > 0)
        {
            if (i <= size / 2)
                ra(stack_a);
            else
                rra(stack_a);
            j--;
        }
        pb(stack_a, stack_b);
        size--;
    }
}

void push_second_pivot(t_list *stack_a, t_list *stack_b, int second_pivot)
{
    t_node  *node;
    int     size;
    int     i;
    int     j;

    size = count_node(stack_a);
    while (size > 3)
    {
        node = stack_a->head;
        i = find_to_push(stack_a, second_pivot);
        if (i == -1)
            break ;
        if (i > size / 2)
            j = size - i;
        else
            j = i;
        while (j > 0)
        {
            if (i <= size / 2)
                ra(stack_a);
            else
                rra(stack_a);
            j--;
        }
        pb(stack_a, stack_b);
        size--;
    }
}

void push_to_b(t_list *stack_a, t_list *stack_b)
{
    int *arr;
    int first_pivot;
    int second_pivot;
    int size;

    size = count_node(stack_a);

    arr = make_arr(stack_a, size);
    sort_arr(arr, size);

    first_pivot = arr[size / 3];
    second_pivot = arr[size / 3 * 2];
    free(arr);
    push_first_pivot(stack_a, stack_b, first_pivot);
    push_second_pivot(stack_a, stack_b, second_pivot);
    while (count_node(stack_a) > 3)
    {
        pb(stack_a, stack_b);
    }
}