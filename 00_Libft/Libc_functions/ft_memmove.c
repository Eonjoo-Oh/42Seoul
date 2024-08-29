/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:23:19 by eoh               #+#    #+#             */
/*   Updated: 2022/11/25 18:01:20 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*temp;
	const char	*temp_src;

	temp = (char *)dest;
	temp_src = (const char *)src;
	i = -1;
	if (dest == 0 && src == 0)
		return (0);
	if (dest < src)
	{
		while (++i < n)
			temp[i] = temp_src[i];
	}
	else
	{
		while (n - (++i) > 0)
			temp[n - i - 1] = temp_src[n - i - 1];
	}
	return (dest);
}
