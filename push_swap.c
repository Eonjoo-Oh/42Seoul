/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:39:01 by eoh               #+#    #+#             */
/*   Updated: 2023/04/20 20:45:33 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leak_test()
{
	system ("leaks push_swap");
}

void	push_swap(t_list *stack_a, t_list *stack_b)
{
	if (count_node(stack_a) < 4)
	{
		sort_few(stack_a, count_node(stack_a));
		free_all(stack_a, stack_b);
		return ;
	}
	else
	{
		sort(stack_a, stack_b);
		free_all(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (1);
	if (check_char(argv) == -1)
		exit(1);
	stack_a = first_stack(argv);
	if (!stack_a)
		return (1);
	if (count_node(stack_a) < 2)
	{
		free_a(stack_a);
		return (1);
	}
	if (check_error(stack_a) == -1)
		return (1);
	stack_b = make_stack();
	push_swap(stack_a, stack_b);
	return (0);
}
