/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:30:53 by eoh               #+#    #+#             */
/*   Updated: 2022/11/22 14:43:23 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*str;
	size_t	i;
	size_t	m_len;

	i = 0;
	m_len = len;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		m_len = ft_strlen(s) - start + 1;
	result = (char *)malloc(sizeof(char) * (m_len + 1));
	if (result == 0)
		return (0);
	while (i < m_len)
	{
		result[i] = str[start + i];
		i++;
	}
	return (result);
}
