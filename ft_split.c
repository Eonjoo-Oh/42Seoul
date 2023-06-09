#include "pipex.h"
#include <stdlib.h>

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

static size_t	count_word(char *s, char c)
{
	size_t	cnt;
	size_t	i;
	int		new_i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			new_i = count_quote(s, i);
			i = new_i + 1;
			cnt++;
			continue ;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
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

static char	**free_result(char **s)
{
	size_t	j;

	j = 0;
	while (s[j])
	{
		free((s[j]));
		j++;
	}
	free(s);
	return (0);
}

char	**ft_split(char *s, char c)
{
	size_t		i;
	char		**result;
	char		*tmp;
	char		*quote;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (0);
	while (*s)
	{
		if (*s == 34 || *s == 39)
		{
			quote = split_quote(s);
			result[i] = (char *)malloc(sizeof(char) * (ft_strlen(quote) + 1));
			if (!result[i])
				return (free_result(result));
			ft_strlcpy(result[i++], quote, ft_strlen(quote) + 1);
			s += (ft_strlen(quote) + 2);
			free(quote);
			continue ;
		}
		else if (*s != c)
		{
			tmp = s;
			while (*s && *s != c)
				s++;
			result[i] = (char *)malloc(sizeof(char) * (s - tmp + 1));
			if (!result[i])
				return (free_result(result));
			ft_strlcpy(result[i++], tmp, s - tmp + 1);
		}
		else
			s++;
	}
	return (result);
}
