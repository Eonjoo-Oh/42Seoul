#include "push_swap.h"

int *make_arr(t_list *stack_a, int size)
{
    int *arr;
    int i;
    t_node *temp;

    arr = (int *)malloc(sizeof(int));
    if (!arr)
        return (NULL);
    i = 0;
    temp = stack_a->head;
    while (i < size)
    {
        arr[i] = temp->content;
        temp = temp->next;
        i++;
    }
    return (arr);
}

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
            result = 1;
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

    size = count_node(stack_a);
    while (size >= 0)
    {
        node = stack_a->head;
        if (find_to_push(stack_a, first_pivot) == -1)
            return ;
        if (node->content < first_pivot)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        size--;
    }
}

void push_second_pivot(t_list *stack_a, t_list *stack_b, int second_pivot)
{
    t_node *node;
    int size;

    size = count_node(stack_a);
    while (size >= 0)
    {
        node = stack_a->head;
        if (find_to_push(stack_a, second_pivot) == -1)
            return ;
        if (node->content < second_pivot)
            pb(stack_a, stack_b);
        else
            ra(stack_a);
        size--;
    }
}

void push_last(t_list *stack_a, t_list *stack_b)
{
    while (stack_a->head != NULL)
    {
        pb(stack_a, stack_b);
    }
}

void push_to_b(t_list *stack_a, t_list *stack_b)
{
    int *arr;
    int first_pivot;
    int second_pivot;
    int size;

    size = count_node(stack_a);
    //if (size < 조건이 있어야할것같다?)

    arr = make_arr(stack_a, size);
    sort_arr(arr, size);//arr을 만들고 정렬까지함

    first_pivot = arr[size / 3];
    second_pivot = arr[size / 3 * 2];//피벗설정
    free(arr);
    push_first_pivot(stack_a, stack_b, first_pivot);
    push_second_pivot(stack_a, stack_b, second_pivot);
    push_last(stack_a, stack_b);
}

void sort(t_list *stack_a, t_list *stack_b)
{    
    push_to_b(stack_a, stack_b);
    while (stack_b != NULL)
    {
        count_tries(stack_a, stack_b);
        do_sort(stack_a, stakc_b);
    }
}