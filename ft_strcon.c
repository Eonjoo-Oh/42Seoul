#include <stdlib.h>

char	*strcon(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*res;
	int		i;
	int		j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;

	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}