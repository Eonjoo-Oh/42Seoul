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
// 여기까지가 피봇나누기

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
// do_sort의 역할

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

void count_to_a(t_list *stack_a, t_list *stack_b)
{
    t_node *a_node;
    t_node *b_node;
    int index;

    a_node = stack_a->head;
    b_node = stack_b->head;
    while (1)
    {
        if (b_node->content == target->content)
            break;
        b_node = b_node->next;
    }

    while (b_node != NULL)
    {
        while (1)
        {
            if (a_node == stack_a->head && b_node->content < a_node->content)
            {
                b_node->tries = 1;
                return ;
            }//맨 앞에 들어올 때
            else if (a_node == stack_a->head->prev && a_node->content < b_node->content)
            {
                b_node->tries = 2;
                break;
            }
            else
            {
                if ((a_node->content > b_node->content) && (a_node->prev->content < b_node->content))
                {
                    index = find_index(stack_a, a_node);
                    if (index <= count_node(stack_a) / 2 + 1)
                        b_node->tries += (index - 1) * 2 + 1;
                    else
                        b_node->tries += 2 * (count_node(stack_a) - index) + 4;
                    break;
                }
            }
            a_node = a_node->next;
        }
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

void sort(t_list *stack_a, t_list *stack_b)
{    
    int b_size;
    t_node *min_node;

    push_to_b(stack_a, stack_b);
    while (stack_b->head != NULL)
    {
        b_size = count_node(stack_b);
        count_to_top(stack_b, b_size);
        count_to_a(stack_a, stack_b);
        min_node = (find_min_tries(stack_b));
        push_to_b(stack_a, stack_b);
    }
}