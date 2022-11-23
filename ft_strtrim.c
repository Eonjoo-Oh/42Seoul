/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:13 by eoh               #+#    #+#             */
/*   Updated: 2022/11/23 09:42:19 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	find_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	while (s1[i])
	{
		start = i;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (start == i)
			break ;
	}
	return (start);
}

int	find_end(const char *s1, char const *set, int start)
{
	int	len;
	int	end;
	int	j;

	len = (int)ft_strlen(s1);
	while (len > start)
	{
		end = len - 1;
		j = 0;
		while (set[j])
		{
			if (s1[len - 1] == set[j])
			{
				len--;
				break ;
			}
			j++;
		}
		if (end == len - 1)
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;
	int		size;

	start = find_start(s1, set);
	end = find_end(s1, set, start);
	size = end - start;
	if ((start == ((int)(ft_strlen(s1)) - 1)) || size == 0)
		return (ft_strdup(""));
	if (end - start < 0)
		size = -1;
	result = (char *)malloc(sizeof(char) * (size + 2));
	if (!result)
		return (0);
	i = 0;
	while (start + i <= end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
