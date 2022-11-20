/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:13 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 16:37:35 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		s1_len;
	int		cnt;
	char	*result;

	s1_len = ft_strlen(s1);
	i = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		cnt = 0;
		while (set[j])
		{
			if (*s1 == set[j])
				cnt++;
		}
		if (cnt == j)
			break;
	}
	result = (char *)malloc(sizeof(char) * (s1_len - j + 1));
	if (result == 0)
		return (0);
	while (*s1)
	{
		if (k >= i && k <= j)
			s1++;
		else
		{
			result = (char *)s1;
		}
		k++;
	}
	return (result);
}
