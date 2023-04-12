/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:12 by eoh               #+#    #+#             */
/*   Updated: 2023/04/12 20:59:23 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_bonus(t_list *stack_a)
{
	stack_a->head = stack_a->head->prev;
}

void	rrb_bonus(t_list *stack_b)
{
	stack_b->head = stack_b->head->prev;
}

void	rrr_bonus(t_list *stack_a, t_list *stack_b)
{
	stack_a->head = stack_a->head->prev;
	stack_b->head = stack_b->head->prev;
}
