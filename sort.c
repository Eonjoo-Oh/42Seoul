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
    push_first_pivot(stack_a, stack_b, first_pivot);
    push_second_pivot(stack_a, stack_b, second_pivot);
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
            else if (a_index == a_size && a_node->content < b_node->content)
            {
                b_node->tries += 2;
                break;
            }
            else
            {
                if (a_node->content < b_node->content && a_node->prev->content > b_node->content)
                {
                    if (a_index <= a_size / 2 + 1)
                        b_node->tries += (a_index - 1) * 2 + 1;
                    else
                        b_node->tries += 2 * (a_size - a_index) + 4;
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
        if (min_node->tries > b_node ->tries)
            min_node = b_node;
        b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
    return (min_node);
}

void sort_more(t_list *stack_a, t_list *stack_b, t_node *min_node)
{
    t_node *a_node;
    t_node *b_node;
    t_node *new_min;

    b_node = stack_b->head;
    b_node->prev->next = NULL
    while (b_node != NULL)
    {
        if (new_min == NULL && b_node->content < min_node->content)
        {
            new_min = b_node;
        }
        else if (new_min != NULL && b_node->content < new_min)
        {
            new_min = b_node;
        }
        b_node = b_node->next;
    }
    stack_b->prev->next = stack_b->head;
    if (new_min == NULL)
        return;
    else
        do_sort(stack_a, stack_b, min_node);//재귀로쓸수있는지 잘 확인해보기, 최솟값이 없을때까지 계속 sort하고 싶다
}

void do_sort(t_list *stack_a, t_list *stack_b, t_node *target)
{
    t_node *a_node;
    t_node *min_node;
    
    a_node = stack_a->head;
    min_node = stack_b->head;
    while (min_node->content != target->content)
    {
        min_node = min_node->next;
    }
    if (min_node->tries == 1)
    {
        pa(stack_a, stack_b);
        sort_more(stack_a, stack_b, min_node);
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
    }
}