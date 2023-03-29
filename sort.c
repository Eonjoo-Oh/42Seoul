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
// pivot값을 찾기위해 배열에 잠시 넣는 것

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
// pivot보다 작은 값이 없으면 굳이 ra하지않고 break하는 장치

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
    while (count_node(stack_a) > 3)
    {
        pb(stack_a, stack_b);
    }
}
// 여기까지가 피봇나누기 실행코드

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
    if (count_node(stack_a)>= 3)
        push_first_pivot(stack_a, stack_b, first_pivot);
    if (count_node(stack_a)>= 3)
        push_second_pivot(stack_a, stack_b, second_pivot);
    if (count_node(stack_a)>= 3)
        push_last(stack_a, stack_b);
}
// 제일 초기에 피벗나누고 b에 넘기는 역할 pivot나누기의 main

void count_to_top(t_list *stack_b, int size)
{
    int index;
    int count;
    t_node *node;

    index = 0;
    node = stack_b->head;
    node->prev->next = NULL;

    while (node != NULL)
    {
        count = 0;
        if (index < size / 2 + 1)
            count += index;
        else
            count += size - index;
        node->tries = count;        
        index++;
        node = node->next;
    }
    stack_b->head->prev->next = stack_b->head;
}
// stack_b에서 제일 위로 올리는 횟수를 세는 함수

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

void count_to_a(t_list *stack_a, t_list *stack_b, int a_size)
{
    t_node *a_node;
    t_node *b_node;
    int a_index;

    a_index = 0;
    a_node = stack_a->head;
    b_node = stack_b->head;
    b_node->prev->next = NULL;
    
    while (b_node != NULL)
    {
        while (1)
        {
            if (a_index == 0 && a_node->content > b_node->content)
            {
                b_node->tries += 1;
                break;
            }
            else if (a_index == a_size - 1 && a_node->content < b_node->content)
            {
                b_node->tries += 2;
                break;
            }
            else
            {
                if (a_node->content < b_node->content && a_node->next->content > b_node->content)
                {
                    if (a_index < a_size / 2 + 1)
                        b_node->tries += a_index +  2;
                    else
                        b_node->tries += a_size - a_index + 1;
                    break;
                }
            }
            a_index++;
            a_node = a_node->next;
        }
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
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
        if (min_node->tries > b_node->tries)
            min_node = b_node;
        else if (min_node->tries == b_node->tries &&
         min_node->content < b_node->content)
            min_node = b_node;
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
    return (min_node);
}

int sort_more(t_list *stack_a, t_list *stack_b)
{
    t_node *top;
    t_node *bot;
    t_node *b_node;
    t_node *target;

    top = stack_a->head;
    bot = stack_a->head->prev;
    b_node = stack_b->head;
    target = NULL;

    b_node->prev->next = NULL;
    while (b_node != NULL)
    {
        if (b_node->content < top->content && b_node->content > bot->content)
        {
            if (target == NULL)
                target = b_node;
            else if (target != NULL && target->content < b_node->content)
                target = b_node;
        }
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
    if (target == NULL)
        return (-1);
    do_sort(stack_a, stack_b, b_node);
    return (1);
}


void do_top_b(t_list *stack_b, t_node *target)
{
    t_node *min_node;
    int index;
    int size;

    min_node = stack_b->head;
    index = 0;
    size = count_node(stack_b);

    while (min_node->content != target->content)
    {
        min_node = min_node->next;
        index++;
    }

    while (min_node != stack_b->head)
    {
        if (index < size / 2 + 1)
            rb(stack_b);
        else
            rrb(stack_b);
    }
}

void do_sort(t_list *stack_a, t_list *stack_b, t_node *target)
{
    t_node *a_node;
    t_node *min;
    int index;
    int i;
    
    a_node = stack_a->head;
    min = stack_b->head;
    index = 0;
    i = 0;
    
    while (min->content != target->content)
    {
        min = min->next;
    }
    
    do_top_b(stack_b, target);//min를 stack_b가장 위에 올려줌
    
    while (1)
    {
        if (a_node == stack_a->head && a_node->content > min->content)
        {
            pa(stack_a, stack_b);
            break ;
        }
        else if (a_node->next == stack_a->head && a_node->content < min->content)
        {
            pa(stack_a, stack_b);
            ra(stack_a);
            break ;
        }
        else
        {
            if (a_node->content < min->content && a_node->next->content > min->content)
            {
                if (index < count_node(stack_a) / 2 + 1)
                {
                    while (i < index + 1)
                    {
                        ra(stack_a);
                        i++;
                    }
                    pa(stack_a, stack_b);        
                }
                else
                {
                    while (i < count_node(stack_a) - index)
                    {
                        rra(stack_a);
                        i++;
                    }
                    pa(stack_a, stack_b);
                }
                break ;
            }
        }
        index++;
        a_node = a_node->next;
    }
}

void sort(t_list *stack_a, t_list *stack_b)
{    
    int b_size;
    int a_size;
    t_node *min_node;

    push_to_b(stack_a, stack_b);
    sort_few(stack_a, count_node(stack_a));
    while (stack_b->head != NULL)
    {
        a_size = count_node(stack_a);
        b_size = count_node(stack_b);
        count_to_top(stack_b, b_size);
        count_to_a(stack_a, stack_b, a_size);
        min_node = (find_min_tries(stack_b));
        do_sort(stack_a, stack_b, min_node);
        while (sort_more(stack_a, stack_b) != -1)
        {
            sort_more(stack_a, stack_b);
        }
    }
}