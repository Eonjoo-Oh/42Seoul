/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:30:53 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 16:32:12 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*str;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	str = (char *)s;
	while (*str)
	{
		if (*str == start)
		{
			while (*result)
			{
				result = str;
				result++;
				str++;
				return (result);
			}
		}
		str++;
	}
	return (0);
}
