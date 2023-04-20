/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:39:14 by eoh               #+#    #+#             */
/*   Updated: 2023/04/20 20:39:26 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1.stack_a node 해제하는것
2. stack_b node 해제하는것
3. stack_a 해제
4. stack_b 해제
*/

void	free_a(t_list *stack_a)
{
	t_node	*node;
	t_node	*temp;

	if (!stack_a)
		return ;
	if (!(stack_a->head))
	{
		free(stack_a);
		return ;
	}
	if (stack_a->head->next != stack_a->head)
	{
		node = stack_a->head->next;
		temp = node->next;
		while (node != stack_a->head)
		{
			free(node);
			node = temp;
			temp = temp->next;
		}
	}
	if (!(stack_a->head == NULL))
		free(stack_a->head);
	free(stack_a);
}

void	free_b(t_list *stack_b)
{
	t_node	*node;
	t_node	*temp;

	if (!stack_b)
		return ;
	if (!(stack_b->head))
	{
		free(stack_b);
		return ;
	}
	if (stack_b->head->next != stack_b->head)
	{
		node = stack_b->head->next;
		temp = node->next;
		while (node != stack_b->head)
		{
			free(node);
			node = temp;
			temp = temp->next;
		}
	}
	free(stack_b->head);
	free(stack_b);
}

void	free_all(t_list *stack_a, t_list *stack_b)
{
	free_a(stack_a);
	free_b(stack_b);
}
