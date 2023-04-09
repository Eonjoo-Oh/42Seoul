/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:33:54 by eoh               #+#    #+#             */
/*   Updated: 2023/04/09 20:25:43 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splited(char **splited, t_list *stack)
{
	if (splited == 0)
	{
		free(stack);
		exit(1);
	}
}

void	add_stack(char **splited, t_list *stack)
{
	int		j;
	t_node	*node;

	j = 0;
	while (splited[j] != 0)
	{
		if (check_splited(splited[j]) == -1
			|| check_range(long_atoi(splited[j])) == -1)
		{
			free_result(splited);
			free(stack);
			exit(1);
		}
		node = (make_lst((int)long_atoi(splited[j])));
		lstadd_back(stack, node);
		j++;
	}
}

t_list	*first_stack(char **argv)
{
	int		i;
	char	**splited;
	t_list	*stack;

	i = 1;
	stack = (t_list *)malloc(sizeof(t_list));
	if (stack == 0)
		return (0);
	while (argv[i] != 0)
	{
		check_only_null(argv[i], stack);
		splited = ft_split(argv[i]);
		free_splited(splited, stack);
		add_stack(splited, stack);
		i++;
	}
	return (stack);
}
