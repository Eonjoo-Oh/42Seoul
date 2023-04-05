#include "push_swap.h"

int count_node(t_list *stack)
{
    t_node *temp;
    int size;

    temp = stack->head;
    size = 1;

    while ((temp->next != NULL) && (temp->next != stack->head))
    {
        size++;
        temp = temp->next;
    }
    return (size);
}

void count_to_top(t_list *stack_b)
{
    t_node *node;
    int index;
    int size;

    size = (count_node(stack_b));
    index = 0;
    node = stack_b->head;
    node->prev->next = NULL;

    while (node != NULL)
    {
        if (index <= size / 2)
            node->top = index;
        else
            node->top = (size - index) * -1;
        index++;
        node = node->next;
    }
    stack_b->head->prev->next = stack_b->head;
}

void count_to_a(t_list *stack_a, t_list *stack_b)
{
    t_node *close;
    t_node *b_node;
    int i;

    b_node = stack_b->head;
    b_node->prev->next = NULL;
    while (b_node != NULL)
    {
        close = find_close(stack_a, b_node);
        i = find_index(stack_a, close);
        if (close->content < b_node->content)//close 뒤에 들어올 때
        {
            if (i == count_node(stack_a) - 1)
                b_node->tries = 1;
            else if (i < count_node(stack_a) / 2)
                b_node->tries = i + 1;
            else
            {
                b_node->tries = (count_node(stack_a) - i - 1) * -1;
            }
        }
        else //close앞에 들어올 때
        {
            if (i <= count_node(stack_a) / 2)
                b_node->tries = i;
            else
                b_node->tries = (count_node(stack_a) - i) * -1;
        }
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;//만약 줄수줄여야되면 이부분 어딘가로 보내거나합치기
}

