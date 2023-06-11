/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:50:01 by eoh               #+#    #+#             */
/*   Updated: 2023/06/12 00:53:43 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_quote(char *s, int i)
{
	char	quote;
	int		end;

	quote = s[i];
	end = -1;
	i++;
	while (s[i])
	{
		if (s[i] == quote)
		{
			end = i;
			break ;
		}
		i++;
	}
	if (end == -1)
	{
		perror("wrong quote");
		exit(errno);
	}
	else
		return (end);
}

char	*split_quote(char *s)
{
	char	*result;
	char	quote;
	int		end;

	quote = s[0];
	end = 1;
	while (s[end] != quote)
	{
		end++;
	}
	result = ft_substr(s, 1, end - 1);
	return (result);
}

char	*when_quote(char	**s)
{
	char	*quote;
	char	*result;

	quote = split_quote(*s);
	result = (char *)malloc(sizeof(char) * (ft_strlen(quote) + 1));
	if (!result)
	{
		free(result);
		return (0);
	}
	ft_strlcpy(result, quote, ft_strlen(quote) + 1);
	*s += (ft_strlen(quote) + 2);
	free(quote);
	return (result);
}
