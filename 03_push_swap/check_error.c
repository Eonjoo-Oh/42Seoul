/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:35:14 by eoh               #+#    #+#             */
/*   Updated: 2023/04/20 20:21:34 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_range(long long n)
{
	if (n > 2147483647 || n < -2147483648)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}

int	check_dup(t_list *stack)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*temp;

	first_node = stack->head;
	last_node = stack->head->prev;
	last_node->next = NULL;
	while (first_node != NULL)
	{
		temp = first_node->next;
		while (temp != NULL)
		{
			if (first_node->content == temp->content)
				return (-1);
			temp = temp->next;
		}
		first_node = first_node->next;
	}
	last_node->next = stack->head;
	return (1);
}

int	check_sorted(t_list *stack)
{
	t_node	*temp;

	temp = stack->head;
	if (temp->content > temp->next->content)
		return (1);
	temp = temp->next;
	while (temp->next != stack->head)
	{
		if ((temp->content < temp->prev->content)
			|| (temp->content > temp->next->content))
			return (1);
		temp = temp->next;
	}
	if (temp->content < temp->prev->content)
		return (1);
	return (-1);
}

int	check_char(char **argv)
{
	if (is_digit_sp(argv) == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}

int	check_error(t_list *stack)
{
	if (check_dup(stack) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (check_sorted(stack) == -1)
	{
		free_a(stack);
		return (-1);
	}
	return (1);
}
