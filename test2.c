/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:09 by eoh               #+#    #+#             */
/*   Updated: 2022/11/23 19:09:45 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	find_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	while (s1[i])
	{
		start = i;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (start == i)
			break ;
	}
	return (start);
}

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

int	find_end(const char *s1, char const *set, int start)
{
	int	len;
	int	end;
	int	j;

	len = (int)ft_strlen(s1);
	if (len == 0)
	{
		end = 0;
		return (end);
	}
	while (len > start)
	{
		end = len - 1;
		j = 0;
		while (set[j])
		{
			if (s1[len - 1] == set[j])
			{
				len--;
				break ;
			}
			j++;
		}
		if (end == len - 1)
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	start = find_start(s1, set);
	end = find_end(s1, set, start);
	if (start == ((int)(ft_strlen(s1)) - 1))
		return (ft_strdup(""));
	if (end == 0 && start == 0)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!result)
		return (0);
	i = 0;
	while (start + i <= end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	main(void)
{
	char *s1 = "abcdba";
    char *s2 = "acb";
	char *result;
	char *s;

	s = ft_strtrim(s1, s2);
	printf("result :%s\n", result);
}
