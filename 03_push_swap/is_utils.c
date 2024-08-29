/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:39:52 by eoh               #+#    #+#             */
/*   Updated: 2023/04/12 22:41:24 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit_sp(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!((str[i][j] >= '0' && str[i][j] <= '9') ||
				((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
				|| str[i][j] == '+' || str[i][j] == '-'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_white_space(char str)
{
	if ((str >= 9 && str <= 13) || str == 32)
		return (1);
	return (-1);
}

int	is_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}
