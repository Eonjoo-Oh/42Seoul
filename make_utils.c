/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:46:50 by eoh               #+#    #+#             */
/*   Updated: 2023/04/08 17:48:01 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*make_stack(void)
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		return (0);
	return (stack);
}

t_node	*make_lst(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->content = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int	*make_arr(t_list *stack_a, int size)
{
	int		*arr;
	int		i;
	t_node	*temp;

	arr = (int *)malloc(sizeof(int) * size);
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

int	make_dif(t_node *a_node, t_node *b_node)
{
	int	dif;

	dif = a_node->content - b_node->content;
	if (dif < 0)
		dif *= -1;
	return (dif);
}
