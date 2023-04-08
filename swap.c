/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:21:24 by eoh               #+#    #+#             */
/*   Updated: 2023/04/08 18:25:15 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_list *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (count_node(stack_a) <= 1)
		return ;
	else if (count_node(stack_a) == 2)
		stack_a->head = stack_a->head->next;
	else
	{
		first = stack_a->head;
		second = stack_a->head->next;
		last = stack_a->head->prev;
		first->next = second->next;
		second->next->prev = first;
		first->prev = second;
		second->next = first;
		second->prev = last;
		last->next = second;
		stack_a->head = second;
	}
}

void	do_sb(t_list *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (count_node(stack_b) <= 1)
		return ;
	else if (count_node(stack_b) == 2)
		stack_b->head = stack_b->head->next;
	else
	{
		first = stack_b->head;
		second = stack_b->head->next;
		last = stack_b->head->prev;
		first->next = second->next;
		second->next->prev = first;
		first->prev = second;
		second->next = first;
		second->prev = last;
		last->next = second;
		stack_b->head = second;
	}
}

void	sa(t_list *stack_a)
{
	do_sa(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b)
{
	do_sb(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	do_sa(stack_a);
	do_sb(stack_b);
	write (1, "ss\n", 3);
}
