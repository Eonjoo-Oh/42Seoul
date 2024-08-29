/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:12 by eoh               #+#    #+#             */
/*   Updated: 2023/04/18 20:53:24 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_bonus(t_list *stack_a)
{
	if (stack_a->head == 0)
		return ;
	stack_a->head = stack_a->head->prev;
}

void	rrb_bonus(t_list *stack_b)
{
	if (stack_b->head == 0)
		return ;
	stack_b->head = stack_b->head->prev;
}

void	rrr_bonus(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head == 0 || stack_b->head == 0)
		return ;
	stack_a->head = stack_a->head->prev;
	stack_b->head = stack_b->head->prev;
}
