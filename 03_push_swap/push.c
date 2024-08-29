/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:27:43 by eoh               #+#    #+#             */
/*   Updated: 2023/04/08 18:03:55 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_less(t_list *stack_a, t_list *stack_b)
{
	if (stack_b->head == NULL)
		return ;
	if (stack_a->head == NULL)
	{
		stack_a->head = stack_b->head;
		stack_b->head->next->prev = stack_b->head->prev;
		stack_b->head->prev->next = stack_b->head->next;
		stack_b->head = stack_b->head->next;
		stack_a->head->next = stack_a->head;
		stack_a->head->prev = stack_a->head;
	}
}

void	pb_less(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head == NULL)
		return ;
	if (stack_b->head == NULL)
	{
		stack_b->head = stack_a->head;
		stack_a->head->next->prev = stack_a->head->prev;
		stack_a->head->prev->next = stack_a->head->next;
		stack_a->head = stack_a->head->next;
		stack_b->head->next = stack_b->head;
		stack_b->head->prev = stack_b->head;
	}
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_node	*temp;

	if (stack_b->head == NULL || stack_a->head == NULL)
		pa_less(stack_a, stack_b);
	else
	{
		temp = stack_b->head->next;
		if (temp == stack_b->head)
			temp = NULL;
		stack_b->head->next->prev = stack_b->head->prev;
		stack_b->head->prev->next = temp;
		stack_b->head->next = stack_a->head;
		stack_b->head->prev = stack_a->head->prev;
		stack_a->head->prev->next = stack_b->head;
		stack_a->head->prev = stack_b->head;
		stack_a->head = stack_b->head;
		stack_b->head = temp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_node	*temp;

	if (stack_a->head == NULL || stack_b->head == NULL)
		pb_less(stack_a, stack_b);
	else
	{
		temp = stack_a->head->next;
		if (temp == stack_a->head)
			temp = NULL;
		stack_a->head->next->prev = stack_a->head->prev;
		stack_a->head->prev->next = temp;
		stack_a->head->next = stack_b->head;
		stack_a->head->prev = stack_b->head->prev;
		stack_b->head->prev->next = stack_a->head;
		stack_b->head->prev = stack_a->head;
		stack_b->head = stack_a->head;
		stack_a->head = temp;
	}
	write(1, "pb\n", 3);
}
