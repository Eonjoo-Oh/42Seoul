/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:05:12 by eoh               #+#    #+#             */
/*   Updated: 2023/04/08 18:05:14 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *stack_a)
{
	stack_a->head = stack_a->head->prev;
	write (1, "rra\n", 4);
}

void	rrb(t_list *stack_b)
{
	stack_b->head = stack_b->head->prev;
	write (1, "rrb\n", 4);
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	stack_a->head = stack_a->head->prev;
	stack_b->head = stack_b->head->prev;
	write (1, "rrr\n", 4);
}
