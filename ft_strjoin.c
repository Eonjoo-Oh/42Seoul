/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:55:11 by eoh               #+#    #+#             */
/*   Updated: 2023/02/21 19:14:09 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*do_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 2);
	if (str == 0)
		return (0);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = ' ';
	str[i + 1] = '\0';
	return (str);
}

char *ft_strjoin(char **argv, int argc)
{
	int i;
	char *result;
	char *temp;

	i = 1;
	result = (char *)malloc(sizeof(char) * (1));
	if (!result)
		return (0);
	result[0] = '\0';
	while (i < argc)
	{
		temp = result;
		result = do_strjoin(result, argv[i]);
		free(temp);
		i++;
	}
	return (result);
}