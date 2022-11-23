/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:24 by eoh               #+#    #+#             */
/*   Updated: 2022/11/24 00:32:34 by eonjoo           ###   ########.fr       */
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
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

int word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
		len++;
	return (len);
}

void free_all(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	} //순서대로 free 안해줘도 되겠지?
}

char *put_word(char const *s, int len)
{
	char *result;
	int i;

	i = 0;
	while (i < len)
	{
		result[i] = s[i];
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_c;
	int word_l;
	int i;

	i = 0;
	word_c = count_c(s, c) + 1;
	result = (char **)malloc(sizeof(char) * (word_c + 1));
	if (result == 0)
		return (0);
	result[word_c] = 0;
	while (i < word_c)
	{
		while (*s == c)
			s++;
		word_l = word_len(s, c);
		result[i] = (char *)malloc(sizeof(char) * (word_l + 1));
		if (result[i] == 0)
		{
			free_all(result, i);
			return (0);
		}
		result[i] = put_word(s, word_l);
		i++;
	}
	return (result);
}
