/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:12:35 by eoh               #+#    #+#             */
/*   Updated: 2023/04/07 20:16:54 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

static size_t	cnt_word(char const *s)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '"') && 
		(s[i + 1] == ' ' || s[i + 1] == '"' || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**free_result(char **s)
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

char	**ft_split(char const *s)
{
	size_t		i;
	char		**result;
	char const	*tmp;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (cnt_word(s) + 1));
	if (!result)
		return (0);
	while (*s)
	{
		if (is_white_space(*s) == -1 && *s != '"')
		{
			tmp = s;
			while (*s && *s != '"' && is_white_space(*s) == -1)
				s++;
			result[i] = (char *)malloc(sizeof(char) * (s - tmp + 1));
			if (!result[i])
				return (free_result(result));
			ft_strlcpy(result[i++], tmp, s - tmp + 1);
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}