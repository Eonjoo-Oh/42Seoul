/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:58:15 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 16:03:58 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d_str;
	const unsigned char	*s_str;

	d_str = dest;
	s_str = src;
	i = 0;
	while (i < n)
	{
		d_str[i] = s_str[i];
		i++;
	}
	return (d_str);
}
