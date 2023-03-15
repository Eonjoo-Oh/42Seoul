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

int find_index(t_list *stack, t_node *node)
{
    t_node *first;
    int index;

    index = 1;

    first = stack->head;

    while (first != node)
    {
        index++;
        first = first->next;
    }
    return (index);
}

void count_tries(t_list *stack_a, t_list *stack_b, int size)
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
        // pb의 가장 위에 올리는것까지 세어주었다. 옆으로 넘기기 위한 작업을 해야함
        while (1)
        {
            if (a_node == stack_a->head)
            {
                if (a_node->content > b_node->content)
                {
                    count++;
                    break;
                }
            } // 맨 앞에 들어올 때
            else if (a_node != stack_a->head->prev)
            {
                if ((a_node->content < b_node->content) && (a_node->next->content > b_node->content))
                {
                    index = find_index(stack_a, a_node);
                    if (index < count_node(stack_a) / 2 + 1)
                        count += index * 2 + 1;
                    else
                        count += (count_node(stack_a) - index + 1) * 2 + 1;
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

t_node *find_min_tries(t_list *stack_b)
{
    t_node *b_node;
    t_node *min_node;

    b_node = stack_b->head;
    min_node = b_node;

    b_node->prev->next = NULL;

    while (b_node != NULL)
    {
        if (b_node->tries == 1)
        {
            min_node = b_node;
            break;
        }
        if (min_node->tries > b_node ->tries)
            min_node = b_node;
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
    return (min_node);
}

void put_last(t_list *stack_a, t_list *stack_b, t_node *min_node)
{
    pa(stack_a, stack_b);
    ra(stack_a);
}

void do_sort(t_list *stack_a, t_list *stack_b, t_node *node)
{
    int index;
    t_node *a_node;
    t_node *b_node;
    t_node *temp;
    t_node *min_node;

    a_node = stack_a->head;
    while (b_node->next != b_node)
    {
        if (b_node == node)
            break;
        b_node = b_node->next;
    }
    min_node = b_node;

    if (min_node->tries == 1)
    {
        pb(stack_a, stack_b);
        return ;
    }
    index = find_index(stack_b, min_node);
    if (index <= count_node(stack_b) / 2 + 1)
    {
        while (min_node == stack_b->head)
            rb(stack_b);
    }
    else
    {
        while (min_node == stack_b->head)
            rrb(stack_b);
    }
    //min_node를 stack_b의 가장 위에 올려줌
    while(a_node->next != stack_a->head)
    {
        if (a_node->content > min_node->content)
        {
            pa(stack_a, stack_b);
            return ;
        }
        else if (min_node->content > a_node->content && min_node->content < a_node->next->content)
        {
            temp = stack_a->head;
            index = find_index(stack_a, a_node);
            if (index < count_node(stack_a) / 2 + 1)
            {
                while (a_node->next == stack_a->head)
                    ra(stack_a);
                pa(stack_a, stack_b);
                while (stack_a->head == temp)
                    rra(stack_a);
                return ;
            }
            else
            {
                while (a_node->next == stack_a->head)
                    rra(stack_a);
                pa(stack_a, stack_b);
                while (stack_a->head == temp)
                    ra(stack_a);
                return ;
            }
        }
        a_node = a_node->next;
    }
    put_last(stack_a, stack_b, min_node);
}

void sort(t_list *stack_a, t_list *stack_b, int size)
{
    t_node *min_node;
    
    push_to_b(stack_a, stack_b, size);
    while (stack_b->head != NULL)
    {
        count_tries(stack_a, stack_b, size - 3);
        min_node = find_min_tries(stack_b);
        do_sort(stack_a, stack_b, min_node);
    }
}