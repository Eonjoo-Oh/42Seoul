/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:25 by eoh               #+#    #+#             */
/*   Updated: 2023/04/18 20:49:08 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_bonus(t_list *stack_a)
{
	if (stack_a->head == 0)
		return ;
	stack_a->head = stack_a->head->next;
}

void	rb_bonus(t_list *stack_b)
{
	if (stack_b->head == 0)
		return ;
	if (count_node(stack_b) > 1)
		stack_b->head = stack_b->head->next;
}

void	rr_bonus(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head == 0 || stack_b->head == 0)
		return ;
	stack_a->head = stack_a->head->next;
	stack_b->head = stack_b->head->next;
}
