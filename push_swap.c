/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:39:01 by eoh               #+#    #+#             */
/*   Updated: 2023/04/12 18:55:51 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
void	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return ;
	if (check_char(argv) == -1)
		exit(1);
	stack_a = first_stack(argv);
	if (!stack_a)
		return ;
	if (count_node(stack_a) < 2)
		return ;
	if (check_error(stack_a) == -1)
		return ;
	if (count_node(stack_a) < 4)
	{
		sort_few(stack_a, count_node(stack_a));
		return ;
	}
	else
	{
		stack_b = make_stack();
		sort(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
*/

void	free_stack2(t_list *stack)
{
	t_node *node;
	t_node *temp;

	node = stack->head;
	temp = node;
	node->prev->next = NULL;

	while (node != NULL)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	free(stack);
}

int main(int argc, char ** argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return 1;
	if (check_char(argv) == -1)
		exit(1);
	stack_a = first_stack(argv);
	stack_b = make_stack();
	if (!stack_a)
		return 1;
	if (count_node(stack_a) < 2)
		return 1;
	if (check_error(stack_a) == -1)
		return 1;
	if (count_node(stack_a) < 4)
	{
		sort_few(stack_a, count_node(stack_a));
		system ("leaks push_swap");
		return 1;
	}
	else
	{
		sort(stack_a, stack_b);
	}
	system ("leaks push_swap");
	return (0);
}