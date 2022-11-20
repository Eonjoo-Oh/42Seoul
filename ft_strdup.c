/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:27:59 by eoh               #+#    #+#             */
/*   Updated: 2022/11/17 15:53:11 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*c_src;
	int		l;
	int		i;

	l = 0;
	i = 0;
	c_src = (char *)src;
	while (c_src[l])
	{
		l++;
	}
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == 0)
		return (0);
	while (i < l)
	{
		str[i] = c_src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
