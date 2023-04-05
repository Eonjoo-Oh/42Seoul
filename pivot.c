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
            result = 1;
            break;
        }
        node = node->next;
    }
    stack_a->head->prev->next = stack_a->head;
    return (result);
}

void push_to_b(t_list *stack_a, t_list *stack_b)
{
    int		*arr;
    int		first_pivot;
    int		second_pivot;
	t_node	*node;

	node = stack_a->head;
    arr = make_arr(stack_a, count_node(stack_a));
    sort_arr(arr, count_node(stack_a));

    first_pivot = arr[count_node(stack_a) / 3];
    second_pivot = arr[count_node(stack_a) / 3 * 2];

    while (count_node(stack_a) > 3 && find_to_push(stack_a, second_pivot) == 1)
    {
		if (node->content <= second_pivot)
		{
			node = node->next;
			pb(stack_a, stack_b);
			if (stack_b->head->content <= first_pivot)
				rb(stack_b);
		}
		else
		{
			ra(stack_a);
			node = node->next;
		}
	}
    while (count_node(stack_a) > 3)
    {
        pb(stack_a, stack_b);
    }
	free(arr);
}