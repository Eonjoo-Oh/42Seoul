/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:13 by eoh               #+#    #+#             */
/*   Updated: 2022/11/23 09:42:19 by eonjoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    size_t len;
    size_t i;
    size_t j;
    char *result;

    i = 0;
    len = ft_strlen(s1);
    while (s1[i])
    {
        start = i;
        j = 0;
        while (set[j])
        {
            if (s1[i] == set[j])
            {
                i++;
                break;
            }
            j++;
        }
        if (start == i)
            break;
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
                break;
            }
            j++;
        }
        if (end == len - 1)
            break;
    }
    i = 0;
    while (start + i <= end)
    {
        result[i] = s1[start + i];
        i++;
    }
    return (result);
}
