/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:14:05 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 15:53:45 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t i;
	size_t l;

	i = 0;
	l = 0;
	while (src[l])
	{
		l++;
	}
	while (i + 1 < size && i < l)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (l);
}
