/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:33:54 by eoh               #+#    #+#             */
/*   Updated: 2023/04/20 20:25:12 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splited(char **splited, t_list *stack)
{
	if (splited == 0)
	{
		free_result(splited);
		free_stack(stack);
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
			exit(1);
		node = (make_lst((int)long_atoi(splited[j])));
		if (node == 0)
		{
			free_result(splited);
			free_stack(stack);
		}
		lstadd_back(stack, node);
		j++;
	}
	free_result(splited);
}

void	check_only_space(char *s, t_list *stack)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
			cnt++;
		i++;
	}
	if (i == cnt)
	{
		write(2, "Error\n", 6);
		free_a(stack);
		exit(1);
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
		check_only_space(argv[i], stack);
		splited = ft_split(argv[i]);
		free_splited(splited, stack);
		add_stack(splited, stack);
		i++;
	}
	return (stack);
}
