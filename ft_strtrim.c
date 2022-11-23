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

char *ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	size_t i;
	char *result;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (0);
	while (start + i <= end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}