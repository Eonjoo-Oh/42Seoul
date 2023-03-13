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

    a_node = stack_a->head;
    b_node = stack_b->head;
    count = 0;

    while (b_node != stack_b->head->prev)
    {
        index = find_index(stack_b, b_node);
        if (index <= count_node(stack_b))
            count += (index - 1);
        else

            /*
            while (b_node != stack_b->head)
            {
                if (index < count_node(stack_b))
                    rb(stack_b); //이걸 쓰는 순간 찍히니까 어떻게하는게 좋을까(바로 write를 안하는게 맞나?)
                    //이걸 실제로 쓰지말고 인덱스로 파악해서 count만 올려주는게 좋지않을까 싶다.
                    //했다치고모드->이거 계산하는 법을 찾아봐야할듯
                else
                    rrb(stack_b);
                count++;
            }*/
            // pb의 가장 위에 올리는것까지 세어주었다. 옆으로 넘기기위한 작업을 해야함
            while ()
            {
                if (a_node = stack_a->head)
                {
                    if (a_node->content > b_node)
                }
                else if (a_node = stack_a->head->prev)

                    else
            }
        b_node->tries = count;
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