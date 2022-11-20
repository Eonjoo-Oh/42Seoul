/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:39:32 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 15:54:24 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	char *str;
	char *result;
	size_t l;
	size_t i;
	char a;

	i = 0;
	result = 0;
	l = ft_strlen(s) + 1;
	a = (char)c;
	str = (char *)s;
	while (i < l)
	{
		if (*str == a)
			result = str;
		str++;
		i++;
	}
	return (result);
}
