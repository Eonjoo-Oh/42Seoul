/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:54:59 by eoh               #+#    #+#             */
/*   Updated: 2023/02/21 18:11:25 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	tr_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

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
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = 10 * result + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

int line_cnt(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int **free_result(int **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free((s[j]));
		j++;
	}
	free(s);
	return (0);
}

int **ft_atoi(char **s)
{
	int i;
	int n;
	int **result;

	i = 0;
	n = line_cnt(s);
	result = (int **)malloc(sizeof(int *) * n);
	if (!result)
		return (0);
	while (i < n)
	{
		result[i] = (int *)malloc(sizeof(int) * 1);
		if (!result[i])
			return (free_result(result));
		i++;
	}
	i = 0;
	while (s[i])
	{
		n = tr_atoi(s[i]);
		result[i][0] = n;
		i++;
	}
	return (result);
}