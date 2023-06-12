/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:28:52 by eoh               #+#    #+#             */
/*   Updated: 2023/06/12 12:20:35 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	count_word(char *s, char c)
{
	size_t	cnt;
	size_t	i;
	int		new_i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			new_i = count_quote(s, i);
			i = new_i + 1;
			cnt++;
			continue ;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**free_result(char **s)
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

char	**do_split(char *s, char **result, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
		{
			result[i] = when_quote(&s);
			if (result[i] == 0)
				return (free_result(result));
			i++;
			continue ;
		}
		else if (*s != c)
		{
			result[i] = when_charset(&s, c);
			if (!result)
				return (free_result(result));
			i++;
		}
		else
			s++;
	}
	return (result);
}

char	*when_charset(char	**s, char c)
{
	char	*tmp;
	char	*result;

	tmp = *s;
	while (**s && **s != c)
		*s += 1;
	result = (char *)malloc(sizeof(char) * (*s - tmp + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, tmp, *s - tmp + 1);
	return (result);
}

char	**ft_split(char *s, char c)
{
	char		**result;

	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	result[count_word(s, c)] = NULL;
	if (!result)
		return (0);
	result = do_split(s, result, c);
	if (result == 0)
		return (0);
	return (result);
}
