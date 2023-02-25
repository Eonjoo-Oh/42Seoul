/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:31:39 by eoh               #+#    #+#             */
/*   Updated: 2023/02/25 17:51:28 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_digit(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!((str[i][j] >= 48 && str[i][j] <= 57) || 
			str[i][j] == '\0'))
				return (-1);
			j++;
		}
		i++;
	}
}

int check_range(char **str)
{
	int i;

	if ()
}

int check_dup(char **str)
{

}
int	check_error(char **str)
{
	if (check_digit(str) == -1)
		return (-1);
	if ()
	
}