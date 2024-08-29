/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:11:26 by eoh               #+#    #+#             */
/*   Updated: 2023/04/09 20:12:36 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_else(t_list *stack_a, t_list *stack_b, t_node *min)
{
	do_both(stack_a, stack_b, min);
	do_top(stack_b, min);
	do_a(stack_a, stack_b, min);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	t_node	*min_tries;
	t_node	*close;

	push_to_b(stack_a, stack_b);
	sort_few(stack_a, count_node(stack_a));
	while (stack_b->head != NULL)
	{
		count_to_top(stack_b);
		count_to_a(stack_a, stack_b);
		stack_b->head->prev->next = stack_b->head;
		min_tries = find_min_tries(stack_b);
		close = find_close(stack_a, min_tries);
		if (find_index(stack_a, close) == count_node(stack_a) - 1
			&& close->content < min_tries->content)
		{
			do_top(stack_b, min_tries);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
			sort_else(stack_a, stack_b, min_tries);
	}
	do_last(stack_a);
}
