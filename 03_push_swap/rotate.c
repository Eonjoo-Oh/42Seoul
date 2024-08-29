/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:25 by eoh               #+#    #+#             */
/*   Updated: 2023/04/08 18:06:41 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *stack_a)
{
	stack_a->head = stack_a->head->next;
	write (1, "ra\n", 3);
}

void	rb(t_list *stack_b)
{
	if (count_node(stack_b) > 1)
		stack_b->head = stack_b->head->next;
	write (1, "rb\n", 3);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	stack_a->head = stack_a->head->next;
	stack_b->head = stack_b->head->next;
	write (1, "rr\n", 3);
}
