/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:23:19 by eoh               #+#    #+#             */
/*   Updated: 2022/11/21 15:23:21 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_str;
	const char		*s_str;
	const char		*c_str;
	size_t			i;

	d_str = dest;
	s_str = src;
	c_str = s_str;
	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < n)
	{
		d_str[i] = c_str[i];
		i++;
	}
	return (dest);
}
