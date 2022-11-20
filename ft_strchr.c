/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:16:22 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 15:53:05 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char a;
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(s) + 1;
	a = (char)c;
	while (i < len)
	{
		if (*s == a)
			return ((char *)s);
		i++;
		s++;
	}
	return (0);
}
