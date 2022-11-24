/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonjoo <eonjoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:39:32 by eoh               #+#    #+#             */
/*   Updated: 2022/11/25 00:51:06 by eonjoo           ###   ########.fr       */
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
	result = 0;
	str = (char *)s;
	while (i < l)
	{
		if (str[i] == a)
			result = &(str[i]);
		i++;
	}
	return (result);
}
