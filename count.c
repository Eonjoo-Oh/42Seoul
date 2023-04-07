/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:11:53 by eoh               #+#    #+#             */
/*   Updated: 2023/04/07 21:26:52 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_node(t_list *stack)
{
	t_node	*temp;
	int		size;

	temp = stack->head;
	size = 1;
	while ((temp->next != NULL) && (temp->next != stack->head))
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	count_to_top(t_list *stack_b)
{
	t_node	*node;
	int		index;
	int		size;

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

void	do_count_to_a(int i, t_list *stack_a, t_list *stack_b, t_node *node)
{
	t_node	*b_node;

	b_node = stack_b->head;
	while (b_node != node)
	{
		b_node = b_node->next;
	}
	if (i == count_node(stack_a) - 1)
		b_node->tries = 1;
	else if (i < count_node(stack_a) / 2)
		b_node->tries = i + 1;
	else
		b_node->tries = (count_node(stack_a) - i - 1) * -1;
}

void	count_to_a(t_list *stack_a, t_list *stack_b)
{
	t_node	*close;
	t_node	*b_node;
	int		i;

	b_node = stack_b->head;
	b_node->prev->next = NULL;
	while (b_node != NULL)
	{
		close = find_close(stack_a, b_node);
		i = find_index(stack_a, close);
		if (close->content < b_node->content)
			do_count_to_a(i, stack_a, stack_b, b_node);
		else
		{
			if (i <= count_node(stack_a) / 2)
				b_node->tries = i;
			else
				b_node->tries = (count_node(stack_a) - i) * -1;
		}
		b_node = b_node->next;
	}
}
