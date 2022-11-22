/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:25:03 by eoh               #+#    #+#             */
/*   Updated: 2022/11/22 13:35:18 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*find == '\0')
		return (src);
	if (*src == '\0' || len <= 0 || ft_strlen(src) < ft_strlen(find))
		return (0);
	while (i < len)
	{
		j = 0;
		while ((src[i + j] == find[j]) && i + j < len)
		{
			j++;
			if (find[j] == 0)
				return (&(src[i]));
		}
		i++;
	}
	return (0);
}
