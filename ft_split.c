/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:24 by eoh               #+#    #+#             */
/*   Updated: 2022/11/25 17:34:13 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset(char c, char charset)
{
	int	i;

	i = 0;
	if (c == charset)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

int	word_cnt(char const *str, char charset)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset) == 0
			&& is_charset(str[i + 1], charset) == 1)
			word++;
		i++;
	}
	return (word);
}

void	write_word(char *result, char const *from, char charset)
{
	int	i;

	i = 0;
	while (is_charset(from[i], charset) == 0)
	{
		result[i] = from[i];
		i++;
	}
	result[i] = '\0';
}

void	split_word(char **result, char const *str, char charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_charset(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_charset(str[i + j], charset) == 0)
				j++;
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (result[word] == 0)
				return ;
			write_word(result[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (s == 0)
		return (0);
	words = word_cnt(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == 0)
		return (0);
	res[words] = 0;
	split_word(res, s, c);
	return (res);
}
