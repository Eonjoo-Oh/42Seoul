#include "push_swap.h"

t_node *find_close(t_list *stack_a, t_node *b_node)
{
	t_node	*close;
	t_node	*a_node;
	int		dif;
	int		temp;

    a_node = stack_a->head;
    close = a_node;
	dif = make_dif(a_node, b_node);
    a_node->prev->next = NULL;
    while (a_node != NULL)
    {
        temp = make_dif(a_node, b_node);
        if (temp < dif)
        {
        	close = a_node;
			dif = temp;
        }
		if (temp == 1)
			break ;
        a_node = a_node->next;
    }
    stack_a->head->prev->next = stack_a->head;
    return (close);
}

int get_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

t_node *find_min_tries(t_list *stack_b)
{
    t_node *min_node;
    t_node *b_node;
    int min_tries;
    int temp;

    b_node = stack_b->head;
    min_node = b_node;
    min_tries = get_abs(min_node->top) + get_abs(min_node->tries); // 여기서도 각각 부호를 따져줘야지?
    // 각각의 절댓값으로 구해줘야됨
    b_node->prev->next = NULL;

    while (b_node != NULL)
    {
        temp = get_abs(b_node->top) + get_abs(b_node->tries);
        if (temp < 0)
            temp *= -1;
		if (min_tries < 0)
			min_tries *= -1;
        if (temp < min_tries)
		{
            min_node = b_node;
			min_tries = min_node->top + min_node->tries;
		}
		b_node = b_node->next;
    }
    stack_b->head->prev->next = stack_b->head;
    return (min_node);
}

t_node *find_min_node(t_list *stack)
{
    t_node *node;
    t_node *min;

    min = stack->head;
    node = stack->head;
    
    node->prev->next = NULL;
    while (node != NULL)
    {
        if (min->content > node->content)
            min = node;
        node = node->next;
    }
    stack->head->prev->next = stack->head;
    
    return (min);
}

int find_index(t_list *stack, t_node *node)
{
    t_node *first;
    int index;

    index = 0;

    first = stack->head;

    while (first != node)
    {
        index++;
        first = first->next;
    }
    return (index);
}