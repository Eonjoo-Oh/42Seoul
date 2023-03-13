#include "push_swap.h"

void push_to_b(t_list *stack_a, t_list *stack_b, int size)
{
    while (size > 3)
    {
        pb(stack_a, stack_b);
        size--;
    }
    sort_few(stack_a, 3);
}

int find_index(t_list *stack_b, t_node *b_node)
{
    t_node *first;
    int index;

    index = 1;

    first = stack_b->head;

    while (first != b_node)
    {
        index++;
        first = first->next;
    }
    return (index);
}

int count_tries(t_list *stack_a, t_list *stack_b, int size)
{
    t_node *b_node;
    t_node *a_node;
    int index;
    int count;

    b_node = stack_b->head;
    count = 0;

    b_node->prev->next = NULL;
    while (b_node != NULL)
    {
        a_node = stack_a->head;
        index = find_index(stack_b, b_node);
        if (index <= count_node(stack_b) / 2 + 1)
            count += (index - 1);
        else
            count += count_node(stack_b) - index + 1;
        // pb의 가장 위에 올리는것까지 세어주었다. 옆으로 넘기기위한 작업을 해야함
        while (1)
        {
            if (a_node = stack_a->head)
            {
                if (a_node->content > b_node->content)
                {
                    count++;
                    break;
                }
            } // 맨 앞에 들어올 때
            else if (a_node != stack_a->head->prev)
            {
                if ((a_node->content < b_node->content) && a_node->next->content > b_node->content)
                {
                }
            } // 중간에 들어올 때
            else
            {
                count += 2;
                break;
            } // 마지막에 들어올 때
            a_node = a_node->next;
        }
        b_node->tries = count;
        stack_b->head->prev->next = stack_b->head;
        if (count == 1)
            return; // count가 1이면 볼것도 없기때문에 그냥 종료함
        b_node = b_node->next;
    }
}

void sort(t_list *stack_a, t_list *stack_b, int size)
{

    push_b(stack_a, stack_b, size);
    count_tries(stack_a, stack_b, size - 3);
}