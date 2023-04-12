/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:36:57 by eoh               #+#    #+#             */
/*   Updated: 2023/04/12 22:41:24 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
	{
		l++;
	}
	while (i + 1 < size && i < l)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (l);
}

long long	long_atoi(char *nptr)
{
	long long	i;
	long long	sign;
	long long	result;

	sign = 1;
	result = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
	{
		return (0);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = 10 * result + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	lstadd_back(t_list *lst, t_node *new_node)
{
	t_node	*tmp;

	if (lst->head == NULL)
	{
		lst->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else if (lst->head != NULL)
	{
		tmp = lst->head;
		while (tmp->next != lst->head)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = lst->head;
		lst->head->prev = new_node;
	}
}

void	free_stack(t_list *stack)
{
	t_node	*node;
	t_node	*temp;
	int		cont;

	if (!stack)
		return ;
	node = stack->head;
	temp = node;
	while (node != NULL)
	{
		node->next = temp;
		cont = node->content;
		free(&cont);
		free(node);
		node = temp;
	}
	free(stack);
}
