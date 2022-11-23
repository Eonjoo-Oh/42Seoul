/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:24 by eoh               #+#    #+#             */
/*   Updated: 2022/11/23 18:43:22 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_c(char const *s, char c)
{	
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

char	*each_word(char const *s, int start, int end, int idx)
{
	int		i;
	int		cnt;
	char	*result;

	cnt = 0;
	i = 0;
	result[idx] = (char *)malloc(sizeof(char) * (end - start + 1));
	if (result == 0)
		return (0);
	result[end - start] = 0;
	while (i < end - start)
	{
		result[i] = s[start + i];
		i++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_c;
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	word_c = count_c(s, c) + 1;
	result = (char **)malloc(sizeof(char) * (word_c + 1));
	result[word_c] = 0;
	while (i < word_c)
	{
		while (s[j] != c)
		{
			temp = i;
			j++;
		}
		result[i] = each_word(s, temp, j, i);
		i++;
		j++;
	}
	free(result);
	return (result);
}
